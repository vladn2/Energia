//example servo class for the modified glitch-free PWMWrite()

#ifndef TServo_H
#define TServo_H

#include <stdint.h>

class TServo {
    uint8_t     pin;
    uint16_t    frq;
    uint16_t    uS_center;
    uint16_t    uS_90d;

public:
    //defaults: PWM frequency (Hz), center position pulse width (uS), scale (uS per 90 degrees)
    void attach (uint8_t pin, uint16_t frq = 50, uint16_t uS_center = 1520, uint16_t uS_90d = 800);

    //angle range -90 to +90 (signed integer)
    void moveto (int);

    //angle range -90. to +90. (float)
    void moveto (float);
};

#endif