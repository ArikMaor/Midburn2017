void police() {
  if (stage) {
    setColor(0, 100, 0, 0);
    setColor(1, 0, 0, 100);
    setColor(2, 100, 0, 0);
    setColor(3, 0, 0, 100);
    stage = 0;
  } else {
    setColor(0, 0, 0, 100);
    setColor(1, 100, 0, 0); 
    setColor(2, 0, 0, 100);
    setColor(3, 100, 0, 0); 
    stage = 1;
  }
}
