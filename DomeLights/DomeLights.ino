#include <Utility.h>
#include <IRremote.h>
#include <TimedAction.h>
#include "Buttons.h"
#include "Pins.h"

void processRemoteSignal();
void startup();
void police();
void greenYellow();
void fading();
//void wave();

// Buttons and Actions mapping
int Buttons[] = {
  BTN_POWER,
  BTN_MODE,
  BTN_MUTE
};
TimedAction actions[] = {
  TimedAction(1000, police),
  TimedAction(1000, greenYellow)
//  TimedAction(100, wave)
};

IRrecv irrecv(RECV_PIN);
unsigned int currentAction = 2;
unsigned int stage = 0;

void setup()
{
  for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
    foreach(STRIPS[i], 3, pinMode, OUTPUT);
  }

  Serial.begin(9600);
//  irrecv.enableIRIn();
  
//  startup();
}

const double STEP = 0.01;

void loop() {
//  processRemoteSignal(&irrecv);
//  actions[currentAction].check();
  for(double h=0; h<=1; h+=STEP) {
    for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
      setHsv(i, EaseInOut(h+(0.15*i)), 1, 0.5);
    }
    delay(100);
  }
}

