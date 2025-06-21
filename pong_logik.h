#pragma once
#include <FastLED.h>

#define LOW  0
#define HIGH 1

extern int ballX, ballY;
extern int ballVX, ballVY;
extern int paddleY1, paddleY2;
extern int score1, score2;
constexpr int PADDLE_HEIGHT = 4;
extern bool ballHeld;
extern int heldByPlayer;

void updateBall();
CRGB updatePlayerColor1(int b1);
CRGB updatePlayerColor2(int b2);
void drawPaddles(CRGB colorp1, CRGB colorp2);
void resetBall(int richtung);
void checkWin();