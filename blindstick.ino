/*#include "talkie.h"
Talkie voice;*/

const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 6;
const int echoPin2 = 7;
const int trigPin3 = 8;
const int echoPin3 = 9;
const int trigPin4 = 4;
const int echoPin4 = 5;

const int buzzerPin = 10;
const int vibrationPin = 11;




void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  float distance1 = pulseIn(echoPin1, HIGH) / 58.0;


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  float distance2 = pulseIn(echoPin2, HIGH) / 58.0;


  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  float distance3 = pulseIn(echoPin3, HIGH) / 58.0;

  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  float distance4 = pulseIn(echoPin4, HIGH) / 58.0;

  Serial.println("distance1");
  Serial.println(distance1);
  delay(100);
  Serial.println("distance2");
  Serial.println(distance2);
  delay(100);
  Serial.println("distance3");
  Serial.println(distance3);
 delay(1000);
  Serial.println("distance4");
  Serial.println(distance4);

  for (int i = 0; i < 1; i++) {
    if (distance1 < 10 || distance2 < 10 || distance3 < 10 ) {

      digitalWrite(vibrationPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      delay(10);
      break;
    }

    else if (distance4 > 30) {
      digitalWrite(vibrationPin, LOW);
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
      delay(100);
      break;
    }

    else if ((distance1 >= 10 && distance1 <= 20) || (distance2 >= 10 && distance2 <= 20) || (distance3 >= 10 && distance3 <= 20) ) {

      // voice.say(spDANGER);
      // voice.say(spALERT);
      digitalWrite(vibrationPin, LOW);
     // digitalWrite(buzzerPin, HIGH);
       tone(buzzerPin, 500, 10); 
      delay(10);
      digitalWrite(buzzerPin, LOW);
      delay(10);
      break;
    }

    else {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(vibrationPin, LOW);
      delay(100);
    }
  }
}
