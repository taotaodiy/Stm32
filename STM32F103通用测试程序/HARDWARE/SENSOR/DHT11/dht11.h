/******************************************************************************
* @fileName dht11.h
* @author  	Bluseli  www.Bluseli.cn
* @date    	2020/1/14
* @brief   	dht11温湿度传感器驱动代码
*******************************************************************************/
#ifndef __DHT11_H__
#define	__DHT11_H__
#include "stm32f10x.h"
#include "delay.h"

#define 	DHT_Direction_I  	{GPIOA->CRL &= 0XFFFFFFF0; GPIOA->CRL |= 8;}
#define 	DHT_Direction_O 	{GPIOA->CRL &= 0XFFFFFFF0; GPIOA->CRL |= 3;}

#define		O_DHT_DAT			PAout(0)
#define		I_DHT_DAT			PAin(0)

#define		DHT_GPIO_CLK	RCC_APB2Periph_GPIOA
#define		DHT_GPIO_PORT	GPIOA
#define		DHT_GPIO_PIN	GPIO_Pin_0


void DHT11_Init(void);
void DHT11_Reset(void);
uint8_t DHT11_IsOnline(void);
uint8_t DHT11_Read_Data(float *temp,float *humi);
#endif

