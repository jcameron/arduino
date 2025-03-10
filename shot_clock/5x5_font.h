/*------------------- FONT CUT TOP HERE -------------------------------*/

// A tiny 5x5 font from 
// https://jared.geek.nz/2014/jan/custom-fonts-for-microcontrollers
// Nice if you only have 5 strings, or if you want to connect something to the TX pin. 
// Connect LEDs to pins 2-6

#define ASCII_OFFSET (0x20)     // ASCII code of 1st char in font array
#define ASCII_NONPRINT (0x80)   // ASCII code of char to show for chars not included in the font (could also be a space)
#define FONT_WIDTH 6
uint8_t fontdata_5x5[95][5] =
{
    {
         0b00000000, // Character 32: ' '
         0b00000000,
         0b00000000,
         0b00000000,
         0b00000000
    },
    {
         0b00110000, // Character 33: '!'
         0b00110000,
         0b00110000,
         0b00000000,
         0b00110000
    },
    {
         0b11011000, // Character 34: '"'
         0b11011000,
         0b01001000,
         0b00000000,
         0b00000000
    },
    {
         0b01010000, // Character 35: '#'
         0b11111000,
         0b01010000,
         0b11111000,
         0b01010000
    },
    {
         0b11111000, // Character 36: '$'
         0b11100000,
         0b11111000,
         0b00111000,
         0b11110000
    },

    {
         0b11011000, // Character 37: '%'
         0b00110000,
         0b01100000,
         0b11011000,
         0b10011000
    },

    {
         0b01010000, // Character 38: '&'
         0b11111000,
         0b11010000,
         0b11011000,
         0b01101000
    },

    {
         0b00110000, // Character 39: '''
         0b00110000,
         0b00010000,
         0b00000000,
         0b00000000
    },

    {
         0b00011000, // Character 40: '('
         0b00110000,
         0b00110000,
         0b00110000,
         0b00011000
    },

    {
         0b11000000, // Character 41: ')'
         0b01100000,
         0b01100000,
         0b01100000,
         0b11000000
    },

    {
         0b11011000, // Character 42: '*'
         0b01110000,
         0b11111000,
         0b01110000,
         0b11011000
    },
// Character 43: '+'
    {
         0b00110000,
         0b00110000,
         0b11111100,
         0b00110000,
         0b00110000
    },
// Character 44: ','
    {
         0b00000000,
         0b00000000,
         0b00110000,
         0b00110000,
         0b01100000
    },
// Character 45: '-'
    {
         0b00000000,
         0b11111000,
         0b11111000,
         0b00000000,
         0b00000000
    },
// Character 46: '.'
    {
         0b00000000,
         0b00000000,
         0b00000000,
         0b00110000,
         0b00110000
    },
// Character 47: '/'
    {
         0b00001100,
         0b00011000,
         0b00110000,
         0b01100000,
         0b11000000
    },
// Character 48: '0'
    {
         0b01110000,
         0b11011000,
         0b11011000,
         0b11011000,
         0b01110000
    },
// Character 49: '1'
    {
         0b01110000,
         0b00110000,
         0b00110000,
         0b00110000,
         0b00110000
    },
// Character 50: '2'
    {
         0b01111000,
         0b00011000,
         0b11111000,
         0b11000000,
         0b11111000
    },
// Character 51: '3'
    {
         0b11111000,
         0b00011000,
         0b01111000,
         0b00011000,
         0b11111000
    },
// Character 52: '4'
    {
         0b01011000,
         0b11011000,
         0b11111000,
         0b00011000,
         0b00011000
    },
// Character 53: '5'
    {
         0b11111000,
         0b11000000,
         0b11111000,
         0b00011000,
         0b11111000
    },
// Character 54: '6'
    {
         0b11110000,
         0b11000000,
         0b11111000,
         0b11011000,
         0b11111000
    },
// Character 55: '7'
    {
         0b11111000,
         0b10011000,
         0b00011000,
         0b00011000,
         0b00011000
    },
// Character 56: '8'
    {
         0b01110000,
         0b11011000,
         0b11111000,
         0b11011000,
         0b01110000
    },
// Character 57: '9'
    {
         0b11111000,
         0b11011000,
         0b11111000,
         0b00011000,
         0b11111000
    },
// Character 58: ':'
    {
         0b00110000,
         0b00110000,
         0b00000000,
         0b00110000,
         0b00110000
    },
// Character 59: ';'
    {
         0b00110000,
         0b00000000,
         0b00110000,
         0b00110000,
         0b01100000
    },
// Character 60: '<'
    {
         0b00110000,
         0b01100000,
         0b11000000,
         0b01100000,
         0b00110000
    },
// Character 61: '='
    {
         0b11111000,
         0b11111000,
         0b00000000,
         0b11111000,
         0b11111000
    },
// Character 62: '>'
    {
         0b01100000,
         0b00110000,
         0b00011000,
         0b00110000,
         0b01100000
    },
// Character 63: '?'
    {
         0b11111000,
         0b00011000,
         0b01111000,
         0b00000000,
         0b01100000
    },
// Character 64: '@'
    {
         0b01110000,
         0b10001000,
         0b11101000,
         0b10101000,
         0b01101000
    },
// Character 65: 'A'
    {
         0b01110000,
         0b11111000,
         0b11011000,
         0b11111000,
         0b11011000
    },
// Character 66: 'B'
    {
         0b11110000,
         0b11011000,
         0b11110000,
         0b11011000,
         0b11111000
    },
// Character 67: 'C'
    {
         0b01111000,
         0b11000000,
         0b11000000,
         0b11111000,
         0b01111000
    },
// Character 68: 'D'
    {
         0b11110000,
         0b11111000,
         0b11011000,
         0b11011000,
         0b11110000
    },
// Character 69: 'E'
    {
         0b11111000,
         0b11000000,
         0b11110000,
         0b11000000,
         0b11111000
    },
// Character 70: 'F'
    {
         0b11111000,
         0b11000000,
         0b11110000,
         0b11000000,
         0b11000000
    },
// Character 71: 'G'
    {
         0b01111000,
         0b11000000,
         0b11111000,
         0b11001000,
         0b01110000
    },
// Character 72: 'H'
    {
         0b11011000,
         0b11011000,
         0b11111000,
         0b11011000,
         0b11011000
    },
// Character 73: 'I'
    {
         0b01110000,
         0b00100000,
         0b00100000,
         0b00100000,
         0b11111000
    },
// Character 74: 'J'
    {
         0b00111000,
         0b00011000,
         0b00011000,
         0b00111000,
         0b11110000
    },
// Character 75: 'K'
    {
         0b11011000,
         0b11110000,
         0b11110000,
         0b11011000,
         0b11011000
    },
// Character 76: 'L'
    {
         0b11000000,
         0b11000000,
         0b11000000,
         0b11111000,
         0b11111000
    },
// Character 77: 'M'
    {
         0b11011000,
         0b11111000,
         0b11111000,
         0b11011000,
         0b11011000
    },
// Character 78: 'N'
    {
         0b10011000,
         0b11011000,
         0b11111000,
         0b11111000,
         0b11011000
    },
// Character 79: 'O'
    {
         0b01110000,
         0b11111000,
         0b11011000,
         0b11011000,
         0b11111000
    },
// Character 80: 'P'
    {
         0b111100000,
         0b011011000,
         0b011110000,
         0b011000000,
         0b011000000
    },
// Character 81: 'Q'
    {
         0b11111000,
         0b11011000,
         0b11011000,
         0b11110000,
         0b11111000
    },
// Character 82: 'R'
    {
         0b11110000,
         0b11011000,
         0b11110000,
         0b11011000,
         0b11011000
    },
// Character 83: 'S'
    {
         0b01111000,
         0b11000000,
         0b11111000,
         0b00011000,
         0b11111000
    },
// Character 84: 'T'
    {
         0b01111000,
         0b01111000,
         0b00110000,
         0b00110000,
         0b00110000
    },
// Character 85: 'U'
    {
         0b11011000,
         0b11011000,
         0b11011000,
         0b11011000,
         0b11111000
    },
// Character 86: 'V'
    {
         0b11011000,
         0b11011000,
         0b11011000,
         0b01010000,
         0b00100000
    },
// Character 87: 'W'
    {
         0b11011000,
         0b11111000,
         0b11111000,
         0b11011000,
         0b10001000
    },
// Character 88: 'X'
    {
         0b11011000,
         0b01010000,
         0b01110000,
         0b01010000,
         0b11011000
    },
// Character 89: 'Y'
    {
         0b11011000,
         0b11011000,
         0b01111000,
         0b00011000,
         0b11111000
    },
// Character 90: 'Z'
    {
         0b11111000,
         0b00110000,
         0b01100000,
         0b11111000,
         0b11111000
    },
// Character 91: '['
    {
         0b00111000,
         0b00110000,
         0b00110000,
         0b00110000,
         0b00111000
    },
// Character 92: '\'
    {
         0b10000000,
         0b11000000,
         0b01100000,
         0b00110000,
         0b00001000
    },
// Character 93: ']'
    {
         0b11100000,
         0b01100000,
         0b01100000,
         0b01100000,
         0b11100000
    },
// Character 94: '^'
    {
         0b00100000,
         0b01110000,
         0b11011000,
         0b00000000,
         0b00000000
    },
// Character 95: '_'
    {
         0b00000000,
         0b00000000,
         0b00000000,
         0b11111000,
         0b11111000
    },
// Character 96: '`'
    {
         0b00110000,
         0b00011000,
         0b00000000,
         0b00000000,
         0b00000000
    },
// Character 97: 'a'
    {
         0b00000000,
         0b01111000,
         0b11011000,
         0b11011000,
         0b01111000
    },
// Character 98: 'b'
    {
         0b11000000,
         0b11000000,
         0b11110000,
         0b11011000,
         0b11011000
    },
// Character 99: 'c'
    {
         0b00000000,
         0b01111000,
         0b11000000,
         0b11000000,
         0b01111000
    },
// Character 100: 'd'
    {
         0b00011000,
         0b00011000,
         0b01111000,
         0b11011000,
         0b11011000
    },
// Character 101: 'e'
    {
         0b01110000,
         0b11011000,
         0b11111000,
         0b11000000,
         0b01111000
    },
// Character 102: 'f'
    {
         0b00111000,
         0b01100000,
         0b01100000,
         0b01110000,
         0b01100000
    },
// Character 103: 'g'
    {
         0b01111000,
         0b11011000,
         0b11111000,
         0b00011000,
         0b11110000
    },
// Character 104: 'h'
    {
         0b11000000,
         0b11000000,
         0b11110000,
         0b11011000,
         0b11011000
    },
// Character 105: 'i'
    {
         0b00110000,
         0b00000000,
         0b00110000,
         0b00110000,
         0b00110000
    },
// Character 106: 'j'
    {
         0b00110000,
         0b00000000,
         0b00110000,
         0b00110000,
         0b11100000
    },
// Character 107: 'k'
    {
         0b11000000,
         0b11011000,
         0b11110000,
         0b11110000,
         0b11011000
    },
// Character 108: 'l'
    {
         0b01100000,
         0b01100000,
         0b01100000,
         0b01100000,
         0b00110000
    },
// Character 109: 'm'
    {
         0b00000000,
         0b01010000,
         0b11111000,
         0b11111000,
         0b11011000
    },
// Character 110: 'n'
    {
         0b00000000,
         0b11110000,
         0b11011000,
         0b11011000,
         0b11011000
    },
// Character 111: 'o'
    {
         0b00000000,
         0b01110000,
         0b11011000,
         0b11011000,
         0b01110000
    },
// Character 112: 'p'
    {
         0b00000000,
         0b11110000,
         0b11011000,
         0b11110000,
         0b11000000
    },
// Character 113: 'q'
    {
         0b00000000,
         0b01111000,
         0b11011000,
         0b01111000,
         0b00011000
    },
// Character 114: 'r'
    {
         0b00000000,
         0b01110000,
         0b11011000,
         0b11000000,
         0b11000000
    },
// Character 115: 's'
    {
         0b01111000,
         0b11000000,
         0b11111000,
         0b00011000,
         0b11110000
    },
// Character 116: 't'
    {
         0b01100000,
         0b11111000,
         0b01100000,
         0b01100000,
         0b00111000
    },
// Character 117: 'u'
    {
         0b00000000,
         0b11011000,
         0b11011000,
         0b11011000,
         0b01111000
    },
// Character 118: 'v'
    {
         0b00000000,
         0b11011000,
         0b11011000,
         0b01110000,
         0b00100000
    },
// Character 119: 'w'
    {
         0b00000000,
         0b11011000,
         0b11111000,
         0b11111000,
         0b01010000
    },
// Character 120: 'x'
    {
         0b00000000,
         0b11011000,
         0b01110000,
         0b11111000,
         0b11011000
    },
// Character 121: 'y'
    {
         0b00000000,
         0b11011000,
         0b11111000,
         0b00011000,
         0b11110000
    },
// Character 122: 'z'
    {
         0b00000000,
         0b11111000,
         0b00110000,
         0b01100000,
         0b11111000
    },
// Character 123: '{'
    {
         0b00011000,
         0b00110000,
         0b01110000,
         0b00110000,
         0b00011000
    },
// Character 124: '|'
    {
         0b00110000,
         0b00110000,
         0b00110000,
         0b00110000,
         0b00110000
    },
// Character 125: '}'
    {
         0b11000000,
         0b01100000,
         0b01110000,
         0b01100000,
         0b11000000
    },
// Character 126: '~'
    {
         0b00000000,
         0b01101000,
         0b10110000,
         0b00000000,
         0b00000000
    },

};


