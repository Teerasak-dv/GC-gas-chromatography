int startBT = 2;
int resetBT = 3;
int ledst = 8;
int ledre = 9;
int ststate = LOW;
int restate = LOW;
int gaspin = 0;
float r1 = 100000;
float r2 = 10000;
float vp = 1.7;
float sum = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(ledst, OUTPUT);
  pinMode(ledre, OUTPUT);
  pinMode(startBT, INPUT);
  pinMode(resetBT, INPUT);
}

void loop() {
  if(digitalRead(startBT) == LOW && ststate != HIGH) {
    ststate = HIGH;
    Serial.println("start");
    digitalWrite(ledst, ststate);
    while(digitalRead(resetBT) != LOW) {
      float v = (analogRead(0) * 5) / 1024.0;
      Serial.println(v);
      if(v >= 0.5){
        sum = sum + v;
        Serial.print( sum);
        }
      delay(100);
    }
    ststate = LOW;
    Serial.println("reset");
    digitalWrite(ledst, ststate);
    delay(200);
  }
}
