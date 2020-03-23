#include "hc_sr501.h"
	   
/** 
* @describe 热释电初始化  修改头文件中的宏进行引脚配置
* @param		无
* 
* @return		无
*/
void HC_SR501_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;

 RCC_APB2PeriphClockCmd(HC_SR501_GPIO_CLK, ENABLE);
	
 GPIO_InitStructure.GPIO_Pin = HC_SR501_GPIO_PIN;	
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  
 GPIO_Init(HC_SR501_GPIO_PORT, &GPIO_InitStructure);
 //GPIO_SetBits(HC_SR501_GPIO_PORT,HC_SR501_GPIO_PIN);	
 //GPIO_ResetBits(HC_SR501_GPIO_PORT,HC_SR501_GPIO_PIN);		
}

int HC_SR501_Read(void)
{
	if(HC_SR501 == ON)
	{
		return ON;
	}
	return OFF;
}
