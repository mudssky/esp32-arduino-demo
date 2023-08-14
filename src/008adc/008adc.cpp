
#ifdef EXAMPLE8

#include <Arduino.h>

// 定义接受电位器adc输入的引脚
#define ADC_PIN 26
#define LED_PIN 15
int adc_value;
int led_value;
void setup()
{
	// 使用串口波特率9600
	Serial.begin(9600);
	pinMode(ADC_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);
}

void loop()
{
	// 读取电位计模拟输入
	adc_value = analogRead(ADC_PIN);

	// 将电位计输入转化为led亮度
	// 之前观察在串口输入发现，模拟信号 最大值为4096，正好是256的16倍。
	// 所以我们可以把这个转换为LED模拟输出

	// 使用min函数，防止溢出
	led_value = min(adc_value / 16, 255);
	analogWrite(LED_PIN, led_value);
	Serial.println(led_value);
	delay(100);
}

#endif