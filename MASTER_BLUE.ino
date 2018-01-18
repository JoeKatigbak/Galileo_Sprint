/*Created by Joseph Locsin Katigbak, LX Robotics Engineer, 01/18/18
 * Master Bluetooth code which reads slave data to control a digital output(led).
*/


int ledPin = 13;
int state = 0;

void setup() {
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 
 // Data is read from the slave and corresponds to the following output
 
 if (state == '1') 
 {
  digitalWrite(ledPin, HIGH); // LED ON
  state = 0;
 }
 else if (state == '0')
 {
  digitalWrite(ledPin, LOW); // LED OFF
  state = 0;
 }
}
