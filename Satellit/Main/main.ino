
void setup() {
  Serial.begin(9600);
  int sw9 = 0;
  int sw8 = 0;
  int sw7 = 0;
  int sw6 = 0;
  int sw5 = 0;
  int sw4 = 0;
  int sw3 = 0;
  int sw2 = 0;
  int sw1 = 0;
  int k = 16;
  for (int i=16; i<24; i++) {
    pinMode(i, OUTPUT); 
  }
  // Digitalpins der LEDs als Outputs definieren
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
 int sw5 = analogRead(5);          //Werte auslesen
 int sw4 = analogRead(4);          //Werte auslesen
 int sw3 = analogRead(3);          //Werte auslesen
 int sw2 = analogRead(2);          //Werte auslesen
 int sw1 = analogRead(1);          //Werte auslesen
 digitalWrite(k, HIGH);            //leuchtreihe
 digitalWrite((k+1)%8+16, LOW);    //leuchtreihe
 k = (k+1)%8+16;                   //leuchtreihe
 //Werte lokal anzeigen:
 Serial.print("   A8(UV4):")
 Serial.print(sw8)
 Serial.print("   A7(UV3):");
 Serial.print(sw7);
 Serial.print("   A6(UV2):");
 Serial.print(sw6);
 Serial.print("   A5(UV1:");          
 Serial.print(sw5);                        
 Serial.print("   A4(Temperatur:):");       
 Serial.print(sw4);                        
 Serial.print("   A3(MQ-4):");         
 Serial.print(sw3);                        
 Serial.print("   A2(MQ-7):");       
 Serial.print(sw2);                        
 Serial.print("   A1(Druck):");    
 Serial.println(sw1);
//Werte absenden: 
 Serial1.print("  A8(UV4):");
 Serial1.print(sw8);
 Serial1.print("  A7(UV3):");
 Serial1.print(sw7);
 Serial1.print("  A6(UV2):");
 Serial1.print(sw6);
 Serial1.print("  A5(UV1:");          
 Serial1.print(sw5);                        
 Serial1.print("  A4(Temperatur:):");       
 Serial1.print(sw4);                        
 Serial1.print("  A3(MQ-4):");         
 Serial1.print(sw3);                        
 Serial1.print("  A2(MQ-7):");       
 Serial1.print(sw2);                        
 Serial1.print("  A1(Druck):");    
 Serial1.println(sw1);                                
}

void leuchtreihe () {
  digitalWrite(k, HIGH);
  delay(200);
  digitalWrite((k+1)%8+16, LOW);
  k = (k+1)%8+16;
  delay (200);
}

// Das PS-Modul geht an 3,3V + GND + D3 D2  (D3 hat PWM -> Wichtig?)
// PINs am Modul:        Vin   GND   TX RX


/*
//////////////////////////////////////////////////////////////////////////////////////////////////////
BEISPIELCODE ZUM ANSTEUERN VOM HIH6130
//////////////////////////////////////////////////////////////////////////////////////////////////////
--> an sich geht das alles, nur fehlt noch die HIH6130.h library

#include <Wire.h>
#include <HIH61XX.h>


//  Create an HIH61XX with I2C address 0x27, powered by 3.3V pin
HIH61XX hih(0x27);
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}


void loop()
{
  //  start the sensor
  hih.start();

  //  request an update of the humidity and temperature
  hih.update();

  Serial.print("Humidity: ");
  Serial.print(hih.humidity(), 5);
  Serial.print(" RH (");
  Serial.print(hih.humidity_Raw());
  Serial.println(")");

  Serial.print("Temperature: ");
  Serial.print(hih.temperature(), 5);
  Serial.println(" C (");
  Serial.print(hih.temperature_Raw());
  Serial.println(")");

  while(true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
