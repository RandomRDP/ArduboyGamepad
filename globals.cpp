#include "globals.h"

Arduboy arduboy;

unsigned char newButtons = 0;
unsigned char oldButtons = 0;

void updateNewInput()
{
	newButtons = arduboy.getInput();
}

void updateOldInput()
{
	oldButtons = newButtons;
}

char progmemString[] = "";

//char up_map_key = 0xDA;//0xB3;
//char down_map_key = 0xD9;//0xB3;
//char left_map_key = 0xD8;//0xB3;
//char right_map_key = 0xD7;//0xB3;
//char b_map_key = 0xD8;//0xB3;
//char a_map_key = 0xD7;//0xB3;
char up_map_key = 'w';
char down_map_key = 's';
char left_map_key = 'a';
char right_map_key = 'd';
char b_map_key = 'q';
char a_map_key = 'e';

char* rps(const char* const* str)
{
	strcpy_P(progmemString, (char*)pgm_read_word(str));
	return progmemString;
}

char* dps(const char* str)
{
	strcpy_P(progmemString, (char*)pgm_read_word(str));
	return progmemString;
}

unsigned char newInput = 0;
unsigned char lastInputted = 0;
float movingVelocity = 1.0;
float movingAccelatation = 1.00177;

float getCursorVelocity()
{
  newInput = arduboy.getInput();
  float v = movingVelocity;
  if (D_PAD_INPUTTED && lastInputted == newInput) {
    v *= movingAccelatation;
  } else {
    v = 1.0;
  }
  movingVelocity = v;
  lastInputted = newInput;
  return v;
}

int getCursorDeltaX(float v)
{
  if (newInput & LEFT_BUTTON)  return -(1.0 * v);
  else if (newInput & RIGHT_BUTTON) return (1.0 * v);
  return 0;
}

int getCursorDeltaY(float v)
{
  if (newInput & UP_BUTTON)  return -(1.0 * v);
  else if (newInput & DOWN_BUTTON) return (1.0 * v);
  return 0;
}

