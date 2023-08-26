
#ifdef EXAMPLE11

#include <Arduino.h>

#define LED 15
#define LED_ONCE 14

hw_timer_t *timer = NULL;
// 只触发一次的定时器
hw_timer_t *timer_once = NULL;

// 定时器中断函数
void timer_interrupt()
{
	digitalWrite(LED, !digitalRead(LED));
}

void timer_once_interrupt()
{
	digitalWrite(LED_ONCE, !digitalRead(LED_ONCE));
}

void setup()
{
	pinMode(LED, OUTPUT);
	pinMode(LED_ONCE, OUTPUT);
	// 初始化定时器
	timer = timerBegin(0, 80, true);
	timer_once = timerBegin(1, 80, true);
	// 配置定时器
	timerAttachInterrupt(timer, timer_interrupt, true);
	timerAttachInterrupt(timer_once, timer_once_interrupt, true);

	// 设置定时模式
	timerAlarmWrite(timer, 1000 * 1000, true);
	timerAlarmWrite(timer_once, 1000 * 3000, false);
	// 启动定时器
	timerAlarmEnable(timer);
	timerAlarmEnable(timer_once);
}

void loop()
{
}
#endif