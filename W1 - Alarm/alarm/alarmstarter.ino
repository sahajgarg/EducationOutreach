/*
 * LED Alarm System Starter Code
 * 
 * This file contains all starter code for Workshop 1. Any function in 
 * alarmStarter.ino can be called from alarm.ino.
 * 
 * This contains functionality for:
 *  -Reseting LED
 *  -Turning the LED a specific color
 */

const int RED_PIN = 10;
const int BLUE_PIN = 9; 
const int GREEN_PIN = 11;


//Compute distance in cm by dividing time to receive ping by speed of ping
int getSonarDistance() 
{
  unsigned int pingTime = sonar.ping(); //see how long it takes to send a ping and receive it 
  unsigned int distance = pingTime/US_ROUNDTRIP_CM; //compute distance based on speed of ping
  return distance;
}

//Turn the LED off; used for initialization of LED
void resetLights() 
{
  analogWrite(RED_PIN,0);
  analogWrite(BLUE_PIN,0);
  analogWrite(GREEN_PIN,0);
}

//Color the LED any specified RGB color
void color (unsigned char red, unsigned char green, unsigned char blue) 
{     
    analogWrite(RED_PIN, red);     
    analogWrite(BLUE_PIN, blue);
    analogWrite(GREEN_PIN, green);
}

void soundAlarm() 
{
  float sinVal;
  int toneVal;
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = 2000+(int(sinVal*1000));
    NewTone(ALARM, toneVal);
  }
}
