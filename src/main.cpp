#include <Arduino.h> 
 /// I, George Mathioudakis,  001211882, certify that this material is my original work. No other person's work has been used without due acknowledgment and I have not made my work available to anyone else.
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int bits; 
  float floatVoltage;
  float floatTemp;
 
  // read digitized value from the D1 Mini's A/D convertor 
  bits = analogRead(A0); 
  // floatVal = 3300/iVal;
  floatVoltage = bits * (3300.0/1024.0)/1000.0;

  floatTemp = (bits/1024.0)*50.0;

  // print value to the USB port 
  //Serial.println("Digitized Value of " + String(bits) +" to an Analog voltage of "+String(floatVoltage)); 
  String info;

  if(floatTemp < 10  ){
    info = "Which is Cold!";
  }else if (floatTemp >= 10 && floatTemp <=15 )
  {
    info = "Which is cool!";
  }else if(floatTemp > 15 && floatTemp <=25){
    info = "Which is Perfect!";
  }else if(floatTemp > 25 && floatTemp <=30){
    info = "Which is Warm!";
  }else if(floatTemp > 30 && floatTemp <=35){
    info = "Which is Hot!";
  }else{
    info = "Which is Too Hot!";
  }
  
 Serial.println("Digitized Output of " + String(bits) +" is equivalent to a temperature  of "+String(floatTemp)+". C,"+String(info)); 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
} 