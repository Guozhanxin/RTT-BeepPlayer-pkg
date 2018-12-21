# 应用 RT-Thread 实现蜂鸣器播放器
## 简介

这是一个应用 RT-Thread 实现蜂鸣器播放器的教程，共包含 5 节的内容，介绍了由浅入深，一步步实现一个蜂鸣器播放器的过程。

此播放器支持 `歌曲列表`、`上一曲`、`下一曲`、`暂停/播放`、`增减音量`。

歌单通过串口打印出来，效果如下：

```
*********** Beep Player ***********
01. 两只老虎
02. 挥着翅膀的女孩
03. 同一首歌
04. 两只蝴蝶
<---  正在播放：同一首歌--->
播放进度：00%  音量大小：03%
***********************************
```

## 教程目录

[第 1 节：使用 PIN 设备控制 LED](pin.md)

[第 2 节：使用 PWM 设备驱动蜂鸣器](pwm.md)

[第 3 节：音乐数据的编码与解码](decode.md)

[第 4 节：播放器的实现](player.md)

[第 5 节：使用 MultiButton 软件包进行按键控制](key.md)

## 程序源码

[模块源码](https://github.com/Guozhanxin/RTT-BeepPlayer/tree/master/code)

[每一节的示例代码](https://github.com/Guozhanxin/RTT-BeepPlayer/tree/master/samples)

