void setColor(int strip, int red, int green, int blue) {
  int* pins = STRIPS[strip];
  analogWrite(pins[0], red);
  analogWrite(pins[1], green);
  analogWrite(pins[2], blue);
}

