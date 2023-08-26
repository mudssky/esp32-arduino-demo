
#ifdef EXAMPLE10

#include <Arduino.h>
#include <U8g2lib.h>

#define BUTTON 22

#define SCL 18
#define SDA 23

// 定义外部中断函数种可以使用的变量
volatile bool is_interrupt = false;

int interrupt_count = 0;

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/SCL, /*data=*/SDA, /*reset=*/U8X8_PIN_NONE);

void handle_interrupt()
{
	is_interrupt = true;
}
void hello()
{

	// 清楚缓冲区内容
	u8g2.clearBuffer();
	// 设置开始坐标
	u8g2.setCursor(0, 15);
	// 绘制内容
	u8g2.print("Hello World!");

	u8g2.setCursor(0, 40);
	u8g2.print("你好,ESP32!");
	// 发送缓冲区内容到oled显示
	u8g2.sendBuffer();
}
void interrupt_action()
{

	u8g2.clearBuffer();
	u8g2.setCursor(10, 15);
	interrupt_count += 1;
	u8g2.print("中断被触发了!" + String(interrupt_count));
	u8g2.sendBuffer();
	// delay(2000);
	is_interrupt = false;
}
void setup()
{
	pinMode(BUTTON, INPUT_PULLUP);
	// 初始化 oled 对象
	u8g2.begin();
	// 开启中文字符集支持
	u8g2.enableUTF8Print();
	//   设置字体
	u8g2.setFont(u8g2_font_wqy12_t_gb2312);
	attachInterrupt(digitalPinToInterrupt(BUTTON), handle_interrupt, FALLING);
}

void loop()
{
	if (is_interrupt)
	{
		interrupt_action();
	}
	else
	{
		hello();
	}
}
#endif