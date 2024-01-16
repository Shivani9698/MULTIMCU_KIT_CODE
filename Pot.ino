int Potentiometer;
void setup() {
  pinMode(26,INPUT);
  Serial.begin(115200);

}

void loop() {
 // Serial.println(analogRead(Potentiometer));
  int val=(analogRead(26));
  Serial.println("Potentiometer reading: ");
  Serial.println(val);
  delay(1000);

}
