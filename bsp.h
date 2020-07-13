/*
*********************************************************************************************************
*
*	模块名称 : 底层驱动模块
*	文件名称 : bsp.h
*	版    本 : V1.0
*	说    明 : 这是底层驱动模块所有的h文件的汇总文件。
*	 	       应用程序只需 #include bsp.h 即可，不需要#include 每个模块的 h 文件
*
*	Copyright (C), 2014-2015, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#ifndef _BSP_H_
#define _BSP_H

#include "stc15.h"
#include "string.h"
#include "stdio.h"

#define FCLK      11059200uL		 /* 定义晶振的频率使, 11.0592MHz */
#define BAUD      9600u		    	 /* 定义串口波特率定义 */

/* IO definitions (access restrictions to peripheral registers) */
/**
    \defgroup CMSIS_glob_defs CMSIS Global Defines

    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */

/* Signed integer types  */
typedef   signed char     int8_t;
typedef   signed short    int16_t;
typedef   signed long     int32_t;

/* Unsigned integer types  */
typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned long     uint32_t;

typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef enum {FALSE = 0, TRUE = !FALSE} bool;

/* 每种类型的整数极限值 */
#define U8_MAX     (255)
#define S8_MAX     (127)
#define S8_MIN     (-128)
#define U16_MAX    (65535u)
#define S16_MAX    (32767)
#define S16_MIN    (-32768)
#define U32_MAX    (4294967295uL)
#define S32_MAX    (2147483647)
#define S32_MIN    (-2147483648uL)

#include "bsp_timer.h"
#include "bsp_uart.h"
#include "bsp_ad7606.h"

void bsp_DelayMS(uint32_t n);

void bsp_Init(void);
void bsp_Idle(void);
void bsp_RunPer1ms(void);
void bsp_RunPer10ms(void);
							
#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
