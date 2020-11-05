

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
 
int del = 750;

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

dataA(0,0,0,0);
dataB(0,0,0,0);
control(0,0,0,0);
}

void loop() {
dataA(1,1,1,0);
delay(del);
dataA(1,1,1,1);
delay(del);

//dataA(0,0,0,0);
//delay(del);
//dataA(0,0,0,1);
//delay(del);
//dataA(0,0,1,0);
//delay(del);
//dataA(0,0,1,1);
//delay(del);
//dataA(0,1,0,0);
//delay(del);
//dataA(0,1,0,1);
//delay(del);
//dataA(0,1,1,0);
//delay(del);
//dataA(0,1,1,1);
//delay(del);
//dataA(1,0,0,0);
//delay(del);
//dataA(1,0,0,1);
//delay(del);
//dataA(1,0,1,0);
//delay(del);
//dataA(1,0,1,1);
//delay(del);
//dataA(1,1,0,0);
//delay(del);
//dataA(1,1,0,1);
//delay(del);
//dataA(1,1,1,0);
//delay(del);
//dataA(1,1,1,1);
//delay(del);

  // 00 add
  
  // 01 and
  // 10 xor
  // 11 and

// add
//doAdd();
//dataA(0,0,0,1);
//dataB(0,0,0,1);

// or
//doOr();
//dataA(0,0,0,1);
//dataB(0,0,0,0);

// and
//doAnd();
//dataB(1,1,1,1);
//dataA(0,0,0,0);


  // LSB --> 
//dataA(0,0,0,1);
//dataB(0,0,0,1);


//dataA(0,0,1,0);
//dataB(0,0,1,0);


//dataA(0,1,0,0);
//dataB(0,1,0,0);


//dataA(0,0,0,0);
//dataB(1,0,0,0);
}


void doOr() {
  control(1,0,0,0);
}


void doAdd() {
  control(0,0,0,0);
}


void doAnd() {
  control(1,0,0,0);
}

void doXor() {
  control(1,1,0,0);
}

void control(int vs1, int vs0, int vcin, int vbinv) {
writeBit(s0, vs0);
writeBit(s1, vs1);
writeBit(cin, vcin);
writeBit(binv, vbinv);
}

void dataA(int v3, int v2, int v1, int v0) {
writeBit(a0, v0);
writeBit(a1, v1);
writeBit(a2, v2);
writeBit(a3, v3);
}


void dataB(int v3, int v2, int v1, int v0) {
writeBit(b0, v0);
writeBit(b1, v1);
writeBit(b2, v2);
writeBit(b3, v3);
}

void writeBit(int bitId, int val) {
if (val == 0) {
  digitalWrite(bitId, LOW);
} else {
  digitalWrite(bitId, HIGH);
}
}
