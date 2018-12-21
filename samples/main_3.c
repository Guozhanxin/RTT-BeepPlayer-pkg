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

uint16_t freq_tab[12]  = {262, 277, 294, 311, 330, 349, 369, 392, 415, 440, 466, 494}; //原始频率表 CDEFGAB
uint8_t beep_volume = 3;

int main(void)
{
    /* user app entry */
    int i;

    beep_init();

    for (i = 0; i < 12; i++)
    {
        beep_set(freq_tab[i], beep_volume);
        beep_on();

        rt_thread_mdelay(500);

        beep_off();
        rt_thread_mdelay(500);
    }

    return 0;
}
