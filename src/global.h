#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <TM1638plus.h>


// Pin configuration for the TM1638 module
#define TM_STROBE 4 
#define TM_CLOCK 6 
#define TM_DIO 7
extern TM1638plus tm;

//Pin configuration for the buzzer
#define buzzer_pin 12


extern LiquidCrystal_I2C lcd;


void nextLevel();
void setGameOver();