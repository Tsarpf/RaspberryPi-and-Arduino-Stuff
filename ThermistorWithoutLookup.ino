#include <avr/pgmspace.h>
#include <math.h>

int led_state;
unsigned long time;

#define THERM_PIN 0

const int ledPin = 13;
const double resist = 10000; //ohms

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  time = millis();
  Serial.println("Ready!");
}

double Thermister(int RawADC) {
 double Temp;
 Temp = log(((1024 * resist /RawADC) - resist));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 return Temp;
}

void loop()
{
  int therm;
  therm = analogRead(THERM_PIN);
  double loltherm = Thermister(therm);
  
  Serial.println(loltherm, DEC);
  
  delay(1000);
  
  if(millis() - time > 1000)
  {
    time = millis();
    digitalWrite(13, led_state);
    led_state=!led_state;
  }
  
}


void flash(int n)
{
  for (int i = 0; i < n; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}
