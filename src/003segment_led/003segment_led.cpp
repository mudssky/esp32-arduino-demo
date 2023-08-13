
#ifdef EXAMPLE3
#include <Arduino.h>
#include <TM1637.h>

// Instantiation and pins configurations
// Pin 3 - > DIO
// Pin 2 - > CLK
TM1637 tm(16, 17);

// Some get temperature function. Returns random temperatures between -10 and 30
int getTemperature()
{
	return static_cast<int8_t>(random(-10, 30));
}

void setup()
{
	tm.init();			  // Initializes the display
	tm.setBrightness(10); // Set brightness to level 3
}

void loop()
{
	tm.display("d", false, false, 3); // Displays the 'd' character at position 0 and don't fill the empty
	// spots on the right
	tm.display(getTemperature(), false, false); // Display the random temperature starting at position 1 and fill the
	// spots on the right with zeros

	delay(2000);
}
#endif