//SketchAr060SoundSimple
//http://developer.alexanderklimov.ru/arduino/piezo.php
//The sketch switches on periodically the piezo buzzer connected to the arduino board

const int SoundPin = 2; // The pin connected to the piezo buzzer
int DelaySound = 100; 

void setup()
{
}
void loop()
{
// Use of 'tone()' function: tone(pin, frequency)
{tone(SoundPin, 1136);  // The sound signal at the frequency 1136Hz by the piezo buzzer
 delay(DelaySound);  // Pause of 1 second - duration of the signal generation 
 noTone(SoundPin); // Switches off the sound.
 delay(DelaySound*10);
}
}
