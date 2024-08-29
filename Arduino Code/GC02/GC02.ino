float vp = 1;
float r1 = 100000;
float r2 = 10000;
float ts = 0;

void setup() {

Serial.begin(9600);

delay(1000);
}
void loop() {
float v = (analogRead (0) * vp) / 1024.0;
float v2 = ((v / (r2 / (r1 + r2))*10)+1); // here you can calibrate the sensor
if (v2 <2) {
v2 = 0.00;

}
Serial.print("DATA,TIME,TIMER,");
Serial.println(v2);
delay (1000);
}
