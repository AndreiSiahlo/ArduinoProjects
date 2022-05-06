//SketchAr065SoundLEDR8Y10G12B13

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

const int PinR8=8;
const int PinY10=10;
const int PinG12=12;
const int PinB13=13;
const int Pause0d5sec=500;

int fNote;

//The Red, Yellow Green and Blue LEDs are on the plate, 
//  connected to Arduino.
//The state of the diodes ('On','Off' or 'Flash') 
//  and the flashing period 
//  could be controlled by the commands
//  'H', 'L', 'F', 'P', '+', '-' and '0'.

// !!! The Baud Rate of the COM window must be equal to the parameter of the function 
//  Serial.begin(BAUDRATE) in the programm

const int SoundPin = 2;
bool SoundMode=true;
int outputPin = 8,ControlledPin=8;
int NumberOfPins=20;
char val='R';
int iPin=8;
int TimeSlot0 = 4000; //1second
int TimeSlotMin = 125, TimeSlotMax =16000;  //good values 124 and 16000,  bad value was TimeSlot0 * 16 (4000*16) and 32000
int TimeDelayInLoop = TimeSlot0 / 100;  // Both variables: TimeDelayInLoop and TimeDelayInLoopT[] are required

int outputPinT[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int TimeSlotT[20];
int FlashModeT[20];
int OnOffModeT[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int DurationOnOffT[20];
int TimeDelayInLoopT[20];
int iRed=8,iYellow=10,iGreen=12;

const int DelaySound = 100; // Пауза 0.1 секунда

void setup()
{ Serial.begin(9600); // Скорость 9600 бит/сек
  // put your setup code here, to run once:
  ControlledPin = 8;
  SoundMode=true;
  delay(DelaySound);  // Пауза 1 секунда (100 миллисекунд – значение переменной DelaySound ) – длительность воспроизведения сигнала
 //noTone(SoundPin); // Выключаем звук
  delay(DelaySound*10);
 
  pinMode(outputPinT[iRed], OUTPUT);pinMode(outputPinT[iYellow], OUTPUT);pinMode(outputPinT[iGreen], OUTPUT);  // режим вывода
//  for(iPin=1;iPin<=NumberOfPins;iPin++)// The Warning Message at compiling
  iPin=iRed;
  {TimeSlotT[iPin] = 1000;
   FlashModeT[iPin]=0;  
   OnOffModeT[iPin]=0;
   DurationOnOffT[iPin]=TimeSlotT[iPin]/10;
   TimeDelayInLoopT[iPin]=TimeSlotT[iPin]/10;
  }
  iPin=iYellow;
  {TimeSlotT[iPin] = 1000;
   FlashModeT[iPin]=0;  
   OnOffModeT[iPin]=0;
   DurationOnOffT[iPin]=TimeSlotT[iPin]/10;
   TimeDelayInLoopT[iPin]=TimeSlotT[iPin]/10;
  }
  iPin=iGreen;
  {TimeSlotT[iPin] = 1000;
   FlashModeT[iPin]=0;  
   OnOffModeT[iPin]=0;
   DurationOnOffT[iPin]=TimeSlotT[iPin]/10;
   TimeDelayInLoopT[iPin]=TimeSlotT[iPin]/10;
  }
  pinMode(outputPinT[ControlledPin], OUTPUT);  // режим вывода
  }

void loop()
{ // put your main code here, to run repeatedly:
  if (Serial.available())
  { // если есть принятый символ
    val = Serial.read(); //сохраняем в val
    Serial.print(val);
  
    if (val == 'R')     // Если принят символ 'R'
    { ControlledPin = PinR8; fNote=fNoteMi;}
      pinMode(outputPin, OUTPUT);
    if (val == 'Y')     // Если принят символ 'Y'
    { ControlledPin = PinY10; fNote=fNoteSol;}// ??Mi
    pinMode(outputPin, OUTPUT);
    if (val == 'G')     // Если принят символ 'G'
    { ControlledPin = PinG12; fNote=fNoteFa;}
    if (val == 'B')     // Если принят символ 'B'
    { ControlledPin = PinB13; fNote=fNoteLa;}
    
    pinMode(ControlledPin, OUTPUT);
    
    if (val == 'H')     // Если принят символ 'H'
    { Serial.print(" Set High for ControlledPin=");
      Serial.print(ControlledPin);
      Serial.println();
      FlashModeT[ControlledPin] = 0;
      //digitalWrite(ControlledPin, HIGH); // То включаем светодиод
      OnOffModeT[ControlledPin]=1;
      if(SoundMode)
      {tone(SoundPin, fNote);}
    }
    if (val == 'L')     // Если принят символ 'L'
    { Serial.print(" Set Low for ControlledPin=");
      Serial.print(ControlledPin);
      Serial.println();
      FlashModeT[ControlledPin] = 0;
      //digitalWrite(ControlledPin, LOW); // То выключаем светодиод
      OnOffModeT[ControlledPin]=0;
      noTone(SoundPin);
    }
    if (val == 'F')
    { Serial.print(" Set Flash for ControlledPin=");
      Serial.print(ControlledPin);
      Serial.println();
      FlashModeT[ControlledPin] = 1;
      //OnOffModeT[ControlledPin]=1;
      TimeSlotT[ControlledPin] = TimeSlot0; 
      DurationOnOffT[ControlledPin] = 0;
    }
    if (val == '>')
    {DurationOnOffT[ControlledPin] = DurationOnOffT[ControlledPin] + TimeDelayInLoopT[ControlledPin]/8;
    }
    if (val == '+')
    {TimeSlotT[ControlledPin] = TimeSlotT[ControlledPin]* 2;
     DurationOnOffT[ControlledPin] = 0;
     if(TimeSlotT[ControlledPin]>=TimeSlotMax)
        TimeSlotT[ControlledPin]=TimeSlotMax;        
     Serial.print(" TimeSlotT[ControlledPin](now)");
     Serial.print(TimeSlotT[ControlledPin]);
     Serial.println();
     };  //  Note: TimeSlot can be as big as possible, because delay(InLoop) is used instead of delay(TimeSlot) 
     if (val == '-')
     { Serial.print(" TimeSlotT[ControlledPin](before)");
       Serial.print(TimeSlotT[ControlledPin]);
       TimeSlotT[ControlledPin] = TimeSlotT[ControlledPin] / 2;
       DurationOnOffT[ControlledPin] = 0;
       if(TimeSlotT[ControlledPin]<TimeSlotMin)
          TimeSlotT[ControlledPin]=TimeSlotMin;
       Serial.print(" TimeSlotT[ControlledPin](now)");
       Serial.print(TimeSlotT[ControlledPin]);
     };
     
   if (val == 'P')
    { Serial.print(" The pause ");
      noTone(SoundPin); // Выключаем звук
      delay(Pause0d5sec); // wait 0.5 seconds
    }

     
     if (val == 'M')
     { Serial.print(" ControlledPin=");
       Serial.println(ControlledPin);
       Serial.print(" TimeSlotT[ControlledPin]=");
       Serial.println(TimeSlotT[ControlledPin]);
       Serial.print("SoundMode=");
       Serial.print(SoundMode);
      };
      if (val == '0')
      { //for(iPin=1;iPin<=NumberOfPins;iPin++)TimeSlotT[iPin] = TimeSlot0;// The Warning Message at compiling
        //DurationOnOffT[iPin] = 0;
        noTone(SoundPin);
        DurationOnOffT[iRed] = 0;DurationOnOffT[iYellow] = 0;DurationOnOffT[iGreen] = 0;
        //wwwwwwwwwwwwdigitalWrite(ControlledPin, LOW);wwwwwwww
        //digitalWrite(outputPinT[iPinR],LOW);
        //digitalWrite(outputPinT[iPinY],LOW);
        //digitalWrite(outputPinT[iPinG],LOW);
        //digitalWrite(outputPinT[iPinB],LOW);
        OnOffModeT[outputPinT[PinR8]]=0;
        OnOffModeT[outputPinT[PinY10]]=0;
        OnOffModeT[outputPinT[PinG12]]=0;
        OnOffModeT[outputPinT[PinB13]]=0;
        FlashModeT[outputPinT[PinR8]]=0;
        FlashModeT[outputPinT[PinY10]]=0;
        FlashModeT[outputPinT[PinG12]]=0;
        FlashModeT[outputPinT[PinB13]]=0;
      }
      if (val == 'S')
      {noTone(SoundPin);
       Serial.print("(In)SoundMode=");
       Serial.print(SoundMode);
       SoundMode=!SoundMode;
       Serial.print("(Out)SoundMode=");
       Serial.print(SoundMode);
      }
     }
        
    //for(iPin=1;iPin<=NumberOfPins;iPin++) // The Warning Message at compiling
    iPin=iRed;
    { DurationOnOffT[iPin] = DurationOnOffT[iPin] + TimeDelayInLoopT[iPin];
      if(FlashModeT[iPin] == 1)
      if (OnOffModeT[iPin] == 1)
      { digitalWrite(iPin, HIGH);
        if(SoundMode)
        {tone(SoundPin, fNote);}
         if(DurationOnOffT[iPin] > TimeSlotT[iPin])
         { OnOffModeT[iPin] = 0;
           DurationOnOffT[iPin] = 0;
      }}
      if(FlashModeT[iPin] == 1)
      if (OnOffModeT[iPin] == 0)
     { digitalWrite(iPin,LOW);
       noTone(SoundPin);
       if(DurationOnOffT[iPin] > TimeSlotT[iPin])
       { OnOffModeT[iPin] = 1;
         DurationOnOffT[iPin] = 0;
    }}}
    
    iPin=iYellow;
    { DurationOnOffT[iPin] = DurationOnOffT[iPin] + TimeDelayInLoopT[iPin];
      if(FlashModeT[iPin] == 1)
      if (OnOffModeT[iPin] == 1)
      { digitalWrite(iPin, HIGH);
        if(SoundMode)
        {tone(SoundPin, fNote);}
        if(DurationOnOffT[iPin] > TimeSlotT[iPin])
        { OnOffModeT[iPin] = 0;
          DurationOnOffT[iPin] = 0;
      }}
      if(FlashModeT[iPin] == 1)
      if (OnOffModeT[iPin] == 0)
     { digitalWrite(iPin,LOW);
       noTone(SoundPin);
       if(DurationOnOffT[iPin] > TimeSlotT[iPin])
       { OnOffModeT[iPin] = 1;
         DurationOnOffT[iPin] = 0;
    }}}
    iPin=iGreen;
    { DurationOnOffT[iPin] = DurationOnOffT[iPin] + TimeDelayInLoopT[iPin];
      if(FlashModeT[iPin] == 1)
      if (OnOffModeT[iPin] == 1)
      { digitalWrite(iPin, HIGH);
        if(SoundMode)
        {tone(SoundPin, fNote);}
        if(DurationOnOffT[iPin] > TimeSlotT[iPin])
        { OnOffModeT[iPin] = 0;
          DurationOnOffT[iPin] = 0;
      }}
      if(FlashModeT[iPin] == 1)
      if (OnOffModeT[iPin] == 0)
      {digitalWrite(iPin,LOW);
       noTone(SoundPin);
       if(DurationOnOffT[iPin] > TimeSlotT[iPin])
       { OnOffModeT[iPin] = 1;
         DurationOnOffT[iPin] = 0;
    }}}
  
  delay(TimeDelayInLoop); // This command should be at the end of the loop()-function
  }
