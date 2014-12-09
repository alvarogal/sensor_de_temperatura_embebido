/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <htc.h>            /* HiTech General Includes */
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "i2c.h"
#include "OLIMEX.h"
#include "MAX31855.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{


	/* Setup analog functionality and port direction */
	ANSELC = 0x00;
	ANSELA = 0x00;

	SCL_TRIS = 1;
	SDA_TRIS = 1;
	SCL_LAT = 0;
	SDA_LAT = 0;

	InitSPI();

	JMP_TRIS = 1;
	JMP_LAT = 0;
	OPTION_REGbits.nWPUEN = 0;
	WPUAbits.WPUA = 0x00;


	DATA_OUT[0] = 0xFF;
	DATA_OUT[1] = 0xFF;
	DATA_OUT[2] = 0xFF;
	DATA_OUT[3] = 0xFF;

	CommandSetLat(0x00);
	CommandSetTris(0xFF);
	CommandSetPullUps(0x00);
}

void InitAddress(void)
{
	unsigned int address;
	address = ReadFlash(ADDR_MEM);
	/* IF THE MEMORY CELL IS EMPTY*/
	if ((address & 0x00FF) == 0xFF)
		ADDRESS = ADDR_DFL;
	else
		ADDRESS = address & 0x00FF;
}

unsigned int ReadFlash(unsigned int address)
{
	unsigned int data = 0;
	PMADRL = address & 0x00FF;
	address >>= 8;
	PMADRH = address & 0x00FF;
	PMCON1bits.CFGS = 0;
	PMCON1bits.RD = 1;
	Nop();
	Nop();

	data = PMDATH;
	data <<= 8;
	data |= PMDATL;
	return data;
}

void EraseFlash(unsigned int address)
{
	GIE = 0;
	PMADRL = address & 0x00FF;
	address >>= 8;
	PMADRH = address & 0x00FF;
	PMCON1bits.CFGS = 0;
	PMCON1bits.FREE = 1;
	PMCON1bits.WREN = 1;
	UnlockFlash();
	PMCON1bits.WREN = 0;
	GIE = 1;
}

void UnlockFlash(void)
{
	PMCON2 = 0x55;
	PMCON2 = 0xAA;
	PMCON1bits.WR = 1;
	Nop();
	Nop();
}

void WriteFlash(unsigned int data, unsigned int address)
{
	GIE = 0;
	PMCON1bits.CFGS = 0;
	PMADRL = address & 0x00FF;
	address >>= 8;
	PMADRH = address & 0x00FF;
	PMCON1bits.FREE = 0;
	PMCON1bits.LWLO = 1;
	PMCON1bits.WREN = 1;
	PMDATL = data & 0x00FF;
	data >>= 8;
	PMDATH = data & 0x00FF;
	PMCON1bits.LWLO = 0;
	UnlockFlash();
	PMCON1bits.WREN = 0;
	GIE = 1;
}

void CommandSetTris(unsigned char data)
{

	GPIO0_TRIS = data & 0x01;
	data >>= 1;
	GPIO1_TRIS = data & 0x01;
	data >>= 1;
	GPIO2_TRIS = data & 0x01;
	data >>= 1;
	GPIO3_TRIS = 1;
	data >>= 1;
	GPIO4_TRIS = data & 0x01;
	data >>= 1;
	GPIO5_TRIS = data & 0x01;
	data >>= 1;
	GPIO6_TRIS = data & 0x01;

}

void CommandSetLat(unsigned char data)
{

	GPIO0_LAT = data & 0x01;
	data >>= 1;
	GPIO1_LAT = data & 0x01;
	data >>= 1;
	GPIO2_LAT = data & 0x01;
	data >>= 1;
	//	GPIO3_LAT = command & 0x01;	GPIO3 is ALWAYS INPUT!!!
	data >>= 1;
	GPIO4_LAT = data & 0x01;
	data >>= 1;
	GPIO5_LAT = data & 0x01;
	data >>= 1;
	GPIO6_LAT = data & 0x01;

}

unsigned char CommandGetPort(void)
{

	unsigned char data = 0;
	data = GPIO6_PORT;
	data <<= 1;
	data |= GPIO5_PORT;
	data <<= 1;
	data |= GPIO4_PORT;
	data <<= 1;
	data |= GPIO3_PORT;
	data <<= 1;
	data |= GPIO2_PORT;
	data <<= 1;
	data |= GPIO1_PORT;
	data <<= 1;
	data |= GPIO0_PORT;
	return data;

}

unsigned long int CommandGetTemp(void)
{
	unsigned long int temp = 0;
	temp = ReadDataSPI();
	return temp;
}

void CommandSetPullUps(unsigned char data)
{
	WPUAbits.WPUA0 = data & 0x01;
	data >>= 1;
	WPUAbits.WPUA1 = data & 0x01;
	data >>= 1;
	WPUAbits.WPUA2 = data & 0x01;
	data >>= 1;
	WPUAbits.WPUA3 = data & 0x01;
	data >>= 1;
	WPUAbits.WPUA5 = data & 0x01;
	data >>= 1;

}

void CommandSetAddress(unsigned char data)
{
	if (!JMP_PORT) {
		/* STORE THE NEW ADDRESS INTO THE FLASH MEMORY */
		EraseFlash(ADDR_MEM);
		WriteFlash(data, ADDR_MEM);
		ADDRESS = data;
	}
}

