#pragma once
#include "./utils/gameLevelUtil/playable.h"
class NumberStationGame: public Playable {
public:
    void setup() override;
    void loop() override;
};