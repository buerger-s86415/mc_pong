#include "pong_logik.h"
#include "led_matrix.h"

// Startposition Mitte
int ballX = WIDTH / 2;
int ballY = HEIGHT / 2;

// Startbewegung (z. B. nach rechts unten)
int ballVX = 1;
int ballVY = 1;

void updateBall() {
  ballX += ballVX;
  ballY += ballVY;

  // Bounce oben/unten
  if (ballY <= 0 || ballY >= HEIGHT - 1) {
    ballVY = -ballVY;
  }

  // Bounce links/rechts (später ersetzen durch Punkt)
  if (ballX <= 0 || ballX >= WIDTH - 1) {
    ballVX = -ballVX;
  }
}