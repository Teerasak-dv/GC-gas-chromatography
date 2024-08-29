float sum = 0.0;

void setup() {

  Serial.begin(9600);
  delay(1000);
}
void loop() {
  float v = (analogRead (0) * 5) / 1024.0;
  if(v >= 0.5) {
    sum = sum + v;
    }
  Serial.print(v);
  Serial.println(sum);
  delay (200);
}
