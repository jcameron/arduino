#include <FastLED.h>
#include "5x5_font.h"
#include "8x12_font.h"
#include <Wire.h>  // Wire library - used for I2C communication

int ADXL345 = 0x53; // The ADXL345 sensor I2C address

CRGB clockleds[5][23];
CRGB shotleds[3][56];
int lastloop;
int lastmove;
float lastx, lasty, lastz;

// Game state enum, and time at which it was entered
const int START = 0;    // 10 second wait before the game starts
const int PLAY = 1;     // Regular play, shotclock is counting down
const int SCORE = 2;    // A point was just scored
const int SHOT = 3;     // Shot clock just expired
const int MISS = 4;     // Missed shot
const int GAMEOVER = 5; // Game time is over
int gamestate;
int statetime;
int gametime;

void setup() {
  // Init game clock LEDs
  FastLED.addLeds<WS2812, 0, GRB>(clockleds[0], 23);
  FastLED.addLeds<WS2812, 1, GRB>(clockleds[1], 23);
  FastLED.addLeds<WS2812, 2, GRB>(clockleds[2], 23);
  FastLED.addLeds<WS2812, 3, GRB>(clockleds[3], 23);
  FastLED.addLeds<WS2812, 4, GRB>(clockleds[4], 23);

  // Init shot clock LEDs
  FastLED.addLeds<WS2812, 5, GRB>(shotleds[0], 56);
  FastLED.addLeds<WS2812, 6, GRB>(shotleds[1], 56);
  FastLED.addLeds<WS2812, 7, GRB>(shotleds[2], 56);

  FastLED.setBrightness(128);

  // Enable sonar pins
  pinMode(9, OUTPUT);  
  pinMode(11, OUTPUT); 
	pinMode(8, INPUT);  
  pinMode(10, INPUT);  
  Serial.begin(9600); 
  
  // Turn off sounds
  noTone(12);
  noTone(13); 

  // Initialize accelerometer
  Wire.begin(); // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345); // Start communicating with the device 
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8); // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable 
  Wire.endTransmission();
  delay(10);

  lastloop = millis();
  gamestate = START;
  gametime = statetime = millis();
  getaccel(&lastx, &lasty, &lastz);
}

int score = 0;
int lastscore = 0;
int redtime = 0;
int movetime = 0;
int lastgamestate = -1;
int misstime = 0;

