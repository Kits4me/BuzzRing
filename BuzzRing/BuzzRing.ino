/*
 Name:		BuzzRing.ino
 Created:	3/23/2021 12:36:51 AM
 Author:	amird

 this project uses Kits4.Me game kit
*/

//#include "display595.h"
//#include "disp595_kits4me.ino"

#define startPositionPin	2
#define midWirePin			3
#define endPositionPin		4

#define passiveBuzzerPin      6

#define ledPinGreen     10
#define ledPinRed       11


//----- states
#define WAITING_TO_START	1
#define ON_START_POINT		2
#define GOING				3
#define ERROR				4
#define FINISHED			5


void setup() {
	pinMode(startPositionPin, INPUT_PULLUP);
	pinMode(midWirePin, INPUT_PULLUP);
	pinMode(endPositionPin, INPUT_PULLUP);

	pinMode(passiveBuzzerPin, OUTPUT);

	pinMode(ledPinGreen, OUTPUT);
	pinMode(ledPinRed, OUTPUT);

	setup_7seg();

	//Serial.begin(9600);
	//currState = WAITING_TO_START; 
}

// the loop function runs over and over again until power down or reset
void loop() {
	stateMachine();
}

void ledsOFF() {
	digitalWrite(ledPinGreen, LOW);
	digitalWrite(ledPinRed, LOW);
}
void greenON() {
	digitalWrite(ledPinGreen, HIGH);
}
void redON() {
	digitalWrite(ledPinRed, HIGH);
}
