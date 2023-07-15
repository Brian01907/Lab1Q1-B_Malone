#include <mbed.h>

// This error message means that the compiler cannot find a suitable version of the "printf" function to use.

DigitalIn button(PA_0);
volatile bool flag = false;

void button_isr() {
    flag = true;
}

int main() {
    button.rise(&button_isr);

    while (1) {
        if (flag) {
            printf("Button pressed\n");
            flag = false;
        }
    }
}


