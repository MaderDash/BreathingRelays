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
// int DelayArray[8]   = {0, 4000, 450, 700, 4000, 450, 700, 1000};
 
// Relay Triggers
//===================
// There are 3 Main Relays
//
 
#define ON  HIGH
#define OFF LOW
 
int triggerArray[8][4] = {
  {ON,  ON,  ON,    0},   // Test all relays.
  {ON,  OFF, OFF,   4000},  // Sieve A Charge / Sieve B Purge
  {ON,  OFF, ON,    450},   // Sieve A Charge / Sieve B Purge / Flush/PreCharge
  {ON,  ON,  ON,    700},   // Sieve A Charge / Sieve B Charge / Flush/PreCharge
  {OFF, ON,  OFF,   4000},  // Sieve A Purge / Sieve B Charge
  {OFF, ON,  ON,    450},   // Sieve A Purge / Sieve B Charge / Flush/PreCharge
  {ON,  ON,  ON,    700},   // Sieve A Charge / Sieve B Charge / Flush/PreCharge
  {OFF, OFF, OFF,   1000}   // All Off
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
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  Serial.println("Fan Switched On");
}
 
int looped;
// Main Loop
//===========
void loop() {
  looped++;
  Serial.print("Loop: ");
  Serial.println(looped);
  cycler(1);  // cycle 1, delay 2/
  cycler(2);  // cycle 2, delay 3/
  cycler(3);  // cycle 3, delay 4/
  cycler(4);  // cycle 4, delay 2/
  cycler(5);  // cycle 5, delay 3/
  cycler(6);  // cycle 6, delay 4/
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
void cycler(int call) {
  Serial.println(message[call]);
 
  for (int i = 0; i < 3; i++) {
   int onOrOff=(triggerArray[call][i] == ON);
   digitalWrite(valvePins[i], onOrOff);  
  Serial.print("ValvePin");
  Serial.print(valvePins[i]);
  Serial.print(" ");
    if(onOrOff) Serial.println("HIGH");
     else Serial.println("LOW");
  }
  Serial.print("Delay: ");
  Serial.println(triggerArray[call][3]);
  delay(triggerArray[call][3]);
}
