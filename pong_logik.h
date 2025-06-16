#pragma once

extern int ballX, ballY;
extern int ballVX, ballVY;
extern int paddleY1, paddleY2;
extern int score1, score2;
constexpr int PADDLE_HEIGHT = 4;
extern bool ballHeld;
extern int heldByPlayer;

void updateBall();
void drawPaddles();
void resetBall(int richtung);
void checkWin();