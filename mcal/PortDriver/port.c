
/*
 * port.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Muammad Elzeiny
 */
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

#include <tm4c123_firmware/utils/Std_Types.h>
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include <tm4c123_firmware/mcal/PortDriver/port_types.h>
#include <tm4c123_firmware/mcal/PortDriver/port.h>

extern Port_CfgType PortCfgArr[];

void PORT_init(void)
{

    volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                            PORTC_BaseAddr,PORTD_BaseAddr,
                                                            PORTE_BaseAddr,PORTF_BaseAddr};
    uint8 CfgArrIndex;
    uint8 PortId;
    Port_ChIdType ChannelId;
    uint8 ChannelPosInPort;
    volatile PORT_RegType* BaseAddr;

    for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
    {
        /*get channelID from CfgIndex*/
        ChannelId = PortCfgArr[CfgArrIndex].Channel;

        /*get PORTId using ChannelId*/
        PortId = ChannelId / MAX_NUM_OF_CH_IN_PORT;

        /*get baseAddress using PortId*/
        BaseAddr = BaseAddrArr[PortId];

        /*get Channel Position in PortGroup using ChannelId */
        ChannelPosInPort = ChannelId % MAX_NUM_OF_CH_IN_PORT;

        /*NOTE use channel position in Group to write in corresponding bit in Desired Register */

        /* set channel mode */

        switch(PortCfgArr[CfgArrIndex].Mode)
        {
        case PORT_MODE_PIN_X_DIO:
            /* set channel direction */
            switch(PortCfgArr[CfgArrIndex].Dir)
            {
            case port_Dir_Input:
                BaseAddr->GPIODIR&=~(1<<ChannelPosInPort);
                break;
            case port_Dir_Output:
                BaseAddr->GPIODIR|=(1<<ChannelPosInPort);
                break;
            }
            break;
            default :
                break;
        }

        /* set Interrupt configuration */
        if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
        {

            CLR_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
        }
        else
        {

            SET_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
        }

        /* set Internal Attachment configuration */
        switch (PortCfgArr[CfgArrIndex].AttachedRes)
        {
        case Port_InternalAttach_PullUpRes:
            SET_BIT(BaseAddr->GPIOPUR,ChannelPosInPort);
            break;
        case Port_InternalAttach_PullDownRes:
            SET_BIT(BaseAddr->GPIOPDR,ChannelPosInPort);
            break;
        case Port_InternalAttach_OpenDrain:
            SET_BIT(BaseAddr->GPIOODR,ChannelPosInPort);
            break;
        default:
            break;
        }

        /* set current strength configuration */
        switch(PortCfgArr[CfgArrIndex].CurrentDrive)
        {
        case Port_CurrDrive_2mA:
            SET_BIT(BaseAddr->GPIODR2R,ChannelPosInPort);
            break;
        case Port_CurrDrive_4mA:
            SET_BIT(BaseAddr->GPIODR4R, ChannelPosInPort);
            break;
        case Port_CurrDrive_8mA:
            SET_BIT(BaseAddr->GPIODR8R, ChannelPosInPort);
            break;
        default:
            break;
        }

        /* set Interrupt configuration */
        if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
        {
            CLR_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
        }
        else
        {
            SET_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
            if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntRisingEdge)
            {
                SET_BIT(BaseAddr->GPIOIEV,ChannelPosInPort);
            }
            else if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntFallingEdge)
            {
                CLR_BIT(BaseAddr->GPIOIEV,ChannelPosInPort);
            }
            else if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntBothEdges)
            {
                SET_BIT(BaseAddr->GPIOIBE,ChannelPosInPort);
            }
        }
        /*Check if analog functionality is required*/
        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
        {
            /*enable digital and disable ADC  */
            /* enable digital */
            SET_BIT(BaseAddr->GPIODEN,ChannelPosInPort);
            /*disable ADC */
            CLR_BIT(BaseAddr->GPIOADCCTL,ChannelPosInPort);

        }
        else
        {
            /* disable digital and enable ADC */
            /* disable digital */
            CLR_BIT(BaseAddr->GPIODEN,ChannelPosInPort);
            /* enable ADC */
            SET_BIT(BaseAddr->GPIOADCCTL,ChannelPosInPort);
        }
    }
}
