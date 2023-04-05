#pragma once
#include <global.h>

void buttonScanLoop();
uint8_t getButtons();
bool areButtonsPressed(uint8_t buttons, bool allSet);
bool areButtonsPressedEvent(uint8_t buttons, bool allSet);