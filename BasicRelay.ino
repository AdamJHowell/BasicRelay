/**
 * @brief This program is a simple way to test a relay.
 * It will toggle the relay at the designated interval.
 */

const unsigned int RELAY_PIN = 4;						// The GPIO which controls the relay.
const unsigned int LED_PIN = 2;							// The GPIO which controls the onboard LED.
const unsigned int RELAY_TOGGLE_INTERVAL = 2000;	// How long to wait between sensor polling.
unsigned long lastRelayToggleTime = 0;					// The last time sensors were polled.


void setup( )
{
	delay( 1000 );
	Serial.begin( 115200 );
	if( !Serial )
		delay( 1000 );
	pinMode( RELAY_PIN, OUTPUT );			// Set the replay GPIO as an output.
	digitalWrite( RELAY_PIN, 0 );			// Turn the relay off.
	pinMode( LED_PIN, OUTPUT );			// Initialize the GPIO which controls the LED as an output.
	digitalWrite( LED_PIN, 0 );			// Turn the LED on.
}


/**
 * @brief toggleRelay() will change the state of the relay.
 * This function does not manage any timings.
 */
void toggleRelay( )
{
	if( digitalRead( RELAY_PIN ) != 1 )
	{
		// Turn the relay and LED on.
		digitalWrite( RELAY_PIN, 1 );
		digitalWrite( LED_PIN, 1 );
	}
	else
	{
		// Turn the relay and LED off.
		digitalWrite( RELAY_PIN, 0 );
		digitalWrite( LED_PIN, 0 );
	}
} // End of toggleRelay() function.


void loop( )
{
	unsigned long currentTime = millis();
	// Toggle the first time.  Avoid subtraction overflow.  Toggle every interval.
	if( lastRelayToggleTime == 0 || (( currentTime > RELAY_TOGGLE_INTERVAL ) && ( currentTime - RELAY_TOGGLE_INTERVAL ) > lastRelayToggleTime ) )
	{
		toggleRelay();
		lastRelayToggleTime = millis();
	}
}
