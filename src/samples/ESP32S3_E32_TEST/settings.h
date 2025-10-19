#ifndef __sett_i_ngs____
#define __sett_i_ngs____
/*   Этот файл предназначен для проверки наличия некоторых флагов по умолчанию */
/*   Только код PreCompiler должен быть установлен в этом файле                */
#include <Arduino.h>

#define DEBUG_PRINT

#define LED_TEST
//#define SIMPLE_LED


/**
 * @brief Следует раскомментировать одно из определений, а другое закомментировать.
 *  - RADIO_1 - раскомментировать если используется одно радио
 * 
 */
#define RADIO_1


/**
 * @brief Выбор режима работы радио при компиляции. Раскомментировать то, что необходимо
 * 
 */

 #define TRANSMITTER             //раскомментировать, если модуль будет использоваться как простой передатчик
 //#define RECEIVER                //раскомментировать, если модуль будет использоваться как простой приёмник



//**************************************************** Параметры радио для компиляции ************************************************

//Задаём параметры конфигурации радиотрансивера 1
#define RADIO_1_FREQ 441
#define RADIO_1_BANDWIDTH 125
#define RADIO_1_SPREAD_FACTOR 9
#define RADIO_1_CODING_RATE 7
#define RADIO_1_SYNC_WORD RADIOLIB_LR11X0_LORA_SYNC_WORD_PRIVATE
#define RADIO_1_OUTPUT_POWER 7
#define RADIO_1_CURRENT_LIMIT 320
#define RADIO_1_PREAMBLE_LENGTH 8
#define RADIO_1_GAIN 0

//**************************************************** Параметры радио для компиляции ************************************************


#ifdef TRANSMITTER 
String RADIO_1_NAME = F("TX_1");
#endif

#ifdef RECEIVER
String RADIO_1_NAME = F("RX_1");
#endif




/**
 * @brief Пины I2C
 * 
 */
#ifndef I2C_SDA_PIN
  #define I2C_SDA_PIN 12
#endif

#ifndef I2C_SCL_PIN
  #define I2C_SCL_PIN 13
#endif


// _______________________ Пин вентилятора (если такой нужен) _______________________
#ifndef FUN
  #define FUN -1
#endif

// _______________________ Пин пользовательского светодиода _______________________
#ifndef LED_PIN
  #define LED_PIN -1
#endif


// _______________________ Пины модема номер 1 _______________________
#ifndef NSS_PIN_1
  #define NSS_PIN_1 -1
#endif

#ifndef IRQ_PIN_1
  #define IRQ_PIN_1 -1
#endif

#ifndef NRST_PIN_1
  #define NRST_PIN_1 -1
#endif

#ifndef BUSY_PIN_1
  #define BUSY_PIN_1 -1
#endif

#ifndef TX_EN_PIN_1
  #define TX_EN_PIN_1 -1
#endif

#ifndef RX_EN_PIN_1
  #define RX_EN_PIN_1 -1
#endif



/**
 * @brief Пины SPI управления модемами 
 * По-умолчанию выбран SPI - VSPI: 
 * _________________________________________________________________________
 *    СПИ	    *      МОСИ	    *      МИСО	    *     СКЛК	    *      КС     *
 *__________________________________________________________________________
 *    VSPI	  *    GPIO 23	  *    GPIO 19	  *    GPIO 18	  *    GPIO5    *
 * ___________*_______________*_______________*_______________*_____________*
 *    HSPI	  *    GPIO 13	  *    GPIO 12	  *    GPIO 14	  *    GPIO 15  *
 * ___________*_______________*_______________*_______________*_____________*
 */
#ifndef MOSI_RADIO
  #define MOSI_RADIO 9
#endif

#ifndef MISO_RADIO
  #define MISO_RADIO 11
#endif

#ifndef SCK_RADIO
  #define SCK_RADIO 8
#endif




// _______________________ Пины .................... _______________________

#ifndef PIN_1
#define PIN_1 -1
#endif

#ifndef PIN_2
#define PIN_2 -1
#endif

#ifndef PIN_3
#define PIN_3 -1
#endif

#ifndef PIN_4
#define PIN_4 -1
#endif

#ifndef PIN_5
#define PIN_5 -1
#endif

#ifndef PIN_6
#define PIN_6 -1
#endif

#ifndef PIN_7
#define PIN_7 -1
#endif




#ifndef UNDEF_PIN
  #define UNDEF_PIN -1
#endif

#ifndef xx
  #define xx -1
#endif



#endif;