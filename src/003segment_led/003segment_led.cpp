
#ifdef EXAMPLE3

#include <Arduino.h>
// include the SevenSegmentTM1637 library
#include "SevenSegmentTM1637.h"
#include "SevenSegmentExtended.h"

/* initialize global TM1637 Display object
 *  The constructor takes two arguments, the number of the clock pin and the digital output pin:
 * SevenSegmentTM1637(byte pinCLK, byte pinDIO);
 */
const byte PIN_CLK = 16; // define CLK pin (any digital pin)
const byte PIN_DIO = 17; // define DIO pin (any digital pin)
SevenSegmentExtended display(PIN_CLK, PIN_DIO);

const unsigned int clockSpeed = 10000; // speed up clock for demo

// run setup code
void setup()
{
	Serial.begin(9600);		   // initializes the Serial connection @ 9600 baud
	display.begin();		   // initializes the display
	display.setBacklight(100); // set the brightness to 100 %
	delay(1000);			   // wait 1000 ms
};

// run loop (forever)
void loop()
{

	byte hours = 14;   // initialize hours
	byte minutes = 39; // initialize minutes

	for (; hours < 24; hours++)
	{ // count hours   up to 24
		for (; minutes < 60; minutes++)
		{											 // count minutes up to 59
			display.printTime(hours, minutes, true); // display time
			delay(60000 / clockSpeed);				 // clock delay ms
		};
		minutes = 0; // reset minutes
	};
};
#endif