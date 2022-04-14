//SketchAr102SoundSimple
//http://developer.alexanderklimov.ru/arduino/piezo.php
//This sketch switches on periodically the piezo element connected to the arduino board

const int SoundPin = 2; // The pin connected to the piezo element
int DelaySound = 100; 

void setup()
{
}
void loop()
{
// Use of 'tone()' function: tone(pin, frequency)
{tone(SoundPin, 1136);  // The sound signal at the frequency 1136Hz by the piezo element
 delay(DelaySound);  // Pause of 1 second - duration of the signal generation 
 noTone(SoundPin); // Switches off the sound.
 delay(DelaySound*10);
}
}
