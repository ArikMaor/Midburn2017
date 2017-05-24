//#include <TimedAction.h>
#include <Utility.h>
#include "Pins.h"
#include "Colors.h"

void processRemoteSignal();
void startup();
void police();
void greenYellow();
void fading();
//void wave();

unsigned int currentAction = 2;
unsigned int stage = 0;

void setup()
{
//  for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
//    foreach(STRIPS[i], 3, pinMode, OUTPUT);
//  }

//  Serial.begin(9600);
//  startup();
}

const double STEP = 0.05;
const double SHORT_DELAY = 15;
const double DELAY = 50;
const double LONG_DELAY = 200;

void loop() {
//  FourStrips();
  Sign();
}

void Sign() {
  ResetAll();
  SimultaniousOnVarying(4);

  ResetAll();
  SimultaniousFadeSingle(7, ORANGE);
}


void FourStrips() {
  ResetAll();
  SimultaniousFadeSingle(7, ORANGE);

  ResetAll();
  SeqBlinkGradient(15, 0, 0.3f);

  ResetAll();
  SeqFadeSingle(15, MAGENTA);

  ResetAll();
  SimultaniousOnVarying(4);

  ResetAll();
  SeqBlinkSingle(15, GREEN);

  // Flames
  ResetAll();
  SeqFadeGradient(15, 0, 0.05f);

  ResetAll();
  SeqBlinkSingle(15, BLUE);

  ResetAll();
  SimultaniousFadeSingle(7, RED);

  // Random
  ResetAll();
  SeqFadeGradient(15, 0, 0.2f);

  ResetAll();
  SeqBlinkSingle(15, MAGENTA);
  
  ResetAll();  
  SeqFadeSingle(15, ORANGE);

  ResetAll();
  SimultaniousOnVarying(4);

  // Random inverse
  ResetAll();
  SeqFadeGradient(15, 1, -0.25f);

  ResetAll();
  SeqBlinkSingle(15, CYAN);

  ResetAll();  
  SeqFadeSingle(15, RED);

  ResetAll();
  SimultaniousFadeSingle(7, MAGENTA);
}



