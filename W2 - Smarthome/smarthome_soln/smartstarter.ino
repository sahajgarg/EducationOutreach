/*
 * Smarthome starter code! This file takes care of simulating 
 * temperatures for you. If you want to change the starting temperature, feel free
 * to change the initial value for starterTemp, which is set at 72 right now. 
 */

unsigned long milliseconds = 0;
unsigned long prevTime = 0;
int starterTemp = 72;

int getTemperature(bool fanOn)
{
  milliseconds = millis();
  if(fanOn)
  {
    //The fan decreases the temperature by 1 degree every "hour" (second).
    if(milliseconds - prevTime >= 1000)
    {
      Serial.print("Temp decreasing from ");
      Serial.print(starterTemp);
      Serial.print(" to ");
      starterTemp--;
      Serial.println(starterTemp);
      prevTime = milliseconds;
    }
  } else
  {
    //The fan increases the temperature by 1 degree every "two hours" (seconds).
    if(milliseconds - prevTime >= 2000)
    {
      Serial.print("Temp increasing from ");
      Serial.print(starterTemp);
      Serial.print(" to ");
      starterTemp++;
      Serial.println(starterTemp);
      prevTime = milliseconds;
    }
  }
  return starterTemp;
}

