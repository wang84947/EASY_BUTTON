#include "easy_key_config.h"

#include "App_Header_include.h"

void Easy_Key_io_init(void)
{
}

#define COM_KEY_NONE          0x00
#define COM_KEY_WOMEN_WASH    0x01
#define COM_KEY_HIPS_WASH     0x02
#define COM_KEY_STOP          0x04
#define COM_KEY_DRY           0x08
#define COM_KEY_FLUSH         0x10
#define COM_KEY_FLUSH_AT_FLIP 0x20

void Get_Key_Call_back(unsigned char* p_key_data)
{
    unsigned char temp_key[2] = {0, 0};
    temp_key[0]               = 0;
    temp_key[1]               = 0;
    if (p_key_data[0] == COM_KEY_NONE)
    {
        return;
    }

    if (p_key_data[0] & COM_KEY_WOMEN_WASH)
    {
        temp_key[0] |= KEY_WOMEN_WASH;
    }

    if (p_key_data[0] & COM_KEY_HIPS_WASH)
    {
        temp_key[0] |= KEY_HIPS_WASH;
    }

    if (p_key_data[0] & COM_KEY_STOP)
    {
        temp_key[0] |= KEY_STOP;
    }

    if (p_key_data[0] & COM_KEY_FLUSH)
    {
        temp_key[0] |= KEY_FLUSH;
    }

    if (p_key_data[0] & COM_KEY_DRY)
    {
        temp_key[0] |= KEY_DRY;
    }
    if (p_key_data[0] & COM_KEY_FLUSH_AT_FLIP)
    {
        temp_key[0] |= KEY_FLUSH_AT_FLIP;
    }
    temp_key[1] = p_key_data[1];
    _KEY_RT_RINGBUFFER_PUT_FORCE((rt_uint8_t*)&temp_key, 2);
}
