/*
* Copyright (c) 2006-2018, RT-Thread Development Team
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date           Author       Notes
* 2018-10-17     flybreak      the first version
*/

#ifndef BEEP_KEY_H
#define BEEP_KEY_H

#include "button.h"
#include "player.h"

#define KEY_PLAY_PIN     2
#define KEY_LAST_PIN     1
#define KEY_NEXT_PIN     3
#define KEY_PRESS_LEVEL  0

int key_init(void);                     //按键初始化

#endif
