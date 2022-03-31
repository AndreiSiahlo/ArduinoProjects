// SketchAr030BlinkOnOnOnOff
// https://habr.com/ru/post/352806/
// The LED on the Arduino plate is switched on for 3 sec.
// And the voltage of 5V between the GND port and the Pin13 is set.
// Thereafter the LED turns out for the short time. 
// At this short time no voltage is set to Pin13.
// This sketch could be used to check the ports voltage
int Led = 13; // declare and set the variable Led
void setup(){
    pinMode(Led, OUTPUT); // Set the variable Led to the OUTPUT
}

int TimeSlot=1000;

void loop()
{  int DurationOn=TimeSlot*0.5;
   int DurationOff=TimeSlot-DurationOn;
    digitalWrite(Led, HIGH); // the voltage is applied to the pin 13
    delay(DurationOn); // wait 0.5 seconds
     digitalWrite(Led, HIGH); // the voltage is applied to the pin 13
    delay(DurationOn); // wait 0.5 seconds
     digitalWrite(Led, HIGH); // the voltage is applied to the pin 13
    delay(DurationOn); // wait 0.5 seconds
     digitalWrite(Led, HIGH); // the voltage is applied to the pin 13
    delay(DurationOn); // wait 0.5 seconds
     digitalWrite(Led, HIGH); // the voltage is applied to the pin 13
    delay(DurationOn); // wait 0.5 seconds
    digitalWrite(Led, LOW); // no voltage applied to the pin 13
    delay(DurationOff); // wait 0.5 seconds
  }
