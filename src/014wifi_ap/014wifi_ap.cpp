
#ifdef EXAMPLE14

#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "ESP32_AP";
const char *password = "12345678";

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
void setup()
{
	Serial.begin(9600);
	WiFi.softAP(ssid, password);

	Serial.print("AP IP address: ");
	Serial.println(WiFi.softAPIP());

	// 通过led反馈wifi连接成功
	wifi_success_notice();
}

void loop()
{
}

#endif