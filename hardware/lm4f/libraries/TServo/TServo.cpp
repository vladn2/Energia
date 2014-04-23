//example servo class for the modified glitch-free PWMWrite()

#include "TServo.h"
#include "wiring_private.h"

void TServo::attach (uint8_t pin, uint16_t frq, uint16_t uS_center, uint16_t uS_90d) {
    TServo::pin = pin;
    TServo::frq = frq;
    TServo::uS_center = uS_center;
    TServo::uS_90d = uS_90d;
}

void TServo::moveto (int angle) {
    PWMWrite (pin, 1000000L/frq, angle*uS_90d/90 + uS_center, frq);
}

void TServo::moveto (float angle) {
    PWMWrite (pin, F_CPU/frq, (angle*uS_90d/90 + uS_center)*F_CPU/1000000L, frq);
}
