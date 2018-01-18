/*Created by Joseph Locsin Katigbak, LX Robotics Engineer, 01/18/18
 * Slave Bluetooth code which uses state of digital input as data to be read by master.
*/

int pir = 5;
int pirState = 0;

void setup() {
  pinMode(pir, INPUT);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
 pirState = digitalRead(pir); //Loop constantly reads for digital input
 if (pirState == HIGH) 
 {
   Serial.write('1'); // Sends '1' to the master if digital input is at HIGH
 }
 else if (pirState == LOW)
 {
   Serial.write('0'); // Sends '0' to the master if digital input is at LOW
 }
 delay(1000);
}
