/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_







/*TODO implement suitable container to store the followings
 *
 * which peripheral clock gate Enabled
 * Desired System clock Source
 * Desired System CLock Frequency
 * */

/**************************************************************************************/
/*                              GPIO CFG                                              */
/**************************************************************************************/

#define PORTA               CLOCK_DISABLE
#define PORTB               CLOCK_DISABLE
#define PORTC               CLOCK_DISABLE
#define PORTD               CLOCK_DISABLE
#define PORTE               CLOCK_DISABLE
#define PORTF               CLOCK_DISABLE

/**************************************************************************************/
/*                                  UART CFG                                          */
/**************************************************************************************/

#define UART0              CLOCK_DISABLE
#define UART1              CLOCK_DISABLE
#define UART2              CLOCK_DISABLE
#define UART3              CLOCK_DISABLE
#define UART4              CLOCK_DISABLE
#define UART5              CLOCK_DISABLE
#define UART6              CLOCK_DISABLE
#define UART7              CLOCK_DISABLE

/**************************************************************************************/
/*                                  SSI CFG                                            */
/**************************************************************************************/

#define SSI0               CLOCK_DISABLE
#define SSI1               CLOCK_DISABLE
#define SSI2               CLOCK_DISABLE
#define SSI3               CLOCK_DISABLE


/**************************************************************************************/
/*                                  SSI CFG                                            */
/**************************************************************************************/

#define I2C0               CLOCK_DISABLE
#define I2C1               CLOCK_DISABLE
#define I2C2               CLOCK_DISABLE
#define I2C3               CLOCK_DISABLE
#define I2C4               CLOCK_DISABLE

/**************************************************************************************/
/*                              Groups and Subgroups CF                               */
/**************************************************************************************/


#define GROUPS8_SUBGROUPS1  0
#define GROUPS4_SUBGROUPS2  5
#define GROUPS2_SUBGROUPS4  6
#define GROUPS1_SUBGROUPS8  7


#define GROUPS_SUBGROUPS    GROUPS8_SUBGROUPS1


#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
