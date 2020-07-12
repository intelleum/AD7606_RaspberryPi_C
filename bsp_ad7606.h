/*
*********************************************************************************************************
*	                                  
*	模块名称 : AD7606驱动模块 
*	文件名称 : bsp_ad7606.h
*	版    本 : V1.0
*	说    明 : 头文件
*	修改记录 :
*		版本号  日期       作者    说明
*		v0.1    2009-12-27 armfly  创建该文件，ST固件库版本为V3.1.2
*		v1.0    2011-01-11 armfly  ST固件库升级到V3.4.0版本。
*
*	Copyright (C), 2010-2011, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#ifndef __BSP_AD7606_H
#define __BSP_AD7606_H

sbit	AD_CS = P1^0;
sbit	SCLK = P1^1;
sbit	DAT = P1^2;
sbit	RANGE = P0^0;
sbit  	AD_RESET = P0^1;
sbit	AD_CONVST = P0^2;
sbit	AD_OS0 = P0^3;
sbit	AD_OS1 = P0^4;
sbit	AD_OS2 = P0^5;
sbit	BUSY = P0^6;

#define		DISABLE_INT()	ET0 = 0
#define		ENABLE_INT()	ET0 = 1

/* 每个样本2字节，采集通道 */
#define CH_NUM			8				/* 采集2通道 */
#define FIFO_SIZE		64		/* 大小不要超过48K (CPU内部RAM 只有64K) */

#define AD_CS_LOW()     				AD_CS = 0
#define AD_CS_HIGH()     				AD_CS = 1

#define AD_RESET_LOW()					AD_RESET = 0
#define AD_RESET_HIGH()					AD_RESET = 1
	
#define AD_CONVST_LOW()					AD_CONVST = 0
#define AD_CONVST_HIGH()				AD_CONVST = 1

#define AD_RANGE_5V()					RANGE = 0
#define AD_RANGE_10V()					RANGE = 1

#define AD_OS0_0()						AD_OS0 = 0
#define AD_OS0_1()						AD_OS0 = 1

#define AD_OS1_0()						AD_OS1 = 0
#define AD_OS1_1()						AD_OS1 = 1

#define AD_OS2_0()						AD_OS2 = 0
#define AD_OS2_1()						AD_OS2 = 1

/* AD数据采集缓冲区 */
typedef struct
{
	uint16_t usRead;
	uint16_t usWrite;
	uint16_t usCount;
	uint16_t usBuf[FIFO_SIZE];
}FIFO_T;

/* 供外部调用的函数声明 */
void ad7606_Reset(void);
void ad7606_SetOS(uint8_t _ucMode);
void bsp_SET_TIM2_FREQ(uint32_t _ulFreq);
void bsp_InitAD7606(void);
void ad7606_StartRecord(uint32_t _ulFreq);
void ad7606_StopRecord(void);
uint8_t GetAdcFormFifo(uint16_t *_usReadAdc);
void bsp_TIM4_Configuration(void);

void ad7606_StartConv(void);

void ad7606_Scan(void);
int16_t ad7606_ReadAdc(uint8_t _ch); 

#endif

