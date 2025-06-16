#include "led_matrix.h"

CRGB leds[NUM_LEDS];

void initMatrix() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
}

void clearMatrix() {
  FastLED.clear();
}

void showMatrix() {
  FastLED.show();
}

void setPixel(int x, int y, CRGB color) {
  int index = xyToIndex(x, y);
  if (index >= 0 && index < NUM_LEDS) {
    leds[index] = color;
  }
}

int xyToIndex(int x, int y) {
  x = constrain(x, 0, WIDTH - 1);
  y = constrain(y, 0, HEIGHT - 1);

  if (x % 2 == 0) {
    return x * HEIGHT + y;
  } else {
    return x * HEIGHT + (HEIGHT - 1 - y);
  }
}