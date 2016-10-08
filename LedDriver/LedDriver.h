
#ifndef _LEDDRIVER_H
#define _LEDDRIVER_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
	
typedef int BOOL;
#define FALSE 0
#define TRUE 1

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
BOOL LedDriver_IsOn(int ledNumber);
BOOL LedDriver_IsOff(int ledNumber);

#ifdef __cplusplus
}
#endif

#endif
