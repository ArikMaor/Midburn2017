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

