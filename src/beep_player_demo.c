#include <rtthread.h>

#include "player.h"
#include "song_data.h"
#include "beep.h"
#include "decode.h"
#include "key.h"
#include "led.h"

struct player player;
struct audio_ops audio;
struct decode_ops decode;

uint8_t beep_volume = 3;

/* 解码器的读操作接口 */
int decode_read(void *song, int index, void *buffer, int size)
{
    beep_song_get_data(song, index, buffer);
    /* 返回歌曲进度的增量 */
    return 1;
}
/* 解码器的控制操作接口 */
int decode_control(void *song, int cmd, void *arg)
{
    if (cmd == DECODE_OPS_CMD_GET_NAME)
        beep_song_get_name(song, arg);
    else if (cmd == DECODE_OPS_CMD_GET_LEN)
        *(uint16_t *)arg = beep_song_get_len(song);
    return 0;
}
int audio_init(void)
{
    beep_init();
    led_init();
    return 0;
}
int audio_open(void)
{
    beep_on();
    led_on();
    return 0;
}
int audio_close(void)
{
    beep_off();
    led_off();
    return 0;
}
int audio_control(int cmd, void *arg)
{
    if (cmd == AUDIO_OPS_CMD_SET_VOL)
        beep_volume = *(uint8_t *)arg;
    return beep_volume;
}
int audio_write(void *buffer, int size)
{
    struct beep_song_data *data = buffer;

    led_toggle();

    beep_on();
    beep_set(data->freq, beep_volume);
    rt_thread_mdelay(data->sound_len);
    beep_off();
    rt_thread_mdelay(data->nosound_len);

    return size;
}

int player_init(void)
{
    decode.init = beep_song_decode_init;
    decode.control = decode_control;
    decode.read = decode_read;

    audio.init = audio_init;
    audio.open = audio_open;
    audio.close = audio_close;
    audio.control = audio_control;
    audio.write = audio_write;

    player.decode = &decode;
    player.audio = &audio;

    player_add_song(&player, (void *)&song1);
    player_add_song(&player, (void *)&song2);
    player_add_song(&player, (void *)&song3);
    player_add_song(&player, (void *)&song4);
    player_start(&player);

    player_control(&player, PLAYER_CMD_PLAY, RT_NULL);
    player_show(&player);

    return 0;
}

int beep_player_demo_init(void)
{
    /* user app entry */
    player_init();
    key_init();
    return 0;
}
INIT_APP_EXPORT(beep_player_demo_init);
