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
