/** 
 * @fileName   	 hc_sr04.c
 * @brief         HCSR04 超声波传感器驱动代码（4个引脚）      
 * @author        Bluseli www.bluseli.cn www.bluseli.site 从此深耕不回头，谢谢关注。
 * @date          2020-3-2
 */
#include "hc_sr04.h"
#include "usart.h"
#include "delay.h"
#include "timer.h"

u16 sr04Count=0;

/** 
 * @describe	 硬件初始化
 * @param		 	 无
 * 
 * @return		 无
 */
void SR04_Init(void)
{
  //使用定时器计数
  //IO口一个为输出一个为输入
  RCC->APB2ENR |=(1<<2);
  GPIOA->CRL &=~(0xFF<<4*1);
  GPIOA->CRL |=0x34<<4*1;
	
	SR04_TIM_Init();
	
}
/** 
 * @describe	 超声波测距定时器初始化
 * @param		 	 无
 * 
 * @return		 无
 */
void SR04_TIM_Init(void)
{
	Timer1_Init(999, 72-1);
}
/** 
 * @describe	 打开定时器
 * @param		 	 无
 * 
 * @return		 无
 */
void SR04_TIM_Open(void)
{
  	TIM_Cmd(TIM1, ENABLE);
}
/** 
 * @describe	 关闭定时器
 * @param		 	 无
 * 
 * @return		 无
 */
void SR04_TIM_Close(void)
{
		TIM_Cmd(TIM1, DISABLE);
}
//前超声波
float SR04_Work(void)
{
	u8 i = 0;
	u32 t = 0;
  u16 cnt=0;
	float lengthTemp = 0;
	float sum = 0;
	while(i!=5)
	{ 
		T1_1;     
		delay_us(30);
		T1_0;
		sr04Count=0;
		while(E1_0);//等待回响信号，     
		SR04_TIM_Open();        
		i = i + 1;
		while(E1_1);//回响信号结束
		SR04_TIM_Close(); 
//		t=sr04Count*1000;
//		t+=TIM1->CNT;
		lengthTemp = ((float)t/58.0);//cm
		sum = lengthTemp + sum ;   
	}
	lengthTemp = sum/5.0;//求平均值
	return lengthTemp;
}

