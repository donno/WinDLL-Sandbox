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

void errorReport(const char *extra) {
    LPVOID errMsg;
    DWORD errorID = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorID,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &errMsg,
        0, NULL );

    printf("Error with %s: %s", extra,  errMsg);
}

int main(int argc, char *argv[]) {
    // Hold onto the dll instance
    HINSTANCE dllInstance;


    // Define functions
    void (__cdecl *func1)(void);
    int (__cdecl *func2)(void);
    int (__cdecl *func3)(int,int);

    // This loads in the libary
    dllInstance = LoadLibrary(TEXT("windll1.dll"));
    if (dllInstance == NULL) {
        errorReport("loading library");
        return -1;
    }

    // Get the address to the function in the libary

    func1 = (void (__cdecl *)(void))GetProcAddress(dllInstance, "function1");
    if (func1 == NULL) {
        errorReport("finding function1");
    }
    func2 = (int (__cdecl *)(void))GetProcAddress(dllInstance, "function2");
    if (func2 == NULL) {
        errorReport("finding function2");
    }
    func3 = (int (__cdecl *)(int,int))GetProcAddress(dllInstance, "function3");
    if (func3 == NULL) {
        errorReport("finding function3");
    }

    // Call the first function
    if (func1 != NULL) {
        func1();
    }
    if (func2 != NULL) {
        printf("Function 2: %d\n", func2());
    }
    if (func3 != NULL) {
        printf("Function 3: %d\n", func3(2, 3));
    }

    return 0;
}
