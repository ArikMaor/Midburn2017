void setColor(int strip, int colors[3]) {
  setColor(strip, colors[0], colors[1], colors[2]);
}

void setColor(int strip, int red, int green, int blue) {
  int* pins = STRIPS[strip];
  Serial.println((red/100)*256-1);
  analogWrite(pins[0], red*255/100);
  analogWrite(pins[1], green*255/100);
  analogWrite(pins[2], blue*255/100);
}

void setAll(int red, int green, int blue) {
  for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
    setColor(i, red, green, blue);
  }
}

void setAllHsv(float h, float s, float v) {
  for (int st = 0; st < sizeof(STRIPS)/sizeof(int[3]); st++) {
    setHsv(st, h, s, v);
  }
}

// string - string index
// h - [0,1]
// s - [0,1]
// v - [0,1]
void setHsv(int strip, double h, double s, double v) {
  double r, g, b;

  if (h>1) { h=h-1; }
  if (s>1) { s=s-1; }
  if (v>1) { v=v-1; }

  int i = h * 6;
  double f = h * 6 - i;
  double p = v * (1 - s);
  double q = v * (1 - f * s);
  double t = v * (1 - (1 - f) * s);

  switch(i % 6){
    case 0: r = v, g = t, b = p; break;
    case 1: r = q, g = v, b = p; break;
    case 2: r = p, g = v, b = t; break;
    case 3: r = p, g = q, b = v; break;
    case 4: r = t, g = p, b = v; break;
    case 5: r = v, g = p, b = q; break;
  }

  int* pins = STRIPS[strip];
  analogWrite(pins[0], r*255);
  analogWrite(pins[1], g*255);
  analogWrite(pins[2], b*255);
}

