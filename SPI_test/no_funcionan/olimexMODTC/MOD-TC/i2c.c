/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <htc.h>            /* HiTech General Includes */
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "OLIMEX.h"
#include "i2c.h"

/******************************************************************************/
/* User Functions                                                             */

/******************************************************************************/

void StartI2C(void)
{
	while (1) {
		while (!SDA_PORT);
		while (SDA_PORT);
		if (SCL_PORT)
			break;
	}
	while (SCL_PORT);
}

void StopI2C(void)
{
	while (!SDA_PORT || !SCL_PORT);
}

unsigned char ReadByteI2C(void)
{
	unsigned char data, i;
	data = 0;
	
	for (i = 8; i; i--) {
		while (!SCL_PORT);
		data |= SDA_PORT & 0x01;
		if (i != 1)
			data <<= 1;
		while (SCL_PORT);
		

	}
	SCL_TRIS = 0;
	return data;

}

void WriteByteI2C(unsigned char data)
{
	unsigned char i;
	for (i = 0; i < 8; i++) {

		SDA_TRIS = (data & 0x80) ? 1 : 0;
		if (i != 7)
			data <<= 1;
		while (!SCL_PORT);
		while (SCL_PORT);

	}
	SDA_TRIS = 1;
}


