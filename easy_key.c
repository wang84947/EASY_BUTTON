#include "easy_key.h"
#include "easy_key_config.h"

#include "component/ringbuffer_config.h"
Easy_Key_t Easy_Key;
#define EASY_KEY_NONE 0x00
void Easy_Key_Init(void)
{
    Easy_Key_io_init();
}

void Easy_Key_On_Key_Donw(uint8_t key)
{
    //KeyDownProcess(key);
}

void Easy_Key_On_Key_Up(uint8_t key)
{
    unsigned char temp_key[2];
    temp_key[0] = key;
    temp_key[1] = 0;

    _KEY_RT_RINGBUFFER_PUT_FORCE((rt_uint8_t*)&temp_key, 2);
}

void Easy_Key_On_Key_LongPress(uint8_t key)
{
    unsigned char temp_key[2];
    temp_key[0] = key;
    temp_key[1] = 1;
    _KEY_RT_RINGBUFFER_PUT_FORCE((rt_uint8_t*)&temp_key, 2);
}
void Easy_Key_Call_Back(unsigned char* p_key_data)
{
    Get_Key_Call_back(p_key_data);
}
void Easy_Key_Scan(void)
{
    // if (Easy_Key.TCount_Key_Scan_ms < TCOUNT_KEY_SCAN_MS)
    // {
    //     return;
    // }

    // Easy_Key.TCount_Key_Scan_ms = 0;

    Easy_Key.KeyScan[1] = Easy_Key.KeyScan[0];

    Easy_Key.KeyScan[0] = 0;

    if (IO_EASY_KEY1 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x01;
    }
    if (IO_EASY_KEY2 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x02;
    }
    if (IO_EASY_KEY3 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x04;
    }
    if (IO_EASY_KEY4 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x08;
    }
    if (IO_EASY_KEY5 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x10;
    }
    if (IO_EASY_KEY6 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x20;
    }
    if (IO_EASY_KEY7 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x40;
    }
    if (IO_EASY_KEY8 == 0)
    {
        Easy_Key.KeyScan[0] |= 0x80;
    }

    if (Easy_Key.KeyScan[0] == Easy_Key.KeyScan[1])
    {
        Easy_Key.KeyValid[1] = Easy_Key.KeyValid[0];
        Easy_Key.KeyValid[0] = Easy_Key.KeyScan[0];
        /* 按下或弹起进入 */
        if (Easy_Key.KeyValid[0] != Easy_Key.KeyValid[1])
        {
            if (Easy_Key.KeyValid[0] > 0)
            {
                Easy_Key.Key_Down      = Easy_Key.KeyValid[0];
                Easy_Key.Key_PressTime = 0;
            }
            else
            {
                if (Easy_Key.Key_PressTime < (TCOUNT_KEY_LONG_PRESS_MS / TCOUNT_KEY_SCAN_MS))
                {
                    //如果发生长按事件，则不再产生弹起和点击事件
                    Easy_Key.Key_Up = Easy_Key.KeyValid[1];
                }
            }
        }
        else
        {
            if (Easy_Key.KeyValid[0] > 0)
            {
                if (Easy_Key.Key_PressTime < MAX_KEY_PRESS_TIME)
                {
                    Easy_Key.Key_PressTime += 1;
                    if (Easy_Key.Key_PressTime == (TCOUNT_KEY_LONG_PRESS_MS / TCOUNT_KEY_SCAN_MS))
                    {
                        Easy_Key.Key_LongPress = Easy_Key.KeyValid[0];
                    }
                }
            }
        }
    }

    if (Easy_Key.Key_Down != EASY_KEY_NONE)
    {
        Easy_Key_On_Key_Donw(Easy_Key.Key_Down);
        Easy_Key.Key_Down = EASY_KEY_NONE;
    }

    if (Easy_Key.Key_Up != EASY_KEY_NONE)
    {
        Easy_Key_On_Key_Up(Easy_Key.Key_Up);
        Easy_Key.Key_Up = EASY_KEY_NONE;
    }

    if (Easy_Key.Key_LongPress != EASY_KEY_NONE)
    {
        Easy_Key_On_Key_LongPress(Easy_Key.Key_LongPress);
        Easy_Key.Key_LongPress = EASY_KEY_NONE;
    }
}
