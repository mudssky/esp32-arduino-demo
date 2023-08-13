
#ifdef EXAMPLE1
#include <Arduino.h>

// 设置 LED 引脚
int led_pin = 15;
void setup()
{ // 设定引脚为输出模式
  pinMode(led_pin, OUTPUT);
}

void loop()
{
  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);
  delay(1000);
}
#endif