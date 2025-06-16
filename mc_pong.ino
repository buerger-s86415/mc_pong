#include <Arduino.h>
#include "led_matrix.h"
#include "joystick_input.h"

// Joystick-LED-Positionen
int led1X = 0, led1Y = 0;
int led2X = WIDTH - 1, led2Y = HEIGHT - 1;

// Autonome LED (läuft automatisch durch)
int autoIndex = 0;
int RGB_COLOR = 0;

void setup() {
  Serial.begin(9600);
  initMatrix();
  clearMatrix();
  showMatrix();
}

void loop() {
  // Joysticks lesen
  int x1 = analogRead(A4);
  int y1 = analogRead(A5);
  int x2 = analogRead(A0);
  int y2 = analogRead(A1);

  // Positionen updaten
  handleJoystick(x1, y1, led1X, led1Y);
  handleJoystick(x2, y2, led2X, led2Y);

  // Matrix aktualisieren
  clearMatrix();

  // Steuerbare LEDs setzen
  setPixel(led1X, led1Y, CHSV((RGB_COLOR * 20) % 255, 255, 255));
  setPixel(led2X, led2Y, CHSV((RGB_COLOR * 20 + 120) % 255, 255, 255));

  // Autonome LED (läuft durch die Matrix)
  setPixel(autoIndex % WIDTH, autoIndex / WIDTH, CHSV(160, 255, 255));
  autoIndex = (autoIndex + 1) % NUM_LEDS;

  showMatrix();
  RGB_COLOR++;
  delay(100);
}
