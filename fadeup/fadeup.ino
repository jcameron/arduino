void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  for(int pin=9; pin<=11; pin++) {
    analogWrite(pin, 0);
  }
}


void loop() {
  for(int pin=9; pin<=11; pin++) {
    for(int i=0; i<255; i++) {
      analogWrite(pin, i);
      delay(10);
    }
  }
  for(int i=255; i>=0; i--) {
    for(int pin=9; pin<=11; pin++) {
      analogWrite(pin, i);
    }
    delay(10);
  }
}