byte old_fontdata_5x5[][FONT_WIDTH] PROGMEM = {
    { // ASCII 0x20 (' ')
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x21 ('!')
       0b01110100,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x22 ('"')
       0b11000000,
       0b00000000,
       0b11000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x23 ('#')
       0b00101000,
       0b01111100,
       0b00101000,
       0b01111100,
       0b00101000,
       0b00000000,
    },
    { // ASCII 0x24 ('$')
       0b01110100,
       0b01010100,
       0b11111110,
       0b01010100,
       0b01011100,
       0b00000000,
    },
    { // ASCII 0x25 ('%')
       0b01000100,
       0b00001000,
       0b00010000,
       0b00100000,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x26 ('&')
       0b00101000,
       0b01010100,
       0b01010100,
       0b00001000,
       0b00010100,
       0b00000000,
    },
    { // ASCII 0x27 (''')
       0b11000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x28 ('(')
       0b00111000,
       0b01000100,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x29 (')')
       0b01000100,
       0b00111000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x2A ('*')
       0b10000000,
       0b11000000,
       0b10000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x2B ('+')
       0b00010000,
       0b00010000,
       0b01111100,
       0b00010000,
       0b00010000,
       0b00000000,
    },
    { // ASCII 0x2C (',')
       0b00000110,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x2D ('-')
       0b00010000,
       0b00010000,
       0b00010000,
       0b00010000,
       0b00010000,
       0b00000000,
    },
    { // ASCII 0x2E ('.')
       0b00000100,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x2F ('/')
       0b00001100,
       0b00010000,
       0b01100000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x30 ('0')
       0b01111100,
       0b01001100,
       0b01010100,
       0b01100100,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x31 ('1')
       0b00100100,
       0b01111100,
       0b00000100,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x32 ('2')
       0b01001100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b00100100,
       0b00000000,
    },
    { // ASCII 0x33 ('3')
       0b01000100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01101100,
       0b00000000,
    },
    { // ASCII 0x34 ('4')
       0b01111000,
       0b00001000,
       0b00011100,
       0b00001000,
       0b00001000,
       0b00000000,
    },
    { // ASCII 0x35 ('5')
       0b01110100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01001000,
       0b00000000,
    },
    { // ASCII 0x36 ('6')
       0b01111100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01011100,
       0b00000000,
    },
    { // ASCII 0x37 ('7')
       0b01000000,
       0b01000000,
       0b01001100,
       0b01010000,
       0b01100000,
       0b00000000,
    },
    { // ASCII 0x38 ('8')
       0b01111100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x39 ('9')
       0b01110100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x3A (':')
       0b01000100,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x3B (';')
       0b01000110,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x3C ('<')
       0b00010000,
       0b00101000,
       0b01000100,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x3D ('=')
       0b00101000,
       0b00101000,
       0b00101000,
       0b00101000,
       0b00101000,
       0b00000000,
    },
    { // ASCII 0x3E ('>')
       0b01000100,
       0b00101000,
       0b00010000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x3F ('?')
       0b00100000,
       0b01000000,
       0b01010100,
       0b00100000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x40 ('@')
       0b01111100,
       0b01000100,
       0b01010100,
       0b01010100,
       0b01110100,
       0b00000000,
    },
    { // ASCII 0x41 ('A')
       0b01111100,
       0b01001000,
       0b01001000,
       0b01001000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x42 ('B')
       0b01111100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01101100,
       0b00000000,
    },
    { // ASCII 0x43 ('C')
       0b01111100,
       0b01000100,
       0b01000100,
       0b01000100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x44 ('D')
       0b01111100,
       0b01000100,
       0b01000100,
       0b01000100,
       0b00111000,
       0b00000000,
    },
    { // ASCII 0x45 ('E')
       0b01111100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x46 ('F')
       0b01111100,
       0b01010000,
       0b01010000,
       0b01010000,
       0b01000000,
       0b00000000,
    },
    { // ASCII 0x47 ('G')
       0b01111100,
       0b01000100,
       0b01000100,
       0b01010100,
       0b01011100,
       0b00000000,
    },
    { // ASCII 0x48 ('H')
       0b01111100,
       0b00010000,
       0b00010000,
       0b00010000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x49 ('I')
       0b01000100,
       0b01000100,
       0b01111100,
       0b01000100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x4A ('J')
       0b00001100,
       0b00000100,
       0b00000100,
       0b01000100,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x4B ('K')
       0b01111100,
       0b00010000,
       0b00010000,
       0b00101000,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x4C ('L')
       0b01111100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b00000000,
    },
    { // ASCII 0x4D ('M')
       0b01111100,
       0b00100000,
       0b00010000,
       0b00100000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x4E ('N')
       0b01111100,
       0b00100000,
       0b00010000,
       0b00001000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x4F ('O')
       0b00111000,
       0b01000100,
       0b01000100,
       0b01000100,
       0b00111000,
       0b00000000,
    },
    { // ASCII 0x50 ('P')
       0b01111100,
       0b01010000,
       0b01010000,
       0b01010000,
       0b00100000,
       0b00000000,
    },
    { // ASCII 0x51 ('Q')
       0b01111000,
       0b01001000,
       0b01001100,
       0b01001000,
       0b01111000,
       0b00000000,
    },
    { // ASCII 0x52 ('R')
       0b01111100,
       0b01010000,
       0b01010000,
       0b01010000,
       0b00101100,
       0b00000000,
    },
    { // ASCII 0x53 ('S')
       0b01110100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01011100,
       0b00000000,
    },
    { // ASCII 0x54 ('T')
       0b01000000,
       0b01000000,
       0b01111100,
       0b01000000,
       0b01000000,
       0b00000000,
    },
    { // ASCII 0x55 ('U')
       0b01111100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x56 ('V')
       0b01100000,
       0b00011000,
       0b00000100,
       0b00011000,
       0b01100000,
       0b00000000,
    },
    { // ASCII 0x57 ('W')
       0b01111000,
       0b00000100,
       0b00011000,
       0b00000100,
       0b01111000,
       0b00000000,
    },
    { // ASCII 0x58 ('X')
       0b01000100,
       0b00101000,
       0b00010000,
       0b00101000,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x59 ('Y')
       0b01100000,
       0b00010000,
       0b00001100,
       0b00010000,
       0b01100000,
       0b00000000,
    },
    { // ASCII 0x5A ('Z')
       0b01000100,
       0b01001100,
       0b01010100,
       0b01100100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x5B ('[')
       0b01111100,
       0b01000100,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x5C ('\')
       0b01100000,
       0b00010000,
       0b00001100,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x5D (']')
       0b01000100,
       0b01111100,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x5E ('^')
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x5F ('_')
       0b00000100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b00000100,
    },
    { // ASCII 0x60 ('`')
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x61 ('a')
       0b01111100,
       0b01001000,
       0b01001000,
       0b01001000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x62 ('b')
       0b01111100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01101100,
       0b00000000,
    },
    { // ASCII 0x63 ('c')
       0b01111100,
       0b01000100,
       0b01000100,
       0b01000100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x64 ('d')
       0b01111100,
       0b01000100,
       0b01000100,
       0b01000100,
       0b00111000,
       0b00000000,
    },
    { // ASCII 0x65 ('e')
       0b01111100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x66 ('f')
       0b01111100,
       0b01010000,
       0b01010000,
       0b01010000,
       0b01000000,
       0b00000000,
    },
    { // ASCII 0x67 ('g')
       0b01111100,
       0b01000100,
       0b01000100,
       0b01010100,
       0b01011100,
       0b00000000,
    },
    { // ASCII 0x68 ('h')
       0b01111100,
       0b00010000,
       0b00010000,
       0b00010000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x69 ('i')
       0b01000100,
       0b01000100,
       0b01111100,
       0b01000100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x6A ('j')
       0b00001100,
       0b00000100,
       0b00000100,
       0b01000100,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x6B ('k')
       0b01111100,
       0b00010000,
       0b00010000,
       0b00101000,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x6C ('l')
       0b01111100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b00000000,
    },
    { // ASCII 0x6D ('m')
       0b01111100,
       0b00100000,
       0b00010000,
       0b00100000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x6E ('n')
       0b01111100,
       0b00100000,
       0b00010000,
       0b00001000,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x6F ('o')
       0b00111000,
       0b01000100,
       0b01000100,
       0b01000100,
       0b00111000,
       0b00000000,
    },
    { // ASCII 0x70 ('p')
       0b01111100,
       0b01010000,
       0b01010000,
       0b01010000,
       0b00100000,
       0b00000000,
    },
    { // ASCII 0x71 ('q')
       0b01111000,
       0b01001000,
       0b01001100,
       0b01001000,
       0b01111000,
       0b00000000,
    },
    { // ASCII 0x72 ('r')
       0b01111100,
       0b01010000,
       0b01010000,
       0b01010000,
       0b00101100,
       0b00000000,
    },
    { // ASCII 0x73 ('s')
       0b01110100,
       0b01010100,
       0b01010100,
       0b01010100,
       0b01011100,
       0b00000000,
    },
    { // ASCII 0x74 ('t')
       0b01000000,
       0b01000000,
       0b01111100,
       0b01000000,
       0b01000000,
       0b00000000,
    },
    { // ASCII 0x75 ('u')
       0b01111100,
       0b00000100,
       0b00000100,
       0b00000100,
       0b01111100,
       0b00000000,
    },
    { // ASCII 0x76 ('v')
       0b01100000,
       0b00011000,
       0b00000100,
       0b00011000,
       0b01100000,
       0b00000000,
    },
    { // ASCII 0x77 ('w')
       0b01111000,
       0b00000100,
       0b00011000,
       0b00000100,
       0b01111000,
       0b00000000,
    },
    { // ASCII 0x78 ('x')
       0b01000100,
       0b00101000,
       0b00010000,
       0b00101000,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x79 ('y')
       0b01100000,
       0b00010000,
       0b00001100,
       0b00010000,
       0b01100000,
       0b00000000,
    },
    { // ASCII 0x7A ('z')
       0b01000100,
       0b01001100,
       0b01010100,
       0b01100100,
       0b01000100,
       0b00000000,
    },
    { // ASCII 0x7B ('{')
       0b00010000,
       0b01111100,
       0b01000100,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x7C ('|')
       0b01101100,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x7D ('}')
       0b01000100,
       0b01111100,
       0b00010000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
    { // ASCII 0x7E ('~')
       0b10000000,
       0b00000000,
       0b10000000,
       0b00000000,
       0b00000000,
       0b00000000,
    },
};