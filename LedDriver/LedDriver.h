
#ifndef _LEDDRIVER_H
#define _LEDDRIVER_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);

#ifdef __cplusplus
}
#endif

#endif
