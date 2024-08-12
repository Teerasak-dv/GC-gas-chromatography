int startBT = 2;
int resetBT = 3;
int ledst = 8;
int ledre = 9;
int ststate;
int restate;
const int gaspin = A0;

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
    Serial.println(analogRead(gaspin));
  }
  if(digitalRead(resetBT) == LOW) {
    ststate = LOW;
    Serial.println("reset");
    digitalWrite(ledst, ststate);
    delay(200);
  }
}
