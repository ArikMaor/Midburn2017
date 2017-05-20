//#include <TimedAction.h>
#include <Utility.h>
#include "Pins.h"

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
  for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
    foreach(STRIPS[i], 3, pinMode, OUTPUT);
  }

  Serial.begin(9600);
//  startup();
}

const double STEP = 0.01;

void loop() {
  for(double h=0; h<=1; h+=STEP) {
    for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
      setHsv(i, EaseInOut(h+(0.15*i)), 1, 0.7);
    }
    delay(50);
  }
}

