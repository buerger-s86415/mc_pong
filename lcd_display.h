#pragma once

#include <Arduino.h>

void initLCD();
void showScore(int score1, int score2);
void showMessage(const String& text);