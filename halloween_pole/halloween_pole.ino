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
  showTwinkle(120);
  //purpleOrange(30);
  //showTrail(30);
}

void zeroLeds() {
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(100);
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

// Shades of red bars
void purpleOrange(int secs) {
  zeroLeds();
  long start = millis();
  int offset = 0;
  while(millis() - start < secs*1000) {
    for(int i=0; i<NUM_LEDS; i++) {
      int p = i%10;
      CRGB c = p<5 ? CRGB(255,0,255) : CRGB(255, 200, 0);
      leds[(i+offset)%NUM_LEDS] = c;
    }
    FastLED.show();
    FastLED.delay(100);
    offset++;
  }
  waitRound(secs, start);
}

// Fading green trail that moves down
void showTrail(int secs) {
  zeroLeds();
  long start = millis();
  int len = 50;
  int offset = NUM_LEDS - len - 1;   // Tail of the trail
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
        leds[i] = oneColor(c, 1);
      }
    }
    offset--;
    if (offset < 0) {
      offset = NUM_LEDS - len - 1;
    }
    FastLED.show();
    delay(2);
  }
  waitRound(secs, start);
}

// Show twinkling purple stars
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
        if (b == 0) {
          leds[s] = CRGB(0, 0, 0);
        } else {
          leds[s] = CRGB(b, 0, b);
        }
      }
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
