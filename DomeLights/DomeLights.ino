#include <IRremote.h>
#include <TimedAction.h>

// Output
int redPin = 9;
int grnPin = 10;
int bluPin = 8;
int redPin2 = 12;
int grnPin2 = 13;
int bluPin2 = 11;

// IR Reciever
int RECV_PIN = 24;
IRrecv irrecv(RECV_PIN);
decode_results results;

// Remote Buttons
const int BTN_POWER = 0xA25D;
const int BTN_MODE = 0x629D;
const int BTN_MUTE = 0xE21D;
const int BTN_PLAY = 0x22DD;
const int BTN_PREV = 0x02FD;
const int BTN_NEXT = 0xC23D;
const int BTN_VOL_DOWN = 0xA857;
const int BTN_VOL_UP = 0x906F;
const int BTN_EQ = 0xE01F;
const int BTN_SWITCH = 0x9867;
const int BTN_USD = 0xB04F;
const int BTN_NUM_0 = 0x6897;
const int BTN_NUM_1 = 0x30CF;
const int BTN_NUM_2 = 0x18E7;
const int BTN_NUM_3 = 0x7A85;
const int BTN_NUM_4 = 0x10EF;
const int BTN_NUM_5 = 0x38C7;
const int BTN_NUM_6 = 0x5AA5;
const int BTN_NUM_7 = 0x42BD;
const int BTN_NUM_8 = 0x4AB5;
const int BTN_NUM_9 = 0x52AD;

int Buttons[] = {
  BTN_POWER,
  BTN_MODE
};
void police();
void greenYellow();
void fading();
TimedAction actions[] = {
  TimedAction(1000, police),
  TimedAction(1000, greenYellow)
};
unsigned int currentAction = 0;
unsigned int stage = 0;

// Set up the LED outputs
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(grnPin2, OUTPUT);
  pinMode(bluPin2, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  startup();
}

void startup() {
  setColor(255, 0, 0);
  setColor2(255, 0, 0);
  delay(400);
  setColor(0, 255, 0);
  setColor2(0, 255, 0);
  delay(400);
  setColor(0, 0, 255);
  setColor2(0, 0, 255);
  delay(400);
  setColor(255, 255, 255);
  setColor2(255, 255, 255);
  delay(1000);
}

void processRemoteSignal() {
  if (irrecv.decode(&results)) {
    int btn = String(results.value).toInt();
    for (int i = 0; i < sizeof(Buttons) / sizeof(int); i++) {
      if (btn == Buttons[i]) {
        TimedAction action = actions[i];
        if (currentAction != i) {
          Serial.println("Change");
          stage = 0;
          currentAction = i;
        }
      }
    }
    irrecv.resume(); // Receive the next value
  }
}

void loop() {
  processRemoteSignal();
  actions[currentAction].check();
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(grnPin, green);
  analogWrite(bluPin, blue);
}

void setColor2(int red, int green, int blue) {
  analogWrite(redPin2, red);
  analogWrite(grnPin2, green);
  analogWrite(bluPin2, blue);
}

void police() {
  if (stage) {
    setColor(255, 0, 0);
    setColor2(0, 0, 255);
    stage = 0;
  } else {
    setColor(0, 0, 255);
    setColor2(255, 0, 0); 
    stage = 1;
  }
}

void greenYellow() {
  if (stage) {
    setColor(0, 255, 0);
    setColor2(255, 255, 0);
    stage = 0;
  } else {
    setColor(255, 255, 0);
    setColor2(0, 255, 0);
    stage = 1;
  }
}

