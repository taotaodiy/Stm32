/** 
 * @fileName   	 hc_sr04.h
 * @brief        HCSR04 超声波传感器驱动代码（4个引脚）
 *							 Trig提供一个10uS 以上脉冲触发信号，该模块内部将发出8个40kHz周期电平并检测回波。一旦检测到有回波信号则Echo输出；
 *							 回响信号的脉冲宽度与所测的距离成正比。由此通过发射信号到收到的回响信号时间间隔可以计算得到距离；
 *							 公式：uS/58=厘米或者uS/148=英寸；或是：距离=高电平时间*声速（340M/S）/2；
 *							 建议测量周期为60ms 以上，以防止发射信号对回响信号的影响。      
 * @author       Bluseli www.bluseli.cn www.bluseli.site 从此深耕不回头，谢谢关注。
 * @date         2020-3-2
 */
#ifndef _HC_SR04_H_
#define _HC_SR04_H_

#include "stm32f10x.h"

//超声波：Echo-------PA1,前超声波数据输出
//       Trig-------PA2,前超声波控制信号输入
//触发接收宏定义
#define E1_1      ((GPIOA->IDR &1<<1)!=0)//回响信号进入，为1    
#define T1_1      {(GPIOA->ODR |=1<<2);}

#define E1_0      ((GPIOA->IDR &1<<1)==0)//回响信号进入，为1    
#define T1_0      {(GPIOA->ODR &=~(1<<2));}

void SR04_Init(void);
void SR04_TIM_Init(void);
void SR04_TIM_Open(void);
void SR04_TIM_Close(void);

float SR04_Work(void);

#endif 

