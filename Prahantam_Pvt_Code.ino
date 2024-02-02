const int relay1Pin = 7;  // SV 1 connected to digital 8 pin
const int relay2Pin = 8;  // SV2 connected to digital 9 pin
const int relay3Pin = 9; // Pump 1 connected to digital 10 pin (Detergent Pump)
const int relay4Pin = 10; // Pump 2 connected to digital 11 pin
const int relay5Pin = 11; // Pump 3 connected to digital 12 pin


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

  // Relay are turned low initially.
  // Take care that Relay are low level trigerred and Pullups are used with buttons
  //hence HIGH = LOW here which means, assigning HIGH means we are turning it off.

  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);
  digitalWrite(relay3Pin, HIGH);
  digitalWrite(relay4Pin, HIGH);
  digitalWrite(relay5Pin, HIGH);
}



void loop() {
  // Pressing button 1: Detergent operation

  int buttonState1 = digitalRead(button1Pin);
  int buttonState2 = digitalRead(button2Pin);
  int buttonState3 = digitalRead(button3Pin);
  int buttonState4 = digitalRead(button4Pin);
  int buttonState5 = digitalRead(button5Pin);

  if (buttonState1 == LOW and buttonState2 == HIGH and buttonState3 == HIGH and buttonState4 == HIGH and buttonState5 == HIGH) {
    digitalWrite(relay3Pin, LOW);
    delay(50);
  }

  
  else if (buttonState1 == HIGH and buttonState2 == LOW and buttonState3 == HIGH and buttonState4 == HIGH and buttonState5 == HIGH) {
    digitalWrite(relay1Pin, LOW);
    digitalWrite(relay2Pin, LOW);
    digitalWrite(relay4Pin, LOW);
    digitalWrite(relay5Pin, LOW);
    delay(50);
  }
 
  
 else if (buttonState1 == HIGH and buttonState2 == HIGH and buttonState3 == LOW and buttonState4 == HIGH and buttonState5 == HIGH) {
    digitalWrite(relay3Pin, LOW);  // Detergent Pump turns ON
    delay(2000);
    digitalWrite(relay3Pin, HIGH); // Detergent Pump turns OFF
    delay(500);
    digitalWrite(relay1Pin, LOW);  // SV 1 turns ON 
    delay(500);
    digitalWrite(relay4Pin, LOW);  // Pump 2 turns ON
    digitalWrite(relay5Pin, LOW);  // Pump 3 also turns ON
    delay(6000);
    digitalWrite(relay4Pin, HIGH); // Pump 2 turns OFF
    digitalWrite(relay5Pin, HIGH); // Pump 3 turns OFF
    delay(500);
    digitalWrite(relay1Pin, HIGH); // SV1 turns OFF and inner wash complete
    delay(1000);
    digitalWrite(relay2Pin, LOW);
    delay(500);
    digitalWrite(relay4Pin, LOW);
    digitalWrite(relay5Pin, LOW);
    delay(4000);
    digitalWrite(relay4Pin, HIGH);
    digitalWrite(relay5Pin, HIGH);
    delay(500);
    digitalWrite(relay2Pin, HIGH);
  }

  else if (buttonState1 == HIGH and buttonState2 == HIGH and buttonState3 == HIGH and buttonState4 == LOW and buttonState5 == HIGH) {
    digitalWrite(relay3Pin, LOW);  // Detergent Pump turns ON
    delay(3500);
    digitalWrite(relay3Pin, HIGH); // Detergent Pump turns OFF
    delay(500);
    digitalWrite(relay1Pin, LOW);  // SV 1 turns ON 
    delay(500);
    digitalWrite(relay4Pin, LOW);  // Pump 2 turns ON
    digitalWrite(relay5Pin, LOW);  // Pump 3 also turns ON
    delay(7000);
    digitalWrite(relay4Pin, HIGH); // Pump 2 turns OFF
    digitalWrite(relay5Pin, HIGH); // Pump 3 turns OFF
    delay(500);
    digitalWrite(relay1Pin, HIGH); // SV1 turns OFF and inner wash complete
    delay(1000);
    digitalWrite(relay2Pin, LOW);
    delay(500);
    digitalWrite(relay4Pin, LOW);
    digitalWrite(relay5Pin, LOW);
    delay(6000);
    digitalWrite(relay4Pin, HIGH);
    digitalWrite(relay5Pin, HIGH);
    delay(500);
    digitalWrite(relay2Pin, HIGH);
  } 

  else if (buttonState1 == HIGH and buttonState2 == HIGH and buttonState3 == HIGH and buttonState4 == HIGH and buttonState5 == LOW) {
    digitalWrite(relay3Pin, LOW);  // Detergent Pump turns ON
    delay(5000);
    digitalWrite(relay3Pin, HIGH); // Detergent Pump turns OFF
    delay(500);
    digitalWrite(relay1Pin, LOW);  // SV 1 turns ON 
    delay(500);
    digitalWrite(relay4Pin, LOW);  // Pump 2 turns ON
    digitalWrite(relay5Pin, LOW);  // Pump 3 also turns ON
    delay(9000);
    digitalWrite(relay4Pin, HIGH); // Pump 2 turns OFF
    digitalWrite(relay5Pin, HIGH); // Pump 3 turns OFF
    delay(500);
    digitalWrite(relay1Pin, HIGH); // SV1 turns OFF and inner wash complete
    delay(1000);
    digitalWrite(relay2Pin, LOW);
    delay(500);
    digitalWrite(relay4Pin, LOW);
    digitalWrite(relay5Pin, LOW);
    delay(7500);
    digitalWrite(relay4Pin, HIGH);
    digitalWrite(relay5Pin, HIGH);
    delay(500);
    digitalWrite(relay2Pin, HIGH);
  }
   
  else
  {
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH);
    digitalWrite(relay3Pin, HIGH);
    digitalWrite(relay4Pin, HIGH);
    digitalWrite(relay5Pin, HIGH);
  }
  
delay(100);
}
