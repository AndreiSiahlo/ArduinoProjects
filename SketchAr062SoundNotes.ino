//SketchAr062SoundNotes
//http://developer.alexanderklimov.ru/arduino/piezo.php
//При загрузке скетча подключенный к плате пьезодинамик генерирует звуковые сигналы с частотами нот
//At the sketch load the piezo element connected to the arduino board generates the sound signals with frequencies of the notes 

const int SoundPin = 2; // Пин подключения пьезоизлучателя – 2 дискретный
const int DelaySound = 100; // Пауза 0.1 секунда
const int Nnotes=8;

// The notes: do,re,mi,fa,sol,la,si,do
// The frequencies of the notes in Hz: 261.6,293.7,329.6,349.2,392,440,494,523.25;
int tFrequencyTNote[8]={262,294,329,349,392,440,494,523};

void setup()
{
}
void loop()
{
//Использования tone():
//tone(pin, частота)
{tone(SoundPin, tFrequencyTNote[0]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[1] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);
  
 tone(SoundPin, tFrequencyTNote[1]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[1] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);
 
 tone(SoundPin, tFrequencyTNote[2]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[2] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, tFrequencyTNote[3]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[3] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, tFrequencyTNote[4]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[4] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, tFrequencyTNote[5]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[5] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, tFrequencyTNote[6]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[6] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

  tone(SoundPin, tFrequencyTNote[7]);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[7] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);
 
 //------------------

 delay(DelaySound*100);
}
}
