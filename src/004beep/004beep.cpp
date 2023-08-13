
#ifdef EXAMPLE4

#include <Arduino.h>

#define beep_pin 25
char beep_input = 0;

void setup()
{
	pinMode(beep_pin, OUTPUT); // 设置引脚为输出模式
}

void loop()
{
	beep_input = !beep_input;
	digitalWrite(beep_pin, beep_input); // 引脚输出电平翻转
	delayMicroseconds(250);				// 延时250us
}

#endif