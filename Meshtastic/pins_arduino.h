#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

static const uint8_t TX = 43;
static const uint8_t RX = 44;

// The default Wire will be mapped to PMU and RTC
static const uint8_t SDA = 12;
static const uint8_t SCL = 13;

// Default SPI will be mapped to Radio
static const uint8_t MISO = 11;
static const uint8_t SCK = 8;
static const uint8_t MOSI = 9;
static const uint8_t SS = 7;


#endif /* Pins_Arduino_h */
