/*Created by Joseph Locsin Katigbak, LX Robotics Engineer, 01/18/18
 * Simple BT function test
 * - as MCU ISBAT send data to Mobile app through bluetooth.
*/

int pwm = A0;

void setup() {
Serial.begin(9600);
pinmode(pwm, INPUT);
}

void loop() {

float val = analogRead(pwm);

float volts = val/205; //dividing by 205 directly

Serial.print(volts); //sends text 
delay(100);
}
