#include <SoftwareSerial.h>

int startBT = 2;
int resetBT = 3;
int ledst = 8;
int ststate = LOW;
int restate = LOW;
int gaspin = 0;
float sum = 0.0;
int rx = 0;
int tx = 1;
int BTpress = 0;

SoftwareSerial bt = SoftwareSerial(rx, tx);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(ledst, OUTPUT);
  pinMode(startBT, INPUT);
  pinMode(resetBT, INPUT);
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,CLOCK,TIME,VARIABLE");
}

void bt() {
  bt.println("RESETTIMER");
  bt.println("start");
  while(digitalRead(resetBT) != 0) {
    statate = !ststate;
    digitalWrite(ledst, ststate);
    float v = (analogRead(0) * 5) / 1024.0;
    bt.print("DATA,TIME,TIMER,");
    bt.println(v);
    if(v >= 0.2){
      sum = sum + v;
    }
    delay(1000);
    statate = !ststate;
    digitalWrite(ledst, ststate);
  }
  bt.print("reset Sum = ");
  bt.println(sum);
  sum = 0.0;
  delay(200);
}

void loop() {
  if(digitalRead(startBT) == 0 && ststate == 0) {
    BTpress = millies();
  }
  else if(BTpress >= 2000) {
    bt();
  }
  else {
    Serial.println("RESETTIMER");
    ststate = 1;
    Serial.println("start");
    digitalWrite(ledst, ststate);
    while(digitalRead(resetBT) != 0) {
      float v = (analogRead(0) * 5) / 1024.0;
      Serial.print("DATA,TIME,TIMER,");
      Serial.println(v);
      if(v >= 0.2){
        sum = sum + v;
        }
      delay(1000);
      }
    ststate = 0;
    Serial.print("reset Sum = ");
    Serial.println(sum);
    sum = 0.0;
    digitalWrite(ledst, ststate);
    delay(200);
  }
}