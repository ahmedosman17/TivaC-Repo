/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "dio_types.h"
/*TODO: include the header file that contains register definitions */
#include "../mcu_hw.h"

#include "dio.h"

volatile PORT_RegType* BaseAddrArr[6] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                                PORTC_BaseAddr,PORTD_BaseAddr,
                                                                PORTE_BaseAddr,PORTF_BaseAddr};



uint8 Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 ret;
    uint8 PortId = ChannelId / 8;
    uint8 ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr=BaseAddrArr[PortId];
    /*TODO: Return the level value of given Channel */

    ret = GET_BIT(BaseAddr->GPIODATA,ChannelPos);

    return ret;

}




void Dio_WriteChannel(Dio_ChannelType ChannelId, uint8 Level)
{
    uint8 PortId = ChannelId / 8;
    uint8 ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr=BaseAddrArr[PortId];

        if(Level == STD_low)
        {
            CLR_BIT(BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(BaseAddr->GPIODATA,ChannelPos);
        }

}


uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;
    volatile PORT_RegType* BaseAddr=BaseAddrArr[PortId];
    ret = BaseAddr->GPIODATA;

    return ret;
}



void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    volatile PORT_RegType* BaseAddr=BaseAddrArr[PortId];

    BaseAddr->GPIODATA = value;

}



void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    uint8 PortId = ChannelId / 8;
    uint8 ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr=BaseAddrArr[PortId];


    TOGGLE_BIT(BaseAddr->GPIODATA,ChannelPos);


}
void Dio_FlipPort(Dio_PortType PortId)
{
    volatile PORT_RegType* BaseAddr=BaseAddrArr[PortId];
    BaseAddr->GPIODATA = ~ BaseAddr->GPIODATA;

}
