int trigger = 7;
int echo = 6;

long dauer = 0;
long entfernug = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  entfernug = (dauer/2) * 0.03432;
  if(entfernug >= 500 || entfernug <= 0){
    Serial.println("Keine Messung");
  }
  else{
    Serial.print(entfernug);
    Serial.println(" cm");
  }
  delay(1000);
}