void loop() {
  // put your main code here, to run repeatedly:
  clearclock();
  clearshot();
  int now = millis();
  int age = now - statetime;
  int agesecs = age / 1000;

/*
  Serial.print("state:");
  Serial.print(gamestate);
  Serial.print(" age:");
  Serial.print(agesecs);
  Serial.print("\n");
  */
  lastgamestate = gamestate;

  if (gamestate != GAMEOVER) {
    // Check if the game is over
    int leftsecs = getgameleft();
    if (leftsecs <= 0) {
      // Game time is over!
      gamestate = GAMEOVER;
      statetime = now;
      tone(12, 45, 1000);
    }
  }

  if (gamestate == PLAY && age > 1000 || gamestate == MISS) {
    // Check for a made shot if playing or in missed shot mode
    if (scoredshot()) {
      // A shot was scored! Clear the game and shot clocks
      tone(12, 90, 500);
      gamestate = SCORE;
      statetime = now;
    }
  }

  if (gamestate == START) {
    // Pre-game countdown
    if (agesecs > 10) {
      // Countdown is over
      gamestate = PLAY;
      gametime = statetime = now;
      tone(12, 90, 500);
    } else {
      // Show countdown bar
      showcountdown(age, 10);
    }
  }
  else if (gamestate == PLAY) {
    // Actually playing, so show game time countdown
    showgameclock();

    // Show the shot clock
    int shotleftsecs = 24 - agesecs;
    if (shotleftsecs <= 0) {
      // Shot clock has expired!
      tone(12, 45, 500);
      gamestate = SHOT;
      statetime = now;
    }
    char sbuf[3];
    sprintf(sbuf, "%2d", shotleftsecs);
    renderbigshotblur(sbuf[0], 1, 0, CRGB(255, 0, 0), CRGB(64, 64, 64));
    renderbigshotblur(sbuf[1], 8, 0, CRGB(255, 0, 0), CRGB(64, 64, 64));
  
    // Check if a shot was missed, but only once per 5 seconds
    if (missedshot() && now - misstime > 5000) {
      // Yes, so reset the shot clock
      tone(12, 300, 50);
      gamestate = MISS;
      statetime = now;
      misstime = now;
    }
  }
  else if (gamestate == GAMEOVER) {
    // Game is over, nothing more to show
    rendershotstring("GAME", 0, 0, CRGB(255, 255, 255));
    rendershotstring("OVER", 0, 7, CRGB(255, 255, 255));
  }
  else if (gamestate == SCORE) {
    // A point was just scored
    if (agesecs > 10) {
      // Resume the game
      gamestate = PLAY;
      statetime = now;
      gametime += 10*1000;  // Freeze the game clock
    } else {
      // Show countdown bar
      showcountdown(age, 10);
      if (agesecs < 2) {
        // Show green immediately after scoring
        greenshot();
      }
    }
  }
  else if (gamestate == SHOT) {
    // Shot clock expired
    if (agesecs > 10) {
      // Resume the game
      gamestate = PLAY;
      statetime = now;
      gametime += 10*1000;  // Freeze the game clock
    } else {
      // Show countdown bar
      showcountdown(age, 10);
      redshot();
    }
  }
  else if (gamestate == MISS) {
    // Missed shot
    showgameclock();
    whiteshot();
    if (age > 1000) {
      gamestate = PLAY;
      statetime = now;
    }
  }

  lastloop = millis();
  FastLED.show();
}

// Returns the number of seconds left in the game
int getgameleft() {
  int now = millis();
  int gameage = now - gametime;
  int leftsecs = 20*60 - gameage/1000;
  if (leftsecs <= 0) {
    leftsecs = 0;
  }
  return leftsecs;
}

// Show the game clock in the top display
void showgameclock() {
  int leftsecs = getgameleft();
  int left1 = leftsecs / 60;
  int left2 = leftsecs % 60;
  char buf[128];
  sprintf(buf, "%2d%02d", left1, left2);
  renderclockstring(buf, -1, 0, CRGB(255, 255, 255));
  setclock(10, 1, CRGB(255, 0, 0));
  setclock(10, 3, CRGB(255, 0, 0));
}

void showcountdown(int age, int max) {
  for(int x=0; x<(max*1000-age)*0.0023; x++) {
    for(int y=0; y<5; y++) {
      clockleds[y][x] = CRGB(128, 128, 128);
    }
  }
}

// Was there just a missed shot?
bool missedshot() {
  float move = getmove();
  return move > 3;
}

// Was there just a scoring shot?
bool scoredshot() {
  int d = getmindistance();
  return d < 50;
}

// Returns the scaled size of the last movement
float getmove() {
  int moveage = millis() - lastmove;
  if (moveage > 100) {
    lastmove = millis();
    float x, y, z;
    getaccel(&x, &y, &z);
    /*
    Serial.print("x=");
    Serial.print(x);
    Serial.print(" y=");
    Serial.print(y);
    Serial.print(" z=");
    Serial.print(z);
    Serial.println("");
    */
    float move = abs(lastx - x) + abs(lasty - y) + abs(lastz - z);
    move = move * 1000 / moveage;
    /*
    Serial.print("moveage: ");
    Serial.print(moveage);
    Serial.print(" move: ");
    Serial.print(move);
    Serial.println("");
    */
    lastx = x;
    lasty = y;
    lastz = z;
    if (moveage < 1000) {
      return move;
    }
  }
  return 0;
}

// Returns the total acceleration, minus gravity
float gettotalaccel() {

}

