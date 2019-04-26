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

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;

const int buttonPin1 = 4;     // the number of the pushbutton pin
const int buttonPin2 = 5;     // the number of the pushbutton pin
const int buttonPin3 = 6;     // the number of the pushbutton pin
const int buttonPin4 = 7;     // the number of the pushbutton pin

const int speaker = 2;
const int pitches[] = { 1, 2, 3, 4, 5 };
const int tones[] = { 100, 200, 300, 400 };

//Not currently using these
volatile int buttonState1 = LOW;
volatile int buttonState2 = LOW;
volatile int buttonState3 = LOW;
volatile int buttonState4 = LOW;
//int lastButtonState1 = LOW;   
//int lastButtonState2 = LOW;   
//int lastButtonState3 = LOW;   
//int lastButtonState4 = LOW;   
//////////////////////////

//bool isPushed1 = false;
//bool isPushed2 = false;
//bool isPushed3 = false;
//bool isPushed4 = false;

int randomNum = 0;
int xPos = 20;
int val = 19;
int width = 150;
int playerY = tft.height();
int max  = 0;

void setup()
{
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode (speaker,OUTPUT);
  digitalWrite(buttonPin1, LOW);
  digitalWrite(buttonPin2, LOW);
  digitalWrite(buttonPin3, LOW);
  digitalWrite(buttonPin4, LOW);
  Serial.begin(9600);
  Serial.println("RA8875 starts");

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
  tft.textMode();

}

void loop()
{
//  Serial.println(val);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  if(buttonState1 == HIGH){
    Serial.println("Red is pressed");         
    
  }
  else{
    Serial.println("Red is not pressed.");
  }
  if(buttonState2 == HIGH){
    Serial.println("Blue is pressed");
  }
  else{
    Serial.println("Blue is not pressed.");
  }
  if(buttonState3 == HIGH){
    Serial.println("Green is pressed");
  }
  else{
    Serial.println("Green is not pressed.");
  }
  if(buttonState4 == HIGH){
    Serial.println("Yellow is pressed");
  }
  else{
    Serial.println("Yellow is not pressed.");
  }
    
    if(val++ == 20){
      width = 150;
      randomNum = random(4);
      Serial.println("randomNum");
      Serial.println(randomNum);
      val = 0;
      xPos = 200;
      playTone(tones[randomNum], 500);
      drawBlock(randomNum, xPos, width);
      drawPlayer(playerY);
      playerY = tft.height();
      max = tft.height()- 150*randomNum;
    }
    else{
      Serial.println("playerY");
      Serial.println(playerY);
      if(val <=10){
        playerY = playerY - max/10;
        drawPlayer(playerY);
      }\
      else{
        playerY = playerY + max/10;
        drawPlayer(playerY); 
      }
      xPos-=20;
      if(xPos > 21){
        
      drawBlock(randomNum, xPos, width);
      }
      else if(val < 16){
        width = width -20;
        if(width <=0){
           width = 0;
        }
        drawBlock(randomNum, 0, width);
      }
//      drawPlayer(playerY);
    }
    
  buttonState1 = LOW;
  buttonState2 = LOW;
  buttonState3 = LOW;
  buttonState4 = LOW;

    delay(100); 
    
}

void drawBlock(int multiplier, int position, int width){
//  tft.fillScreen(RA8875_BLACK);
  if(multiplier != 0){
    tft.fillRect(position, tft.height(), width, 150*multiplier+20, RA8875_RED);
  }
}

void drawPlayer(int jump){
  tft.fillScreen(RA8875_BLACK);
  tft.fillCircle(50, jump-100, 10, RA8875_WHITE);
  tft.drawLine(50, jump-100, 50, jump-50, RA8875_WHITE);//body
  tft.drawLine(50, jump-80, 25, jump-90, RA8875_WHITE);//left arm
  tft.drawLine(50, jump-80, 75, jump-90, RA8875_WHITE);//right arm
  tft.drawLine(50, jump-50, 25, jump-40, RA8875_WHITE);//left leg
  tft.drawLine(50, jump-50, 75, jump-40, RA8875_WHITE);//right leg
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speaker, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speaker, LOW);
    delayMicroseconds(tone);
  }
}
