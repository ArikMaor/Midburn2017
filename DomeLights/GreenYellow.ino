void greenYellow() {
  if (stage) {
    setColor(0, 0, 100, 0);
    setColor(1, 100, 100, 0);
    setColor(2, 0, 100, 0);
    setColor(3, 100, 100, 0);
    stage = 0;
  } else {
    setColor(0, 100, 100, 0);
    setColor(1, 0, 100, 0);
    setColor(2, 100, 100, 0);
    setColor(3, 0, 100, 0);
    stage = 1;
  }
}

