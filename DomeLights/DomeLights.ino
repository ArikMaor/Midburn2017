//#include <TimedAction.h>
#include <Utility.h>
#include "Pins.h"

const int NUMBER_OF_STRIPS = sizeof(STRIPS)/sizeof(int[3]);
const double RED = 0;
const double YELLOW = (double)1/6;
const double GREEN = (double)2/6;
const double CYAN = (double)3/6;
const double BLUE = (double)4/6;
const double MAGENTA = (double)5/6;

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

void loop () {
  #if defined(__AVR_ATmega2560__)
    // Mega
    fadeAllColors();
  #else
    // Uno
  #endif
//  for (double i=0; i<2; i+=0.10) {
//    for(int strip=0; strip<NUMBER_OF_STRIPS; strip++) {
//      if (i<1) {
//        i+=0.05;
//        setHsv(strip, RED, 1, i);
//      } else {
//        setHsv(strip, RED, 1, 2-i);  
//      }
//    }
//    
//    delay(50);
//  }
}

void fadeAllColors() {
  const double STEP = 0.01; 
  for(double h=0; h<=1; h+=STEP) {
    for(int i=0; i<NUMBER_OF_STRIPS; i++) {
      setHsv(i, EaseInOut(h+(0.15*i)), 1, 0.7);
    }
    delay(50);
  }
}

