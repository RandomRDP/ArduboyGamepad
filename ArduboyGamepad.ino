#include "globals.h"
#include "prompt.h"
#include "title.h"
#include "gamepad.h"

void setup()
{
	arduboy.begin();
	arduboy.setFrameRate(FRAME_RATE);
	arduboy.setTextSize(1);
 
  pinMode(TX_LED, INPUT);// Disable TX LED on Keyboard.press();
}

void loop() 
{
	// Display ARDUBOY GAMEPAD title screen
	displayTitle();
	
	// Display ROOT MENU
	displayGamePad();
}

