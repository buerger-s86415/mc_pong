#include "Arduino.h"
#include "led_matrix.h"
#include "pong_logik.h"

void handleJoystick(int yVal, int &yPos) {
  if (yVal < 400 && yPos > 0){
    yPos--;
  } else if (yVal > 600 && yPos < HEIGHT - PADDLE_HEIGHT){
    yPos++;
  }
}
