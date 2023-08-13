
#ifdef EXAMPLE5

#include <Arduino.h>

int k1_pin = 22;
int led_pin = 15;

// 定义led 逻辑值
int led_logic = 0;
// 记录led是可否更改过
bool led_changed = false;
void setup()
{
	pinMode(k1_pin, INPUT_PULLUP); // 设置引脚为输出模式
	pinMode(led_pin, OUTPUT);
}

void loop()
{
	if (digitalRead(k1_pin))
	{

		// 延迟10ms 防抖
		delay(10);
		if (digitalRead(k1_pin) && !led_changed)
		{
			led_logic = !led_logic;
			digitalWrite(led_pin, led_logic);
			// 修改状态
			led_changed = !led_changed;
		}
		else if (!digitalRead(k1_pin))
		{
			led_changed = false;
		}
	}
}

#endif