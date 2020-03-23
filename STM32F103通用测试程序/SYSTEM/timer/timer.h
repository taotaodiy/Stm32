/** 
* @projectName   定时器
* @brief         定时器 
* @author        Bluseli
* @date          2020-3-2
*/
#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

//基本定时器
void Timer6_Init(u16 arr,u16 psc);
//通用定时器
void Timer3_Init(u16 arr,u16 psc); 
void Timer4_Init(u16 arr,u16 psc);
//高级定时器
void Timer1_Init(u16 arr,u16 psc);
#endif
