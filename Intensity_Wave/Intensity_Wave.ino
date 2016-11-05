#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 8

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_RGB + NEO_KHZ400);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  intensityWave(strip.Color(127, 127, 127), 100); // White
  intensityWave(strip.Color(255, 0, 0), 100); // Red
  intensityWave(strip.Color(127, 127, 0), 100); // Yellow
  intensityWave(strip.Color(0, 255, 0), 100); // Green
  intensityWave(strip.Color(0, 127, 127), 100);//Teal
  intensityWave(strip.Color(0, 0, 255), 100); // Blue
  intensityWave(strip.Color(127, 0, 127), 100); // Pink
  
}
//Intensity Wave: I want each group of 6(25% steps) or 18(10% steps) LEDs to form a 
//wave of intensity from 100% to 25% or 10%, respectively. The color lights should 
//be defined in the parameters when the function is called, as well as a delay time 
//for setting the speed of the effect.  The wave should push down 
//the strip, but not return (although that may be another neat look). 

void intensityWave(uint32_t c, uint8_t wait){
  
  for (int j=0; j<20; j++) 
   
  { 
    for (int p=0; p < 18; p++) 
    for (uint16_t i=0; i < strip.numPixels(); i=i++)
      strip.setPixelColor(i+p, c);
//strip.show();
//delay(wait);
    for (int q=0; q < 250; q=q+25){ 
     strip.setBrightness(q);
     strip.show();}
delay(wait); 
    for (int q=250; q > 0; q=q-25)
    {strip.setBrightness(q);
    strip.show();
    delay(wait);}
}

}

