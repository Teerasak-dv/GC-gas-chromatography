int startBT = 2;
int resetBT = 3;
int ledst = 8;
int ledre = 9;
int ststate = LOW;
int restate = LOW;
int gaspin = 0;
float sum = 0.0;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(ledst, OUTPUT);
  pinMode(ledre, OUTPUT);
  pinMode(startBT, INPUT);
  pinMode(resetBT, INPUT);
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
}

void loop() {
  if(digitalRead(startBT) == LOW && ststate != HIGH) {
    ststate = HIGH;
    Serial.println("start");
    bt.println("start");
    digitalWrite(ledst, ststate);
    while(digitalRead(resetBT) != LOW) {
      float v = (analogRead(0) * 5) / 1024.0;
      Serial.println(v);
      bt.println(v);
      if(v >= 0.2){
        sum = sum + v;
        }
      delay(1000);
      }
    ststate = LOW;
    Serial.print("reset Sum = ");
    bt.print("reset Sum = ");
    Serial.println(sum);
    bt.println(sum);
    sum = 0.0;
    digitalWrite(ledst, ststate);
    delay(200);
  }
}
