#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 5;
const int echoPin = 4;
const int ledPin = 6;
const int buzPin = 7;

long duration;
int distance;

void setup() {
  delay(500);              
  lcd.init();               
  lcd.backlight();          

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);


  distance = (duration / 2) * 0.034;

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");


  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzPin, LOW);
  }

  delay(500);
}
