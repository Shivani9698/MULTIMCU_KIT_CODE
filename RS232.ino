void setup() {
  // start communication with baud rate 9600
  //Serial.begin(9600);   // Serial Monitor
  Serial2.begin(9600);  // RS232

  // wait a moment to allow serial ports to initialize
  delay(100);
}

void loop() {
  // Check if there's data available on Serial
  Serial2.println("Val : " + String(random(1,100)));
  if (Serial2.available()) {
    char data = Serial2.read();  // read the received character
    Serial2.print(data);          // print the recived data to Serial Monitor
  }
}
