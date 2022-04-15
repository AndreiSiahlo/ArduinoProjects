//SketchAr062SoundNotes
//http://developer.alexanderklimov.ru/arduino/piezo.php
//При загрузке скетча подключенный к плате пьезодинамик генерирует звуковые сигналы с частотами нот
//At the sketch execution, the piezo element connected to the arduino board, 
// plays notes in sequence "La La La Fa Sol Sol Sol Mi" 

const int SoundPin = 2; // Пин подключения пьезоизлучателя – 2 дискретный
const int DelaySound = 100; // Пауза 0.1 секунда
const int Nnotes=8;

// The notes: do,re,mi,fa,sol,la,si,do
// The frequencies of the notes in Hz: 261.6,293.7,329.6,349.2,392,440,494,523.25;
const int fNoteDo=262;
const int fNoteRe=294;
const int fNoteMi=329;
const int fNoteFa=349;
const int fNoteSol=392;
const int fNoteLa=440;
const int fNoteSi=494;
const int fNoteD2=523;


int tFrequencyTNote[8]={fNoteDo,fNoteRe,fNoteMi,fNoteFa,fNoteSol,fNoteLa,fNoteSi,fNoteD2};

void setup()
{
 //Использования tone():
//tone(pin, частота)
 tone(SoundPin, fNoteDo);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[1] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);
  
 tone(SoundPin, fNoteRe);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[1] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);
 
 tone(SoundPin, fNoteMi);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[2] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, fNoteFa);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[3] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, fNoteSol);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[4] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, fNoteLa);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[5] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

 tone(SoundPin, fNoteSi);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[6] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*10);

  tone(SoundPin, fNoteD2);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[7] (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*50);
}

void loop()
{
 //------------------
 tone(SoundPin, fNoteLa);  // Начинается воспроизводство сигнала с частотой fNoteLa (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*5);

tone(SoundPin, fNoteLa);  // Начинается воспроизводство сигнала с частотой fNoteLa (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*5);

 tone(SoundPin, fNoteLa);  // Начинается воспроизводство сигнала с частотой fNoteLa (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*5);

 tone(SoundPin, fNoteFa);  // Начинается воспроизводство сигнала с частотой fNoteFa (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*30);

tone(SoundPin, fNoteSol);  // Начинается воспроизводство сигнала с частотой fNoteSol (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*5);

tone(SoundPin, fNoteSol);  // Начинается воспроизводство сигнала с частотой fNoteSol (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*5);

 tone(SoundPin, fNoteSol);  // Начинается воспроизводство сигнала с частотой fNoteSol (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*5);

 tone(SoundPin, fNoteMi);  // Начинается воспроизводство сигнала с частотой fNoteSol (Гц)
 delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(DelaySound*30);

 delay(DelaySound*100);
}
