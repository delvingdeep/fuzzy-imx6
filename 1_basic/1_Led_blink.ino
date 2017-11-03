/*Here leds are connected on pin number 13*/

int led = 13;   //defines the pin number

void setup() {
  // initailizing pin as Output pin
  pinMode(led, OUTPUT);
}

void loop() {
  //passing a high signal
  digitalWrite(led, HIGH);
  delay(1000);            //wait for 1 second
  //passing a low signal
  digitalWrite(led, LOW); //wait for  asecond
  delay(1000);
}
