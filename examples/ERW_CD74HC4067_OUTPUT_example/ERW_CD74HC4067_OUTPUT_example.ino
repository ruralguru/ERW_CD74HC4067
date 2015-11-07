/*Editor: Earl R. Watkins II Title: ERW_MSGEQ7_example Date: 11/04/2015
 * Datasheet: http://www.ti.com/lit/ds/symlink/cd74hc4067.pdf
 * Use to hook up pins properly.
 * This example requires 1 cd74hc4067  MUX/DEMUX.
 * Enable = Enable chip
 * Common INPUT/OUTPUT = Read/write pin (recommend Analog for read and PWM for output)
 * S_0 = Gives the 0 bit of selection, OUTPUT.
 * S_1 = Gives the 1 bit of selection, OUTPUT.
 * S_2 = Gives the 2 bit of selection, OUTPUT.
 * S_3 = Gives the 3 bit of selection, OUTPUT.
 * I_0-I_15 are the 16 channels of INPUT/OUTPUT from the MUX/DEMUX.
 * 
 * One good way of testing it as an output or DEMUX is an LED array.
 * It can also be used as a 16 channel input or MUX, testing with varied resistors.
 * Mix and match as desired, just remember to use pinMode to change from input to output.
*/
//Libraries
#include <ERW_CD74HC4067.h> // Add Earl's CD74HC4067 library.
//Definitions 
#define muxInOut 3 // Define demux input or output pin. 
int muxSelect[4] = {4,5,6,7}; // Define demux Select pins.
const unsigned long timeStep = 17; // 1000ms is 1 second. This controls the sample rate.
//Variables
byte chSelect=0; // Holder for channel select.
unsigned long Timer; // Timer to do math instead of delay.
//Objects
ERW_CD74HC4067 muxDemux; // Rename object

void setup() // Setup -------------------------------------------------------------
{
  Serial.begin(9600); //Begin Serial interface
  muxDemux.begin(muxSelect); //Begin multiplexer/demultiplexer
           //Requires 1 pin for output or input
  Serial.println("MUX started"); //User info.
  pinMode(muxInOut,OUTPUT); //Tell if INPUT or OUTPUT
  digitalWrite(muxInOut,HIGH); // Writes the output high.
  Timer=millis(); // Start timer.
}

void loop() // Pete & repete ------------------------------------------------------
{
  if(millis()-Timer>=timeStep) // Returns true once timestep has passed.
  {
    muxDemux.channelSelect(chSelect); // Choose the mux/demux channel.
    if(chSelect==15)
    {
      chSelect = 0; // set channel  to 0.
    }
    else
    {
      chSelect ++; // Increment the channel.
    }
    Timer+=timeStep; // Update timer.
  }
}
