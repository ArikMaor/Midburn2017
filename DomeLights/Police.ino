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
