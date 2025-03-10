#include <FastLED.h>
#include "font8x8_basic.h"
#include "icons.h"
#define NUM_ROWS 20
#define NUM_LEDS 59
#define STARS 100
#define NUM_SNAKES 2

CRGB leds[NUM_ROWS][NUM_LEDS];

#define NUM_MESSAGES 5
char *messages[] = {
  "Happy Halloween",
  "Halloween 2024!",
  "Trick or Treat!",
  "Spoooooooooky",
  "Yes, We Have Candy",
};

#define NUM_ZOOMS 1
char *zooms[] = {
  "BOO!",
};

void setup() {
  delay(1000);
  FastLED.addLeds<WS2812, 0, GRB>(leds[0], NUM_LEDS);
  FastLED.addLeds<WS2812, 1, GRB>(leds[1], NUM_LEDS);
  FastLED.addLeds<WS2812, 2, GRB>(leds[2], NUM_LEDS);
  FastLED.addLeds<WS2812, 3, GRB>(leds[3], NUM_LEDS);
  FastLED.addLeds<WS2812, 4, GRB>(leds[4], NUM_LEDS);
  FastLED.addLeds<WS2812, 5, GRB>(leds[5], NUM_LEDS);
  FastLED.addLeds<WS2812, 6, GRB>(leds[6], NUM_LEDS);
  FastLED.addLeds<WS2812, 7, GRB>(leds[7], NUM_LEDS);
  FastLED.addLeds<WS2812, 8, GRB>(leds[8], NUM_LEDS);
  FastLED.addLeds<WS2812, 9, GRB>(leds[9], NUM_LEDS);
  FastLED.addLeds<WS2812, 10, GRB>(leds[10], NUM_LEDS);
  FastLED.addLeds<WS2812, 11, GRB>(leds[11], NUM_LEDS);
  FastLED.addLeds<WS2812, 12, GRB>(leds[12], NUM_LEDS);
  FastLED.addLeds<WS2812, 13, GRB>(leds[13], NUM_LEDS);
  FastLED.addLeds<WS2812, 14, GRB>(leds[14], NUM_LEDS);
  FastLED.addLeds<WS2812, 15, GRB>(leds[15], NUM_LEDS);
  FastLED.addLeds<WS2812, 16, GRB>(leds[16], NUM_LEDS);
  FastLED.addLeds<WS2812, 17, GRB>(leds[17], NUM_LEDS);
  FastLED.addLeds<WS2812, 18, GRB>(leds[18], NUM_LEDS);
  FastLED.addLeds<WS2812, 19, GRB>(leds[19], NUM_LEDS);
  FastLED.setBrightness(127);
}

void loop() {
  renderStars(30);
  renderMerryChristmas(30);
  //renderPong(15);
  renderZoom(20);
  renderMessages(60);
  //renderBigMerryChristmas(30);
}

// Twinkle some stars
void renderStars(int secs) {
  zeroLeds();
  long start = millis();
  short starsx[STARS];
  short starsy[STARS];
  short starsc[STARS];
  for(int i=0; i<STARS; i++) {
    starsx[i] = starsy[i] = -1;
    starsc[i] = 0;
  }
  while(millis() - start < secs*1000) {
    // Create random stars where needed
    for(int i=0; i<STARS; i++) {
      if (starsx[i] < 0 && random(0, 10) < 5) {
        starsx[i] = random(0, NUM_LEDS);
        starsy[i] = random(0, NUM_ROWS);
        starsc[i] = 0;
      }
    }
    // Fade them up and down
    for(int i=0; i<STARS; i++) {
      int sx = starsx[i];
      int sy = starsy[i];
      if (sx >= 0) {
        int b = starsc[i];
        b += 8 + (i%8);
        if (b >= 255) {
          // End of life
          b = 0;
          starsx[i] = starsy[i] = -1;
        }
        leds[sy][sx] = CRGB(b, 0, b);
        starsc[i] = b;
      }
    }
    FastLED.show();
    delay(20);
  }
}

void shadeLeds(int r, int g, int b) {
  for(int i=0; i<NUM_ROWS; i++) {
    for(int j=0; j<NUM_LEDS; j++) {
      int c = (i + j) / 2 + 5;
      leds[i][j] = CRGB(r*c, g*c, b*c);
    }
  }
}

// Render two scrolling messages
void renderMerryChristmas(int secs) {
  long start = millis();
  int offset = 0;
  char *msg1 = "  HAPPY  ";
  int msglen1 = (int)strlen(msg1)*8;
  char *msg2 = "HALLOWEEN";
  int msglen2 = (int)strlen(msg2)*8;
  while(millis() - start < secs*1000) {
    shadeLeds(0, 0, 0);
    renderString(msg1, offset, 2, 1);
    renderString(msg2, NUM_LEDS-offset-msglen2, 11, 1);
    offset--;
    if (offset < -msglen1) {
      offset = NUM_LEDS;
    }
    delay(50);
    FastLED.show();
  }
}

