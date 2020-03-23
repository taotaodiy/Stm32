/******************************************************************************
* @fileName hc_sr501.h
* @author  	Bluseli  www.Bluseli.cn
* @date    	2020/3/7
* @brief   	热释电驱动代码 
*******************************************************************************/
#ifndef __HC_SR501_H
#define __HC_SR501_H	 

#include "sys.h"

#define ON	1
#define OFF	0

//位带操作
//LED引脚
#define HC_SR501_BIT   0
//LED端口定义 
#define HC_SR501 PAin(HC_SR501_BIT)// PA0

//这个写法来自 火哥 方便移植
//LED1
#define HC_SR501_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* 时钟 */
#define HC_SR501_GPIO_PORT    	GPIOA			              /* 端口 */
#define HC_SR501_GPIO_PIN				GPIO_Pin_0	        /* 位 */

void HC_SR501_Init(void);//初始化
int  HC_SR501_Read(void); //读取热释电状态
		 				    
#endif
