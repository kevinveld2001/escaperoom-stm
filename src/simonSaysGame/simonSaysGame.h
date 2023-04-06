#pragma once
#include "./utils/gameLevelUtil/playable.h"

class SimonSaysGame: public Playable {
public:
    void setup() override;
    void loop() override;
};