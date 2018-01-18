/*Created by Joseph Locsin Katigbak, LX Robotics Engineer, 01/18/18
 * Mobile app Galileo(16).apk sends data via voice output to control BT relay[3 ports]. 
 * - as Mobile App ISBAT send data to MCU  via bluetooth
*/


#include <SPI.h>
#include <SoftwareSerial.h>

int relay1 = 5;   //initializes relay pins
int relay2 = 6;
int relay3 = 7;

String c;         //initializes string variables
String readStrin;

void setup() {
 pinMode(relay1, OUTPUT); //initialize output pins
 pinMode(relay2, OUTPUT);
 pinMode(relay3, OUTPUT);

 Serial.begin(9600);
 digitalWrite(relay1, LOW); //Turns all relay off once via setup
 digitalWrite(relay2, LOW);
 digitalWrite(relay3, LOW);

}

void loop() {
  while(Serial.available()){ //Checks BT input whenever available
    delay(50);
    char c=Serial.read();
    readStrin += c;
                         }
  if(readStrin.length()>0)  //Analyzes BT input and commands its corresponding action.
    {
      Serial.println(readStrin);
      delay(100);
      if (readStrin =="all on")
      {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      Serial.println(readStrin);
      delay(2000); 
      }
      if (readStrin =="all off")
      {
        digitalWrite(relay1, LOW);
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, LOW);
        delay(2000);
      }
      else if (readStrin =="light on")
      {
        digitalWrite(relay1, HIGH);
        delay(2000);
      }
      else if (readStrin =="fan on")
      {
        digitalWrite(relay2, HIGH);
        delay(2000);
      }
      else if (readStrin =="tv on")
      {
        digitalWrite(relay3, HIGH);
        delay(2000);
      }
      else if (readStrin =="light off")
      {
      digitalWrite(relay1, LOW);
      delay(2000);
      }
      else if (readStrin =="fan off")
      {
        digitalWrite(relay2, LOW);
        delay(2000);
      }
      else if (readStrin =="tv off")
      {
        digitalWrite(relay3, LOW);
        delay(2000);
      }
    
   }
    readStrin="";
}

