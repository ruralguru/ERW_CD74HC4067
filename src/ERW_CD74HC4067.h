/*Editor: Earl R. Watkins II Title: ERW_CD74HC4067.h Date: XX/XX/XXXX
		
	Texas Instruments CD74HC4067 1-16 multiplexer/demultiplexer Library
	Datasheet: http://www.ti.com/lit/ds/symlink/cd74hc4067.pdf
	
	Notes: Can be used as an input or an output. turns 5 inputs into 16. Only requires 1 PWM pin.
	
	Enable = Enable chip
	Common INPUT/OUTPUT = Read/write pin (recommend Analog for read and PWM for output)
	S_0 = Gives the 0 bit of selection, OUTPUT.
	S_1 = Gives the 1 bit of selection, OUTPUT.
	S_2 = Gives the 2 bit of selection, OUTPUT.
	S_3 = Gives the 3 bit of selection, OUTPUT.
	I_0-I_15 are the 16 channels of INPUT/OUTPUT from the MUX/DEMUX.

	This example code uses the "beerware" license. Use it, modify it, and/or reference it. 
	If you find it useful, buy me an ice cold tasty beverage someday.
*/

#ifndef ERW_CD74HC4067_h
#define ERW_CD74HC4067_h

#if defined(ARDUINO) && ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

//Include needed libraries with ifndef

class ERW_CD74HC4067
{
	public: //Can be called upon.
	
	//Public Functions
		ERW_CD74HC4067(void); 
		// Base type
		void begin(int muxSelect[4]);
			// Call CD74HC4067.begin() to initialize CD74HC4067 before use.
		bool channelSelect(byte chSelect);
			// select the channel of output and do the heavy work.
		
	//Public Variables

	private:
	
	//Private Functions
		
	//Private Variables
		int selectionBit[4]; // Gives the 0 bit of selection, OUTPUT.
		int muxInOut; // Read/write pin (recommend Analog for read and PWM for output)
};
//Definitions

#endif