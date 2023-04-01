#pragma once
#include <global.h>

void buttonScanLoop();
bool areButtonsPressed(uint8_t buttons, bool allSet);
bool areButtonsPressedEvent(uint8_t buttons, bool allSet);