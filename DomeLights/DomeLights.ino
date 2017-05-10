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

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(grnPin2, OUTPUT);
  pinMode(bluPin2, OUTPUT);

  irrecv.enableIRIn();
  
  startup();
}

void loop() {
  processRemoteSignal(&irrecv);
  actions[currentAction].check();
}

