/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcu_hw.h"
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "SysCtr.h"




#define CLOCK_ENABLE    1
#define CLOCK_DISABLE   0

/*TODO include SysCtr_cfg.h*/

#include "../../config/SysCtr_cfg.h"


void SysCtr_init(void)
{
    /*TODO Enable configured Peripherals CLock gates*/

/*********************************************************/
/*                   SET PORT REGs                       */
/*********************************************************/

    RCGCGPIO_REG.R0 = PORTA;
    RCGCGPIO_REG.R1 = PORTB;
    RCGCGPIO_REG.R2 = PORTC;
    RCGCGPIO_REG.R3 = PORTD;
    RCGCGPIO_REG.R4 = PORTE;
    RCGCGPIO_REG.R5 = PORTF;

/*********************************************************/
/*                   SET UART REGs                       */
/*********************************************************/

    RCGCUART_REG.R0 = UART0;
    RCGCUART_REG.R1 = UART1;
    RCGCUART_REG.R2 = UART2;
    RCGCUART_REG.R3 = UART3;
    RCGCUART_REG.R4 = UART4;
    RCGCUART_REG.R5 = UART5;
    RCGCUART_REG.R6 = UART6;
    RCGCUART_REG.R7 = UART7;



/*********************************************************/
/*                   SET SSI REGs                       */
/*********************************************************/


     RCGCSSI_REG.R0 = SSI0;
     RCGCSSI_REG.R1 = SSI1;
     RCGCSSI_REG.R2 = SSI2;
     RCGCSSI_REG.R3 = SSI3;


/*********************************************************/
/*                   SET SSI REGs                        */
/*********************************************************/

     RCGCI2C_REG.R0 = I2C0;
     RCGCI2C_REG.R1 = I2C1;
     RCGCI2C_REG.R2 = I2C2;
     RCGCI2C_REG.R3 = I2C3;


/*********************************************************/
/*             SET GROUPS AND SUBGROUPS REGs             */
/*********************************************************/
     /* Warring ********** you have to be at privileged mode to access this register */


    // APINT= ((APINT&(0x0000FFFF)UL)|(0xFA05UL<<16));
     APINT = (((APINT&0x0000FFFFUL))|(0xFA05UL<<16) );
     APINT = ((APINT&(~(0x07<<8)))|(GROUPS_SUBGROUPS<<8) );

    /*TODO Set System CLock Source as configured*/

    /*TODO set CLock Frequency as configured -
     * use Figure 5-5. Main Clock Tree Page.222 in DATASHEET as reference.
     * */
#warning "Set Privileged Mode !!!!! "

}




uint32 SysCtr_getSysClockFreq(void)
{
    /*TODO return the current system clock frequency */


    return 16000000UL;
}

