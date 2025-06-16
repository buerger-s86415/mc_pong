#pragma once

#include <Arduino.h>
#include <FastLED.h>

constexpr uint8_t WIDTH = 16;
constexpr uint8_t HEIGHT = 16;
constexpr uint16_t NUM_LEDS = WIDTH * HEIGHT;
constexpr uint8_t DATA_PIN = 2;

extern CRGB leds[NUM_LEDS];

void initMatrix();
void clearMatrix();
void showMatrix();
void setPixel(int x, int y, CRGB color);
int xyToIndex(int x, int y);