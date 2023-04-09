#pragma once
#include "./utils/gameLevelUtil/playable.h"
#include "radio/radio.h"

class NumberStationGame: public Playable {
public:
    void setup() override;
    void loop() override;
    ~NumberStationGame() {
        radioShutdown();
    };
};