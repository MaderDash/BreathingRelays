// Project: Breathing Machine Relays
//
//
//
//=========================================

// Global Variables
//==================
// valvePins are used for the Breathing Machine Relays
int valvePins[5]    = {5, 6, 7, 8, 9};

// Delay Array is how long to wait for each cycle
// valules are in Milliseconds
// example: 4000 Milliseconds = 4 seconds
int DelayArray[5]   = {0, 1000, 4000, 450, 700};

// Relay Triggers
//===================
// There are 3 Main Relays
//

#define ON HIGH
#define OFF LOW

bool triggerArray[8][3] = {
  {ON,  ON,  ON},   // Test all relays.
  {ON,  OFF, OFF},  // Sieve A Charge / Sieve B Purge
  {ON,  OFF, ON},   // Sieve A Charge / Sieve B Purge / Flush/PreCharge
  {ON,  ON,  ON},   // Sieve A Charge / Sieve B Charge / Flush/PreCharge
  {OFF, ON,  OFF},  // Sieve A Purge / Sieve B Charge
  {OFF, ON,  ON},   // Sieve A Purge / Sieve B Charge / Flush/PreCharge
  {ON,  ON,  ON},   // Sieve A Charge / Sieve B Charge / Flush/PreCharge
  {OFF, OFF, OFF}   // All Off
};

// Messages for each Cycle
//==========================
char *message[] = {
  "",
  "Sieve A Charge / Sieve B Purge",
  "Sieve A Charge / Sieve B Purge / Flush/PreCharge",
  "Sieve A Charge / Sieve B Charge / Flush/PreCharge",
  "Sieve A Purge / Sieve B Charge",
  "Sieve A Purge / Sieve B Charge / Flush/PreCharge",
  "Sieve A Charge / Sieve B Charge / Flush/PreCharge"
};

// Main Setup
//================
void setup() {
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

// Main Loop
//===========
void loop() {
  cycler(1, 2);  // cycle 1, delay 2/
  cycler(2, 3);  // cycle 2, delay 3/
  cycler(3, 4);  // cycle 3, delay 4/
  cycler(4, 2);  // cycle 4, delay 2/
  cycler(5, 3);  // cycle 5, delay 3/
  cycler(6, 4);  // cycle 6, delay 4/
}

// Functions
// ================
//

// Function: cycler
//--------------------------
// Cycler uses 2 parameters
// parameter 1 = cycle number
// parameter 2 = points to which delay to use
// for example DelayArray item 2 = 4000 Milliseconds = 4 Seconds
void cycler(int call, int hold) {
  Serial.println(message[call]);
  for (int i = 0; i < 3; i++) {
    int onOrOff=(triggerArray[call][i] == ON);
    digitalWrite(valvePins[i], onOrOff);
  }
  delay(DelayArray[hold]);
}
