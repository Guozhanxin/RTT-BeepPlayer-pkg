from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()

# add beep player src files.
if GetDepend('PKG_USING_BEEPPLAYER'):
    src += Glob('code/beep/*.c')
    src += Glob('code/button/*.c')
    src += Glob('code/decode/*.c')
    src += Glob('code/key/*.c')
    src += Glob('code/led/*.c')
    src += Glob('code/player/*.c')
    src += Glob('samples/beep_player_demo.c')

# add beep player include path.
path  = [cwd + '/code/beep', cwd + '/code/button', cwd + '/code/decode', cwd + '/code/key', cwd + '/code/led', cwd + '/code/player', cwd + '/samples']

# add src and include to group.
group = DefineGroup('beep-player', src, depend = ['PKG_USING_BEEPPLAYER'], CPPPATH = path)

Return('group')