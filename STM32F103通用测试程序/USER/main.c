#include "math.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "timer.h"
#include "usart.h"
#include "pwm.h"
#include "sys.h"
#include "hc_sr04.h" //超声波

/**************************************************************************************/
unsigned char usart1Buf[64];
unsigned char usart1Len;
unsigned char usart2Buf[64];
unsigned char usart2Len;
/**************************************************************************************/
const u8 *COMPILED_DATE=__DATE__;//获得编译日期
const u8 *COMPILED_TIME=__TIME__;//获得编译时间

const u8 *Week[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
/**************************************************************************************/
/**************************************************************************************/
extern u16 sr04Count;
/**************************************************************************************/
/**************************************************************************************/
void Board_Init(void);
short MPU6050_Get_Angle(float x,float y,float z,u8 dir);
/**************************************************************************************/
void LED_Iest(void);
void KEY_Test(void);

int main(void)
{
	float pitch,roll,yaw; 		//欧拉角
	short aacx,aacy,aacz;		//加速度传感器原始数据
	short gyrox,gyroy,gyroz;	//陀螺仪原始数据
	short temp;					//温度	
	
	int statue=0;
	
	Board_Init();
	while(1)
	{
		LED_Iest();
		//KEY_Test();

//		temp=MPU_Get_Temperature();	//得到温度值
//		MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
//		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
//		UsartPrintf(USART1, "MPU6050\r\n");
//		UsartPrintf(USART1, "%f\r\n", temp/100.0);
//		UsartPrintf(USART1, "%d %d %d\r\n", aacx, aacy, aacz);
//		UsartPrintf(USART1, "%d %d %d\r\n", gyrox, gyroy, gyroz);
		
		//dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors,&more);
		
//	  UsartPrintf(USART1, "超声波\r\n");
//		UsartPrintf(USART1, "%f\r\n", SR04_Work());
//		UsartPrintf(USART1, "%d\r\n", sr04Count);
//		UsartPrintf(USART1, "%d\r\n",HC_SR501_Read());
//		if(HC_SR501_Read()==ON)
//		{
//			LED1ON;
//		}else
//		{
//			LED1OFF;
//		}

		delay_ms(1000);
	}	 
}

void Board_Init(void)
{
	Delay_Init(72);
	NVIC_Configuration();
	//Timer1_Init(5000,7199);				   //定时器TIM1
	Usart1_Init(115200);						 //串口初始化
	//SR04_Init();
//	MPU_Init();
//	mpu_dmp_init();
//	UsartPrintf(USART1, "11111\r\n");
	LED_Init();//led初始化
	//KEY_Init();//按键初始化
	//Timer6_Init(999, 71);
	//Timer3_Init(10000,7199);//10Khz的计数频率，计数到10000为1s 
	//Timer4_Init(50000,7199);//10Khz的计数频率，计数到50000为5s 
	//EXTIX_KEY_Init();
	//TIM2_PWM_Init(10000,7199);
	
	//HC_SR501_Init();//初始化

}

void LED_Iest(void)
{
	LED1TURN;
	LED2TURN;
	LED3TURN;
	LED4TURN;
}
void KEY_Test(void)
{
	if(KEY_Scan(GPIOC,GPIO_Pin_1) == KEY_DOWN)
	{
		LED1=!LED1;
	}
}

