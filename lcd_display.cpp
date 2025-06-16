#include "lcd_display.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

void initLCD() {
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PONG bereit!");
}

void showScore(int score1, int score2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Spieler1: ");
    lcd.print(score1);

    lcd.setCursor(0, 1);
    lcd.print("Spieler2: ");
    lcd.print(score2);
}

void showMessage(const String& text) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text);
}