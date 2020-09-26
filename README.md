# EASY_BUTTON
a simple button chek for key up or long press or muti-button pressed
这个项目 主要解决一些简单的按键处理，比如按键短按后弹起响应，长按响应，组合按键响应，目前设计按8个按键处理
easykey.c 核心算法
easykeyconfig.c/h 是按键相关配置

void Easy_Key_io_init(void)
进行按键IO 配置

#include "App_Header_include.h" 上层应用层 相关文件包含
#include "Global.h"  //  分别为底层硬件相关文件包含
#关联相关IO配置

// #define IO_EASY_KEY1 ((BitStatus)(GPIOD->IDR & (uint8_t)GPIO_PIN_2))
// #define IO_EASY_KEY2 ((BitStatus)(GPIOC->IDR & (uint8_t)GPIO_PIN_5))
// #define IO_EASY_KEY3 ((BitStatus)(GPIOC->IDR & (uint8_t)GPIO_PIN_6))
// #define IO_EASY_KEY4 IO_KEY_FLUSH_R
#define IO_EASY_KEY5 IO_KEY_FLUSH_R

// #define IO_EASY_KEY6
// #define IO_EASY_KEY7
// #define IO_EASY_KEY8

//对外接口函数
extern void Easy_Key_Init(void);

extern void Easy_Key_Scan(void);
插入到周期调用的相关地方，如20ms调用
extern void Easy_Key_Call_Back(unsigned char * p_key_data);
对外开放接口 用来传入非按键类信息


检测到的按键传入  ringbuffer
