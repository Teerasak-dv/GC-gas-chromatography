int startBottom = 2;
int resetBottom = 3;
int ledStart = 8;
int StartState = LOW;
int gaspin = 0;
float sum = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(ledStart, OUTPUT);
  pinMode(startBottom, INPUT);
  pinMode(resetBottom, INPUT);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,CLOCK,TIME,VARIABLE");
}

void loop() {
  if(digitalRead(startBottom) == LOW && StartState != HIGH) {
    StartState = HIGH;
    Serial.println("start");
    digitalWrite(ledStart, StartState);
    while(digitalRead(resetBottom) != LOW) {
      float v = (analogRead(0) * 5) / 1024.0;
      Serial.println(v);
      if(v >= 0.2){
        sum = sum + v;
        }
      delay(1000);
      }
    StartState = LOW;
    Serial.print("reset Sum = ");
    Serial.println(sum);
    sum = 0.0;
    digitalWrite(ledStart, StartState);
    delay(200);
  }
}
