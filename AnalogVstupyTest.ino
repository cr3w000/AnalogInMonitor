/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:

const int analogInPin[8] = {A0,A1,A2,A3,A4,A5,A6,A7};
int analogInPinState[8] = {0,0,0,0,0,0,0,0};

const int threshold = 200;

int sensorValue = 0;        // value read from the pot
int iterator = 0;
int state = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin[0]);


  // DEBUG: print the results to the Serial Monitor:
  //Serial.print("Input ");
  //Serial.print(iterator);
  Serial.print(" sensor = ");
  Serial.println(sensorValue);


  if(sensorValue > threshold){
    //new state will be 1. check current one
    if(analogInPinState[iterator] == 0){
      //previous state was 0, report state change
       Serial.println();
        Serial.print("State changed to 1 on port ");
        Serial.println(iterator);
    }
    analogInPinState[iterator] = 1;
  }
  else
  {
    //new state will be 0. check current one
    if(analogInPinState[iterator] == 1){
      //previous state was 1, report state change
        Serial.println();
        Serial.print("State changed to 0 on port ");
        Serial.println(iterator);
    }
    analogInPinState[iterator] = 0;
  }

  //increase iterator to check next input in next loop
  //reset to 0 if we reached 8 (last input is A7)
  iterator++;
  if(iterator = 8){
    iterator = 0;
   // Serial.print("x");
  }
  // wait 50 milliseconds before the next loop to avoid transition flickering
  delay(50);
}
