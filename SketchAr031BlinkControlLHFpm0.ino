//  SketchAr031BlinkControlLHFpm0.ino
// https://habr.com/ru/post/352806/
//  The LED on the Arduino plate 
//  could be set in the 'On', 'Off' or the 'blinking' state.
//  by the commands 'H' and 'L' or 'F'.
//  The frequency of blinking is controlled by the commands '+' or '-'.
//  The initial frequency of blinking is set by the command '0'.
const int BITRATE=9600;
const int ModeHIGH=1,ModeLOW=0,ModeFLASH=3,ModeON=1,ModeOFF=0;
int HLFmode, OnOffMode, DurationOnOff;
int TimeSlot=1000;
int TimeSlot0=1000;
int TimeSlotMin=10;
int TimeSlotMax=8001;
int TimeSlotSmall=10;

int Led = 13; // объявляем переменную Led на 13 пин (выход)
void setup(){
    Serial.begin(BITRATE);    // Rate 9600 bit/s
    pinMode(Led, OUTPUT); // определяем переменную
    HLFmode=ModeHIGH;
    HLFmode=ModeFLASH;
    OnOffMode=ModeON;
    DurationOnOff=0;
    TimeSlot=1000;
    TimeSlotSmall=10;
}

void loop()
{   int val;
    if (Serial.available())
    { // если есть принятый символ
      val=Serial.read(); //сохраняем в val
      if (val == 'H')     // Если принят символ 'H'
         {HLFmode=ModeHIGH;
          OnOffMode=ModeON;
        }
      if (val == 'L')     // Если принят символ 'L'
         {HLFmode=ModeLOW;
          OnOffMode=ModeOFF;
         }
      if (val == 'F')     // Если принят символ 'L'
         {HLFmode=ModeFLASH;
         }
      if (val == '+')     // Если принят символ '+'
          TimeSlot=TimeSlot*2;
      if (val == '-')     // Если принят символ '-'
          TimeSlot=TimeSlot/2;
      if (val == '0')     // Если принят символ '0'
      {TimeSlot=TimeSlot0;
       }    
    }
  
    switch(HLFmode)
    {case ModeLOW:
          OnOffMode=ModeOFF;
          break;
     case ModeHIGH:
          OnOffMode=ModeON;
          break;
     case ModeFLASH:
          if(DurationOnOff>=TimeSlot)
          { DurationOnOff=0;
            switch(OnOffMode)
            {case ModeOFF:
                  OnOffMode=ModeON;
                  break;
             case ModeON:
                  OnOffMode=ModeOFF;
                  break;     
       }
      }
      break;
    }
    
    if(TimeSlot>=TimeSlotMax)
       TimeSlot=TimeSlotMax;
    if(TimeSlot<=TimeSlotMin)
       TimeSlot=TimeSlotMin;   
    
    switch(OnOffMode)
    {case ModeON:
         // Serial.println("OnOffMode==ModeON");
          digitalWrite(Led, HIGH); // Set Voltage on pin Led 
          break;
     case ModeOFF:
          //Serial.println("OnOffMode==ModeOFF");
          digitalWrite(Led, LOW);
          break;
    }
       
    DurationOnOff=DurationOnOff+TimeSlotSmall;
    delay(TimeSlotSmall);
  }
