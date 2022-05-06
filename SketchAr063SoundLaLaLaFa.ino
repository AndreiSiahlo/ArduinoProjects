//SketchAr062SoundNotes
//http://developer.alexanderklimov.ru/arduino/piezo.php
//При загрузке скетча подключенный к плате пьезодинамик генерирует звуковые сигналы с частотами нот
//At the sketch execution, the piezo buzzer connected to the arduino board, 
// plays notes in sequence "La La La Fa Sol Sol Sol Mi" 

const int SoundPin = 2; // Пин подключения пьезоизлучателя – 2 дискретный
const int NoteDuration100 = 70; // Длительность звучания ноты (0.1 секунда)
const int GapNotesDuration300 = 200; // Пауза 0.3 секунды
const int GapNotesDuration1000=1000; 
const int Nnotes=8;
const int Nrepeats=4;

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
const int GapPause=1000;

const int PinR8=8;
const int PinY10=10;
const int PinG12=12;
const int PinB13=13;
const int Pause0d5sec=500;
int iNote=0;
int iRepeats=0;

int tFrequencyTNote[8]={fNoteDo,fNoteRe,fNoteMi,fNoteFa,fNoteSol,fNoteLa,fNoteSi,fNoteD2};
const int NotesSonataLength=31;
int tNotesSonata[NotesSonataLength]={
                 GapPause,fNoteLa,fNoteLa,fNoteLa,fNoteFa,GapPause,GapPause,GapPause,
                 fNoteSol,fNoteSol,fNoteSol,fNoteMi,GapPause,GapPause,
                 fNoteRe,fNoteRe,fNoteRe,fNoteDo,
                 fNoteRe,fNoteRe,fNoteRe,fNoteDo,
                 fNoteRe,fNoteRe,fNoteRe,fNoteDo,
                 GapPause,fNoteDo,GapPause,fNoteDo,GapPause                 
                 //GapPause,fNoteDo,GapPause,fNoteDo, 
                 };

void SwitchOffAllLEDs()
{   digitalWrite(PinR8, LOW);
    digitalWrite(PinY10, LOW);
    digitalWrite(PinG12, LOW);
    digitalWrite(PinB13, LOW);
  }

void setup()
{Serial.begin(9600); // Скорость 9600 бит/сек
  iNote=0;
  iRepeats=0;

  // Set output mode to the pins:
  pinMode(PinR8, OUTPUT);  
  pinMode(PinY10, OUTPUT); 
  pinMode(PinG12, OUTPUT); 
  pinMode(PinB13, OUTPUT);  

 return; 
 //Использования tone():
//tone(pin, частота)
 tone(SoundPin, fNoteDo);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[1] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);
  
 tone(SoundPin, fNoteRe);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[1] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);
 
 tone(SoundPin, fNoteMi);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[2] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);

 tone(SoundPin, fNoteFa);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[3] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);

 tone(SoundPin, fNoteSol);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[4] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);

 tone(SoundPin, fNoteLa);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[5] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);

 tone(SoundPin, fNoteSi);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[6] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);

  tone(SoundPin, fNoteD2);  // Начинается воспроизводство сигнала с частотой tFrequencyTNote[7] (Гц)
 delay(NoteDuration100);  // Пауза 1 секунда (100 миллисекунд – значение переменной GapNotesDuration ) – длительность воспроизведения сигнала
 noTone(SoundPin); // Выключаем звук
 delay(GapNotesDuration1000);
 delay(GapNotesDuration1000);
 delay(GapNotesDuration1000);
}

void loop()
{ //------------------
 if(iRepeats>=Nrepeats)
 {return;}
 Serial.print("iNote=");Serial.print(iNote);
 Serial.print("tNotesSanata[iNote]=");Serial.print(tNotesSonata[iNote]);Serial.print(" ");

 if(tNotesSonata[iNote]==fNoteDo)
 {digitalWrite(PinR8, HIGH);}
 if(tNotesSonata[iNote]==fNoteRe)
 {digitalWrite(PinY10, HIGH);}
 if(tNotesSonata[iNote]==fNoteMi)
 {digitalWrite(PinG12, HIGH);}
 if(tNotesSonata[iNote]==fNoteFa)
 {digitalWrite(PinB13, HIGH);}
  if(tNotesSonata[iNote]==fNoteSol)
 {digitalWrite(PinR8, HIGH);}
 if(tNotesSonata[iNote]==fNoteLa)
 {digitalWrite(PinY10, HIGH);}
 if(tNotesSonata[iNote]==fNoteSi)
 {digitalWrite(PinG12, HIGH);}
 
 if(tNotesSonata[iNote]!=GapPause)
 {tone(SoundPin, tNotesSonata[iNote]);  // Начинается воспроизводство сигнала с частотой fNoteLa (Гц)
  delay(NoteDuration100);  // Длительность звучания ноты 0.1 секунд
  noTone(SoundPin); // Выключаем звук
  delay(GapNotesDuration300);
  SwitchOffAllLEDs();
 }
 if(tNotesSonata[iNote]==GapPause)
 {Serial.print(" Pause ");
  noTone(SoundPin);
  SwitchOffAllLEDs();
  //delay(GapNotesDuration300);
  delay(GapNotesDuration300);
  }
  delay(GapNotesDuration300);

 iNote++;
 if(iNote>=NotesSonataLength)
 {iNote=0;
  iRepeats++;
  delay(GapNotesDuration1000);
  delay(GapNotesDuration300);
 }
 }
