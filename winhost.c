/**
    Window Host
    This will host the DLL

    The intention is pure dynamic loading not linked against at
    run time. Known as Run-Time Dynamic Linking

    Sources:
        http://msdn.microsoft.com/en-us/library/ms686944(v=VS.85).aspx

    Compiling
    VC:
        cl winhost.c
    GCC:
        gcc winhost.c
*/

#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Hold onto the dll instance
    HINSTANCE dllInstance;
    // Define functions
    void (__cdecl *func1)(void);
    int (__cdecl *func2)(void);
    int (__cdecl *func3)(int,int);

    // This loads in the libary
    dllInstance = LoadLibrary(TEXT("windll1.dll"));
    // Get the address to the function in the libary

    func1 = (void (__cdecl *)(void))GetProcAddress(dllInstance, "function1");
    func2 = (int (__cdecl *)(void))GetProcAddress(dllInstance, "function2");
    func3 = (int (__cdecl *)(int,int))GetProcAddress(dllInstance, "function3");

    // Call the first function
    func1();
    printf("Function 2: %d\n", func2());
    printf("Function 3: %d\n", func3(2, 3));

    return 0;
}
