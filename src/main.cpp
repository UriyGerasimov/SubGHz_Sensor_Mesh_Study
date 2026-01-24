#include <Arduino.h> 
#include <RadioLib.h> 

// Пока что пустой объект, имитируем структуру проекта 
void setup() { 
  Serial.begin(115200); 
  delay(2000); 
  Serial.println(F("[SubGHz-Study] System Start...")); 
  Serial.println(F("[SubGHz-Study] Platform: ESP32-C3")); 
  Serial.println(F("[SubGHz-Study] Radio module: LR1121 - Pending init")); 
} 

void loop() { 
  // В будущем здесь будет алгоритм анализа спектра 
  delay(5000); 
  Serial.println(F("[SubGHz-Study] Heartbeat: Monitoring noise...")); 
} 
