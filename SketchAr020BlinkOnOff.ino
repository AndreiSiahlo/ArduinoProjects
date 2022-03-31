// https://habr.com/ru/post/352806/
// The sketch makes an LED on the Arduino plate light up and light off periodically
int Led = 13; //  // declare and set the variable Led
void setup(){
    pinMode(Led, OUTPUT); // Set the variable Led to the OUTPUT
}

int TimeSlot=1000;

void loop()
{  int DurationOn=TimeSlot*0.5;
   int DurationOff=TimeSlot-DurationOn;
    digitalWrite(Led, HIGH); // the voltage is applied to the pin 13
    delay(DurationOn); // wait 0.5 seconds
    digitalWrite(Led, LOW); // no voltage is applied to the pin 13
    delay(DurationOff); // wait 0.5 seconds
  }
