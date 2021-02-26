#include <Adafruit_NeoPixel.h>

#define PIN        7

#define NUMPIXELS 30 

const int buttonPin = 9; 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGBW + NEO_KHZ800);
int buttonState = 0;
int lastButtonState = 0;
int currentMode = 0;

void setup() {
  pixels.begin(); 
  pixels.clear();
  pinMode(buttonPin, INPUT);
  colorWipe(pixels.Color(0,140,255));
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      changeLEDMode();
    }   
    delay(200);
  }
  lastButtonState = buttonState;

  pixels.show();

}

void changeLEDMode(){
  if(currentMode==6){
    currentMode = 0;
  }
  else{
    currentMode++;
  }
  if(currentMode==0){
        //strawberry
    colorWipe(pixels.Color(0,140,255));
  }
  else if(currentMode==1){
        //vanilla
    colorWipe(pixels.Color(50,100,0));
  }
  else if(currentMode==2){
        //chocolate
    colorWipe(pixels.Color(32,170,0));
  }
  else if(currentMode==3){
        //strawberry vanilla swirl
    colorWipeSwirl(pixels.Color(50,100,0),pixels.Color(0,140,255));
  }
  else if(currentMode==4){
        //chocolate strawberry
    colorWipeSwirl(pixels.Color(0,140,255),pixels.Color(32,170,0));
  }
  else if(currentMode==5){
        //vanilla chocolate swirl
    colorWipeSwirl(pixels.Color(32,170,0),pixels.Color(50,100,0));
  }
  else{
        //neopolitan
    neopolitan(pixels.Color(32,170,0),pixels.Color(50,100,0),pixels.Color(0,140,255));
  }
}

void colorWipe(uint32_t color) {
  for(int i=0; i<pixels.numPixels(); i++) { 
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(50);
  }
}
void colorWipeSwirl(uint32_t color1, uint32_t color2) {
  for(int i=0; i<8; i++) { 
    pixels.setPixelColor(i, color1); 
    pixels.show();
    delay(50);
  }
  for(int i=7; i<15; i++) { 
    pixels.setPixelColor(i, color2); 
    pixels.show();
    delay(50);
  }
  for(int i=14; i<22; i++) { 
    pixels.setPixelColor(i, color1); 
    pixels.show();
    delay(50);
  }
  for(int i=21; i<30; i++) { 
    pixels.setPixelColor(i, color2); 
    pixels.show();
    delay(50);
  }
}
void neopolitan(uint32_t color1, uint32_t color2, uint32_t color3) {
  for(int i=0; i<5; i++) { 
    pixels.setPixelColor(i, color1); 
    pixels.show();
    delay(50);
  }
  for(int i=6; i<10; i++) { 
    pixels.setPixelColor(i, color2); 
    pixels.show();
    delay(50);
  }
  for(int i=11; i<15; i++) { 
    pixels.setPixelColor(i, color3); 
    pixels.show();
    delay(50);
  }
  for(int i=16; i<20; i++) { 
    pixels.setPixelColor(i, color1); 
    pixels.show();
    delay(50);
  }
  for(int i=21; i<25; i++) { 
    pixels.setPixelColor(i, color2); 
    pixels.show();
    delay(50);
  }
  for(int i=26; i<30; i++) { 
    pixels.setPixelColor(i, color3); 
    pixels.show();
    delay(50);
  }
}
