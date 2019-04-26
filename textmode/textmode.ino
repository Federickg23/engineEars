/******************************************************************
 This is an example for the Adafruit RA8875 Driver board for TFT displays
 ---------------> http://www.adafruit.com/products/1590
 The RA8875 is a TFT driver for up to 800x480 dotclock'd displays
 It is tested to work with displays in the Adafruit shop. Other displays
 may need timing adjustments and are not guanteed to work.

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source hardware
 by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries.
 BSD license, check license.txt for more information.
 All text above must be included in any redistribution.
 ******************************************************************/


#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"

// Library only supports hardware SPI at this time
// Connect SCLK to UNO Digital #13 (Hardware SPI clock)
// Connect MISO to UNO Digital #12 (Hardware SPI MISO)
// Connect MOSI to UNO Digital #11 (Hardware SPI MOSI)
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9

Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;


const int buttonPin1 = 4;     // the number of the pushbutton pin
const int buttonPin2 = 5;     // the number of the pushbutton pin
const int buttonPin3 = 6;     // the number of the pushbutton pin
const int buttonPin4 = 7;     // the number of the pushbutton pin

int buttonState1 = LOW;
int buttonState2 = LOW;
int buttonState3 = LOW;
int buttonState4 = LOW;
int lastButtonState1 = LOW;   
int lastButtonState2 = LOW;   
int lastButtonState3 = LOW;   
int lastButtonState4 = LOW;   

bool isPushed1 = false;
bool isPushed2 = false;
bool isPushed3 = false;
bool isPushed4 = false;

void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  digitalWrite(buttonPin1, LOW);
  digitalWrite(buttonPin2, LOW);
  digitalWrite(buttonPin3, LOW);
  digitalWrite(buttonPin4, LOW);
  Serial.begin(9600);
  Serial.println("RA8875 start");

  /* Initialize the display using 'RA8875_480x80', 'RA8875_480x128', 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_800x480)) {
    Serial.println("RA8875 Not Found!");
    while (1);
  }

  tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);
  tft.fillScreen(RA8875_BLACK);

  /* Switch to text mode */
  tft.textMode();
  tft.cursorBlink(32);


  /* Set a solid for + bg color ... */

  /* ... or a fore color plus a transparent background */


  /* Set the cursor location (in pixels) */
  tft.textSetCursor(10, 10);

  /* Render some text! */
  char string[15] = "Hello, World! ";
  tft.textTransparent(RA8875_WHITE);
  tft.textWrite(string);
  tft.textColor(RA8875_WHITE, RA8875_RED);
  tft.textWrite(string);
  tft.textTransparent(RA8875_CYAN);
  tft.textWrite(string);
  tft.textTransparent(RA8875_GREEN);
  tft.textWrite(string);
  tft.textColor(RA8875_YELLOW, RA8875_CYAN);
  tft.textWrite(string);
  tft.textColor(RA8875_BLACK, RA8875_MAGENTA);
  tft.textWrite(string);

  /* Change the cursor location and color ... */
  tft.textSetCursor(100, 100);
  tft.textTransparent(RA8875_RED);
  /* If necessary, enlarge the font */
  tft.textEnlarge(1);
  /* ... and render some more text! */
  tft.textWrite(string);
  tft.textSetCursor(100, 150);
  tft.textEnlarge(2);
  tft.textWrite(string);
}

void loop()
{

  tft.textMode();
  if(digitalRead(buttonPin1)== HIGH){
    isPushed1 = true;
  }
  if(digitalRead(buttonPin2)== HIGH){
    isPushed2 = true;
  }
  if(digitalRead(buttonPin3)== HIGH){
    isPushed3 = true;
  }
  if(digitalRead(buttonPin4)== HIGH){
    isPushed4 = true;
  }
  if (isPushed1) {
    tft.textWrite("Red ");
    delay(50);
  }
  else if (isPushed2) {
    
    tft.textWrite("Blue ");
    delay(50);
  }
  else if (isPushed3) {
    tft.textWrite("Green");
    delay(50);
  }
  else if (isPushed4) {
    tft.textWrite("Yellow");
    delay(50);
  }

  
  
}
