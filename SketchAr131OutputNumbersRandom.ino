//SketchAr131OutputNumbers
// The sketch outputs to the COM window  
//  the float numbers numbers defined in the table NumbersToOutput[10].

// The Commands that control this outputin the COM window:
// 'O' - output the next number
// '0' - reset the list of the numbers
// 'R' - generates and outputs the Random number
// 'E' - generates the end of the line in the output window
 
// !!! The Baud Rate of the COM window must be equal to the parameter of the function 
//  Serial.begin(BAUDRATE) in the programm

char val;
float LastNumber;
int LastNumStrLen;
float NumbersToOutput[10]={119.87,229.86,33.85,4497.84,09.83,09.82,396.81,-9.81,175.80,-153.79};
int NumbersN=10;
int NumbersI=0;
int ii1;
String LastNumberString="12345678";

void setup()
{ Serial.begin(9600); // Скорость 9600 бит/сек
  // put your setup code here, to run once:
  NumbersI=0;
  ii1=0;
}

void loop()
{ // put your main code here, to run repeatedly:
  int i;
  if (Serial.available())
  { // если есть принятый символ
    val = Serial.read(); //сохраняем в val
    //Serial.print(val);
    if(val=='0')
    {NumbersI=0;};//  Set Counter Of The Numbers to 0

    if(val=='O') //  Output the next number
    { 
      LastNumber=NumbersToOutput[NumbersI];
      Serial.print(LastNumber);
            NumbersI++;
      if(NumbersI>NumbersN)
         NumbersI=0;  
      }

    if(val=='L') //  Output the Length of the last next number
    { //Serial.print(" LastNumber=");
      //Serial.print(LastNumber);
      LastNumberString=String(LastNumber);
      LastNumStrLen=LastNumberString.length();
      Serial.print(" LastNumberStringLength=");
      Serial.print(LastNumStrLen);
      }      
    
    if(val=='R')
    {LastNumber = random(100);
     Serial.print(LastNumber);
     }

     if(val=='E') //  End of the line in the output window
      {Serial.println();}
     Serial.print(' ');
     };//if (Serial.available())
    };
