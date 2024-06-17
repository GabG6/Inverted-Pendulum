#include "stepper.h"
#include <stdio.h>
#include "pico/stdlib.h"

// constructor to set up pins and initialize data
int ms1_pin, ms2_pin, ms3_pin, dir_pin, step_pin;
int step_delay = 20000;
void set_stepper(int motor_steps, int ms1, int ms2, int ms3, int dir, int step)
{
    ms1_pin = ms1;
    ms2_pin = ms2;
    ms3_pin = ms3;
    dir_pin = dir;
    step_pin = step;

   // setup the pins on the microcontroller:
    gpio_init(ms1_pin);
    gpio_init(ms2_pin);
    gpio_init(ms3_pin);
    gpio_init(dir_pin);
    gpio_init(step_pin);

    gpio_set_dir(ms1_pin, GPIO_OUT);
    gpio_set_dir(ms2_pin, GPIO_OUT);
    gpio_set_dir(ms3_pin, GPIO_OUT);
    gpio_set_dir(dir_pin, GPIO_OUT);
    gpio_set_dir(step_pin, GPIO_OUT);


                                     
}

// set delay in microseconds, set before starting to step
void setDelay(unsigned long delay)
{
   step_delay = delay;
}

// set direction: 0 or 1
void setDirection(int direction)
{
    gpio_put(dir_pin,direction == 0 ? 1:0);
}

// step only once
void stepOnce(void)
{
    gpio_put(step_pin, 1);
    sleep_us(step_delay);
    gpio_put(step_pin, 0);
    sleep_us(step_delay);
}

// step given number of times
void step(unsigned long num_steps)
{
   for(unsigned long x = 0; x < num_steps; x++)
   {
      stepOnce();
   }
}

// set microstepping mode
// (1 /) 1, 2, 4, 8, or 16
void setStepMode(int stepMode)
{   
    int _step_mode = stepMode;
    switch (stepMode)
    {
                  // MS1   MS2   MS3
      case 16:    // 1  1  1
      gpio_put(ms1_pin, 1);
      gpio_put(ms2_pin, 1);
      gpio_put(ms3_pin, 1);
      break;
      case 8:    // 1  1  0
      gpio_put(ms1_pin, 1);
      gpio_put(ms2_pin, 1);
      gpio_put(ms3_pin, 0);
      break;
      case 4:    // 0   1  0
      gpio_put(ms1_pin, 0);
      gpio_put(ms2_pin, 1);
      gpio_put(ms3_pin, 0);
      break;
      case 2:    // 1  0   0
      gpio_put(ms1_pin, 1);
      gpio_put(ms2_pin, 0);
      gpio_put(ms3_pin, 0);
      break;
      case 1:    // 0   0   0
      gpio_put(ms1_pin, 0);
      gpio_put(ms2_pin, 0);
      gpio_put(ms3_pin, 0);
      break;
    }
}
