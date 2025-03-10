#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    196
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define CIRC        80
#define SWAPS       10

CRGB leds[NUM_LEDS];

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(BRIGHTNESS);
    Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  //showTrail(65535, 6);
  /*
  srand(millis());
  int c = rand() % 7;
  showHSV(60);
  showRotate(60, c);
  */
  //showWhite(6000, 6);
  showDials(0);
}

void zeroLeds() {
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void redLeds() {
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
  delay(100);
}

void waitRound(int secs, long start) {
  long until = start + secs*1000 + 2000;
  until -= until%1000;
  while(millis() < until) { }
}

 static float offset = 0;

void showRotate(long secs, int tc) {
  long start = millis();
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      float dist = abs(i - offset);
      if (dist > NUM_LEDS) {
        dist = dist - NUM_LEDS;
      }
      dist = dist > NUM_LEDS/2 ? NUM_LEDS-dist : dist;
      int c = 64 - dist*0.75;
      leds[i] = oneColor(c < 0 ? 0 : c, tc);
      //leds[i] = oneColor(dist == 0 ? 255 : 0, tc);
    }
    offset += 0.1;
    if (offset > NUM_LEDS) {
      offset = 0;
    }
    FastLED.show();
    delay(5);
  }
  waitRound(secs, start);
}

// Fading white trail that moves down
void showTrail(long secs, int tc) {
  zeroLeds();
  long start = millis();
  int len = 100;
  int offset = NUM_LEDS + len + 1;   // Tail of the trail
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      if (i > offset) {
        // Off the end
        leds[i] = CRGB::Black;
      } else if (i < offset - len) {
        // Off the start
        leds[i] = CRGB::Black;
      } else {
        int c = (offset - i) * 255 / len;
        leds[i] = oneColor(c, tc);
      }
    }
    offset--;
    if (offset < 0) {
      offset = NUM_LEDS + len + 1;
    }
    FastLED.show();
    delay(10);
  }
}

void showHSV(long secs) {
  zeroLeds();
  long start = millis();
  int hue = 0;
  while(millis() - start < secs*1000) {
    hue = (hue + 4)%256;
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i].setHSV((hue+i)%256, 255, 64);
    }
    FastLED.show();
    delay(100);
  }
}

void showHSVAll(int secs) {
  zeroLeds();
  long start = millis();
  int hue = 0;
  while(millis() - start < secs*1000) {
    hue = (hue + 4)%256;
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i].setHSV(hue%256, 255, 64);
    }
    FastLED.show();
    delay(100);
  }
}

void showWhite(long secs, int m) {
  long start = millis();
  int level = 64;
  int dir = 1;
  while(millis() - start < secs*1000) {
    int pot3 = analogRead(3);
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i] = oneColor(level, m);
    }
    level += dir;
    /*
    if (level == 32) {
      m = (m+1) % 7;
    }
    */
    if (level == 255 || level == 32) {
      dir =- dir;
    }
    FastLED.show();
    delay(5);
  }
}

void showDials(int m) {
  int level = 64;
  int dir = 1;
  while(1) {
    int pot1 = analogRead(1);
    int pot2 = analogRead(2);
    int pot3 = analogRead(3);
    int hue = pot3 / 4;
    int sat = pot1 / 4;
    int value = pot2 / 4;
    for(int i=0; i<NUM_LEDS; i++) {
      //leds[i] = oneColor(level, m);
      leds[i].setHSV(hue, sat, value);
    }
    FastLED.show();
    delay(5);
  }
}

CRGB oneColor(int c, int m) {
  if (m == 0) {
    return CRGB(c, 0, 0);
  } else if (m == 1) {
    return CRGB(0, c, 0);
  } else if (m == 2) {
    return CRGB(0, 0, c);
  } else if (m == 3) {
    return CRGB(c, c, 0);
  } else if (m == 4) {
    return CRGB(0, c, c);
  } else if (m == 5) {
    return CRGB(c, 0, c);
  } else {
    return CRGB(c, c, c);
  }
}
