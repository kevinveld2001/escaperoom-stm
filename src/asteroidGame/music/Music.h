#pragma once
#include <Arduino.h>
#include "pitches.h"

#define songLength 11

class Music {
    private:
        unsigned long lastTime = millis();
        int noteIndex = 0;
        int* notesList = new int[songLength]{ 
            NOTE_A4,
            NOTE_F4,
            NOTE_A4,
            NOTE_F4,
            NOTE_A4,
            NOTE_D4,
            NOTE_A4,
            NOTE_C5,
            NOTE_A4,
            0,
            NOTE_A4
            };

    public:
        // playMusic(); should be called in a loop
        void playMusic();

        // stopMusic(); should be called when the game is over
        void stopMusic();
        ~Music() {
                delete[] notesList;
        }
};

