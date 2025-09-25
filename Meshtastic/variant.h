//*************************************************  RGB NEOPIXEL   ****************************************************/
// Board has RGB LED 21
#define ENABLE_AMBIENTLIGHTING
//#define HAS_RGB_LED                          // Enable the use of RGB LED
#define HAS_NEOPIXEL                         // Enable the use of neopixels
#define NEOPIXEL_COUNT 1                     // How many neopixels are connected
#define NEOPIXEL_DATA 21                     // gpio pin used to send data to the neopixels
#define NEOPIXEL_TYPE (NEO_RGB + NEO_KHZ800) // type of neopixels in use
//************************************************  END LED  ***************************************************/



//*************************************************   OLED   ****************************************************/
// Дисплей OLED
// #define HAS_SCREEN 1
#define USE_SSD1306
// #define USE_SH1106 1
#define I2C_SCL 13
#define I2C_SDA 12
//***********************************************   END OLED  ***************************************************/



//*************************************************   I2C2   ****************************************************/
// Другий I2C для підключення зовнішніх пристроїв
#define I2C_SDA1 17
#define I2C_SCL1 18
//*************************************************  END I2C2  ***************************************************/



//*************************************************   GPS   ******************************************************/
/*
  No GPS - but free pins are available.
*/
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

//*************************************************  END GPS  *****************************************************/

//*************************************************   BUTTON   ****************************************************/
// Пін кнопки
#define BUTTON_PIN 0   
#define BUTTON_NEED_PULLUP
//#define BUTTON_ACTIVE_LOW true
//#define BUTTON_ACTIVE_PULLUP true

// #define PIN_BUTTON1 47 // 功能键
// #define PIN_BUTTON2 4  // 电源键
// #define ALT_BUTTON_PIN PIN_BUTTON2
// #define ALT_BUTTON_ACTIVE_LOW false
// #define ALT_BUTTON_ACTIVE_PULLUP false

// #define EXT_NOTIFY_OUT 22

//*************************************************  END BUTTON  ***************************************************/

//***************************************************   UART   *****************************************************/
// UART
#define UART_TX 43
#define UART_RX 44

//*************************************************   END UART   ****************************************************/


//***************************************************   FAN    ******************************************************/
//#define RF95_FAN_EN 5 // Пін для керування вентилятором якщо буде це потрібно. Теоретично достатньо радіатора,
                        // або навіть можна обійтись і без радіатора, якщо не буде суттєвого нагріву модема, бо 
                        // проєкт меш-мережі не передбачає високих навантажень на радіомодем
//*************************************************   END FAN   *****************************************************/

//*************************************************   SPI    ******************************************************/
//Піни, які приєднані до модема SX127x
#define LORA_CS 7
#define LORA_DIO1 1
#define LORA_RESET 3
#define LORA_DIO0 2
#define LORA_TXEN 6
#define LORA_RXEN 10

// Піни для SPI інтерфейсу радіомодема
#define LORA_MOSI 9
#define LORA_MISO 11
#define LORA_SCK 8


//Тип радіомодема
#define USE_RF95

//Піни для управління завданим радіомодемом
// #define USE_RF95_RFO
#define RF95_CS LORA_CS
#define RF95_IRQ LORA_DIO0
#define RF95_DIO1 LORA_DIO1
#define RF95_TXEN LORA_TXEN
#define RF95_RXEN LORA_RXEN
#define RF95_RESET LORA_RESET
#define RF95_MAX_POWER 17