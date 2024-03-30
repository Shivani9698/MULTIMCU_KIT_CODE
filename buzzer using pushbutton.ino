const int buttonPin = 2;  // the number of the pushbutton pin
const int buzzer = 9;   // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(buzzer, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    tone(buzzer, 1000);
    Serial.println("State: ");
    Serial.println(buttonState);
    delay(100);
    
  } else {
    // turn LED off:
   noTone(buzzer);
    Serial.println("State: ");
    Serial.println(buttonState);
    delay(100);
  }
}
