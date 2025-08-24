#ifndef _____rgb_led______
#define _____rgb_led______

#include <Arduino.h>
#include "soc/soc_caps.h"         //Для управління світодіодом
#include "esp32-hal-rgb-led.h"    //Для управління світодіодом

#define RGB_BRIGHTNESS 10       //Регулировка яркости светодиода (max 255)


enum class COLORS_RGB_LED
{
    red,
    green,
    blue,
    black,

};



void WriteColorPixel(COLORS_RGB_LED color)
{
    


    switch (color)
    {
    case COLORS_RGB_LED::red :
        neopixelWrite(LED_PIN,0,RGB_BRIGHTNESS,0); // Red
        break;
    case COLORS_RGB_LED::green:
        neopixelWrite(LED_PIN,RGB_BRIGHTNESS,0,0); // Green  
        break;
    case COLORS_RGB_LED::blue:
        neopixelWrite(LED_PIN,0,0,RGB_BRIGHTNESS); // Blue
        break;
    case COLORS_RGB_LED::black:
        neopixelWrite(LED_PIN,0,0,0); // Off / black  
        break;

    default:
        break;
    }
    
}

// #ifdef RGB_BUILTIN
//   // digitalWrite(RGB_BUILTIN, HIGH);   // Turn the RGB LED white
//   neopixelWrite(RGB_BUILTIN,RGB_BRIGHTNESS,RGB_BRIGHTNESS,RGB_BRIGHTNESS); // Red
//   delay(1000);
//   // digitalWrite(RGB_BUILTIN, LOW);    // Turn the RGB LED off
//   neopixelWrite(RGB_BUILTIN,0,0,0); // Red
//   delay(1000);

//   neopixelWrite(RGB_BUILTIN,RGB_BRIGHTNESS,0,0); // Red
//   delay(1000);
//   neopixelWrite(RGB_BUILTIN,0,RGB_BRIGHTNESS,0); // Green
//   delay(1000);
//   neopixelWrite(RGB_BUILTIN,0,0,RGB_BRIGHTNESS); // Blue
//   delay(1000);
//   neopixelWrite(RGB_BUILTIN,0,0,0); // Off / black
//   delay(1000);
// #endif
#endif