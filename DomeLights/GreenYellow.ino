void greenYellow() {
  if (stage) {
    setColor(0, 0, 255, 0);
    setColor(1, 255, 255, 0);
    stage = 0;
  } else {
    setColor(0, 255, 255, 0);
    setColor(1, 0, 255, 0);
    stage = 1;
  }
}

