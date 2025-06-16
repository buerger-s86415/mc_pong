#include "Arduino.h"
#include "led_matrix.h"

void handleJoystick(int xVal, int yVal, int &xPos, int &yPos) {
  if (yVal < 400 && yPos > 0) yPos--;
  else if (yVal > 600 && yPos < HEIGHT - 1) yPos++;

  if (xVal < 400 && xPos > 0) xPos--;
  else if (xVal > 600 && xPos < WIDTH - 1) xPos++;
}
