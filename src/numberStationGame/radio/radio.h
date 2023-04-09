#pragma once
#include <Arduino.h>
#include <global.h>

void radioSetup();
void radioShutdown();
void radioSendMorseCode(char code);
void radioLoop();
