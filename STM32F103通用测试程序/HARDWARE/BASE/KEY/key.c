#include "key.h"
#include "led.h"
#include "delay.h"
#include "sys.h"

/** 
* @describe KEY引脚初始化  修改头文件中的宏进行引脚配置
* @param		无
* 
* @return		无
*/
void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
	
	
 	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK | KEY2_GPIO_CLK,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = KEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = KEY2_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = KEY3_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = KEY4_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY4_GPIO_PORT, &GPIO_InitStructure);
	
	/*
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = KEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	*/
}

/*******************************************************************
 *
 *          @describe 按键扫描
 *
 *******************************************************************/
/** 
* @describe 按键扫描  修改头文件中的宏进行引脚配置
* @param		无
* 
* @return		KEY_DOWN KEY1按下 KEY_UP KEY1无按下
*/
uint8_t KEY_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
	{	 
		/*等待按键释放 */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN);   
		return 	KEY_DOWN;	 
	}
	else
		return KEY_UP;
}


/*******************************************************************
 *
 *          @describe 按键--外部中断
 *
 *******************************************************************/
/** 
* @describe 配置外部中断 第几根引脚对应第几跟中断线
* @param		无
* 
* @return		无
*/
void EXTIX_KEY_Init(void)
{
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;

	  //RCC_APB2Periph_AFIO  复用IO时钟 需要用到外设的重映射功能时才需要使能AFIO的时钟
  	//外部中断（EXTI）中与AFIO有关的寄存器是AFIO-EXTICR1、2、3，它们是用来选择EXTIx外部中断的输入脚之用。
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO,ENABLE);

	  /* 选择EXTI的信号源 */
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource3);
		//中断/事件线 EXTI_Line0-15 用于GPIIO
  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
		//模式选择 EXTI_Mode_Interrupt = 0x00 产生中断   EXTI_Mode_Event = 0x04 产生事件
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
		//边沿触发事件   EXTI_Trigger_Rising = 0x08, 上升沿触发  EXTI_Trigger_Falling = 0x0C, 下降沿触发  EXTI_Trigger_Rising_Falling = 0x10 上升下降都触发
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	  //中断使能
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);
		//配置中断优先级
		
		//配置中断源
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  	//抢占优先级
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
  	//子优先级
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  	//使能
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  	NVIC_Init(&NVIC_InitStructure); 
}
/** 
* @describe 中断服务函数 必须和启动文件中的函数名相同
* @param		无
* 
* @return		无
*/
void EXTI3_IRQHandler(void)
{
	//PA0和PB0 同时使用的话，进入的都是同一个中断服务函数，那么怎么区别？ 
	//可以通过读取PB0 或者 PA0 输入数据寄存器IDR的值来判断。
	//delay_ms(10);    //消抖			 

	if(EXTI_GetITStatus(EXTI_Line3) != RESET)
	{
		LED4=!LED4;
	}
	//清除EXTI0线路挂起位
	EXTI_ClearITPendingBit(EXTI_Line3);  
}
