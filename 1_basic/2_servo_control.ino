/*Here Servo motor is connected at pin number 9 */

#include <Servo.h>

Servo myservo; //create servo object to control a servo
int pos = 0;  //variable to store the servo position

void setup() {
  myservo.attach(9);  //attaches the servo on pin 9
}

void loop() {
  //parsing position value to servo from 0 to 180 degrees
  //with +1, it increments position by 1 degree.
  for (pos =0; pos <=180; pos +=1){
    myservo.write(pos);
    delay(15);
  }
  //parsing position value to servo from 180 to 0 degrees
  for (pos=180; pos>=0; pos -=1){
    myservo.write(pos);
    delay(15);
  }
}
