/*
 * Jan 2019
 * ERICA JEWELL
 * - Magnet switch used to detect whether the bicycle is being pedalled.
 * - Five relays are successively switched on after a certain "distance" pedalled.
 * - When magnet switch has not been turned on after a certain time, turn off relays.
 */

int magnet = 3; // connect S (signal) of magnetic switch to digital pin 0
int relay1 = 4; // relays to pins 1 - 5
int relay2 = 5;
int relay3 = 6;
int relay4 = 7;
int relay5 = 8;
int relay6 = 9;
int relay7 = 10;
int relay8 = 11;

int randomSet1[8] = {6, 8, 5, 10, 7, 11, 4, 9};
int randomSet2[8] = {9, 4, 11, 7, 5, 6, 10, 8};
int randomSet3[8] = {5, 7, 10, 8, 9, 4, 11, 6};

bool stopped = false;
bool flashing = false;
bool randomWords = false;
bool set1 = true;
bool set2 = false;
bool set3 = false;

int random1, random2, random3, random4, random5, random6, random7, random8;

int switchState = 0; // state of magnet switch
int lastSwitchState = 0; // last state of magnet switch
int distancePedalled = 0; // how far the cyclist has pedalled
unsigned long timeStopped = 0; // milliseconds passed since the wheel (magnet) has made a full revolution
unsigned long timeFlashed = 0;
// change these ones
int distancePerWord = 10; // how many revolutions are required for a word to light up (relay)
int timeToStop = 1000; // milliseconds of inactivity required to switch everything off

void setup(){
  Serial.begin(9600);
  pinMode(magnet, INPUT);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, HIGH);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, HIGH);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay4, HIGH);
  pinMode(relay5, OUTPUT);
  digitalWrite(relay5, HIGH);
  pinMode(relay6, OUTPUT);
  digitalWrite(relay6, HIGH);
  pinMode(relay7, OUTPUT);
  digitalWrite(relay7, HIGH);
  pinMode(relay8, OUTPUT);
  digitalWrite(relay8, HIGH);
  random1 = randomSet1[0];
  random2 = randomSet1[1];
  random3 = randomSet1[2];
  random4 = randomSet1[3]; 
  random5 = randomSet1[4]; 
  random6 = randomSet1[5]; 
  random7 = randomSet1[6]; 
  random8 = randomSet1[7];
}
  
void loop(){
  /*Serial.println(random1);
  Serial.println(random2);
  Serial.println(random3);
  Serial.println(random4); 
  Serial.println(random5);
  Serial.println(random6);
  Serial.println(random7);
  Serial.println(random8);*/
  checkSwitch();
  if (switchState == 1 && lastSwitchState == 0){
    stopped = false;
    distancePedalled++; // magnet has made one revolution
  }
  
//--NORMAL MODE--
  if (randomWords == false){
    if (distancePedalled > 2 && distancePedalled < distancePerWord*2){
       digitalWrite(relay1, LOW);  
    }
    if (distancePedalled > distancePerWord*2 && distancePedalled < distancePerWord*3){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, LOW);  
    }
    if (distancePedalled > distancePerWord*3 && distancePedalled < distancePerWord*4){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, HIGH);  
      digitalWrite(relay3, LOW);  
    }
    if (distancePedalled > distancePerWord*4 && distancePedalled < distancePerWord*5){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, HIGH);  
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, LOW);  
    }
    if (distancePedalled > distancePerWord*5 && distancePedalled < distancePerWord*6){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, HIGH);  
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH); 
      digitalWrite(relay5, LOW);  
    }
    if (distancePedalled > distancePerWord*6 && distancePedalled < distancePerWord*7){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, HIGH);  
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH); 
      digitalWrite(relay5, HIGH);  
      digitalWrite(relay6, LOW);  
    }
    if (distancePedalled > distancePerWord*7 && distancePedalled < distancePerWord*8){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, HIGH);  
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH); 
      digitalWrite(relay5, HIGH);  
      digitalWrite(relay6, HIGH); 
      digitalWrite(relay7, LOW);  
    }
    if (distancePedalled > distancePerWord*8 && distancePedalled < distancePerWord*9){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, HIGH);  
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH); 
      digitalWrite(relay5, HIGH);  
      digitalWrite(relay6, HIGH); 
      digitalWrite(relay7, HIGH); 
      digitalWrite(relay8, LOW); 
    }
  }

