#include <NewPing.h>

/*
 * NAME: 
 * LED Alarm System 
 * Workshop 1
 * 
 * Project borrowed and modified from 
 * http://www.makeuseof.com/tag/how-to-make-a-simple-arduino-alarm-system/
 */

#include <NewPing.h>
#include <NewTone.h>

// Select which PWM-capable pins are to be used.
const int RED_PIN =       10;
const int GREEN_PIN =     11;
const int BLUE_PIN =      9;

const int TRIGGER_PIN =   6;  // Arduino pin tied to trigger pin on the ultrasonic sensor.
const int ECHO_PIN =      7;  // Arduino pin tied to echo pin on the ultrasonic sensor.
const int MAX_DISTANCE =  100; // Maximum distance we want to ping for (in centimeters).

const int ALARM = 3;

float sinVal;
int toneVal;
bool triggered;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() { 
  // setup code runs once when the program starts
  
  //set pinModes for RGB strip
  pinMode(RED_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(ALARM, OUTPUT); //Set pinMode for Alarm

  //reset lights
  analogWrite(RED_PIN,0);
  analogWrite(BLUE_PIN,0);
  analogWrite(RED_PIN,0);

  triggered = false; //Alarm has not yet been tripped

  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.  
  
  //delay to give time to get out of the way
  delay(5000); 
}

void loop() {
  if(triggered == true) {
    alarm();
  } else {
    delay(50); //Don't repeatedly check too quickly

    unsigned int pingTime = sonar.ping(); //see how long it takes to send a ping and receive it 
    unsigned int distance = pingTime/US_ROUNDTRIP_CM; //compute distance based on speed of ping
    Serial.println(distance); //output distance to the serial monitor
    if(distance < MAX_DISTANCE) {
      triggered = true;
    }
  }
}

//helper function enabling us to send a color in one command
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{     
    analogWrite(RED_PIN, red);     
    analogWrite(BLUE_PIN, blue);
    analogWrite(GREEN_PIN, green);
}

//Flashes light if alarm is tripped
void alarm(){
  //Sound the alarm
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = 2000+(int(sinVal*1000));
    NewTone(ALARM, toneVal);
  }

  //Flash the lights
  color(255,0,0); //red
  delay(100);
  color(255,255,0); //yelow
  delay(100);
}
