#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    590
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define FLAKES      40
#define STARS       40
#define CIRC        80
#define SWAPS       10

CRGB leds[NUM_LEDS];

int offset = 0;

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  showRandomSwap(30);
  showHSV(30);
  showYellows(30);
  showIncrease(30);
  showTwinkle(30);
  redGreenWhite(30);
  showSnow(30);
  showHSVAll(30);
  //showRandom(30);
  showTrail(30);
  //showBars(30);
}

void zeroLeds() {
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(100);
}

void waitRound(int secs, long start) {
  long until = start + secs*1000 + 2000;
  until -= until%1000;
  while(millis() < until) { }
}

// Red, green and white bars
void redGreenWhite(int secs) {
  zeroLeds();
  long start = millis();
  int offset = 0;
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      int p = i%15;
      CRGB c = p<5 ? CRGB::Red : p<10 ? CRGB::Green : CRGB(32, 32, 32);
      leds[(i+offset)%NUM_LEDS] = c;
    }
    FastLED.show();
    FastLED.delay(100);
    offset++;
  }
  waitRound(secs, start);
}

// Snowflakes that move down
void showSnow(int secs) {
  zeroLeds();
  long start = millis();
  short flakes[FLAKES];
  for(int i=0; i<FLAKES; i++) {
    flakes[i] = random(0, NUM_LEDS);
  }
  int m = random(0, 7);
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
    for(int i=0; i<FLAKES; i++) {
      leds[flakes[i]] = oneColor(255, m);
      flakes[i]--;
      if (flakes[i] < 0) {
        flakes[i] = NUM_LEDS-1;
      }
    }
    FastLED.show();
    delay(40);
  }
  waitRound(secs, start);
}

// Fading trail that moves down
void showTrail(int secs) {
  zeroLeds();
  long start = millis();
  int len = 150;
  int offset = NUM_LEDS - len - 1;   // Tail of the trail
  int mode = 0;
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
        leds[i] = oneColor(c, mode);
      }
    }
    offset--;
    if (offset < 0) {
      offset = NUM_LEDS - len - 1;
      mode = (mode+1) % 7;
    }
    FastLED.show();
    delay(2);
  }
  waitRound(secs, start);
}

// Every pixel oscillates between red and green random colors
void showRandom(int secs) {
  zeroLeds();
  long start = millis();
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      if (random(0, 2) == 0) {
        leds[i] = CRGB(random(0, 255), 0, 0);
      } else {
        leds[i] = CRGB(0, random(0, 255), 0);
      }
    }
    FastLED.show();
    delay(20);
  }
  waitRound(secs, start);
}

// Strip filling from the top
void showIncrease(int secs) {
  zeroLeds();
  long start = millis();
  CRGB cols[] = {CRGB::Red, CRGB::Blue, CRGB::Green, CRGB::White};
  int c = 0;
  while(millis() - start < secs*1000) {
    for(int i=NUM_LEDS-1; i>=0; i--) {
      leds[i] = cols[c];
      FastLED.show();
      delay(1);
    }
    c = (c + 1)%4;
  }
  waitRound(secs, start);
}

void showBars(int secs) {
  zeroLeds();
  long start = millis();
  int offet = 0;
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      int p = i%(CIRC * 3);
      CRGB c = p<CIRC ? CRGB::Red : p<(CIRC*2) ? CRGB::Green : CRGB::Blue;
      leds[(i+offset)%NUM_LEDS] = c;
    }
    FastLED.show();
    FastLED.delay(1000);
    offset += CIRC;
  }
  waitRound(secs, start);
}

// Random colors, with random ones being replaced
void showRandomSwap(int secs) {
  zeroLeds();
  long start = millis();
  int offet = 0;
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB(random(0, 255), random(0, 255), random(0, 255));
  }
  FastLED.show();
  while(millis() - start < secs*1000) {
    for(int i=0; i<SWAPS; i++) {
      leds[random(0, NUM_LEDS)] = CRGB(random(0, 255), random(0, 255), random(0, 255));
    }
    FastLED.show();
  }
  waitRound(secs, start);
}

void showTwinkle(int secs) {
  zeroLeds();
  long start = millis();
  short stars[STARS];
  for(int i=0; i<STARS; i++) {
    stars[i] = -1;
  }
  while(millis() - start < secs*1000) {
    // Create random stars where needed
    for(int i=0; i<STARS; i++) {
      if (stars[i] < 0 && random(0, 10) < 5) {
        stars[i] = random(0, NUM_LEDS);
      }
    }
    // Fade them up and down
    for(int i=0; i<STARS; i++) {
      int s = stars[i];
      if (s >= 0) {
        int b = leds[s].red;
        b += i+8;
        if (b >= 255) {
          // End of life
          b = 0;
          stars[i] = -1;
        }
        leds[s] = CRGB(b, b, b);
      }
    }
    FastLED.show();
    delay(20);
  }
  waitRound(secs, start);
}

void showYellows(int secs) {
  zeroLeds();
  long start = millis();
  int m = random(0, 6);
  for(int i=0; i<NUM_LEDS; i++) {
    int c = random(0, 255);
    leds[i] = oneColor(c, m);
  }
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      int c = max(max(leds[i].red, leds[i].green), leds[i].blue);
      c += 16;
      if (c >= 255) {
        c = random(0, 32);
      }
      leds[i] = oneColor(c, m);
    }
    FastLED.show();
    delay(100);
  }
  waitRound(secs, start);
}

void showHSV(int secs) {
  zeroLeds();
  long start = millis();
  int hue = 0;
  while(millis() - start < secs*1000) {
    hue = (hue + 4)%256;
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i].setHSV((hue+i)%256, 255, 196);
    }
    FastLED.show();
    delay(20);
  }
  waitRound(secs, start);
}

void showHSVAll(int secs) {
  zeroLeds();
  long start = millis();
  int hue = 0;
  while(millis() - start < secs*1000) {
    hue = (hue + 4)%256;
    for(int i=0; i<NUM_LEDS; i++) {
      leds[i].setHSV(hue%256, 255, 196);
    }
    FastLED.show();
    delay(20);
  }
  waitRound(secs, start);
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
