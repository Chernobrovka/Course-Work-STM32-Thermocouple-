#include "max6675.h"

int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600); 

  Serial.println("MAX6675 test");
  delay(500);
}

void loop() {
  
   Serial.print("C = ");
   Serial.println(thermocouple.readCelsius());

   delay(1000);
}
