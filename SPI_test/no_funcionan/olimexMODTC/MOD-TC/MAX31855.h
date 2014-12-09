/*
 * File:   MAX31855.h
 * Author: Stefan
 *
 * Created on 06 July 2012, 11:05
 */

#ifndef MAX31855_H
#define MAX31855_H

#define	MISO_INIT	TRISCbits.TRISC1 = 1
#define MISO		PORTCbits.RC1
#define CLK_INIT	TRISCbits.TRISC0 = 0
#define CLK		LATCbits.LATC0
#define CS_INIT		TRISAbits.TRISA4 = 0
#define CS_HIGH		LATAbits.LATA4 = 1
#define CS_LOW		LATAbits.LATA4 = 0



void InitSPI(void);
void DelaySPI(void);
unsigned long int ReadDataSPI(void);



#endif
