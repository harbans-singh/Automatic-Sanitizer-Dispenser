/* This program is of Automatic Sanitizer Dispenser in which 'pump' is connected to pin 12, 'trig pin' of  
 * ultrasonic sensor is connected to pin 7 and 'echo pin' of sensor is connected to pin 6 of Arduino UNO board
 * and rest GND and Vcc pins are connected in desired pins of Arduino UNO board
 */

int trigPin = 7;              //trigger Pin of Ultrasonic Sensor
int echoPin = 6;              //echo Pin of Ultrasonic Sensor
int circuit_start = 12;       //pin to which pump is connected
int long duration;            //duration variable is set to hold the time taken by reflected wave to come back to sensor
int cm;                       //variable to hold distance of hand in centimeters from sensor

void setup()
{
  pinMode(trigPin, OUTPUT);             //set trig pin as output pin
  pinMode(echoPin, INPUT);              //set echo pin as input pin
  pinMode(circuit_start, OUTPUT);       //set circuit_start pin as output pin
}

void loop()
{
   
   digitalWrite(trigPin, LOW);          //set trig pin of Utrasonic sensor low for 2ms
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);         //set trig pin of sensor high for 10ms
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);   //time taken by reflected wave (reflected from hand) to come back
   cm = duration / 29 / 2;              //distance of hand from sensor in centimeters
    
   if(cm <=7)                           //if distance of hand from sensor is less than 7cm, sanitizer will be drawn out using motor
   {
    digitalWrite(circuit_start, HIGH);  //Pump starts up and sanitizer continues to come out for 170ms
    delay(170);
    digitalWrite(circuit_start, LOW);   //Pump is off for 2000ms or 2secs
    delay(2000);
   }
}
