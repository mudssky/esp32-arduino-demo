
#ifdef EXAMPLE6

#include <Arduino.h>

#define LED_PIN 15

void setup()
{
	pinMode(LED_PIN, OUTPUT);
}
// 使用analogWrite输出实现亮度控制
void breath_led()
{
	// 变亮效果
	for (int i = 0; i < 256; i++)
	{

		analogWrite(LED_PIN, i);
		delay(5);
	}
	// 变暗
	for (int i = 255; i >= 0; i--)
	{

		analogWrite(LED_PIN, i);
		delay(5);
	}
}
void loop()

{
	breath_led();
}

#endif