#pragma once
#include "utils/gameLevelUtil/playable.h"

class GameWonScreen: public Playable {
public:
    void setup() override;
    void loop() override;
};