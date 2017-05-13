void processRemoteSignal(IRrecv* irrecv) {
  decode_results results;
  if (irrecv->decode(&results)) {
    int btn = String(results.value).toInt();
    Serial.println(btn);
    for (int i = 0; i < sizeof(Buttons) / sizeof(int); i++) {
      if (btn == Buttons[i]) {
        TimedAction action = actions[i];
        if (currentAction != i) {
          stage = 0;
          currentAction = i;
        }
      }
    }
    irrecv->resume(); // Receive the next value
  }
}
