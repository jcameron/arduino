const int trigPin = 9;  
const int echoPin = 8; 

float duration, distance; 

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  // put your setup code here, to run once:
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
  matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  byte frame[8][12];
  int c = 0;
  for(int i=0; i<8; i++) {
    for(int j=0; j<12; j++) {
      frame[i][j] = c < distance ? 1 : 0;
      c++;
    }
  }
  matrix.renderBitmap(frame, 8, 12);
}
