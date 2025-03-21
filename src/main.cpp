#include <Arduino.h>
#include <settings.h>
#include <rgb_led.h>
// #include <radioLR.h>
#include <display.h>



uint64_t count = 0;           //Счётчик для сохранения количества отправленных/полученных пакетов
boolean FUN_IS_ON = false;    //Логический флаг включения/отключения вентилятора охлаждения




void setup_pin_led()
{
    pinMode(PIN_1, OUTPUT);
    pinMode(PIN_2, OUTPUT);
    pinMode(PIN_3, OUTPUT);
    pinMode(PIN_4, OUTPUT);
    pinMode(PIN_5, OUTPUT);
    pinMode(PIN_6, OUTPUT);
    pinMode(PIN_7, OUTPUT);
    
}


void led_test()
{
    Serial.println("");
    Serial.println("****************************************  LED TEST ON  ***********************************");
    Serial.println("");

    int temp = 500;

    delay(temp);
    digitalWrite(PIN_1, LOW);
    delay(temp);
    digitalWrite(PIN_1, HIGH);
    digitalWrite(PIN_2, LOW);
    delay(temp);
    digitalWrite(PIN_2, HIGH);
    digitalWrite(PIN_3, LOW);
    delay(temp);
    digitalWrite(PIN_3, HIGH);
    digitalWrite(PIN_4, LOW);
    delay(temp);
    digitalWrite(PIN_4, HIGH);
    digitalWrite(PIN_5, LOW);
    delay(temp);
    digitalWrite(PIN_5, HIGH);
    digitalWrite(PIN_6, LOW);
    delay(temp);
    digitalWrite(PIN_6, HIGH);
    digitalWrite(PIN_7, LOW);
    delay(temp);
    digitalWrite(PIN_7, HIGH);
    
}





void setup() {
    #ifdef DEBUG_PRINT
        Serial.begin(115200);
        Serial.println(" ");
        Serial.println(F("*************************  Serial ready 115200 *******************************"));
        Serial.println(" ");
    #endif

    SPI_MODEM.begin(SCK_RADIO, MISO_RADIO, MOSI_RADIO);
    display_wire.begin(I2C_SDA_PIN, I2C_SCL_PIN, 100000);

    setup_pin_led();

    #ifdef DEBUG_PRINT
        Serial.println(" ");
        Serial.print("Chip Model = ");
        Serial.println(ESP.getChipModel());
        Serial.print("Cpu Freq = ");
        Serial.println(ESP.getCpuFreqMHz());
        Serial.print("ChipRevision = ");
        Serial.println(ESP.getChipRevision());
        Serial.print("SDK Version = ");
        Serial.println(ESP.getSdkVersion());
        Serial.println(" ");
    #endif

    #ifdef DEBUG_PRINT
        Serial.print(TABLE_LEFT);
        Serial.print(F("DISPLAY INIT"));
        Serial.println(TABLE_RIGHT);
        Serial.println(SPACE);
    #endif

    //инициализируем дисплей
    displayInit();

    pinMode(FUN, OUTPUT);                   //Контакт управления вентилятором охлаждения
    


    WriteColorPixel(COLORS_RGB_LED::red);   //Зажигаем красный цвет

    setRadioMode();

    radio1.setRfSwitchPins(RX_EN_PIN_1, TX_EN_PIN_1);         //Назначаем контакты для управлением вкл./выкл. усилителем передатчика
    

    //Устанавливаем функцию, которая будет вызываться при отправке пакета данных
    radio1.setPacketSentAction(flag_operationDone_1);

    radioBeginAll();

    #ifdef DEBUG_PRINT
        Serial.println(SPACE);
    #endif

    //Устанавливаем наши значения, определённые ранее в структуре config_radio1
    radio_setSettings(radio1, config_radio1, "1");

    #ifdef TRANSMITTER   //Если определена работа модуля как передатчика
        

        //Начинаем передачу пакетов
        Serial.println(F("Sending first packet ... "));

        String str = F("START!");
        
        transmit_and_print_data(str);
        WriteColorPixel(COLORS_RGB_LED::green);

        // и вентилятор охлаждения не включен, то включаем вентилятор охлаждения
        if(config_radio1.outputPower > 1 && FUN_IS_ON != true)
        {
            //отмечаем вентилятор как включенный
            FUN_IS_ON = true;
            //и включаем его
            digitalWrite(FUN, HIGH);
        }

    #endif

}
















void loop() {
    delay(500);
    WriteColorPixel(COLORS_RGB_LED::black);
    led_test();
    
    #ifdef TRANSMITTER   //Если определен как передатчик проверяем, была ли предыдущая передача успешной
        
        // if(operationDone_1) {
            #ifdef DEBUG_PRINT
                Serial.println("..................................................");
            #endif
            //Сбрасываем сработавший флаг прерывания
            operationDone_1 = false;

            //готовим строку для отправки
            String str = "#" + String(count++);
            transmit_and_print_data(str);
            WriteColorPixel(COLORS_RGB_LED::green);
            
        // }

    #endif

   
}

