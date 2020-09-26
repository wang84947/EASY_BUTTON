#ifndef EASY_KEY_CONFIG_H
#define EASY_KEY_CONFIG_H
#include "App_Header_include.h"
#include "Global.h"  //包含硬件相关文件
void Easy_Key_io_init(void);
void Get_Key_Call_back(unsigned char* p_key_data);
#define MAX_KEY_NUM        4
#define MAX_KEY_PRESS_TIME 10000
//按键

#define TCOUNT_KEY_SCAN_MS       TCOUNT_KEY_SCAN
#define TCOUNT_KEY_LONG_PRESS_MS (3000)

#define KEY_NONE 0x00

#define KEY_WOMEN_WASH    0x01
#define KEY_HIPS_WASH     0x02
#define KEY_STOP          0x04
#define KEY_DRY           0x08
#define KEY_FLUSH         0x10
#define KEY_FLUSH_AT_FLIP 0x20

// #define IO_EASY_KEY1 ((BitStatus)(GPIOD->IDR & (uint8_t)GPIO_PIN_2))
// #define IO_EASY_KEY2 ((BitStatus)(GPIOC->IDR & (uint8_t)GPIO_PIN_5))
// #define IO_EASY_KEY3 ((BitStatus)(GPIOC->IDR & (uint8_t)GPIO_PIN_6))
// #define IO_EASY_KEY4 IO_KEY_FLUSH_R
#define IO_EASY_KEY5 IO_KEY_FLUSH_R

// #define IO_EASY_KEY6
// #define IO_EASY_KEY7
// #define IO_EASY_KEY8

#ifndef IO_EASY_KEY1
    #define IO_EASY_KEY1 1
#endif
#ifndef IO_EASY_KEY2
    #define IO_EASY_KEY2 1
#endif
#ifndef IO_EASY_KEY3
    #define IO_EASY_KEY3 1
#endif
#ifndef IO_EASY_KEY4
    #define IO_EASY_KEY4 1
#endif
#ifndef IO_EASY_KEY5
    #define IO_EASY_KEY5 1
#endif
#ifndef IO_EASY_KEY6
    #define IO_EASY_KEY6 1
#endif
#ifndef IO_EASY_KEY7
    #define IO_EASY_KEY7 1
#endif
#ifndef IO_EASY_KEY8
    #define IO_EASY_KEY8 1
#endif

#endif  // EASY_KEY
