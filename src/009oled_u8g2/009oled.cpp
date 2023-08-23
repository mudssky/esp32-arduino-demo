
#ifdef EXAMPLE9

#include <Arduino.h>
#include <U8g2lib.h>

#define SCL 18
#define SDA 23

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/SCL, /*data=*/SDA, /*reset=*/U8X8_PIN_NONE);
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

// 初始化进度条长度
int progress = 0;
void setup()
{

	// 初始化 oled 对象
	u8g2.begin();
	// 开启中文字符集支持
	u8g2.enableUTF8Print();
	//   设置字体
	u8g2.setFont(u8g2_font_wqy12_t_chinese2);
}
void draw_progress()
{
	u8g2.firstPage();
	// 因为需要先绘制一边，所以用了do while
	do
	{
		// 显示边框
		u8g2.drawFrame(0, 0, 128, 20);

		// 显示进度
		u8g2.drawBox(5, 5, progress, 10);

	} while (u8g2.nextPage()); // 如果存在下一页，则返回True

	if (progress < 118)
	{
		progress++;
	}
	else
	{
		progress = 0;
	}
}

void loop()
{
	draw_progress();
}

#endif