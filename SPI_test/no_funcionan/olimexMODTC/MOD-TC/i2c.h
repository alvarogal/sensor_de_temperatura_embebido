#ifndef i2c_H
#define i2c_H

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
#define SendAck()	SDA_TRIS = 0; \
			SCL_TRIS = 1; \
			while(!SCL_PORT); \
			while(SCL_PORT); \
			SDA_TRIS = 1;

#define SendNack()	while(!SCL_PORT); \
			while(SCL_PORT);
/******************************************************************************/
/* Local Variables							      */
/******************************************************************************/


/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

 void StartI2C(void);
 void StopI2C(void);
 unsigned char ReadByteI2C(void);
#endif