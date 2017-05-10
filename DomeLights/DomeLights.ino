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

// Buttons and Actions mapping
int Buttons[] = {
  BTN_POWER,
  BTN_MODE
};
TimedAction actions[] = {
  TimedAction(1000, police),
  TimedAction(1000, greenYellow)
};

IRrecv irrecv(RECV_PIN);
unsigned int currentAction = 0;
unsigned int stage = 0;

void initStrip(int pins[3]) {
  foreach(pins, 3, pinMode, OUTPUT);
}

void setup()
{
  initStrip(STRIPS[0]);
  initStrip(STRIPS[1]);

  irrecv.enableIRIn();
  
  startup();
}

void loop() {
  processRemoteSignal(&irrecv);
  actions[currentAction].check();
}

