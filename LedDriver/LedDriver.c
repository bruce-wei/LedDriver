#include "LedDriver.h"



enum
{
	ALL_LEDS_ON		= ~0,
	ALL_LEDS_OFF	= ~ALL_LEDS_ON
};

enum
{
	FIRST_LED	= 1,
	LAST_LED	= 16
};

static uint16_t* ledsAddress;
static uint16_t ledsImage;

static uint16_t ConvertLedNumberToBit(int ledNumber)
{
	return 1 << (ledNumber - 1);
}

static BOOL IsLedOutOfBounds(int ledNumber)
{
	return ledNumber < FIRST_LED || ledNumber > LAST_LED;
}

static void SetLedImageBit(int ledNumber)
{
	ledsImage |= ConvertLedNumberToBit(ledNumber);
}

static void ClearLedImageBit(int ledNumber)
{
	ledsImage &= ~(ConvertLedNumberToBit(ledNumber));
}

static void UpdateHardWare()
{
	*ledsAddress = ledsImage;
}

void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	UpdateHardWare();
}

void LedDriver_TurnOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return;

	SetLedImageBit(ledNumber);
	UpdateHardWare();
}

void LedDriver_TurnOff(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return;

	ClearLedImageBit(ledNumber);
	UpdateHardWare();
}

void LedDriver_TurnAllOn(void)
{
	ledsImage = ALL_LEDS_ON;
	UpdateHardWare();
}

void LedDriver_TurnAllOff(void)
{
	ledsImage = ALL_LEDS_OFF;
	UpdateHardWare();
}

BOOL LedDriver_IsOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return FALSE;

	return ledsImage & (ConvertLedNumberToBit(ledNumber));
}

BOOL LedDriver_IsOff(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return TRUE;

	return !LedDriver_IsOn(ledNumber);
}

