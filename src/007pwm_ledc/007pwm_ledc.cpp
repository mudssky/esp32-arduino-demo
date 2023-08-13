
#ifdef EXAMPLE7

#include <Arduino.h>
#define FREQ 2000	 // 频率
#define CHANNEL 0	 // 通道
#define RESOLUTION 8 // 分辨率
#define LED_PIN 15

void setup()
{
	// 设置通道
	ledcSetup(CHANNEL, FREQ, RESOLUTION);
	// 绑定通道号与引脚
	ledcAttachPin(LED_PIN, CHANNEL);
}

void loop()

{
	// 变亮效果
	for (int i = 0; i < pow(2, RESOLUTION); i++)
	{

		ledcWrite(CHANNEL, i);
		delay(5);
	}
	// 变暗
	for (int i = pow(2, RESOLUTION) - 1; i >= 0; i--)
	{

		ledcWrite(CHANNEL, i);
		delay(5);
	}
}

#endif