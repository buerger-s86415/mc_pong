# Belegarbeit: Microcontroller
## Benjamin Banse, Kevin Bürger
## Arduino Pong auf 16×16 WS2812-Matrix

## Inhalt
- Pong-Spiel mit Echtzeitanzeige auf einer 16×16 WS2812B-Matrix
- LCD zeigt Punktestand und Spielstatus
- Zwei Joysticks für Paddle-Steuerung
- Piezo-Buzzer für Soundeffekte
- Ball-Logik über Timer-Interrupt

## Komponenten
- Arduino Uno
- 16×16 WS2812B LED-Matrix
- LCD 2×16 (I2C)
- 2x Joysticks
- Piezo-Buzzer
- Breadboard, Jumperwires

## Steuerung
- Linker Joystick: Spieler 1
- Rechter Joystick: Spieler 2
- Spiel läuft automatisch

## Kompilieren & Hochladen
Öffne `src/main.ino` in der Arduino IDE oder nutze PlatformIO.
