/*
 * File      : main.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2015-07-29     Arda.Fu      first implementation
 */
#include <rtthread.h>
#include "beep.h"
#include "decode.h"

const struct beep_song song1 =
{
    .name = "两只老虎",
    .data = {
        0x15, 0x02, 0x16, 0x02, 0x17, 0x02, 0x15, 0x02, 0x15, 0x02,
        0x16, 0x02, 0x17, 0x02, 0x15, 0x02, 0x17, 0x02, 0x18, 0x02,
        0x19, 0x01, 0x17, 0x02, 0x18, 0x02, 0x19, 0x01, 0x19, 0x03,
        0x1A, 0x03, 0x19, 0x03, 0x18, 0x03, 0x17, 0x02, 0x15, 0x16,
        0x19, 0x03, 0x1A, 0x03, 0x19, 0x03, 0x18, 0x03, 0x17, 0x02,
        0x15, 0x16, 0x15, 0x02, 0x0F, 0x02, 0x15, 0x01, 0x15, 0x02,
        0x0F, 0x02, 0x15, 0x01, 0x00, 0x00
    }
};

int main(void)
{
    /* user app entry */
    struct beep_song_data data;
    int len, i;
    char name[20];

    beep_init();
    beep_song_decode_init();

    beep_song_get_name(&song1, name);
    rt_kprintf("正在播放：%s\n", name);

    len = beep_song_get_len(&song1);
    while (i < len)
    {
        /* 解码音乐数据 */
        beep_song_get_data(&song1, i, &data);
        beep_set(data.freq, 3);
        beep_on();

        rt_thread_mdelay(data.sound_len);

        beep_off();
        rt_thread_mdelay(data.nosound_len);
        i++;
    }

    return 0;
}