// Render one scrolling message
void renderBigMerryChristmas(int secs) {
  long start = millis();
  int offset = 0;
  while(millis() - start < secs*1000) {
    shadeLeds(1, 0, 0);
    char *msg = "Gong Xi Fa Cai";
    int msglen = (int)strlen(msg)*16;
    renderString(msg, offset, 2, 2);
    offset--;
    if (offset < -msglen) {
      offset = NUM_LEDS;
    }
    delay(25);
    FastLED.show();
  }
}

// Scroll through several messages
void renderMessages(int secs) {
  long start = millis();
  int offset = NUM_LEDS;
  char *msg;
  while(millis() - start < secs*1000) {
    if (offset == NUM_LEDS) {
      msg = messages[random(0, NUM_MESSAGES)];
    }
    shadeLeds(0, 0, 0);
    //renderIcon((CRGB*)snowman, snowman_width, snowman_height, 25, 2);
    renderString(msg, offset, 7, 1);
    offset--;
    int len = (int)strlen(msg) * 8;
    if (offset < -len) {
      offset = NUM_LEDS;
    }
    delay(20);
    FastLED.show();
  }
}

// Render a game of Pong, with bats
void renderPong(int secs) {
  long start = millis();
  int x = NUM_LEDS/2, y = NUM_ROWS/2;
  int dx = 1, dy = 1;
  int b1 = NUM_ROWS / 2;
  int b2 = NUM_ROWS / 2;
  while(millis() - start < secs*1000) {
    zeroLeds();
    x += dx;
    y += dy;
    if (x < 2 || x > NUM_LEDS-3) {
      dx = -dx;
    }
    if (y < 2 || y > NUM_ROWS-3) {
      dy = -dy;
    }
    // Draw message
    renderColorString("PONG!", 10, 7, 1, CRGB::Blue);
    
    // Draw the ball
    leds[y-1][x] = leds[y+1][x] = CRGB(64, 64, 64);
    leds[y][x-1] = leds[y][x+1] = CRGB(64, 64, 64);
    leds[y-1][x-1] = leds[y+1][x-1] = CRGB(16, 16, 16);
    leds[y-1][x+1] = leds[y+1][x+1] = CRGB(16, 16, 16);
    leds[y][x] = CRGB::White;

    // Draw the bats
    if (x < NUM_LEDS / 2) {
      b1 = y;
    }
    if (x > NUM_LEDS / 2) {
      b2 = y;
    }
    for(int i=0; i<NUM_ROWS; i++) {
      if (i >= b1-3 && i <= b1+3) {
        leds[i][0] = CRGB::Red;
        leds[i][1] = CRGB::Red;
      }
      if (i >= b2-3 && i <= b2+3) {
        leds[i][NUM_LEDS-1] = CRGB::Green;
        leds[i][NUM_LEDS-2] = CRGB::Green;
      }
    }
    delay(25);
    FastLED.show();
  }
}

// Zoom some messages from small to big
void renderZoom(int secs) {
  long start = millis();
  float size = 0.1;
  int n = 0;
  while(millis() - start < secs*1000) {
    char *msg = zooms[n];
    shadeLeds(0, 0, 0);
    int w = (int)(strlen(msg) * 8 * size);
    int h = (int)(8 * size);
    renderColorString(msg, (NUM_LEDS - w)/2, (NUM_ROWS - h)/2, size, CRGB(128, 128, 128));
    size *= 1.1;
    if (size > 2.5) {
      // Too big, next message
      size = 0.1;
      n++;
      if (n == NUM_ZOOMS) {
        // Reached the end, exit here
        delay(2000);
        return;
        n = 0;
      }
    }
    delay(50);
    FastLED.show();
  }
}

void zeroLeds() {
  for(int i=0; i<NUM_ROWS; i++) {
    for(int j=0; j<NUM_LEDS; j++) {
      leds[i][j] = CRGB(0, 0, 0);
    }
  }
}

void renderString(char *s, int x, int y, float scale) {
  for(int i=0; s[i]; i++) {
    CRGB col = i%2 ? CRGB::Purple : CRGB::Orange;
    renderChar(s[i], x+i*8*scale, y, col, scale);
  }
}

void renderColorString(char *s, int x, int y, float scale, CRGB col) {
  for(int i=0; s[i]; i++) {
    renderChar(s[i], x+i*8*scale, y, col, scale);
  }
}

void renderChar(char c, int x, int y, CRGB col, float scale) {
  char *bm = font8x8_basic[c];
  for(int i=0; i<8*scale; i++) {
    for(int j=0; j<8*scale; j++) {
      int xx = i + x;
      int yy = j + y;
      if (xx >= 0 && xx < NUM_LEDS && yy >= 0 && yy <= NUM_ROWS) {
        if (bm[(int)(j/scale)] & (1<<((int)(i/scale)))) {
          leds[yy][xx] = col;
        }
      }
    }
  }
}

// Show one icon from a bitmap
void renderIcon(CRGB *icon, int w, int h, int x, int y) {
  for(int i=0; i<w; i++) {
    for(int j=0; j<h; j++) {
      int xx = i + x;
      int yy = j + y;
      if (xx >= 0 && xx < NUM_LEDS && yy >= 0 && yy <= NUM_ROWS) {
        leds[yy][xx] = icon[j*w + i];
      }
    }
  }
}
