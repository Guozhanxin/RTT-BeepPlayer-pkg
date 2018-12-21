from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()

# add beep player src files.
if GetDepend('PKG_USING_BEEPPLAYER'):
    src += Glob('src/*.c')

# add beep player include path.
path  = [cwd + '/inc']

# add src and include to group.
group = DefineGroup('beep-player', src, depend = ['PKG_USING_BEEPPLAYER'], CPPPATH = path)

Return('group')