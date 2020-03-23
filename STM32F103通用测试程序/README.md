板子测试程序

BluseLi  
博客 www.bluseli.cn www.bluseli.site
百度 贪贪贪丶慎独

本工程包含各种外设驱动，全部调试成功。
本工程力求兼容，方便移植修改

部分代码是参照 火哥和原子哥 改的
我只是想把代码写得规范，方便移植

修改时间 2020/1/14

目录结构 参照别人的工程

./工程
	/CORE													内核 启动文件
		/core_cm3.h core_cm3.c								Cortex-M3核心外设访问层源文件 如提供了一些汇编级函数实现（百度的）
		/stm32f10x.h										Cortex-M3设备外围访问层头文件。 这个文件包含所有外围寄存器的定义，STM32F10x连接线的定义和内存映射，
		/stm32f10x_conf.h									库配置文件
		/stm32f10x_it.h stm32f10x_it.c						此文件为所有异常处理程序和外围设备提供模板中断服务程序 我一般是在哪个外设用到中断就把中断函数写到哪个文件
		/system_stm32f10x.c system_stm32f10x.h				Cortex-M3设备外围访问层系统源文件
		/startup_stm32f10x_md.s startup_stm32f10x_hd.s		启动文件
	/HARDWARE												硬件驱动代码
		/LED
			/led.h led.c
		/KEY
			/key.h key.c
		...
	/STM32F10x_FWLib										固件库
		/inc
			/.h
		/src
			/.c
	/SYSTEM													片上外设 协议
		/sys
			/sys.h sys.c
		/i2c
			/i2c.h i2c.c
		...
	/USER													用户目录
		/Output												编译好的文件
		/main.c												mian函数
		/.uvprojx											工程文件
		/JLinkSettings.ini									JLink配置

命名规范 （也是自己强迫自己这样做的，也不知道符不符合规范）

变量

预定义
	LED1 LED2 			   变量名（硬件）+序号
	LED1_GPIO_CLK		   变量名_用途
全局变量
	usart1Buf[64];		   名称+用途（大写）
	usart1Len;
函数命名
	void Board_Init(void); 函数名_用途

注释
文件摘要	

/** 
 * @fileName   	 hc_sr04.h
 * @brief        HCSR04 超声波传感器驱动代码（4个引脚）    
 * @author       Bluseli www.bluseli.cn www.bluseli.site 从此深耕不回头，谢谢关注。
 * @date         2020-3-2
 */

函数
/** 
 * @describe	 硬件初始化
 * @param		 	 无
 * 
 * @return		 无
 */

注释
// 这是注释

分割
/*******************************************************************
 *
 *          @describe 描述
 *
 *******************************************************************/