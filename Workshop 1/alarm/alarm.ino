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

const int RED_PIN = 10;
const int BLUE_PIN = 9; //Fix these numbers!
const int GREEN_PIN = 11;

//Initialize the ECHO_PIN, TRIGGER_PIN, and ALARM pins here!

void setup() { 
  //setup code runs once when the program starts
  
  //Challenge 2: setup pin modes for the blue and green pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  //Now, reset the lights by calling the appropriate function
  
  //delay(5000); //delay to give time to get out of the way
}

void loop() { 
  //loop code repeats while the program is running
  //Challenge 3-6: Worki  ng with LEDs. Write your code here! 

  delay(10000); //delay so you can tell when the loop finishes one cycle
}

