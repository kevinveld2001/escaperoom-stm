#pragma once
#include "utils/gameLevelUtil/playable.h"

class GameOverScreen: public Playable {
public:
    void setup() override;
    void loop() override;
};