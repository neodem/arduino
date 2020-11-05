

int s0 = 43;
int s1 = 45;
int binv = 47;
int cin = 49;

int a0 = 23;
int a1 = 25;
int a2 = 27;
int a3 = 29;

int b0 = 31;
int b1 = 33;
int b2 = 35;
int b3 = 37;
 
int del = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(binv, OUTPUT);
  pinMode(cin, OUTPUT);
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);

  digitalWrite(a0, LOW);
digitalWrite(a1, LOW);
digitalWrite(a2, LOW);
digitalWrite(a3, LOW);
digitalWrite(b0, LOW);
digitalWrite(b1, LOW);
digitalWrite(b2, LOW);
digitalWrite(b3, LOW);
  digitalWrite(s0, LOW); 
  digitalWrite(s1, LOW); 
  digitalWrite(binv, LOW); 
  digitalWrite(cin, LOW); 
}

void loop() {
  digitalWrite(b3, LOW); 
  digitalWrite(a0, HIGH); 
delay(del);
  digitalWrite(a0, LOW); 
  digitalWrite(a1, HIGH); 
delay(del);
  digitalWrite(a1, LOW); 
  digitalWrite(a2, HIGH); 
delay(del);
  digitalWrite(a2, LOW); 
  digitalWrite(a3, HIGH); 
delay(del);
  digitalWrite(a3, LOW); 
  digitalWrite(b0, HIGH); 
delay(del);
  digitalWrite(b0, LOW); 
  digitalWrite(b1, HIGH); 
delay(del);
  digitalWrite(b1, LOW); 
  digitalWrite(b2, HIGH); 
delay(del);
  digitalWrite(b2, LOW); 
  digitalWrite(b3, HIGH); 
delay(del);
}
