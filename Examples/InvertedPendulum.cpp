#include <stdio.h>
#include "pico/stdlib.h"
#include "pio_rotary_encoder.pio.h"
#include "pio_rotary_encoder.h"
#include <cmath>
#include <cstdio>
extern "C"{
#include "stepper.h"
}


//Set encoder rotation to 0
int RotaryEncoder::rotation = 0;
// needed for printf
RotaryEncoder my_encoder(14);
// the A of the rotary encoder is connected to GPIO 14, B to GPIO 15

// initialize the rotatry encoder rotation as 0

int main()
{
    stdio_init_all();
    set_stepper(200,8,9,10,17,16);
    my_encoder.set_rotation(0);
    setStepMode(2);
    setDelay(400);
    int dirFlag = 1;
    setDirection(1);
    int send_data = 0;
    int buffer = 0;
    while(true){
        printf("ready\n");
        sleep_ms(10);
        scanf("%d", &buffer);
        sleep_ms(10);
        if (buffer <0) { setDirection(0);} else setDirection(1);
        step(abs(buffer));
        sleep_ms(10);
    }
}
