#include "Music.h"
#include <global.h>

void Music::playMusic() {
    if (millis() - lastTime > 200) {
        lastTime = millis();
        tone(buzzer_pin, notesList[noteIndex], 300);
        noteIndex++;
        if (noteIndex >= songLength) {
            noteIndex = 0;
        }
    }
}

void Music::stopMusic() {
    noTone(buzzer_pin);
}