//--RANDOM MODE--
if (randomWords == true){
    if (distancePedalled > 2 && distancePedalled < distancePerWord*2){
       digitalWrite(random1, LOW);  
    }
    if (distancePedalled > distancePerWord*2 && distancePedalled < distancePerWord*3){
      digitalWrite(random1, HIGH);  
      digitalWrite(random2, LOW);  
    }
    if (distancePedalled > distancePerWord*3 && distancePedalled < distancePerWord*4){
      digitalWrite(random1, HIGH);  
      digitalWrite(random2, HIGH);  
      digitalWrite(random3, LOW);  
    }
    if (distancePedalled > distancePerWord*4 && distancePedalled < distancePerWord*5){
      digitalWrite(random1, HIGH);  
      digitalWrite(random2, HIGH);  
      digitalWrite(random3, HIGH);
      digitalWrite(random4, LOW);  
    }
    if (distancePedalled > distancePerWord*5 && distancePedalled < distancePerWord*6){
      digitalWrite(random1, HIGH);  
      digitalWrite(random2, HIGH);  
      digitalWrite(random3, HIGH);
      digitalWrite(random4, HIGH); 
      digitalWrite(random5, LOW);  
    }
    if (distancePedalled > distancePerWord*6 && distancePedalled < distancePerWord*7){
      digitalWrite(random1, HIGH);  
      digitalWrite(random2, HIGH);  
      digitalWrite(random3, HIGH);
      digitalWrite(random4, HIGH); 
      digitalWrite(random5, HIGH);  
      digitalWrite(random6, LOW);  
    }
    if (distancePedalled > distancePerWord*7 && distancePedalled < distancePerWord*8){
      digitalWrite(random1, HIGH);  
      digitalWrite(random2, HIGH);  
      digitalWrite(random3, HIGH);
      digitalWrite(random4, HIGH); 
      digitalWrite(random5, HIGH);  
      digitalWrite(random6, HIGH); 
      digitalWrite(random7, LOW);  
    }
    if (distancePedalled > distancePerWord*8 && distancePedalled < distancePerWord*9){
      digitalWrite(random1, HIGH);  
      digitalWrite(random2, HIGH);  
      digitalWrite(random3, HIGH);
      digitalWrite(random4, HIGH); 
      digitalWrite(random5, HIGH);  
      digitalWrite(random6, HIGH); 
      digitalWrite(random7, HIGH); 
      digitalWrite(random8, LOW);  
    }
}
    
//--FLASHING--   
  /*if (distancePedalled > distancePerWord*9 && distancePedalled < distancePerWord*10){
      digitalWrite(relay1, LOW);  
      digitalWrite(relay2, LOW);  
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW); 
      digitalWrite(relay5, LOW);  
      digitalWrite(relay6, LOW); 
      digitalWrite(relay7, LOW); 
      digitalWrite(relay8, LOW);  
  } */
  if (distancePedalled > distancePerWord*9 && flashing == false){
    timeFlashed = millis();
    flashing = true;
  }
  if (distancePedalled > distancePerWord*9 && flashing == true){
    if ((millis() - timeFlashed) < 2000){
      digitalWrite(relay1, LOW);  
      digitalWrite(relay2, LOW);  
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW); 
      digitalWrite(relay5, LOW);  
      digitalWrite(relay6, LOW); 
      digitalWrite(relay7, LOW); 
      digitalWrite(relay8, LOW);  
    }
    else if ((millis() - timeFlashed) < 2500){
      digitalWrite(relay1, HIGH);  
      digitalWrite(relay2, HIGH);  
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH); 
      digitalWrite(relay5, HIGH);  
      digitalWrite(relay6, HIGH); 
      digitalWrite(relay7, HIGH); 
      digitalWrite(relay8, HIGH);  
    }
    else if ((millis() - timeFlashed) > 2500){  
      flashing = false;   
    }
  }

//--STOPPED--
  if (switchState == 0 && lastSwitchState == 0 && stopped == false || switchState == 1 && lastSwitchState == 1 && stopped == false){
     timeStopped = millis();
     stopped = true;
  }
  if (stopped == true && (millis() - timeStopped) > timeToStop){
     distancePedalled = 0;
     digitalWrite(relay1, HIGH);
     digitalWrite(relay2, HIGH);
     digitalWrite(relay3, HIGH);
     digitalWrite(relay4, HIGH);
     digitalWrite(relay5, HIGH);
     digitalWrite(relay6, HIGH);
     digitalWrite(relay7, HIGH);
     digitalWrite(relay8, HIGH);  
     stopped = false;
     flashing = false;
     goRandomWords();
  }
  lastSwitchState = switchState;
}

//--CHECK SWITCH--
void checkSwitch(){  // detect whether bicycle is being pedalled
  if (digitalRead(magnet) == HIGH){
    switchState = 0;
  }
  if (digitalRead(magnet) == LOW){
    switchState = 1;
  }
}

//--CHANGE RANDOMNESS--
void goRandomWords(){
  Serial.println("random loop");
  randomWords = !randomWords;
  if (set1 == true){
    random1 = randomSet2[0];
    random2 = randomSet2[1];
    random3 = randomSet2[2];
    random4 = randomSet2[3]; 
    random5 = randomSet2[4]; 
    random6 = randomSet2[5]; 
    random7 = randomSet2[6]; 
    random8 = randomSet2[7];
    set1 = false;
    set2 = true;
  }
  else if (set2 == true){
    random1 = randomSet1[0];
    random2 = randomSet1[1];
    random3 = randomSet1[2];
    random4 = randomSet1[3]; 
    random5 = randomSet1[4]; 
    random6 = randomSet1[5]; 
    random7 = randomSet1[6]; 
    random8 = randomSet1[7];
    set2 = false;
    set3 = true;
  }
  else if (set3 == true){
    random1 = randomSet3[0];
    random2 = randomSet3[1];
    random3 = randomSet3[2];
    random4 = randomSet3[3]; 
    random5 = randomSet3[4]; 
    random6 = randomSet3[5]; 
    random7 = randomSet3[6]; 
    random8 = randomSet3[7];
    set3 = false;
    set1 = true;
  }
}
