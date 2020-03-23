#ifndef __HW_H
#define __HW_H 			   
#include "stm32f10x.h"
#include "sys.h"

//红外对管
//透明   长正---3.3v 短负---GND 发送端
//不透明 长负---GND  短信号--GPIO 接收端

//端口定义
#define HW_EN PAout(1)								 	// PC0 红外使能，给1为使能
#define HW GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)			// PC1 红外上检测

#define HW_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* 时钟 */
#define HW_GPIO_PORT    	GPIOA			              /* 端口 */
#define HW_GPIO_PIN				GPIO_Pin_1			        /* 位 */


void HW_Init(void);//红外初始化
void EXTI_HW_Init(void);

#endif
