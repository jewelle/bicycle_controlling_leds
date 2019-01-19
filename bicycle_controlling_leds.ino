/*
 * Jan 2019
 * ERICA JEWELL
 * - Magnet switch used to detect whether the bicycle is being pedalled.
 * - Five relays are successively switched on after a certain "distance" pedalled.
 * - When magnet switch has not been turned on after a certain time, turn off relays.
 */

int magnet = 0; // connect S (signal) of magnetic switch to digital pin 0
int relay1 = 1; // relays to pins 1 - 5
int relay2 = 2;
int relay3 = 3;
int relay4 = 4;
int relay5 = 5;

int switchState = 0; // state of magnet switch
int lastSwitchState = 0; // last state of magnet switch
int distancePedalled = 0; // how far the cyclist has pedalled
int distancePerWord = 10; // how many revolutions are required for a word to light up (relay)
int timeStopped; // milliseconds passed since the wheel (magnet) has made a full revolution
int timeToStop = 4000; // milliseconds of inactivity required to switch everything off

void setup(){
  Serial.begin(9600);
  pinMode(magnet, INPUT);
}
  
void loop(){
  checkSwitch();
  if (switchState == 1 && lastSwitchState == 0){
    distancePedalled++; // magnet has made one revolution
  }
  
  if (distancePedalled > distancePerWord){
     digitalWrite(relay1, HIGH);  
  }
  if (distancePedalled > distancePerWord*2){
     digitalWrite(relay2, HIGH);  
  }
  if (distancePedalled > distancePerWord*3){
     digitalWrite(relay3, HIGH);  
  }
  if (distancePedalled > distancePerWord*4){
     digitalWrite(relay4, HIGH);  
  }
  if (distancePedalled > distancePerWord*5){
     digitalWrite(relay5, HIGH);  
  }

  if (switchState == 0 && lastSwitchState == 0){
    timeStopped = timeStopped + (millis() - timeStopped);
    if (timeStopped > timeToStop){
      distancePedalled = 0;
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
      digitalWrite(relay5, LOW);  
    }
  }
  lastSwitchState = switchState;
}

void checkSwitch(){  // detect whether bicycle is being pedalled
  if (digitalRead(magnet) == HIGH){
    switchState = 0;
    Serial.println("not touching");
  }
  if (digitalRead(magnet) == LOW){
    switchState = 1;
    Serial.println("touching");
  }
}
