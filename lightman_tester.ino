






#include <Bridge.h>
#include <Console.h>

#include <QueueList.h>


#include "tlc_config.h"
#include "Tlc5940.h"

#include <Lightman.h>


Lightman larray;
int flashled = 13;


void setup() {
  pinMode(flashled, OUTPUT);
  ledSignal(1000, false);
  
  Serial.begin(9600);
  printMessage("Building bridge");
  //Bridge.begin();
  printMessage("Bridge built!");
  delay(3000);
  //if (Console) Console.println("Lightman tester console");
  printMessage("(Lightman tester console)");
  
  Tlc.init(4000);
  //Tlc.update(); 
  
  
  
  delay(4000);
  //Tlc.setAll(0); 
  //Tlc.update(); 
 
  
  
  
  
  
  

  //int st[] = {0,4000,0};
  //int en[] = {4000,4000,4000};
 
  //larray.set_curve(15,st,en,4000,2,0);
  
  
  //larray.set_light(15,1000,1000,1000);
  //Tlc.update(); 
  
  ledSignal(500,true);
  
  //forLoop();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Tlc.setAll(1000);
  Tlc.update(); 
  //fauxdelay(1000);
  delay(1000);
  Tlc.setAll(0);
  Tlc.update(); 
  
  
  forLoop();
   
  ledSignal(100,true);   
  printMessage(String(NUM_TLCS));
}


void printMessage(String msg) {
  if (Console) Console.println("C: " + msg);
  if (Serial) Serial.println("S: " + msg);
}
String doubletostring (double number){
  char tempChar[32];
  dtostrf(number,4,2,tempChar);
  String tempString;
  tempString = String(tempChar);
  return tempString;
}  

void ledSignal(int gap, bool endHigh){
  
  delay(gap);
  
  digitalWrite(flashled, HIGH);
  delay(gap);
  digitalWrite(flashled, LOW);
  delay(gap);
  digitalWrite(flashled, HIGH);
  delay(gap);
  digitalWrite(flashled, LOW);
  if (endHigh){ delay(gap); digitalWrite(flashled, HIGH);}
  
  printMessage("loop");
 

}




void forLoop() {
  printMessage("starting for loop");
  
  int li;
  int colour;
  int R;
  int G;
  int B;
  
  
  for (colour = 0; colour <=2; colour+=1){
   R = colour==0;
   G = colour==1;
   B = colour==2;
     
    for (li = 0; li <= 15; li +=1){
    larray.set_light(li,R*4000,G*4000,B*4000);
    printMessage("light: " + String(li));
    delay(1000);
    Tlc.update(); 
   }
  }    
  

  //Tlc.init(0);
  Tlc.update(); 
}
