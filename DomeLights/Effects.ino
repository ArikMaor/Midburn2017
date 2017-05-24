void ResetAll()
{
  for (int i = 0; i < 4; i++) {
    setColor(i, 0, 0, 0);
  }
}

void SeqFadeGradient(int rounds, float baseHue, float hueStep) {
  
  for (int r = 0; r < rounds; r++) {
  
    float h = baseHue;

    for (int st = 0; st < 4; st++) {
    
      for (float i = 0; i <= 1; i += STEP) {
      
        setHsv(st, h, 1, ZeroOut(1 - i));

        if (((st + 1) % 4) == 0) {
            setHsv((st + 1) % 4, baseHue, 1, ZeroOut(i));
        } else {
            setHsv((st + 1) % 4, h + hueStep, 1, ZeroOut(i));
        }
        
        delay(SHORT_DELAY);
      }
      
      h += hueStep;
    }
  }
}

void SeqFadeSingle(int rounds, float hue) {
  
  for (int r = 0; r < rounds; r++) {
    
    for (int st = 0; st < 4; st++) {
        
      for (float i = 0; i <= 1; i += STEP) {

        setHsv(st, hue, 1, ZeroOut(1 - i));
        setHsv((st+1)%4, hue, 1, ZeroOut(i));
        
        delay(SHORT_DELAY);
      }
    }
  }
}

void SeqBlinkSingle(int rounds, float hue) {
  
  for (int r = 0; r < rounds; r++) {
    
    for (int st = 0; st < 4; st++) {

      setHsv(st, hue, 1, 0);
      setHsv((st+1)%4, hue, 1, 1);

      delay(LONG_DELAY);
    }
  }
}

void SeqBlinkGradient(int rounds, float baseHue, float hueStep) {
  
  for (int r = 0; r < rounds; r++) {
  
    float h = baseHue;

    for (int st = 0; st < 4; st++) {
    
      setHsv(st, h, 1, 0);

      if (((st + 1) % 4) == 0) {
          setHsv((st + 1) % 4, baseHue, 1, 1);
      } else {
          setHsv((st + 1) % 4, h + hueStep, 1, 1);
      }
      
      delay(LONG_DELAY);
      
      h += hueStep;
    }
  }
}

void SimultaniousFadeSingle(int rounds, float hue) {
  
  for (int r = 0; r < rounds; r++) {

    for (float i = 0; i <= 1; i += STEP) {
      
      for (int st = 0; st < 4; st++) {
        setHsv(st, hue, 1, ZeroOut(1 - i));
      }
      delay(DELAY);
    }
    for (float i = 0; i <= 1; i += STEP) {
      
      for (int st = 0; st < 4; st++) {
        setHsv(st, hue, 1, ZeroOut(i));
      }
      delay(DELAY);
    }
  }
}

void SimultaniousOnVarying(int rounds) {
  
  for (int r = 0; r < rounds; r++) {
  
    for (float i = 0; i < 1; i += STEP * 0.05f) {
    
      setAllHsv(i, 1.0f, 0.5f);
      delay(DELAY);
    }
  }
}

