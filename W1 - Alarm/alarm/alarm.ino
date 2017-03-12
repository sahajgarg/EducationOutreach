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

const int TRIGGER_PIN =   6;  // Arduino pin tied to trigger pin on the ultrasonic sensor.
const int ECHO_PIN =      7;  // Arduino pin tied to echo pin on the ultrasonic sensor.
const int MAX_DISTANCE =  500; 

const int ALARM = 3;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


//Initialize the ECHO_PIN, TRIGGER_PIN, and ALARM pins here!

void setup() { 
  //setup code runs once when the program starts
  
  //Challenge 2: setup pin modes for the blue and green pins
  pinMode(10, OUTPUT);

  //Now, reset the lights by calling the appropriate function
  
  //delay(5000); //delay to give time to get out of the way
}

void loop() { 
  //loop code repeats while the program is running
  //Challenge 3-6: Working with LEDs. Write your code here! 

  delay(10000); //delay so you can tell when the loop finishes one cycle
}

