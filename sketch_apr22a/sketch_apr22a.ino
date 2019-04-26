#include <SD.h>
#include <SPI.h>
#include <TFT.h>

//#include "Adafruit_GFX.h"
//#include "MCUFRIEND_kbv.h" 

//Colors
#define BLACK 0x0000
#define NAVY 0x000F
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define BLUE 0x001F
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
#define PINK 0xF81F

#define CS   10
#define RESET  9 

// pin definition for the Leonardo
// #define CS   7
// #define DC   0
// #define RESET  1 

TFT myScreen = TFT(CS, DC, RESET);
void setup(){
  myScreen.begin();  
  myScreen.background(0,0,0);  // clear the screen with black
  delay(1000);  // pause for dramatic effect
}
void loop(){
  myScreen.stroke(255, 0, 0); // set the stroke color to red
  myScreen.line(0, 10, myScreen.width(), 10); // draw a line across the screen
  delay(1000);

  myScreen.noStroke(); // don't draw a line around the next rectangle
  myScreen.fill(0,255,0); // set the fill color to green
  myScreen.rect(0,20,myScreen.width(),10); //draw a rectangle across the screen
  delay(1000);

  myScreen.fill(0,0,255); // set the fill color to blue
  myScreen.stroke(255,255,255); // outline the rectangle with a white line
  myScreen.rect(0,45,myScreen.width(),45); // draw a fat rectangle
  delay(1000);

  myScreen.background(0,0,0); // clear the screen before starting again
  delay(1000); 
}

