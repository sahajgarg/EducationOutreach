/*
 * NAMES: YOUR NAMES HERE
 * Smarthome! A smart thermostat.
 * Workshop 2
 * 
 * In this file, you'll write an implementation of a smart thermostat. 
 * Follow ahead on the instructions, and good luck!
 * 
 * Schematics borrowed from: 
 * https://learn.adafruit.com/adafruit-arduino-lesson-13-dc-motors/breadboard-layout
 * https://www.arduino.cc/en/Tutorial/HelloWorld  
 */

const int FAN_PIN = 7;
bool fanOn = false; 
int temp = 0;
int desiredTemp = 68;
unsigned long currTime = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Welcome to our smart thermostat!");

  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = getTemperature(fanOn);
  currTime = millis();
    
  if(currTime % 24000 > 8000 && currTime % 24000 < 16000)
  {
    if(fanOn)
    {
      digitalWrite(FAN_PIN, LOW);
      fanOn = false;
      Serial.println("Nobody's home. Turning fan on!");
    }
    Serial.println("Nobody's home. Conserving energy!");
  } else
  {
    if(temp > desiredTemp && fanOn == false)
    {
      fanOn = true;
      digitalWrite(FAN_PIN, HIGH);
      Serial.println("Turning fan on!");
    }
  
    if(temp < desiredTemp && fanOn == true)
    {
      fanOn = false;
      digitalWrite(FAN_PIN, LOW);
      Serial.println("Turning fan off!");
    }
  }
  
  Serial.print("Temperature is ");
  Serial.println(temp);
  delay(500);  
}

