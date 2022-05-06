 //SketchAr064SoundDRMFSLC

// The sounds with the frequencies of the notes: do,re,mi,fa,sol,la,si,do are generated
// on the piezo buzzer port if the commands 'D', 'R', 'M', 'F', 'S', 'L', 'C'
// are set to the Monitor Window. 
// The frequencies of the notes in Hz: 261.6,293.7,329.6,349.2,392,440,494,523.25;
// The command 'P' performs the pause between the notes of 1 sec is generated.
// The following sequence of the commands allow to generate simple melodies:
// LLLFPPSSSMP   
// PLLLFPPSSSMPRRRDPRRRDPRRRDPDPDPLLLFP  

const int fNoteDo=262;
const int fNoteRe=294;
const int fNoteMi=329;
const int fNoteFa=349;
const int fNoteSol=392;
const int fNoteLa=440;
const int fNoteSi=494;
const int fNoteD2=523;

const int PinR8=8;
const int PinY10=10;
const int PinG12=12;
const int PinB13=13;

const int NoteDuration100 = 100; // Note duration (0.1 sec.)
const int NoteDuration300 = 300; // Note duration (0.3 sec.)
const int GapNotesDuration300 = 300; // Pause 0.3 sec.
const int GapNotesDuration1000=1000; 
const int Nnotes=8;

int fNote;
// !!! The Baud Rate of the COM window must be equal to the parameter of the function 
//  Serial.begin(BAUDRATE) in the programm

const int SoundPin = 2;
char val='R';
bool NeedToPlay=false;

void setup()
{ Serial.begin(9600); // Baud rate 9600 bits/sec
  // put your setup code here, to run once:
  noTone(SoundPin);
  // Set output mode to the pins:
  pinMode(PinR8, OUTPUT);  
  pinMode(PinY10, OUTPUT); 
  pinMode(PinG12, OUTPUT); 
  pinMode(PinB13, OUTPUT);  
  delay(GapNotesDuration1000);
  Serial.print("Play the Notes");
  tone(SoundPin, fNoteDo);delay(NoteDuration100);delay(GapNotesDuration300);
  tone(SoundPin, fNoteRe);delay(NoteDuration100);delay(GapNotesDuration300);
  tone(SoundPin, fNoteMi);delay(NoteDuration100);delay(GapNotesDuration300);
  tone(SoundPin, fNoteFa);delay(NoteDuration100);delay(GapNotesDuration300);
  tone(SoundPin, fNoteSol);delay(NoteDuration100);delay(GapNotesDuration300);
  tone(SoundPin, fNoteLa);delay(NoteDuration100);delay(GapNotesDuration300);
  tone(SoundPin, fNoteSi);delay(NoteDuration100);delay(GapNotesDuration300);
  tone(SoundPin, fNoteD2);delay(NoteDuration100);delay(GapNotesDuration300);
  noTone(SoundPin);
  }
  
void SwitchOffAllLEDs()
{   digitalWrite(PinR8, LOW);
    digitalWrite(PinY10, LOW);
    digitalWrite(PinG12, LOW);
    digitalWrite(PinB13, LOW);
  }

void loop()
{ // put your main code here, to run repeatedly:
 int iPin;
 if (Serial.available())
 { // если есть принятый символ
   NeedToPlay=true;
   val=Serial.read(); //Save the accepted symbol to  val
   Serial.print(val);
   if (val == 'D')     // If symbol 'D' is accepted
   { fNote=fNoteDo;  iPin=PinR8;}
   if (val == 'R')     // If symbol 'R' is accepted
   { fNote=fNoteRe;  iPin=PinY10;}
   if (val == 'M')     // If symbol 'M' is accepted
   { fNote=fNoteMi;  iPin=PinG12;}
   if (val == 'F')     // If symbol 'F' is accepted
   { fNote=fNoteFa;  iPin=PinB13;}
   if (val == 'S')     // If symbol 'S' is accepted
   { fNote=fNoteSol; iPin=PinR8;}
   if (val == 'L')     // If symbol 'L' is accepted
   { fNote=fNoteLa;  iPin=PinY10;}
   if (val == 'C')     // If symbol 'C' is accepted
   { fNote=fNoteSi;  iPin=PinG12;}
   if (val == 'P')     // If symbol 'P' is accepted 
   {NeedToPlay=false;
    Serial.println(" ");
    noTone(SoundPin);
    SwitchOffAllLEDs();
    delay(GapNotesDuration1000);
    }
   }
   if(NeedToPlay)
   {Serial.print("NeedToPlay, iPin="); 
    Serial.print(iPin);
    Serial.print(" ");
    digitalWrite(iPin, HIGH); // Switch On the LED that corresponds to the note};
    tone(SoundPin, fNote);    // generate the note
    delay(NoteDuration100);
    SwitchOffAllLEDs();
    noTone(SoundPin);
    delay(GapNotesDuration300);
   }
  }


   
