cl /nologo /LD windll1.c
cl /nologo /LD windll2.c
cl /nologo winhost.c
cl /nologo winhostalt.c windll1.lib
move windll1.dll windll1.org.dll
copy windll2.dll windll1.dll
winhostalt.exe
