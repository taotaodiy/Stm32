/******************************************************************************
* @fileName beep.h
* @author  	Bluseli  www.Bluseli.cn
* @date    	2020/1/14
* @brief   	·äÃùÆ÷Çý¶¯ 
*******************************************************************************/
#ifndef __BEEP__H
#define __BEEP__H

#include "stm32f10x.h"

#define BEEP_BIT   7
#define BEEP PAout(BEEP_BIT)

#define    BEEP_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    BEEP_GPIO_PORT    GPIOA			   
#define    BEEP_GPIO_PIN		 GPIO_Pin_7

void BEEP_Init(void);
void Sound(u16 frq);
void Sound2(u16 time);
void play_music(void);
void play_successful(void);
void play_failed(void);

#endif


