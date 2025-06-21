# Projektdokumentation: MC_PONG

## Projektname

MC_PONG – ein modulares Pong-Spiel auf echter Hardware mit LED-Matrix, Joysticks, LCD-Anzeige und Sound.

## Zielsetzung

Ziel des Projekts ist die Umsetzung eines eigenständig lauffähigen Pong-Spiels auf einem Arduino Uno, das mithilfe einer 16×16 WS2812B-LED-Matrix das Spielfeld darstellt. Zwei Spieler steuern die Paddles über analoge Joysticks. Ein LCD-Display dient zur Anzeige des Punktestands und des Spielausgangs. Zusätzlich sorgt ein aktiver Buzzer für akustisches Feedback bei Kollisionen, Toren und Spielstart/Spielende.

## Verwendete Hardware

- Arduino Uno  
- 16×16 WS2812B LED-Matrix (gesteuert über FastLED)  
- Zwei analoge Joysticks  
  - Spieler 1: A4 (X), A5 (Y)  
  - Spieler 2: A0 (X), A1 (Y)  
- 2×16 LCD (14-Pin-Version, 4-Bit-Modus, ohne I2C)  
- Aktiver Piezo-Buzzer (3-polig, Signal an D10)

## Projektstruktur

Das Projekt ist modular aufgebaut. Jedes Modul ist in einer eigenen .h/.cpp-Datei gekapselt:

| Datei                     | Beschreibung                                          |
|---------------------------|-------------------------------------------------------|
| MC_PONG.ino               | Haupt-Setup, Loop, Initialisierung                   |
| led_matrix.h / .cpp       | Matrix-Ansteuerung, Pixelsteuerung, xyToIndex        |
| pong_logik.h / .cpp       | Spiellogik, Ballphysik, Punktestand, Reset           |
| joystick_input.h / .cpp   | Joysticksteuerung für beide Spieler                  |
| lcd_display.h / .cpp      | Punktestand und Statusmeldungen auf dem LCD          |
| sound.h / .cpp            | Soundausgabe bei Ereignissen (Tor, Start, Ende etc.) |

## Spielfunktionen

- Paddle-Steuerung mit zwei analogen Joysticks  
- Der Ball bewegt sich über die Matrix und prallt an Wänden und Paddles ab  
- Punktesystem bei Verfehlen eines Paddles  
- Nach einem Punkt bleibt der Ball am gegnerischen Paddle kleben (ballHeld)  
- Der Ball startet durch Stoßbewegung des Joysticks  
- Der Punktestand wird live auf dem LCD angezeigt  
- Das Spiel endet bei 10 Punkten mit Gewinneranzeige  
- Akustische Rückmeldungen für Treffer, Tor, Start und Ende

## Technische Besonderheiten

- Serpentinen-Adressierung der Matrix per xyToIndex-Funktion  
- ballHeld-Mechanik verhindert unkontrolliertes Spiel nach Punkt  
- LCD im 4-Bit-Modus direkt verdrahtet (ohne I2C)  
- Saubere Trennung der Module für einfache Erweiterung und Wartung

## Soundübersicht

| Ereignis        | Tonfolge                  |
|-----------------|---------------------------|
| Paddle-Aufprall | 1000 Hz, 50 ms            |
| Wandaufprall    | 1500 Hz, 30 ms            |
| Tor             | 300 Hz → 1000 Hz          |
| Spielstart      | Dreiklang aufsteigend     |
| Spielende       | Fanfarenartige Abfolge    |

## Erweiterungsideen

- Timer-Interrupt zur Steuerung der Ballgeschwindigkeit  
- Schwierigkeitsstufen (z. B. schnellere Bewegung, kleinere Paddles)  
- Menüführung mit Joystick (Start, Neustart)  
- Lauftext auf dem LCD  
- Highscore-Speicherung im EEPROM

## Entwicklungsverlauf

1. Erste LED-Tests und Paddle-Bewegung  
2. Zwischenzeitliche Verwendung von PlatformIO mit sim/src-Trennung  
3. Rückkehr zur klassischen Arduino-IDE-Struktur  
4. Modularisierung in .cpp/.h  
5. Integration von LCD-Anzeige und Soundmodul  
6. Einbau der Gewinnererkennung bei 10 Punkten

## Autor

Kevin Bürger, Benjamin Banse
Studienprojekt an der Hochschule für Technik und Wirtschaft Dresden im Moduel "Programmierung von Microcontroller".
Unterstützt durch ChatGPT bei Strukturierung
