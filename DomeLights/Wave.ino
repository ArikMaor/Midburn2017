//const int STEP = 20;
//
//void wave() {
//  for(int i=0; i<sizeof(STRIPS)/sizeof(int[3]); i++) {
//    runWave(i);
//  }
//  
//  stage += STEP;
//  if (stage >= 200) {
//    stage = 0;
//  }
//}
//
//void runWave(int strip) {
//  int stripStage = stage + strip*STEP;
//  if (stripStage > 200) {
//    stripStage -= 200;
//  }
//  
//  int val = stripStage <= 100 ? stripStage : (200 - stripStage);
//  setColor(strip, 100-val, val, 10);
//}
//

