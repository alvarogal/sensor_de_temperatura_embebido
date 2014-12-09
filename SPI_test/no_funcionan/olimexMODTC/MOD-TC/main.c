/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <htc.h>           /* Global Header File */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */


/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/


unsigned char ADDRESS;
unsigned char DATA_OUT[4];


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/


void main(void)
{

    ConfigureOscillator();

    InitApp();

    InitAddress();


    while(1)
    {
	    StartSystem();


    }

}



