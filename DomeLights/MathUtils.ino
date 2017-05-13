double EaseInOut(double x) {
  if (x>1) { x=x-1; }

  float top = x*x;
  float bot = (x*x) + ((1-x)*(1-x));

  return (top/bot);
}
