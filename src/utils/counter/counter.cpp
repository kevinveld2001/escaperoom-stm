#include "counter.h"

#define minutesToPlay 300000

long millisSinceStart = 0;
bool isRunning = false;

int secondsPassed = 0;
int minutesPassed = 0;

void startCounter() {
    millisSinceStart = millis();
    isRunning = true;
    tm.displayBegin();
}

void displayCounter() {
    if (!isRunning) return;
    long millisPassed = minutesToPlay - (millis() - millisSinceStart);

    if (millisPassed <= 0) {
        timeUp();
        isRunning = false;
        return;
    }

    int newSecondsPassed = (millisPassed / 1000) % 60;
    int newMinutesPassed = (millisPassed / 1000) / 60;
    if (newSecondsPassed != secondsPassed || newMinutesPassed != minutesPassed) {
        secondsPassed = newSecondsPassed;
        minutesPassed = newMinutesPassed;
        tm.displayIntNum((minutesPassed * 1000) + secondsPassed, false, TMAlignTextRight);
        tm.display7Seg(5, 0);
    }
}