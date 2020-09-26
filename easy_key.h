#ifndef EASY_KEY_H
#define EASY_KEY_H
#include "stdint.h"

typedef struct
{
    uint8_t  KeyScan[2];
    uint8_t  KeyValid[2];
    uint8_t  Key_Up;
    uint8_t  Key_Down;
    uint8_t  Key_LongPress;
    uint16_t Key_PressTime;
} Easy_Key_t;
extern Easy_Key_t Easy_Key;

extern void Easy_Key_Init(void);
extern void Easy_Key_Scan(void);
extern void Easy_Key_Call_Back(unsigned char * p_key_data);

#endif  // EASY_KEY
