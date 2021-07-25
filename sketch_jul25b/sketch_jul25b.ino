int trigger = 7;
int echo = 6;

long dauer = 0;
long entfernug = 0;

#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;


void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
}

void loop() {
  oled.setFont(Arial14); // Auswahl der Schriftart
  oled.clear(); //Löschen der aktuellen Displayanzeige
  
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  entfernug = (dauer/2) * 0.03432;
  if(entfernug >= 500 || entfernug <= 0){
    Serial.println("Keine Messung");
    oled.println("Keine Messung");
  }
  else{
    Serial.print(entfernug);
    oled.print(entfernug);
    Serial.println(" cm");
    oled.println(" cm");
  }
  delay(1000);
}
