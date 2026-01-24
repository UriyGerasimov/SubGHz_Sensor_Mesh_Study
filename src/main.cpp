#include <Arduino.h> 
#include <RadioLib.h> 
#include "user_config.h" // Подключаем нашу "секретную комнату" 

// Объявляем объект для управления радиомодулем LR1121 
// Используем RadioLib для абстракции железа. 
// SCSS, SCK, MISO, MOSI, NRST, NSS, BUSY, DIO1 
// Заглушка, реальные пины будут определены при сборке на стенде. 
SX1268 radio = new Module(10, 11, 12, 13, 14, 15, 2, 1); 

void setup() { 
  Serial.begin(115200); 
  delay(2000); 
  Serial.println(F("[SubGHz-Study] System Start...")); 
  Serial.print(F("[SubGHz-Study] Platform: ESP32-C3 @ ")); 
  Serial.print(RF_FREQUENCY_HZ); // Выводим нашу частоту-невидимку 
  Serial.println(F(" Hz")); 

  // Имитация инициализации радиомодуля 
  int state = radio.begin(RF_FREQUENCY_HZ, RF_TX_POWER_DBM); 
  if (state == RADIOLIB_ERR_NONE) { 
    Serial.println(F("[SubGHz-Study] Radio Init OK. Monitoring mode active.")); 
  } else { 
    // Если модуль не подключен физически, это норма 
    Serial.print(F("[SubGHz-Study] Radio Init Failed, code: ")); 
    Serial.println(state); 
  } 
} 

void loop() { 
  // В будущем здесь будет алгоритм анализа спектра и Джиттера 
  delay(5000); 
  //Serial.println(F("[SubGHz-Study] Heartbeat: Monitoring noise for Fading Study...")); 
  Serial.println(F("[SubGHz-Study] Local node: SYNC OK"));
  // Имитируем отправку пакета с данными 
  String data = "Test_Packet_"; 
  data += millis(); 
  radio.transmit(data); 
} 
