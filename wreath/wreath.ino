#include <FastLED.h>
#define LED_PIN     3
#define NUM_LEDS    300
#define FLAKES      50
#define SPIRALS     6
#define STARS       50

CRGB leds[NUM_LEDS];
CRGB pal[NUM_LEDS];

char spirals[SPIRALS] = {65, 60, 53, 48, 42, 40};

short stars[STARS];
short bright[STARS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(127);
  for(int i=0; i<NUM_LEDS; i+=15) {
    for(int j=0; j<15 && j+i<NUM_LEDS; j++) {
      pal[i+j] = j < 5 ? CRGB::Red :
                 j < 10 ? CRGB::Green : CRGB::Black;
    }
  }
}

void loop() {
  showTwinkle(30);
  showSnow(30);
  showWheel(30);
  showDisc(30);
  showRedGreen(30);
  showIncrease(30);
}

void zeroLeds() {
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void showDisc(int secs) {
  zeroLeds();
  int angle = 0;
  long start = millis();
  while(millis() - start < secs*1000) {
    int start = 0;
    for(int s=0; s<SPIRALS; s++) {
      int p1 = start + (angle * spirals[s] / 360);
      int p2 = start + (((angle+180)%360) * spirals[s] / 360);
      for(int j=start; j<start+spirals[s] && j<NUM_LEDS; j++) {
        if (p2 > p1) {
          leds[j] = j>p1 && j<p2 ? CRGB::Red : CRGB::Blue;
        } else {
          leds[j] = j>p2 && j<p1 ? CRGB::Blue : CRGB::Red;
        }
      }
      start += spirals[s];
    }
    FastLED.show();
    delay(80);
    angle = (angle + 10) % 360;
  }
}

void showWheel(int secs) {
  zeroLeds();
  int angle = 0;
  long start = millis();
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
    int start = 0;
    for(int s=0; s<SPIRALS; s++) {
      for(int offset=0; offset < 360; offset += 45) {
        int p = start + (((angle+offset)%360) * spirals[s] / 360);
        if (p < NUM_LEDS) {
          leds[p] = CRGB::Green;
        }
      }
      start += spirals[s];
    }
    FastLED.show();
    delay(80);
    angle = (angle + 10) % 360;
  }
}

void showRedGreen(int secs) {
  zeroLeds();
  int offset = 0;
  long start = millis();
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      leds[(i+offset)%NUM_LEDS] = pal[i];
    }
    FastLED.show();
    delay(40);
    offset += 1;
  }
}

void showIncrease(int secs) {
  zeroLeds();
  long start = millis();
  CRGB cols[] = {CRGB::Red, CRGB::Blue, CRGB::Green, CRGB::White};
  int c = 0;
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i] = cols[c];
      FastLED.show();
      delay(10);
    }
    c = (c + 1)%4;
  }
}

void showSnow(int secs) {
  zeroLeds();
  long start = millis();
  int flakes[FLAKES];
  for(int i=0; i<FLAKES; i++) {
    flakes[i] = random(0, NUM_LEDS);
  }
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
    for(int i=0; i<FLAKES; i++) {
      leds[flakes[i]] = CRGB::White;
      flakes[i] = (flakes[i]+1) % NUM_LEDS;
    }
    FastLED.show();
    delay(40);
  }
}

void showTwinkle(int secs) {
  zeroLeds();
  long start = millis();
  for(int i=0; i<STARS; i++) {
    stars[i] = -1;
  }
  while(millis() - start < secs*1000) {
    // Create random stars where needed
    for(int i=0; i<STARS; i++) {
      if (stars[i] < 0 && random(0, 10) < 5) {
        stars[i] = random(0, NUM_LEDS);
        bright[i] = 0;
      }
    }
    // Fade them up and down
    for(int i=0; i<STARS; i++) {
      int s = stars[i];
      if (s >= 0) {
        bright[i] += i+8;
        if (bright[i] >= 256) {
          // End of life
          bright[i] = 0;
          stars[i] = -1;
        }
        leds[s] = CRGB(bright[i], bright[i], bright[i]);
      }
    }
    FastLED.show();
    delay(20);
  }
}
