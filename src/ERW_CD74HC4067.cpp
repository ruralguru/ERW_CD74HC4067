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

#include <ERW_CD74HC4067.h>


ERW_CD74HC4067::ERW_CD74HC4067()
// Base library type
{
	
}

void ERW_CD74HC4067::begin(int muxSelect[4])
	// Initialize library.
{
	for(int i = 0; i<4; i++)
	{
		ERW_CD74HC4067::selectionBit[i] = muxSelect[i]; // Assign the ith bit selection pin ith.
		pinMode(muxSelect[i],OUTPUT); //Tell if input
	}
}

bool ERW_CD74HC4067::channelSelect(byte chSelect)
	//Select the channel that you intend to use.
{
	if(chSelect>15) // cant be more than 15 channels 0-15
	{
		return 0; // if you try to push a channel that doesn't exist function returns 0.
	}
	for(int i = 0; i<4; i++) // there are ony 4 bits of selection.
	{
		if(bitRead(chSelect,i))
		{
			digitalWrite(selectionBit[i],HIGH); //Power channel to high.
		}
		else
		{
			digitalWrite(selectionBit[i],LOW); // Power channel to high
		}
	}
	
	return 1; // You chose an existing channel.
}