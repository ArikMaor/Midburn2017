const float EPSILON = 0.05f;

double EaseInOut(double x) {
  if (x>1) { x=x-1; }

  float top = x*x;
  float bot = (x*x) + ((1-x)*(1-x));

  return (top/bot);
}

float ZeroOut(float x) {
  if (x > EPSILON)
    return x;
  else
    return 0;
}

