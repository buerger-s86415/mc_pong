#include "pong_logik.h"
#include "led_matrix.h"
#include "lcd_display.h"
#include "sound.h"
#include <FastLED.h>


// Ball def
int ballX = WIDTH / 2;
int ballY = HEIGHT / 2;
int ballVX = 1;
int ballVY = 1;
int score1 = 0;
int score2 = 0;
int heldByPlayer = 0;
bool ballHeld = false;

// Paddle Positionen
int paddleY1 = HEIGHT / 2 - PADDLE_HEIGHT /2;
int paddleY2 = HEIGHT / 2 - PADDLE_HEIGHT / 2;

const CRGB colors[8] = {
  CRGB::Red,
  CRGB::Green,
  CRGB::Blue,
  CRGB::Yellow,
  CRGB::Orange,
  CRGB::Purple,
  CRGB::Cyan,
  CRGB::White
};


void updateBall() {
  if (ballHeld) return;

  // Ballposition updaten
  ballX += ballVX;
  ballY += ballVY;

  // Bounce oben/unten
  if (ballY <= 0 || ballY >= HEIGHT - 1) {
    ballVY = -ballVY;
    ballY = constrain(ballY, 0, HEIGHT - 1);
    playWallSound();
  }

  // Bounce an Paddle 1 (links)
  if (ballX == 0) {
    if (ballY >= paddleY1 && ballY < paddleY1 + PADDLE_HEIGHT) {
      ballVX = 1;
      playBounceSound();
      if (ballVY == 0) ballVY = (random(0, 2) * 2 - 1);
      ballX = 1;
    }
  }

  // Bounce an Paddle 2 (rechts)
  else if (ballX == WIDTH - 1) {
    if (ballY >= paddleY2 && ballY < paddleY2 + PADDLE_HEIGHT) {
      ballVX = -1;
      playBounceSound();
      if (ballVY == 0) ballVY = (random(0, 2) * 2 - 1);
      ballX = WIDTH - 2;
    }
  }

  // Tor für Spieler 2
  if (ballX < 0) {
    score2++;
    playGoalSound();
    showMessage("Tor Spieler 2!");
    delay(1000);
    showScore(score1, score2);
    checkWin();
    resetBall(-1);
    return;
  }

  // Tor für Spieler 1
  if (ballX > WIDTH - 1) {
    score1++;
    playGoalSound();
    showMessage("Tor Spieler 1!");
    delay(1000);
    showScore(score1, score2);
    checkWin();
    resetBall(1);
    return;
  }

  // Sicherheitsregel
  if (ballVX == 0) ballVX = (random(0, 2) * 2 - 1);
}

void drawPaddles(CRGB colorp1, CRGB colorp2) {
  for (int i = 0; i < PADDLE_HEIGHT; i++) {
    if (paddleY1 + i < HEIGHT) {
      setPixel(0, paddleY1 + i, colorp1);
    }
    if (paddleY2 + i < HEIGHT) {
      setPixel(WIDTH - 1, paddleY2 + i, CRGB(colorp2));
    }
  }
}

void resetBall(int richtung) {
  ballHeld = true;
  heldByPlayer = (richtung == 1) ? 2 : 1;

  ballY = (heldByPlayer == 1) ? paddleY1 + PADDLE_HEIGHT / 2
                              : paddleY2 + PADDLE_HEIGHT / 2;
  ballX = (heldByPlayer == 1) ? 0 : WIDTH - 1;

  ballVX = 0;
  ballVY = 0;
}

void checkWin() {
  if (score1 >= 10) {
    showMessage("1 gewinnt!");
    playEndSound();
    while (true);
  }
  if (score2 >= 10) {
    showMessage("2 gewinnt!");
    playEndSound();
    while (true);
  }
}

CRGB updatePlayerColor1(int b1) {
  static bool lastState = LOW;
  static uint8_t colorIndex = 0;

  if (b1 == HIGH && lastState == LOW) {
    playWallSound();
    colorIndex++;
    if (colorIndex >= 8) {
      colorIndex = 0;
    }
  }
  lastState = b1;

  return colors[colorIndex];
}

CRGB updatePlayerColor2(int b2) {
  static bool lastState = LOW;
  static uint8_t colorIndex = 0;

  if (b2 == HIGH && lastState == LOW) {
    playWallSound();
    colorIndex++;
    if (colorIndex >= 8) {
      colorIndex = 0;
    }
  }
  lastState = b2;

  return colors[colorIndex];
}