#include <Servo.h>
//declaring all the digital output pin numbers used for the arduino
int TRIG_PIN = 4; 
int ECHO_PIN = 3; 
int MOTOR_PIN1 = 10; 
int MOTOR_PIN2 = 11;
int MOTOR_PIN3 = 6;
int MOTOR_PIN4 = 5;
int servo_pin=2;
//defining the speed of sound for the ultrasonic sensor
float SPEED_OF_SOUND = 0.0345; 
//declaring the name of the servo
Servo myservo;

void setup() {
  pinMode (MOTOR_PIN1, OUTPUT) ; //set all 4 motor pins as output
  pinMode (MOTOR_PIN2, OUTPUT) ;
  pinMode (MOTOR_PIN3, OUTPUT) ;
  pinMode (MOTOR_PIN4, OUTPUT) ;
  pinMode (TRIG_PIN, OUTPUT) ; //set trigger pin of ultrasonic sensor as output
  digitalWrite(TRIG_PIN, LOW); //initally, trigger pin is set to low
  pinMode (ECHO_PIN, INPUT) ; //set echo pin of ultrasonic sensor as input for reading distance
  Serial.begin (9600); //establish communication between computer and arduino
  myservo.attach(servo_pin); 
  myservo.write(0); //set inital servo position
}
  
  
void loop() {
  digitalWrite(TRIG_PIN, HIGH); //ultrasonic sensor sends out a pulse wave
  delayMicroseconds (10); 
  digitalWrite (TRIG_PIN, LOW); 
  int microsecs = pulseIn (ECHO_PIN, HIGH); //ultrasonic sensors time the duration for the pulse to reflect back
  float cms = microsecs * SPEED_OF_SOUND/2; //use the time to calculate the distance to the wall
  Serial.println(cms); // print the distance on serial monitor for debugging purposes
  if(cms < 15) { //if distance to the wall is less than 15cm
    digitalWrite (MOTOR_PIN1, LOW); //motor will stop spinning
    digitalWrite (MOTOR_PIN2, LOW);
    digitalWrite (MOTOR_PIN3, LOW);
    digitalWrite (MOTOR_PIN4, LOW);
    delay(1000); //delay for 1 second
    myservo.write(90); //servo to change from position 0 to position 90, catapult arm will swing up
    delay(3000); //catapult arm will stay up for 3 seconds
    myservo.write(0); //catapult returns back to inital position
    delay(2000); //delay for 2 seconds
    digitalWrite (MOTOR_PIN1,LOW);  //motor will spin in reverse direction
    digitalWrite (MOTOR_PIN2, LOW); 
    digitalWrite (MOTOR_PIN3, HIGH); 
    digitalWrite (MOTOR_PIN4, HIGH);
    delay(11000);
    } else { //if distance is more than and equal to 15 cm
    digitalWrite (MOTOR_PIN1, HIGH); //motor will spin in forard direction
    digitalWrite (MOTOR_PIN2, HIGH); 
    digitalWrite (MOTOR_PIN3, LOW); 
    digitalWrite (MOTOR_PIN4, LOW); 
   }
   delay (10);
}