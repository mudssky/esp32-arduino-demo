
#ifdef EXAMPLE13

#include <Arduino.h>
#include <WiFi.h>
#include "my_secrets.h"

const char *ssid = my_secrets::ssid;
const char *password = my_secrets::password;

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

void loop()
{
}

#endif