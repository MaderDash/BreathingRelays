int valvePins[5]    = {5, 6, 7, 8, 9};
int DelayArray[5]   = {0, 1000, 4000, 450, 700};
// If there is a 1 in this array then the pin turns HIGH, if 0 then the pin turns LOW.
bool triggerArray[8][3] = {
  {1, 1, 1},              //Test all relays.
  {1, 0, 0},              //Sieve A Charge / Sieve B Purge
  {1, 0, 1},              //Sieve A Charge / Sieve B Purge / Flush/PreCharge
  {1, 1, 1},              //Sieve A Charge / Sieve B Charge / Flush/PreCharge
  {0, 1, 0},              //Sieve A Purge / Sieve B Charge
  {0, 1, 1},              //Sieve A Purge / Sieve B Charge / Flush/PreCharge
  {1, 1, 1},              //Sieve A Charge / Sieve B Charge / Flush/PreCharge
  {0, 0, 0}               //all off
};
char *message[] = {" left void", "Sieve A Charge / Sieve B Purge", "Sieve A Charge / Sieve B Purge / Flush/PreCharge",
                   "Sieve A Charge / Sieve B Charge / Flush/PreCharge", "Sieve A Purge / Sieve B Charge",
                   "Sieve A Purge / Sieve B Charge / Flush/PreCharge", "Sieve A Charge / Sieve B Charge / Flush/PreCharge"
                  };
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(valvePins[i], OUTPUT);
  }
  Serial.println("Program Starting...");
  delay(DelayArray[0]);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  Serial.println("Fan Switched On");
}
void loop() {
  //cycle 1 called 1 is for the first part of the triggerArray,
  //the 2 is the delay that is needed to be used.DelayArray 2 = 4000.
  cycler(1, 2);    //cycle 2, delay 3/
  cycler(2, 3);    //cycle 2, delay 3/
  cycler(3, 4);    // cycle 3
  cycler(4, 2);    //cycle 4
  cycler(5, 3);    //cycle 5
  cycler(6, 4);    //cycle 6
}
void cycler(int call, int hold) {
  Serial.println(message[call]);
  for (int i = 0; i < 3; i++) {
    if (triggerArray[call][i] == 1) {
      digitalWrite(valvePins[i], HIGH);
    } else {
      digitalWrite(valvePins[i], LOW);
    }
  }
  delay(DelayArray[hold]);
}
