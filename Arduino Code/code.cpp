int startBT = 2;
int resetBT = 3;
int ledst = 8;
int ledre = 9;
int ststate;
int restate;
const int gaspin = 0;

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
    while(digitalRead(resetBT) == LOW) {
      int v1 = analogRead(gaspin);
      float v2 = v1 * (5.0 / 1024);
      Serial.println(v2);
    }
  }
  ststate = LOW;
  Serial.println("reset");
  digitalWrite(ledst, ststate);
  delay(200);

}
