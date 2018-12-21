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
#include "led.h"
#include "button.h"

#define KEY_PIN          1
#define KEY_PRESS_VALUE  0

void key_cb(struct my_button *button)
{
    switch (button->event)
    {
    case BUTTON_EVENT_CLICK_UP:
        led_toggle();
        rt_kprintf("This is click up callback!\n");
        break;
    case BUTTON_EVENT_HOLD_CYC:
        rt_kprintf("This is hold cyc callback!\n");
        break;
    default:
        ;
    }
}

int main(void)
{
    /* user app entry */
    static struct my_button key = {0};

    led_init();

    key.press_logic_level = KEY_PRESS_VALUE;
    key.hold_cyc_period = 100;
    key.cb = (my_button_callback)key_cb;
    key.pin = KEY_PIN;

    my_button_register(&key);
    my_button_start();

    return RT_EOK;
}
