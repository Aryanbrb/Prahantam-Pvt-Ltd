const int relay1Pin = 7;  // SV 1 connected to digital 7 pin (SV Internal 1)
const int relay2Pin = 8;  // SV 2 connected to digital 8 pin (SV Internal 2)
const int relay3Pin = 9;  // SV 3 connected to digital 9 pin (SV External)
const int relay4Pin = 10; // Pump 1 connected to digital 10 pin (Detergent Pump)
const int relay5Pin = 11; // Pump 2 connected to digital 11 pin (Water Pump 1)
const int relay6Pin = 12; // Pump 3 connected to digital 12 pin (Water Pump 2)


const int button1Pin = 2; // 1st button: Will activate detergent pump
const int button2Pin = 3; // 2nd button: Will activate all Pumps and SVs
const int button3Pin = 4; // 3rd button: Will run 1st cycle 2s > 6s > 4s (low wash)
const int button4Pin = 5; // 4th button: Will run 2nd cycle 3s > 8s > 6s (medium wash)
const int button5Pin = 6; // 5th button: Will run 3rd cycle 4s > 12s > 9s (high wash)

void setup() {
  //  Activate all buttons and assigning them as input,
  //  pullup resistors inside Arduino activated

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
  pinMode(button5Pin, INPUT_PULLUP);

  // Activating all relays and assigning them as output to recieve signals

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
  pinMode(relay5Pin, OUTPUT);
  pinMode(relay6Pin, OUTPUT);

  // Relay are turned low initially.
  // Take care that Relay are low level trigerred and Pullups are used with buttons
  //hence HIGH = LOW here which means, assigning HIGH means we are turning it off.

  digitalWrite(relay1Pin, HIGH); // SV1
  digitalWrite(relay2Pin, HIGH); //SV2
  digitalWrite(relay3Pin, HIGH); //SV3
  digitalWrite(relay4Pin, HIGH); // Detergent Pump (PD1)
  digitalWrite(relay5Pin, HIGH); // Water Pump 1 (PW1)
  digitalWrite(relay6Pin, HIGH); // Water Pump 2 (PW2)
}



