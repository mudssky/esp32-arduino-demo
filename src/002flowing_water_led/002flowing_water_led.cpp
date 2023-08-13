#ifdef EXAMPLE2

#include <Arduino.h>

int pin_list[8] = {15, 16, 17, 18, 19, 21, 22, 23};

int pin_num = sizeof(pin_list) / sizeof(pin_list[0]);
void setup()
{
	// 设置所有GPIO引脚为输出
	for (int i = 0; i < pin_num; i++)
	{
		pinMode(pin_list[i], OUTPUT);
	}
}

void all_led_reset(uint8_t val = LOW)
{
	for (int i = 0; i < pin_num; i++)
	{
		digitalWrite(pin_list[i], val);
	}
}
// 顺向的流水灯，先点亮，然后同顺序熄灭
void water_led(int delay_ms = 50)
{
	for (int i = 0; i < pin_num; i++)
	{
		digitalWrite(pin_list[i], HIGH);
		delay(delay_ms);
	}

	for (int i = 0; i < pin_num; i++)
	{
		digitalWrite(pin_list[i], LOW);
		delay(delay_ms);
	}
}
// 熄灭时反向
void water_led_reverse(int delay_ms = 50)
{
	for (int i = 0; i < pin_num; i++)
	{
		digitalWrite(pin_list[i], HIGH);
		delay(delay_ms);
	}

	for (int i = pin_num - 1; i >= 0; i--)
	{
		digitalWrite(pin_list[i], LOW);
		delay(delay_ms);
	}
}

// 平移流水灯
void water_led_translate(int delay_ms = 50)
{
	for (int i = 0; i < pin_num; i++)
	{
		// 点亮当前的同时熄灭前一个
		digitalWrite(pin_list[i], HIGH);

		if (i != 0)
		{
			digitalWrite(pin_list[i - 1], LOW);
		}
		else
		{
			// 等于0时写灭最后一个灯
			digitalWrite(pin_list[pin_num - 1], LOW);
		}

		// 可以用模运算简化代码为一行
		// digitalWrite(pin_list[(i - 1 + pin_num) % pin_num], LOW);
		delay(delay_ms);
	}
	all_led_reset();
}
void loop()
{
	water_led_translate(100);
	water_led_reverse(100);
	water_led(100);
}

#endif