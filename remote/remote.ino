#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define DECODE_NEC
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

#define PIN 6
#define NUMPIXELS 16
#define OFF 0
#define RED 1
#define ORANGE 2
#define YELLOW 4
#define BRIGHTYELLOW 5
#define LIGHTGREEN 6
#define GREEN 8
#define TEAL 9
#define BLUE 10
#define LAVENDER 12
#define PURPLE 13
#define HOTPINK 14
#define PINK 16
#define WHITE 17
#define RAINBOW 18
#define RAINBOWGRADIENT 20
#define COOLGRADIENT 21
#define WARMGRADIENT 22
//#define          24
//#define          25
//#define          26
#define DELAYVAL 500
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t red = pixels.Color(255, 0, 0);
uint32_t orange = pixels.Color(255, 50, 0);
uint32_t yellow = pixels.Color(255, 100, 0);
uint32_t chartreuse = pixels.Color(190, 255, 47);
uint32_t green = pixels.Color(51, 255, 57);
uint32_t cyan = pixels.Color(0, 255, 255);
uint32_t blue = pixels.Color(0, 0, 255);
uint32_t lilac = pixels.Color(132, 19, 240);
uint32_t purple = pixels.Color(128, 0, 128);
uint32_t pink = pixels.Color(255, 80, 205);
uint32_t colors[] = { red, orange, yellow, chartreuse, green, cyan, blue, lilac, purple, pink };

int r;
int g;
int b;
int x;
int remoteValue;
int state;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to receive IR signals of protocols: "));
  Serial.println(F("at pin " STR(IR_RECEIVE_PIN)));
  pixels.begin();
}

void loop() {
  //Serial.println('a');
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      IrReceiver.printIRResultRawFormatted(&Serial, true);
      IrReceiver.resume();
      Serial.println('b');

    } else {
      remoteValue = IrReceiver.decodedIRData.command;
      Serial.println(remoteValue);
      state = remoteValue;
      Serial.println('c');


      IrReceiver.resume();

      Serial.println();
      Serial.println('d');
      Serial.println(state);

      
    }
  }
  delay(100);
  switch (state) {
        case RED:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 0, 0));
            pixels.show();
            delay(100);
          }
          break;

        case ORANGE:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 50, 0));
            pixels.show();
            delay(100);
          }
          break;

        case YELLOW:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 100, 0));
            pixels.show();
            delay(100);
          }
          break;
        case BRIGHTYELLOW:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 234, 0));
            pixels.show();
            delay(100);
          }
          break;

        case LIGHTGREEN:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(51, 255, 57));
            pixels.show();
            delay(100);
          }
          break;

        case GREEN:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(0, 255, 0));
            pixels.show();
            delay(100);
          }
          break;

        case TEAL:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(0, 128, 128));
            pixels.show();
            delay(100);
          }
          break;

        case BLUE:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(0, 0, 255));
            pixels.show();
            delay(100);
          }
          break;

        case LAVENDER:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(70, 51, 255));
            pixels.show();
            delay(100);
          }
          break;

        case PURPLE:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(132, 19, 240));
            pixels.show();
            delay(100);
          }
          break;

        case HOTPINK:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 0, 255));
            pixels.show();
            delay(100);
          }
          break;

        case PINK:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 80, 205));
            pixels.show();
            delay(100);
          }
          break;

        case WHITE:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(255, 255, 255));
            pixels.show();
            delay(100);
          }
          break;

        case RAINBOW:
          pixels.setPixelColor(0, pixels.Color(242, 133, 2));
          pixels.setPixelColor(1, pixels.Color(255, 213, 69));
          pixels.setPixelColor(2, pixels.Color(255, 193, 69));
          pixels.setPixelColor(3, pixels.Color(170, 255, 80));
          pixels.setPixelColor(4, pixels.Color(51, 255, 57));
          pixels.setPixelColor(5, pixels.Color(80, 255, 255));
          pixels.setPixelColor(6, pixels.Color(70, 51, 255));
          pixels.setPixelColor(7, pixels.Color(94, 69, 255));
          pixels.setPixelColor(8, pixels.Color(132, 19, 240));
          pixels.setPixelColor(9, pixels.Color(232, 69, 255));
          pixels.setPixelColor(10, pixels.Color(255, 80, 205));
          pixels.setPixelColor(11, pixels.Color(255, 69, 171));
          pixels.setPixelColor(12, pixels.Color(255, 123, 69));
          pixels.setPixelColor(13, pixels.Color(201, 6, 6));
          pixels.setPixelColor(14, pixels.Color(255, 0, 0));
          pixels.setPixelColor(15, pixels.Color(242, 64, 2));
          pixels.show();
          delay(100);
          break;

        case RAINBOWGRADIENT:
          for (int x = 0; x < 11; x++) {
            for (int i = 0; i < NUMPIXELS; i++) {
              pixels.setPixelColor(i, colors[x]);
              pixels.show();
              delay(100);
            }
          }
          break;

        case COOLGRADIENT:
          for (int x = 5; x < 10; x++) {
            for (int i = 0; i < NUMPIXELS; i++) {
              pixels.setPixelColor(i, colors[x]);
              pixels.show();
              delay(100);
            }
          }
          break;

        case WARMGRADIENT:
          for (int x = 0; x < 3; x++) {
            for (int i = 0; i < NUMPIXELS; i++) {
              pixels.setPixelColor(i, colors[x]);
              pixels.show();
              delay(100);
            }
          }
          break;

        case OFF:
          for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            pixels.show();
            delay(100);
          }
          break;
      }
}
