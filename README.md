# 蜂鸣器播放音乐

## 简介

这是一个利用蜂鸣器播放音乐的软件包，具有显示歌单、上一曲、下一曲、暂停/播放、音量加减的功能。

具体的实现方式在 `/doc` 目录下有一份教程文档。

> 注意：只有无源蜂鸣器才能播放音乐

### 实际效果

```c
/*
*********** Beep Player ***********
01. 挥着翅膀的女孩
02. 同一首歌
03. 两只蝴蝶
<---  暂停播放：挥着翅膀的女孩--->
播放进度：38%  音量大小： 3%
***********************************
*/
```

### 目录结构

```
beep-player
│   README.md                       // 软件包说明
│   SConscript                      // RT-Thread 默认的构建脚本
│   LICENSE                         // 权限文件
├───docs 
│   └───figures                     // 文档使用图片
│   │   xxx.md                      // 教程文档
├───samples                         // 示例代码
│   └───BeepPlayer                  // 软件包索引示例代码
│       │   Kconfig                 // Kconfig示例代码
│       └───package.json            // json文件示例代码
└───src                             // 源文件
└───inc                             // 头文件
```

### 许可证

beep-player 遵循 Apache-2.0 许可，详见 `LICENSE` 文件。

### 依赖

- RT_Thread 4.0+
- pwm 设备驱动

## 获取方式

使用 `beep-player package` 需要在 RT-Thread 的包管理中选中它，具体路径如下：

```
RT-Thread online packages
    multimedia packages  --->
        a BeepPlayer package for rt-thread  --->
```

进入 beep-player 软件包的配置菜单按下图所示配置，里面的信息依据自己设备的**实际情况**填写

```
    --- a BeepPlayer package for rt-thread                           
     (pwm1) Beep pwm device                           
     (1)   Beep pwm channel                           
     (2)   Play/Stop key PIN                            
     (1)   Last song key PIN                           
     (3)   Last song key PIN                            
     (0)   Key press level                            
     (21)  LED PIN                                     
           Version (latest)  --->                           
```

**Beep pwm device** ：控制蜂鸣器使用的 PWM 设备名

**Beep pwm channel** ：配置控制蜂鸣器使用的 PWM 通道

**Play/Stop key PIN** ：播放/暂停 按键对应的 PIN

**Last song key PIN** ：上一曲 按键对应的 PIN

**Next song key PIN** ：下一曲 按键对应的 PIN

**Key press level** ：配置按键按下后的电平高低（默认0：低电平）

**LED PIN** ：LED 对应的 PIN

配置完成后让 RT-Thread 的包管理器自动更新，或者使用 pkgs --update 命令更新包到 BSP 中。

## 使用 BeepPlayer 软件包

- 短按 播放/暂停 按键切换播放状态
- 短按 上一首 按键切换上一首
- 短按 下一首 按键切换下一首
- 长按 上一首 按键减小音量
- 长按 下一首 按键加大音量
- 在终端执行命令 beep_player_show 打印当前播放状态

了解本软件包的制作过程，请参考[从零开始制作一个播放器的软件包](./doc/tutorial.md)