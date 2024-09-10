#include <SoftwareSerial.h>

int startBT = 2;
int resetBT = 3;
int ledst = 8;
int ststate = LOW;
int restate = LOW;
int gaspin = 0;
float sum = 0.0;
int BTpress, press;
int period = 500;

SoftwareSerial bt = SoftwareSerial(0, 1);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  press = millis();
  pinMode(ledst, OUTPUT);
  pinMode(startBT, INPUT);
  pinMode(resetBT, INPUT);
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,CLOCK,TIME,VARIABLE");
}

void bto() {
  bt.println("RESETTIMER");
  bt.println("start");
  while(digitalRead(resetBT) != 0) {
    ststate = !ststate;
    digitalWrite(ledst, ststate);
    float v = (analogRead(0) * 5) / 1024.0;
    bt.print("DATA,TIME,TIMER,");
    bt.println(v);
    if(v >= 0.2){
      sum += v;
    }
    delay(1000);
    ststate = !ststate;
    digitalWrite(ledst, ststate);
  }
  bt.print("reset Sum = ");
  bt.println(sum);
  sum = 0.0;
  delay(200);
}

void loop() {
  if(digitalRead(startBT) == 0 && ststate == 0) {
    BTpress = millis();
    press = BTpress;
    while(digitalRead(startBT) == 0 && ststate == 0){
      BTpress = millis();
       Serial.println(BTpress);
      delay(500);
    }
    if(BTpress - press >= period){
      Serial.println("Hello");
      Serial.println(press);
    }
    delay(500);
  }
}
