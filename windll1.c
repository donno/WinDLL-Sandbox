/**
    Window DLL 1
    The first Window DLL that providers minimal functionality

    Compiling
    VC:
        cl /LD windll1.c
    GCC:
        gcc -shared -o windll1.dll windll1.c
*/

#include <stdio.h>

__declspec (dllexport) void function1 () {
    printf("Hello World!\n");
}

__declspec (dllexport) int function2 () {
    return 42;
}

__declspec (dllexport) int function3 (int x, int y) {
    return (x << 2 + y);
}