void loop() {
  // Pressing button 1: Detergent operation

  int buttonState1 = digitalRead(button1Pin); // Manual 1 button
  int buttonState2 = digitalRead(button2Pin); // Manual 2 button
  int buttonState3 = digitalRead(button3Pin); // Simple Wash cycle
  int buttonState4 = digitalRead(button4Pin); // Medium Wash cycle
  int buttonState5 = digitalRead(button5Pin); // High Wash Cycle

  // Manual button 1 - Activates only detergent
  if (buttonState1 == LOW and buttonState2 == HIGH and buttonState3 == HIGH and buttonState4 == HIGH and buttonState5 == HIGH) {
    digitalWrite(relay4Pin, LOW); // Detergent Pump
    delay(50);
  }

  // Manual button 2 - Activates 2 Water Pumps and 3 SVs (SI1, SI2, SE3) together (Relay 1,2,3,5 & 6)
  else if (buttonState1 == HIGH and buttonState2 == LOW and buttonState3 == HIGH and buttonState4 == HIGH and buttonState5 == HIGH) {
    digitalWrite(relay1Pin, LOW);
    digitalWrite(relay2Pin, LOW);
    digitalWrite(relay3Pin, LOW);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(50);
  }

  // Cycle 1 button - Runs SIMPLE WASH cycle
  /*
      1. PD1 on then off (Relay 4)
      2. Internal SVs and Water pumps on (Relay 1,2 and 5,6)
      3. Internal SV 1 (SI1) and Water Pumps turns on (Relay 1,5 and 6) and off
      4. Internal SV 2 (SI2) and Water pumps turns on (Relay 2,5 and 6) and off
      5. External SV 3 (SE3) and Water Pumps turns on (Relay 3,5 and 6) and off
  */
  else if (buttonState1 == HIGH and buttonState2 == HIGH and buttonState3 == LOW and buttonState4 == HIGH and buttonState5 == HIGH) {
    digitalWrite(relay4Pin, LOW); //Step 1 Starts
    delay(3000);
    digitalWrite(relay4Pin, HIGH); //Step 1 Ends
    delay(1000);
    digitalWrite(relay1Pin, LOW); //Step 2 Starts
    digitalWrite(relay2Pin, LOW);
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH); //Step 2 Ends
    delay(1000);
    digitalWrite(relay1Pin, LOW);  //Step 3 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay1Pin, HIGH); //Step 3 Ends
    delay(1000);
    digitalWrite(relay2Pin, LOW);  //Step 4 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay2Pin, HIGH); //Step 4 Ends
    delay(1000);
    digitalWrite(relay3Pin, LOW);  //Step 5 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay3Pin, HIGH); //Step 5 Ends
    
  }
  // Cycle 2 button - Runs MEDIUM WASH cycle
  /*
      1. PD1 on then off (Relay 4)
      2. Internal SVs and Water pumps on (Relay 1,2 and 5,6)
      3. Internal SV 1 (SI1) and Water Pumps turns on (Relay 1,5 and 6) and off
      4. Internal SV 2 (SI2) and Water pumps turns on (Relay 2,5 and 6) and off
      5. External SV 3 (SE3) and Water Pumps turns on (Relay 3,5 and 6) and off
  */
  else if (buttonState1 == HIGH and buttonState2 == HIGH and buttonState3 == HIGH and buttonState4 == LOW and buttonState5 == HIGH) {
    digitalWrite(relay4Pin, LOW); //Step 1 Starts
    delay(3000);
    digitalWrite(relay4Pin, HIGH); //Step 1 Ends
    delay(1000);
    digitalWrite(relay1Pin, LOW); //Step 2 Starts
    digitalWrite(relay2Pin, LOW);
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH); //Step 2 Ends
    delay(1000);
    digitalWrite(relay1Pin, LOW);  //Step 3 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay1Pin, HIGH); //Step 3 Ends
    delay(1000);
    digitalWrite(relay2Pin, LOW);  //Step 4 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay2Pin, HIGH); //Step 4 Ends
    delay(1000);
    digitalWrite(relay3Pin, LOW);  //Step 5 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay3Pin, HIGH); //Step 5 Ends
    
  }
  // Cycle 3 button - Runs HIGH WASH cycle
  /*
      1. PD1 on then off (Relay 4)
      2. Internal SVs and Water pumps on (Relay 1,2 and 5,6)
      3. Internal SV 1 (SI1) and Water Pumps turns on (Relay 1,5 and 6) and off
      4. Internal SV 2 (SI2) and Water pumps turns on (Relay 2,5 and 6) and off
      5. External SV 3 (SE3) and Water Pumps turns on (Relay 3,5 and 6) and off
  */

  else if (buttonState1 == HIGH and buttonState2 == HIGH and buttonState3 == HIGH and buttonState4 == HIGH and buttonState5 == LOW) {
    digitalWrite(relay4Pin, LOW); //Step 1 Starts
    delay(3000);
    digitalWrite(relay4Pin, HIGH); //Step 1 Ends
    delay(1000);
    digitalWrite(relay1Pin, LOW); //Step 2 Starts
    digitalWrite(relay2Pin, LOW);
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH); //Step 2 Ends
    delay(1000);
    digitalWrite(relay1Pin, LOW);  //Step 3 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay1Pin, HIGH); //Step 3 Ends
    delay(1000);
    digitalWrite(relay2Pin, LOW);  //Step 4 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay2Pin, HIGH); //Step 4 Ends
    delay(1000);
    digitalWrite(relay3Pin, LOW);  //Step 5 Starts
    delay(500);
    digitalWrite(relay5Pin, LOW);
    digitalWrite(relay6Pin, LOW);
    delay(6000);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
    delay(500);
    digitalWrite(relay3Pin, HIGH); //Step 5 Ends
   
  }
  
// Default Condition - ALL RELAYS OFF

  else
  {
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH);
    digitalWrite(relay3Pin, HIGH);
    digitalWrite(relay4Pin, HIGH);
    digitalWrite(relay5Pin, HIGH);
    digitalWrite(relay6Pin, HIGH);
  }

  delay(100);
}
