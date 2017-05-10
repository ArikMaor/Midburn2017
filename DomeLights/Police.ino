void police() {
  if (stage) {
    setColor(0, 255, 0, 0);
    setColor(1, 0, 0, 255);
    stage = 0;
  } else {
    setColor(0, 0, 0, 255);
    setColor(1, 255, 0, 0); 
    stage = 1;
  }
}
