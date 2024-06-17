#ifndef pio_rotary_encoder_h
#define pio_rotary_encoder_h
#include <stdio.h>
#include <string.h>
#include "pio_rotary_encoder.pio.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/irq.h"

class RotaryEncoder{
    public:
    RotaryEncoder(uint rotary_encoder_A);
    void set_rotation(int _rotation);
    int get_rotation(void);
    private:
    static void pio_irq_handler();
    PIO pio;
    uint sm;
    static int rotation;
};
#endif