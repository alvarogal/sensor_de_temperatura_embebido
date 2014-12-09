#ifndef user_H
#define user_H
/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/


//I2C specific macros
#define SDA_TRIS	TRISCbits.TRISC5
#define SDA_LAT		LATCbits.LATC5
#define SDA_PORT	PORTCbits.RC5
#define SCL_TRIS	TRISCbits.TRISC4
#define SCL_LAT		LATCbits.LATC4
#define SCL_PORT	PORTCbits.RC4

//GPIO pins
#define GPIO0_TRIS	TRISAbits.TRISA0
#define GPIO0_LAT	LATAbits.LATA0
#define GPIO0_PORT	PORTAbits.RA0

#define GPIO1_TRIS	TRISAbits.TRISA1
#define GPIO1_LAT	LATAbits.LATA1
#define GPIO1_PORT	PORTAbits.RA1

#define GPIO2_TRIS	TRISAbits.TRISA2
#define GPIO2_LAT	LATAbits.LATA2
#define GPIO2_PORT	PORTAbits.RA2

#define GPIO3_TRIS	TRISAbits.TRISA3
#define GPIO3_PORT	PORTAbits.RA3

#define GPIO4_TRIS	TRISAbits.TRISA5
#define GPIO4_LAT	LATAbits.LATA5
#define GPIO4_PORT	PORTAbits.RA5

#define GPIO5_TRIS	TRISCbits.TRISC2
#define GPIO5_LAT	LATCbits.LATC2
#define GPIO5_PORT	PORTCbits.RC2

#define GPIO6_TRIS	TRISCbits.TRISC3
#define GPIO6_LAT	LATCbits.LATC3
#define GPIO6_PORT	PORTCbits.RC3

#define ADDR_MEM	0x7FF
#define ADDR_DFL	0x23

#define JMP_TRIS	TRISAbits.TRISA5
#define JMP_LAT		LATAbits.LATA5
#define JMP_PORT	PORTAbits.RA5



#define Nop() asm("NOP")
/******************************************************************************/
/* Local Variables							      */
/******************************************************************************/

extern unsigned char ADDRESS;
extern unsigned char DATA_OUT[4];

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

void InitApp(void);         /* I/O and Peripheral Initialization */
void InitAddress(void);		/* Set the device ID at startup */

/*FLASH MEMORY COMMANDS*/
void WriteFlash(unsigned int data, unsigned int address);
unsigned int ReadFlash(unsigned int address);
void EraseFlash(unsigned int address);
void UnlockFlash(void);

/*OLIMEX COMMANDS ROUTINES*/
void CommandSetTris(unsigned char data);
void CommandSetLat(unsigned char data);
unsigned char CommandGetPort(void);
void CommandSetPullUps(unsigned char data);

unsigned long int CommandGetTemp(void);
unsigned int CommandGetAn(unsigned char channel);
void CommandSetAddress(unsigned char data);
void StartSystem(void);



#endif
