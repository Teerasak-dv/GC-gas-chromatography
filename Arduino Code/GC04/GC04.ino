#include <SoftwareSerial.h>

int startBT = 2;
int resetBT = 3;
int ledst = 8;
int ststate = LOW;
int restate = LOW;
int gaspin = 0;
float sum = 0.0;
int BTpress, press1;
int period = 500;

SoftwareSerial bt = SoftwareSerial(0, 1);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  press1 = millis();
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
  while(digitalRead(resetBT) != 0){
    if(digitalRead(startBT) == 0){
      bt.println("start");
      Serial.println("Test3");
      while(digitalRead(resetBT) != 0) {
        ststate = 1;
        digitalWrite(ledst, ststate);
        float v = (analogRead(0) * 5) / 1024.0;
        bt.print("DATA,TIME,TIMER,");
        bt.println(v);
        Serial.println("Test");
        if(v >= 0.2){
          sum += v;
        }
        delay(1000);
      }
    }
    Serial.println("Test2");
    ststate = !ststate;
    digitalWrite(ledst, ststate);
    delay(500);
  }
  bt.print("reset Sum = ");
  bt.println(sum);
  sum = 0.0;
}

void loop() {
  if(digitalRead(startBT) == 0 && ststate == 0) {
    BTpress = millis();
    press1 = BTpress;
    while(digitalRead(startBT) == 0 && ststate == 0){
      BTpress = millis();
       Serial.println(BTpress);
       delay(500);
    }
    if(BTpress - press1 >= period){
      bto();
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
          sum += v;
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
}
