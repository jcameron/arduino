int snowman_width = 11;
int snowman_height = 17;
CRGB snowman[17][11] = {
  {CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(8, 36, 85), CRGB(230, 67, 47), CRGB(230, 67, 47), CRGB(8, 36, 85), CRGB(8, 36, 85), CRGB(9, 36, 85), },
  {CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(6, 35, 84), CRGB(6, 35, 84), CRGB(29, 171, 75), CRGB(231, 67, 47), CRGB(230, 67, 47), CRGB(230, 67, 47), CRGB(230, 67, 47), CRGB(231, 66, 46), CRGB(6, 35, 84), },
  {CRGB(9, 36, 85), CRGB(4, 34, 84), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(28, 171, 75), CRGB(231, 67, 47), CRGB(230, 67, 47), CRGB(231, 66, 46), CRGB(255, 255, 255), CRGB(255, 255, 255), },
  {CRGB(9, 36, 85), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(27, 171, 75), CRGB(231, 67, 47), CRGB(6, 35, 84), CRGB(255, 255, 255), CRGB(255, 255, 255), },
  {CRGB(0, 35, 85), CRGB(255, 255, 255), CRGB(0, 0, 0), CRGB(255, 255, 255), CRGB(0, 0, 0), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(26, 171, 74), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(247, 148, 33), CRGB(246, 147, 28), CRGB(246, 147, 28), CRGB(246, 147, 28), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(9, 36, 85), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(9, 36, 85), CRGB(0, 36, 85), CRGB(230, 67, 47), CRGB(230, 67, 47), CRGB(230, 67, 47), CRGB(229, 67, 47), CRGB(229, 67, 47), CRGB(0, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(9, 36, 85), CRGB(229, 67, 47), CRGB(229, 67, 47), CRGB(229, 67, 47), CRGB(229, 67, 47), CRGB(228, 67, 47), CRGB(228, 67, 47), CRGB(229, 67, 47), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(13, 40, 88), CRGB(253, 253, 254), CRGB(250, 251, 251), CRGB(253, 253, 253), CRGB(253, 253, 251), CRGB(228, 69, 52), CRGB(228, 67, 47), CRGB(253, 251, 251), CRGB(13, 40, 88), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(253, 253, 254), CRGB(250, 250, 250), CRGB(19, 21, 25), CRGB(253, 253, 253), CRGB(253, 225, 44), CRGB(252, 253, 253), CRGB(228, 67, 47), CRGB(228, 66, 47), CRGB(253, 253, 253), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(253, 253, 254), CRGB(0, 0, 0), CRGB(253, 253, 253), CRGB(253, 253, 253), CRGB(253, 252, 250), CRGB(252, 253, 253), CRGB(228, 74, 60), CRGB(228, 74, 59), CRGB(253, 253, 253), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(253, 253, 254), CRGB(38, 39, 42), CRGB(253, 253, 254), CRGB(253, 253, 253), CRGB(253, 225, 55), CRGB(253, 253, 253), CRGB(253, 253, 253), CRGB(253, 253, 253), CRGB(253, 253, 254), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(250, 250, 251), CRGB(253, 254, 254), CRGB(253, 254, 254), CRGB(253, 254, 254), CRGB(253, 254, 254), CRGB(253, 253, 254), CRGB(253, 253, 254), CRGB(253, 254, 254), CRGB(250, 250, 251), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(9, 36, 85), CRGB(250, 250, 250), CRGB(255, 255, 255), CRGB(255, 255, 255), CRGB(254, 255, 255), CRGB(254, 254, 255), CRGB(254, 254, 255), CRGB(250, 250, 250), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  {CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(250, 250, 250), CRGB(249, 249, 250), CRGB(249, 249, 250), CRGB(249, 249, 250), CRGB(249, 249, 250), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), CRGB(9, 36, 85), },
  };