unsigned int CommandGetAn(unsigned char channel)
{
	unsigned int data;

	/* PORT INIT */

	switch (channel) {
	case 0:
		TRISAbits.TRISA0 = 1;
		ANSELAbits.ANSA0 = 1;
		break;
	case 1:
		TRISAbits.TRISA1 = 1;
		ANSELAbits.ANSA1 = 1;
		break;
	case 2:
		TRISAbits.TRISA2 = 1;
		ANSELAbits.ANSA2 = 1;
		break;
	case 6:
		TRISCbits.TRISC2 = 1;
		ANSELCbits.ANSC2 = 1;
		break;

	case 7:
		TRISCbits.TRISC3 = 1;
		ANSELCbits.ANSC3 = 1;
		break;

	default:
		break;
	}

	/*CONFIG ADC*/
	ADCON1bits.ADFM = 1;
	ADCON1bits.ADCS = 0;
	ADCON1bits.ADPREF = 0;
	ADCON0bits.CHS = channel;
	ADCON0bits.ADON = 1;

	ADCON0bits.ADGO = 1;
	while (ADCON0bits.ADGO);

	data = ADRESH;
	data << = 8;
	data |= ADRESL;

	switch (channel) {
	case 0:
		ANSELAbits.ANSA0 = 0;
		break;
	case 1:
		ANSELAbits.ANSA1 = 0;
		break;
	case 2:
		ANSELAbits.ANSA2 = 0;
		break;
	case 6:
		ANSELCbits.ANSC2 = 0;
		break;

	case 7:
		ANSELCbits.ANSC3 = 0;
		break;

	default:
		break;
	}
	return data;
}

void StartSystem(void)
{
	unsigned char address = 0;
	unsigned char command = 0;
	unsigned char data = 0;
	unsigned char rw = 0;
	unsigned char temp_data = 0;
	unsigned char i;
	unsigned char j = 0;
	unsigned int adc;
	unsigned long int tc;


	/*Loop until START condition is recieved*/
	StartI2C();

	/*Read the first bit of the address*/
	address = ReadByteI2C();
	if ((address >> 1) == ADDRESS) {
		/* Send ACK */
		SendAck();

		SCL_TRIS = 0; //HOLD THE CLOCK
		rw = address & 0x01;
		if (rw) {
			while (1) {
				temp_data = DATA_OUT[j++];
				/* READ LAST WAS ADDRESS */
				SDA_TRIS = (temp_data & 0x80) ? 1 : 0;
				temp_data <<= 1;
				SCL_TRIS = 1; //RELEASE THE CLOCK
				for (i = 0; i < 7; i++) {
					while (!SCL_PORT);
					while (SCL_PORT);
					SDA_TRIS = (temp_data & 0x80) ? 1 : 0;
					temp_data <<= 1;
				}


				while (!SCL_PORT);
				while (SCL_PORT);
				SDA_TRIS = 1;
				while (!SCL_PORT);
				if (SDA_PORT)
					break;
				while (SCL_PORT);
			}
		} else {
			/* WRITE LAST WAS ADDRESS */
			SCL_TRIS = 1;
			command = ReadByteI2C();
			SendAck();
			SCL_TRIS = 0;
			switch (command) {
			case GET_ID:
				DATA_OUT[0] = DEVICE_ID;
				SCL_TRIS = 1;
				break;

			case GET_PORT:
				DATA_OUT[0] = CommandGetPort();
				SCL_TRIS = 1;
				break;

			case SET_ADDRESS:
				SCL_TRIS = 1;
				data = ReadByteI2C();
				SendAck();
				SCL_TRIS = 0;
				CommandSetAddress(data);
				SCL_TRIS = 1;
				break;

			case SET_TRIS:
				SCL_TRIS = 1;
				data = ReadByteI2C();
				SendAck();
				SCL_TRIS = 0;
				CommandSetTris(data);
				SCL_TRIS = 1;
				break;

			case SET_LAT:
				SCL_TRIS = 1;
				data = ReadByteI2C();
				SendAck();
				SCL_TRIS = 0;
				CommandSetLat(data);
				SCL_TRIS = 1;
				break;

			case SET_PU:
				SCL_TRIS = 1;
				data = ReadByteI2C();
				SendAck();
				SCL_TRIS = 0;
				CommandSetPullUps(data);
				SCL_TRIS = 1;
				break;

			case GET_AN0:
			case GET_AN1:
			case GET_AN2:
			case GET_AN6:
			case GET_AN7:
				adc = CommandGetAn(command - 0x10);
				DATA_OUT[0] = adc & 0xFF;
				DATA_OUT[1] = (adc >> 8) & 0xFF;
				DATA_OUT[2] = 0xFF;
				DATA_OUT[3] = 0xFF;
				SCL_TRIS = 1;
				break;

			case GET_TEMP:
				tc = CommandGetTemp();
				DATA_OUT[0] = tc & 0xFF;
				tc >>= 8;
				DATA_OUT[1] = tc & 0xFF;
				tc >>= 8;
				DATA_OUT[2] = tc & 0xFF;
				tc >>= 8;
				DATA_OUT[3] = tc & 0xFF;
				SCL_TRIS = 1;
				break;


			default:
				SCL_TRIS = 1;
				break;
			}
		}


	} else {
		SCL_TRIS = 1;
		SendNack();
	}

	StopI2C();

}



