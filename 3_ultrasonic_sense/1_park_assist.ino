/*
 HC-SR04 Ping distance sensor

 Connections:
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 180 ohm resistor to both LED NEG and GRD power rail

 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */

#define trigPin 13
#define echoPin 12
#define ledRed 11
#define ledGreen 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}


void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance < 10 && distance > 0) {  // This is where the LED On/Off happens
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(ledRed,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(ledGreen,LOW);
  }
  else if(distance >= 10 && distance < 100){
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(ledRed,LOW);
    digitalWrite(ledGreen,HIGH);
  }
  else if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    digitalWrite(ledRed,LOW);
    digitalWrite(ledGreen,LOW);
  }
  else {
    digitalWrite(ledRed,LOW);
    digitalWrite(ledGreen,LOW);
  }
  delay(400);
}
