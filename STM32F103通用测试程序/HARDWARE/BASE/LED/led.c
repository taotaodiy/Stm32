#include "led.h"
	   
/** 
* @describe LED引脚初始化  修改头文件中的宏进行引脚配置
* @param		无
* 
* @return		无
*/
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;

 RCC_APB2PeriphClockCmd(LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK | LED4_GPIO_CLK, ENABLE);	 //使能PA端口时钟
	
 GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;				 //LED1-->PA1 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
 GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);
 //GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);			 //PA1 输出高
 GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);			 //PA1 输出低
	
 GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;				 //LED2-->PA2 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
 //GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);			 //PA2输出高
 GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);			 //PA2 输出低
}
