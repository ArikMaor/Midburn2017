void startup() {
  for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
    setColor(i, 30, 0, 0);
    delay(200);
    setColor(i, 50, 0, 0);
    delay(200);  
    setColor(i, 100, 0, 0);
    delay(200);  
    setColor(i, 0, 30, 0);
    delay(200);
    setColor(i, 0, 50, 0);
    delay(200);
    setColor(i, 0, 100, 0);
    delay(200);
    setColor(i, 0, 0, 30);
    delay(200);
    setColor(i, 0, 0, 50);
    delay(200);
    setColor(i, 0, 0, 100);
    delay(200);
    setColor(i, 0, 0, 0);
  }

  setAll(30, 0, 0);
  delay(200);
  setAll(50, 0, 0);
  delay(200);  
  setAll(100, 0, 0);
  delay(200);  
  setAll(0, 30, 0);
  delay(200);
  setAll(0, 50, 0);
  delay(200);
  setAll(0, 100, 0);
  delay(200);
  setAll(0, 0, 30);
  delay(200);
  setAll(0, 0, 50);
  delay(200);
  setAll(0, 0, 100);
  delay(200);
  setAll(100, 100, 100);
  delay(1000);
  setAll(0, 0, 0);
}
