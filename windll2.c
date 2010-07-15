/**
    Window DLL 2
    This is a man-in-the-middle for the first Window DLL that providers alternate functionality.

    How to use it:
        Rename windll1.dll to windll1.org.dll
        Rename this to windll1.dll
        Run the normal program that links/loads this

    Compiling
        VC:
            cl /LD windll2.c
        GCC:
            gcc -shared -o windll2.dll windll2.c
*/

#include <windows.h>
#include <stdio.h>

HINSTANCE orgLib;

// Calls the normal function
__declspec (dllexport) void function1 () {
    void (__cdecl *func1)(void);
    func1 = (void(__cdecl *)(void))GetProcAddress(orgLib, "function1");
    func1();
}

__declspec (dllexport) int function2 () {
    return 142; // lets override this one
}

// Call normal function
__declspec (dllexport) int function3 (int x, int y) {
    int (__cdecl *func3)(int,int);
    func3 = (int (__cdecl *)(int,int))GetProcAddress(orgLib, "function3");
    return func3(x, y ); // call the real function
}


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved
) {
    // Load Real DLL
    orgLib = LoadLibrary(TEXT("windll1.org.dll"));
    if (orgLib == NULL) {
        return FALSE;
    }

    return TRUE;
}
