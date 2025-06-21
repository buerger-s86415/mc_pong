#include <Arduino.h>
#include <FastLED.h>
#include "pong_logik.h"
#include "led_matrix.h"
#include "joystick_input.h"
#include "lcd_display.h"
#include "sound.h"

#include <FastLED.h>

// Joystick-LED-Positionen
int led1X = 0, led1Y = 0;
int led2X = WIDTH - 1, led2Y = HEIGHT - 1;

void setup() {
  Serial.begin(9600);
  initMatrix();
  clearMatrix();
  showMatrix();
  initLCD();
  showScore(score1, score2);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  ballHeld = true;
  heldByPlayer = 1;

  ballX = 1;
  ballY = paddleY1 + PADDLE_HEIGHT / 2;
  ballVX = 0;
  ballVY = 0;
  playStartSound();
}

void loop() {
  // Joysticks lesen
  int x1 = analogRead(A4);
  int y1 = analogRead(A5);
  int b1 = digitalRead(12);
  int x2 = analogRead(A0);
  int y2 = analogRead(A1);
  int b2 = digitalRead(3);

  if (ballHeld) {
    if (heldByPlayer == 1) {
      int x1 = analogRead(A4);
      if (x1 > 600) {
        ballVX = 1;
        ballVY = (random(0, 2) * 2 - 1);
        ballHeld = false;
      }
    } else if (heldByPlayer == 2) {
      int x2 = analogRead(A0);
      if (x2 < 400) {
        ballVX = -1;
        ballVY = (random(0, 2) * 2 - 1);
        ballHeld = false;
      }
    }
  }

  if (ballHeld) {
    if (heldByPlayer == 1) {
      ballX = 1;
      ballY = paddleY1 + PADDLE_HEIGHT / 2;
    } else if (heldByPlayer == 2) {
      ballX = WIDTH - 2;
      ballY = paddleY2 + PADDLE_HEIGHT / 2;
    }
  }

  // Positionen updaten
  handleJoystick(y1, paddleY1);
  handleJoystick(y2, paddleY2);

  // Matrix aktualisieren
  clearMatrix();
  updateBall();
  setPixel(ballX, ballY, CRGB::White);
  CRGB colorp1 = updatePlayerColor1(b1);
  CRGB colorp2 = updatePlayerColor2(b2);

  drawPaddles(colorp1, colorp2);
  showMatrix();
  delay(100);
}