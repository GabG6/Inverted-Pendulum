// class a4988{
//     private:
//     int ms1;
//     int ms2;
//     int ms3;
//     int stepPin;
//     int dirPin;
//     public:
//     a4988(int motorsteps, int ms1_pin_, int ms2_pin_, int ms3_pin_, int dir_pin_, int step_pin_);
//     void setdelay_(unsigned long delay_);
//     void setDirection_(int direction_);     // 0 forward, 1 backward
//     void step_(unsigned long num_steps_);   // step a given number of steps
//     void stepOnce_(void);
//     void setStepMode_(int stepMode_);       // (1 /) 1, 2, 4, 8, or 16 
//     void stepMotor_(int this_step_);
// }