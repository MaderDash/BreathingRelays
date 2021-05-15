int numberofcycles= 8;

struct Cycles {
  char Messatetxt[50];      
  int  theDelay;       
  int relay1;
  int relay2;
  int relay3;
};

Cycles ours[8] ={
  { "Test all relays                                  ",    0,  1,  1,  1},
  { "Sieve A Charge / Sieve B Purge                   ", 4000,  1,  0,  0},
  { "Sieve A Charge / Sieve B Purge / Flush/PreCharge ",  450,  1,  0,  1},
  { "Sieve A Charge / Sieve B Charge / Flush/PreCharge",  700,  1,  1,  1},
  { "Sieve A Purge / Sieve B Charge                   ", 4000,  0,  1,  0},
  { "Sieve A Purge / Sieve B Charge / Flush/PreCharge ",  450,  0,  1,  1},
  { "Sieve A Charge / Sieve B Charge / Flush/PreCharge",  700,  1,  1,  1},
  { "All Off                                          ", 1000,  0,  0,  0} 
 
};

int valvePins[3]    = {5, 6, 7};
int fanPins[2]    = { 8, 9};

void setup() {
  Serial.begin(9600);
    //Set the Valve Pins to out
  for (int i = 0; i < 3; i++) {
    pinMode(valvePins[i], OUTPUT);
  }
  //Set the Fan Pins to out
    for (int i = 0; i < 2; i++) {
    pinMode(fanPins[i], OUTPUT);
  }
    Serial.println("Program Starting...");
    Serial.println(ours[0].Messatetxt);
    digitalWrite(valvePins[0],ours[0].relay1);
    digitalWrite(valvePins[1],ours[0].relay2);
    digitalWrite(valvePins[2],ours[0].relay3);
    delay(ours[0].theDelay);
    digitalWrite(fanPins[0], HIGH);
    digitalWrite(fanPins[1], HIGH);
    Serial.println("Fan Switched On");
}

void loop() {
  // we skip cycle 0
  for ( int thiscycle=1; thiscycle<numberofcycles; thiscycle++)
  {
    Serial.println(ours[thiscycle].Messatetxt);
    digitalWrite(valvePins[0],ours[thiscycle].relay1);
    digitalWrite(valvePins[1],ours[thiscycle].relay2);
    digitalWrite(valvePins[2],ours[thiscycle].relay3);
    delay(ours[thiscycle].theDelay);
  }
  Serial.println("---------------------------END -------------");
  delay(5000);
}
