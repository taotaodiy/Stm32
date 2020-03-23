#include "dht11.h"

/** 
* @describe DHT-11引脚初始化 头文件中配置引脚
* @param		无
* 
* @return		无
*/
void DHT11_Init(void)
{	 
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(DHT_GPIO_CLK, ENABLE);	 
	
 	GPIO_InitStructure.GPIO_Pin 	= DHT_GPIO_PIN;				 
 	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP; 		 
 	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
 	GPIO_Init(DHT_GPIO_PORT, &GPIO_InitStructure);				  
	
	DHT11_Reset();
} 

/** 
* @describe 复位DHT-11
* @param		无
* 
* @return		无
*/
void DHT11_Reset(void)	   
{   
	//改变GPIO方向 准备发出数据
	DHT_Direction_O;
	GPIO_ResetBits(DHT_GPIO_PORT,DHT_GPIO_PIN);
	delay_ms(20);    	
	GPIO_SetBits(DHT_GPIO_PORT,DHT_GPIO_PIN);
	delay_us(30);     
}

/** 
* @describe 等待DHT11回应
* @param		无
* 
* @return		0 OK 1 未检测到
*/
uint8_t DHT11_IsOnline(void) 	   
{   
	uint8_t retry = 0;
	//改变GPIO方向 准备读取数据
	DHT_Direction_I;
	while (GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	
	if(retry >= 100)
	{
		return 1;
	}
	else
	{
		retry = 0;
	}
	
	while (!GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	
	if(retry >= 100)
	{
		return 1;
	}	    
	return 0;
}
/** 
* @describe 读取一个Bit
* @param		无
* 
* @return		0uint8_t
*/
uint8_t DHT11_ReadBit(void) 			 
{
 	uint8_t retry = 0;
	while(GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	retry = 0;
	while(!GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	
	delay_us(40);
	
	if(GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN))
	{
		return 1;
	}
	else 
	{
		return 0;	
	}		
}

/** 
* @describe 读取一个字节
* @param		无
* 
* @return		0uint8_t
*/
uint8_t DHT11_ReadByte(void)    
{        
	uint8_t i,dat;
	dat = 0;
	for (i = 0; i < 8; i ++) 
	{
   		dat <<= 1; 
	    dat |= DHT11_ReadBit();
    }						    
    return dat;
}

/** 
* @describe 读取一次数据
* @param		temp 温度值 humi 湿度值
* 
* @return		0 正常 1 失败
*/
uint8_t DHT11_Read_Data(float *temp,float *humi)
{
	uint8_t buf[5];
	uint8_t i;
	
	DHT11_Reset();
	
	if(DHT11_IsOnline() == 0)
	{
		//四位数据位 1位校验位
		//第一位为湿度整数位，第二位为湿度小数位
		//第三位为温度整数位，第四位位温度小数位
		for(i = 0; i < 5; i ++)
		{
			buf[i] = DHT11_ReadByte();
		}
		if((buf[0] + buf[1] + buf[2] + buf[3]) == buf[4])
		{
			*humi = (float)buf[0];
			*temp = (float)buf[2];
		}
	}
	else 
	{
		return 1;
	}
	
	return 0;	    
}