// Returns the three acceleration axes
void getaccel(float *x, float *y, float *z) {
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  float X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  float Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  float Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  X_out /= 256;
  Y_out /= 256;
  Z_out /= 256;
  if (X_out > 128) {
    X_out = X_out - 256;
  }
  if (Y_out > 128) {
    Y_out = Y_out - 256;
  }
  if (Z_out > 128) {
    Z_out = Z_out - 256;
  }
  *x = X_out;
  *y = Y_out;
  *z = Z_out;
}

int getdistance(int sonar) {
  int trigPin, echoPin;
  if (sonar == 0) {
    trigPin = 9;
    echoPin = 8;
  } else {
    trigPin = 11;
    echoPin = 10;
  }
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration*.0343)/2;
  return int(distance);
}

int getmindistance() {
  int s0 = getdistance(0);
  int s1 = getdistance(1);
  return s0 < s1 ? s0 : s1;
}

void clearclock() {
  for(int i=0; i<5; i++) {
    for(int j=0; j<23; j++) {
      clockleds[i][j] = CRGB(0, 0, 0);
    }
  }
}

void setclock(int x, int y, CRGB c) {
  if (x >= 0 && x < 23 && y >= 0 && y < 5) {
    clockleds[y][x] = c;
  }
}

void fillshot(CRGB c) {
  for(int i=0; i<3; i++) {
    for(int j=0; j<56; j++) {
      shotleds[i][j] = c;
    }
  }
}

void clearshot() {
  fillshot(CRGB(0, 0, 0));
}

void redshot() {
  fillshot(CRGB(255, 0, 0));
}

void greenshot() {
  fillshot(CRGB(0, 255, 0));
}

void whiteshot() {
  for(int i=0; i<3; i++) {
    for(int j=0; j<56; j++) {
      shotleds[i][j] = CRGB(128, 128, 128);
    }
  }
}

void setshot(int x, int y, CRGB c) {
  if (x >= 0 && x < 14 && y >= 0 && y < 12) {
    int s = y/4;
    int p;
    if (y%4 == 0) {
      p = x;
    } else if (y%4 == 1) {
      p = 27-x;
    } else if (y%4 == 2) {
      p = x+28;
    } else {
      p = 55-x;
    }
    shotleds[s][p] = c;
  }
}

void renderclockstring(char *s, int x, int y, CRGB col) {
  for(int i=0; s[i]; i++) {
    renderclockchar(s[i], x+i*6, y, col);
  }
}

void renderclockchar(char c, int x, int y, CRGB col) {
  uint8_t *bm = fontdata_5x5[c - ASCII_OFFSET];
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      int xx = i + x;
      int yy = j + y;
      if (bm[j] & (128>>i)) {
        setclock(xx, yy, col);
      }
    }
  }
}

void rendershotstring(char *s, int x, int y, CRGB col) {
  for(int i=0; s[i]; i++) {
    rendershotchar(s[i], x+i*6, y, col);
  }
}

void rendershotchar(char c, int x, int y, CRGB col) {
  uint8_t *bm = fontdata_5x5[c - ASCII_OFFSET];
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      int xx = i + x;
      int yy = j + y;
      if (bm[j] & (128>>i)) {
        setshot(xx, yy, col);
      }
    }
  }
}

void renderbigshotchar(char c, int x, int y, CRGB col) {
  char *bm = fontdata_8x12 + (c - ASCII_OFFSET) * 12;
  for(int i=0; i<8; i++) {
    for(int j=0; j<12; j++) {
      int xx = i + x;
      int yy = j + y;
      if (bm[j] & (128>>i)) {
        setshot(xx, yy, col);
      }
    }
  }
}

void renderbigshotblur(char c, int x, int y, CRGB col, CRGB bcol) {
  renderbigshotchar(c, x-1, y, bcol);
  renderbigshotchar(c, x+1, y, bcol);
  renderbigshotchar(c, x, y-1, bcol);
  renderbigshotchar(c, x, y+1, bcol);
  renderbigshotchar(c, x, y, col);
}
