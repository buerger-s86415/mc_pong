#include "sound.h"

void playBounceSound() {
  tone(BUZZER_PIN, 1000, 50); // Paddle
}

void playWallSound() {
  tone(BUZZER_PIN, 1500, 30); // Wand (höher, kürzer)
}

void playGoalSound() {
  tone(BUZZER_PIN, 300, 200);
  delay(200);
  tone(BUZZER_PIN, 1000, 200);
}

void playStartSound() {
  tone(BUZZER_PIN, 880, 100);
  delay(120);
  tone(BUZZER_PIN, 1047, 100);
  delay(120);
  tone(BUZZER_PIN, 1319, 100);
}

void playEndSound() {
  tone(BUZZER_PIN, 659, 150);
  delay(200);
  tone(BUZZER_PIN, 523, 200);
  delay(250);
  tone(BUZZER_PIN, 784, 400);
}