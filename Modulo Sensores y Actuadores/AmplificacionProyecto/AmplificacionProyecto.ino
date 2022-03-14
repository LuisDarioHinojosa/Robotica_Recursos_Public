// Autor: Luis Felipe Flores Sanchez & Luis Dario Hinojosa

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// 16 CHARACTERS AND 2 LINE DYSPLAY

LiquidCrystal_I2C lcd(0x27,16,2);


float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
float v;
int pinLM35 = A0; // Variable del pin de entrada del sensor (A0)
float tempNormal;
 
void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
 
}
 
void loop() {
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  v = analogRead(pinLM35);    
  // Calculamos la temperatura con la fórmula
  //tempC = v/2.046; // sin opam
  //tempC = (v*5*100)/1023;
  tempC = (v/20.46)+5; // Con opam
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("V(mv): ");
  lcd.print(v);
  lcd.setCursor(0,1);
  lcd.print("T(C): ");
  lcd.print(tempC);
  lcd.blink();
  delay(500);
  /*
  // Envia el dato al puerto serial
  Serial.print("V: ");
  Serial.print(v);
  Serial.print("\t");
  Serial.print("T: ");
  Serial.print(tempC);
  Serial.print("\n");
  */
  
  // Esperamos un tiempo para repetir el loop
  delay(1000);
}
