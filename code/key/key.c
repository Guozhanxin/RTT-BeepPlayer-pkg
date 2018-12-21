/*
* Copyright (c) 2006-2018, RT-Thread Development Team
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date           Author       Notes
* 2018-10-17     flybreak      the first version
*/

#include <rtthread.h>
#include <rtdevice.h>

#include "key.h"


/*
* Copyright (c) 2006-2018, RT-Thread Development Team
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date           Author       Notes
* 2018-10-17     flybreak      the first version
*/

#include <rtdevice.h>
#include "key.h"

extern struct player player;

struct my_button btn_last = {0}, btn_play = {0}, btn_next = {0};

static void beep_key_press_long(rt_uint32_t pin)
{
    uint8_t volume;
    switch (pin)
    {
    case KEY_PLAY_PIN:
        break;
    case KEY_LAST_PIN:
        player_control(&player, PLAYER_CMD_GET_VOL, &volume);
        if (volume > 1)
        {
            volume--;
            player_control(&player, PLAYER_CMD_SET_VOL, &volume);
        }
        break;
    case KEY_NEXT_PIN:
        player_control(&player, PLAYER_CMD_GET_VOL, &volume);
        if (volume < 99)
        {
            volume++;
            player_control(&player, PLAYER_CMD_SET_VOL, &volume);
        }
        break;
    }
}

static void beep_key_press_short(rt_uint32_t pin)
{
    switch (pin)
    {
    case KEY_PLAY_PIN:
        /* 根据当前播放状态切换播放状态 */
        if (player.status == PLAYER_RUNNING)
        {
            player_control(&player, PLAYER_CMD_STOP, RT_NULL);
        }
        else
        {
            player_control(&player, PLAYER_CMD_PLAY, RT_NULL);
        }

        /*打印一次播放状态*/
        player_show(&player);
        break;
    case KEY_LAST_PIN:
        player_control(&player, PLAYER_CMD_LAST, RT_NULL);

        /*打印一次播放状态*/
        player_show(&player);
        break;
    case KEY_NEXT_PIN:
        player_control(&player, PLAYER_CMD_NEXT, RT_NULL);

        /*打印一次播放状态*/
        player_show(&player);
        break;
    }
}

void btn_cb(struct my_button *button)
{
    switch (button->event)
    {
    case BUTTON_EVENT_CLICK_UP:
        beep_key_press_short(button->pin);
        break;
    case BUTTON_EVENT_HOLD_CYC:
        beep_key_press_long(button->pin);
        break;
    default:
        ;
    }
}

int key_init(void)
{
    btn_last.press_logic_level = KEY_PRESS_LEVEL;
    btn_last.hold_cyc_period = 100;
    btn_last.cb = (my_button_callback)btn_cb;
    
    btn_next = btn_play = btn_last;
    
    btn_last.pin = KEY_PLAY_PIN;
    btn_play.pin = KEY_LAST_PIN;
    btn_next.pin = KEY_NEXT_PIN;

    my_button_register(&btn_last);
    my_button_register(&btn_play);
    my_button_register(&btn_next);
    my_button_start();

    return 0;
}
