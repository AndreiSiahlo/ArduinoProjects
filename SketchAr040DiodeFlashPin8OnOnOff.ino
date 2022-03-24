int Led = 8;  
// The declaration of a integer variable 'Led'
// that contains the port number 
// to which the voltage is applied.

void setup()  
// The mandatory procedure 'setup()' is executed once at the programm start. 
{
pinMode(Led, OUTPUT); 
// The function 'PinMode(PortNumber,State)'
// sets the type 'State' ('OUTPUT' or 'INPUT') to the digital port 'PortNumber' 
}

void loop() 
// The mandatory procedure 'loop()' is execuded cyclically after the procedure 'setup()' execution
{
 digitalWrite(Led, HIGH);  // the state 'switched on' is set 0n the digital port 'Led'
 // The command digitalWrite(PortNumber,State) is used 
 // to 'switch on' or to 'switch off' the voltage on a didital port
 // The first argument('PortNumber') is the number of the digital port,
 // the second argument('State') is the state ('switched on' (HIGH) or 'switched off' (LOW)),
 // to which the digital port should be set. 

delay(3000); //эта команда используется для ожидания между действиями, аргумент - время ожидания в миллисекундах
// The command delay(time) is used for the waiting between the actions.
// The argument ('time') is the time (in milliseconds) of the waiting 

digitalWrite(Led, LOW);  // the state 'switched off' is set 0n the digital port 'Led'

delay(500);
}
