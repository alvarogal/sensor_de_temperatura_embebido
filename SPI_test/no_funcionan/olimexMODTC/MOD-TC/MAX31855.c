#include <htc.h>            /* HiTech General Includes */
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "MAX31855.h"

void InitSPI(void)
{
	MISO_INIT;
	CLK_INIT;
	CS_INIT;
	CS_HIGH;

	DelaySPI();
	DelaySPI();

}

void DelaySPI()
{
	int i;
	for (i = 0; i < 10; i++);
}

unsigned long int ReadDataSPI(void)
{
	unsigned long int data = 0, i;

	CS_LOW;


	for (i = 0; i < 32; i++) {
		CLK = 1;
		data |= (MISO & 0x01) ? 1 : 0;

		if (i != 31) data <<= 1;
		CLK = 0;
	}

	CS_HIGH;
	return data;
}

