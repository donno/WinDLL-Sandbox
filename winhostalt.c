/**
    Window Host
    This will host the DLL

    This uses Load-Time Linking rather then Run-Time

    Compiling
    VC:
        cl winhostalt.c windll1.lib
    GCC:
        gcc winhostalt.c windll1.lib
*/
#include <stdio.h>
// Imports
void function1 ();
int function2 ();
int function3 (int x, int y);

int main(int argc, char *argv[]) {

    // Call the functions

    function1();
    printf("Function 2: %d\n", function2());
    printf("Function 3: %d\n", function3(2, 3));

    return 0;
}
