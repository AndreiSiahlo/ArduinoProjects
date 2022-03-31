//SketchAr50LEDR8G10Y12HLF
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
int MustBeOnOffT[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int DurationOnOffT[20];
int TimeDelayInLoopT[20];
int iRed=8,iYellow=10,iGreen=12;
void setup()
{ Serial.begin(9600); // Скорость 9600 бит/сек
  // put your setup code here, to run once:
  ControlledPin = 8;
  pinMode(outputPinT[iRed], OUTPUT);pinMode(outputPinT[iYellow], OUTPUT);pinMode(outputPinT[iGreen], OUTPUT);  // режим вывода
//  for(iPin=1;iPin<=NumberOfPins;iPin++)// The Warning Message at compiling
  iPin=iRed;
  {TimeSlotT[iPin] = 1000;
   FlashModeT[iPin]=0;  
   MustBeOnOffT[iPin]=0;
   DurationOnOffT[iPin]=TimeSlotT[iPin]/10;
   TimeDelayInLoopT[iPin]=TimeSlotT[iPin]/10;
  }
  iPin=iYellow;
  {TimeSlotT[iPin] = 1000;
   FlashModeT[iPin]=0;  
   MustBeOnOffT[iPin]=0;
   DurationOnOffT[iPin]=TimeSlotT[iPin]/10;
   TimeDelayInLoopT[iPin]=TimeSlotT[iPin]/10;
  }
  iPin=iGreen;
  {TimeSlotT[iPin] = 1000;
   FlashModeT[iPin]=0;  
   MustBeOnOffT[iPin]=0;
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
    { ControlledPin = 8;}
      pinMode(outputPin, OUTPUT);
    if (val == 'Y')     // Если принят символ 'Y'
    { ControlledPin = 10;}
    pinMode(outputPin, OUTPUT);
    if (val == 'G')     // Если принят символ 'G'
    { ControlledPin = 12;}
    
    pinMode(ControlledPin, OUTPUT);
    
    if (val == 'H')     // Если принят символ 'H'
    { Serial.print(" Set High for ControlledPin=");
      Serial.print(ControlledPin);
      Serial.println();
      FlashModeT[ControlledPin] = 0;
      digitalWrite(ControlledPin, HIGH); // То включаем светодиод
    }
    if (val == 'L')     // Если принят символ 'L'
    { Serial.print(" Set Low for ControlledPin=");
      Serial.print(ControlledPin);
      Serial.println();
      FlashModeT[ControlledPin] = 0;
      digitalWrite(ControlledPin, LOW); // То выключаем светодиод
    }
    if (val == 'F')
    { Serial.print(" Set Flash for ControlledPin=");
      Serial.print(ControlledPin);
      Serial.println();
      FlashModeT[ControlledPin] = 1;
      MustBeOnOffT[ControlledPin]=1;
      TimeSlotT[ControlledPin] = TimeSlot0; 
      DurationOnOffT[ControlledPin] = 0;
    }
    if (val == '>')
    {DurationOnOffT[ControlledPin] = DurationOnOffT[ControlledPin] + TimeDelayInLoopT[ControlledPin]/8;
    }
    if (val == '+')
    {TimeSlotT[ControlledPin] = TimeSlotT[ControlledPin]* 2;
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
       if(TimeSlotT[ControlledPin]<TimeSlotMin)
          TimeSlotT[ControlledPin]=TimeSlotMin;
       Serial.print(" TimeSlotT[ControlledPin](now)");
       Serial.print(TimeSlotT[ControlledPin]);
     };
     if (val == 'M')
     { Serial.print("ControlledPin=");
       Serial.println(ControlledPin);
       Serial.print("TimeSlotT[ControlledPin]=");
       Serial.println(TimeSlotT[ControlledPin]);
      };
      if (val == '0')
      { //for(iPin=1;iPin<=NumberOfPins;iPin++)TimeSlotT[iPin] = TimeSlot0;// The Warning Message at compiling
        //DurationOnOffT[iPin] = 0;
        DurationOnOffT[iRed] = 0;DurationOnOffT[iYellow] = 0;DurationOnOffT[iGreen] = 0;
      }
     }
        
    //for(iPin=1;iPin<=NumberOfPins;iPin++) // The Warning Message at compiling
    iPin=iRed;
    { DurationOnOffT[iPin] = DurationOnOffT[iPin] + TimeDelayInLoopT[iPin];
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 1)
      { digitalWrite(iPin, HIGH);
        if(DurationOnOffT[iPin] > TimeSlotT[iPin])
        { MustBeOnOffT[iPin] = 0;
          DurationOnOffT[iPin] = 0;
      }}
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 0)
     { digitalWrite(iPin,LOW);
       if(DurationOnOffT[iPin] > TimeSlotT[iPin])
       { MustBeOnOffT[iPin] = 1;
         DurationOnOffT[iPin] = 0;
    }}}
    
    iPin=iYellow;
    { DurationOnOffT[iPin] = DurationOnOffT[iPin] + TimeDelayInLoopT[iPin];
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 1)
      { digitalWrite(iPin, HIGH);
        if(DurationOnOffT[iPin] > TimeSlotT[iPin])
        { MustBeOnOffT[iPin] = 0;
          DurationOnOffT[iPin] = 0;
      }}
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 0)
     { digitalWrite(iPin,LOW);
       if(DurationOnOffT[iPin] > TimeSlotT[iPin])
       { MustBeOnOffT[iPin] = 1;
         DurationOnOffT[iPin] = 0;
    }}}
    iPin=iGreen;
    { DurationOnOffT[iPin] = DurationOnOffT[iPin] + TimeDelayInLoopT[iPin];
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 1)
      { digitalWrite(iPin, HIGH);
        if(DurationOnOffT[iPin] > TimeSlotT[iPin])
        { MustBeOnOffT[iPin] = 0;
          DurationOnOffT[iPin] = 0;
      }}
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 0)
     { digitalWrite(iPin,LOW);
       if(DurationOnOffT[iPin] > TimeSlotT[iPin])
       { MustBeOnOffT[iPin] = 1;
         DurationOnOffT[iPin] = 0;
    }}}
  
  delay(TimeDelayInLoop); // This command should be at the end of the loop()-function
  }
