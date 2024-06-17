#ifndef stepper_h
#define stepper_h
#include <stdio.h>
#include "pico/stdlib.h"


// constructors:
void set_stepper(int motor_steps, int ms1, int ms2, int ms3, int dir, int step);

// speed setter method:
void setDelay(unsigned long delay);   // in microseconds


// mover method:
void setDirection(int direction);     // 0 forward, 1 backward
void step(unsigned long num_steps);   // step a given number of steps
void stepOnce(void);
void setStepMode(int stepMode);       // (1 /) 1, 2, 4, 8, or 16 
void stepMotor(int this_step);
    
#endif //a4988_h