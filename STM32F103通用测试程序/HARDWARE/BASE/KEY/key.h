/******************************************************************************
* @fileName key.h
* @author  	Bluseli  www.Bluseli.cn
* @date    	2020/1/14
* @brief   	按键驱动代码 
*******************************************************************************/

#ifndef __KEY_H
#define __KEY_H	 

#include "stm32f10x.h"

#define KEY_DOWN	1
#define KEY_UP		0


//LED引脚
#define KEY1_BIT   1
#define KEY2_BIT   2
//LED端口定义 
#define KEY1 PAout(KEY1_BIT)// PA1
#define KEY2 PAout(KEY2_BIT)// PA2

#define    KEY1_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    KEY1_GPIO_PORT    GPIOC			   
#define    KEY1_GPIO_PIN		 GPIO_Pin_1

#define    KEY2_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    KEY2_GPIO_PORT    GPIOC		   
#define    KEY2_GPIO_PIN		 GPIO_Pin_2

#define    KEY3_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    KEY3_GPIO_PORT    GPIOC		   
#define    KEY3_GPIO_PIN		 GPIO_Pin_3

#define    KEY4_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    KEY4_GPIO_PORT    GPIOC		   
#define    KEY4_GPIO_PIN		 GPIO_Pin_4

void KEY_Init(void);//IO初始化
uint8_t KEY_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);	//按键扫描

void EXTIX_KEY_Init(void);//中断初始化
#endif
