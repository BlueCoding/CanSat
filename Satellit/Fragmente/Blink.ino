/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
int k; 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 16;

// the setup routine runs once when you press reset:
void setup() {                
  for (int i=16; i<24; i++) {
    pinMode(i, OUTPUT); 
  }
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  Serial.begin(9600);
  Serial1.begin(9600);
  k = 16;
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(k, HIGH);
  digitalWrite((k+1)%8+16, LOW);
  k = (k+1)%8+16;
  delay(200);
  Serial.println("b");
  Serial1.println(String(k));
}
