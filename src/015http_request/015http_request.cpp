
#ifdef EXAMPLE15

#include <Arduino.h>
#include <WiFi.h>
#include "../013wifi/my_secrets.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char *ssid = my_secrets::ssid;
const char *password = my_secrets::password;

String url = "http://apis.juhe.cn/simpleWeather/query";
String city = "城市名";
String key = "你的请求Key";

#define LED 15

void led_blink()
{
	digitalWrite(LED, HIGH);
	delay(100);
	digitalWrite(LED, LOW);
	delay(100);
}
void wifi_success_notice()
{
	pinMode(LED, OUTPUT);
	for (int i = 0; i < 10; i++)
	{
		led_blink();
	}
	digitalWrite(LED, HIGH);
}

void connect_wifi()
{
	WiFi.begin(ssid, password);
	Serial.println("Connecting to WiFi");
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.print("Connected to WiFi. IP address: ");
	Serial.println(WiFi.localIP());

	// 通过led反馈wifi连接成功
	wifi_success_notice();
}
void setup()
{
	Serial.begin(9600);
	connect_wifi();
	// 创建 HTTPClient 对象
	HTTPClient http;

	// 发送GET请求
	http.begin(url + "?city=" + city + "&key=" + key);

	int httpCode = http.GET();

	// 获取响应状态码
	Serial.printf("HTTP 状态码: %d", httpCode);

	// 获取响应正文
	String response = http.getString();
	Serial.println("响应数据");
	Serial.println(response);

	http.end();

	// 创建 DynamicJsonDocument 对象
	DynamicJsonDocument doc(1024);

	// 解析 JSON 数据
	deserializeJson(doc, response);

	// 从解析后的 JSON 文档中获取值
	unsigned int temp = doc["result"]["realtime"]["temperature"].as<unsigned int>();
	String info = doc["result"]["realtime"]["info"].as<String>();
	int aqi = doc["result"]["realtime"]["aqi"].as<int>();

	Serial.printf("温度: %d\n", temp);
	Serial.printf("天气: %s\n", info);
	Serial.printf("空气指数: %d\n", aqi);
}

void loop()
{
}

#endif