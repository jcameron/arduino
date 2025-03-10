void setup() {
  for(int pin=9; pin<=11; pin++) {
    pinMode(pin, OUTPUT);
  }
}


void loop() {
  fadeAll(30);
  rotateTree(30);
  fadeUp(30);
  blinkAll(30);
}

void zeroTree() {
  for(int pin=9; pin<=11; pin++) {
    analogWrite(pin, 0);
  }
}

void rotateTree(int secs) {
  zeroTree();
  long start = millis();
  while(millis() - start < secs*1000) {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        if (i == j) {
          analogWrite(j+9, 255);
        } else if (i == (j+1)%3) {
          analogWrite(j+9, 0);
        } else {
          analogWrite(j+9, 0);
        }
      }
      delay(200);
    }
  }
}

void fadeAll(int secs) {
  zeroTree();
  long start = millis();
  int speed = 1;
  while(millis() - start < secs*1000) {
    for(int i=0; i<255; i+=speed) {
      for(int pin=9; pin<=11; pin++) {
        analogWrite(pin, i);
      }
      delay(10);
    }
    delay(1000);
    for(int i=255; i>=0; i-=speed) {
      for(int pin=9; pin<=11; pin++) {
        analogWrite(pin, i);
      }
      delay(10);
    }
    speed++;
  }
}

void fadeUp(int secs) {
  zeroTree();
  long start = millis();
  while(millis() - start < secs*1000) {
    for(int pin=9; pin<=11; pin++) {
      for(int i=0; i<255; i++) {
        analogWrite(pin, i);
        delay(10);
      }
      delay(1000);
    }
    for(int i=255; i>=0; i--) {
      for(int pin=9; pin<=11; pin++) {
        analogWrite(pin, i);
      }
      delay(10);
    }
  }
}

void blinkAll(int secs) {
  zeroTree();
  long start = millis();
  while(millis() - start < secs*1000) {
    for(int pin=9; pin<=11; pin++) {
      analogWrite(pin, 128);
    }
    delay(500);
    for(int pin=9; pin<=11; pin++) {
      analogWrite(pin, 0);
    }
    delay(500);
  }
}
