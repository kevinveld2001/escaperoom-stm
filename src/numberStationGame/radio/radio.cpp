#include "radio.h"
#include "morse.h"

// long playBeepTill = 0;
long timeSinsLastMorse = -UNITTIME * 16;
u_int16_t morseToPlay = 0;

void radioSetup() {
    analogWrite(RADIO_PIN, 127);
}

void radioShutdown() {
    analogWrite(RADIO_PIN, 0);
}

void radioSendMorseCode(char code) {
    // playBeepTill = millis() + 500;

    if (islower(code)) {
        code -= 'a';
    } else if (isupper(code)) {
        code -= 'A';
    } else if (isDigit(code)) {
        code -= 22;
    }
    morseToPlay = morseCodeMapping[code];
    timeSinsLastMorse = millis();

}

bool beepHigh = false;
long lastSwitch = 0;
void radioLoop() {
    u_int16_t index = (millis() - timeSinsLastMorse) / UNITTIME;

    if (lastSwitch + 1 > millis()) return;
    if ((timeSinsLastMorse + UNITTIME * 16 > millis() && (morseToPlay&(0b1000000000000000 >> index)) == (0b1000000000000000 >> index))) {
        lastSwitch = millis();
        beepHigh = !beepHigh;
        analogWrite(RADIO_PIN, 127 + beepHigh);
    }
}
