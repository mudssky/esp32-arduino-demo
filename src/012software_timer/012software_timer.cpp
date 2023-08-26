
#ifdef EXAMPLE12

#include <Arduino.h>
#include <Ticker.h>
#define LED 15
#define LED_ONCE 14

// 定义定时器对象
Ticker timer;
Ticker timer_once;

// 定义定时器中断回调函数
void toggle(int pin)
{
	digitalWrite(pin, !digitalRead(pin));
}

void setup()
{
	pinMode(LED, OUTPUT);
	pinMode(LED_ONCE, OUTPUT);

	// 配置周期性定时器
	timer.attach(0.5, toggle, LED);
	// 配置一次性定时器
	timer_once.once(3, toggle, LED_ONCE);
}

void loop()
{
}

#endif