/*
 * Jan 2019
 * ERICA JEWELL
 * - Magnet switch used to detect whether the bicycle is being pedalled.
 * - Five relays are successively switched on after a certain "distance" pedalled.
 * - When magnet switch has not been turned on after a certain time, turn off relays.
 */

int magnet = 2; // connect S (signal) of magnetic switch to digital pin 2
int switchState = 0; // state of magnet switch
int lastSwitchState = 0; // last state of magnet switch
int distancePedalled = 0; // how far the cyclist has pedalled
int distancePerWord = 10; // how many revolutions are required for a word to light up (relay)
int timeToStop; // how long it has been since the wheel (magnet) has made a full revolution

// -- these might be unecessary
int timePedalled = 0; // how long the cyclist has been pedalling
int pedalSpeed = 0; // speed at which the magnet is triggering the switch (revolutions per second)
//
void setup(){
  Serial.begin(9600);
  pinMode(magnet, INPUT);
}
  
void loop(){
  checkSwitch();
  if (switchState == 1 && lastSwitchState == 0){
    // magnet has made one revolution
    distancePedalled++;
  }
  // if (distancePedalled > distancePerWord){
     // switch on relay 1
  //}

// add something here to calculate how long it's been, can remove it
  // if (switchState == 0 && lastSwitchState == 0){
  // switch off all relays
  // distancePedalled = 0;
  //}
  lastSwitchState = switchState;
}

void checkSwitch(){  // detect whether bicycle is being pedalled
  if (digitalRead(magnet)==HIGH){
    switchState = 0;
    Serial.println("not touching");
  }
  if (digitalRead(magnet)==LOW){
    switchState = 1;
    Serial.println("touching");
  }
}
