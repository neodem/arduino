
// LSB first in each of these
int inputAPins[] = {23, 25, 27, 29};
int inputBPins[] = {31, 33, 35, 37};
int outputPins[] = {52, 50, 48, 46};
int carryOutPins[] = {40, 38, 36, 34};

// s0,s1,binv,cin
int controlPins[] = {43, 45, 47, 49};

int del = 150;

boolean debug = false;

void setup() {
  Serial.begin(9600);

  for (byte i = 0; i < 4; i = i + 1) {
    pinMode(inputAPins[i], OUTPUT);
    pinMode(inputBPins[i], OUTPUT);
    pinMode(outputPins[i], INPUT);
    pinMode(carryOutPins[i], INPUT);
    pinMode(controlPins[i], OUTPUT);
  }

  resetPins();
}


void loop() {
  delay(4000);

//  ringOutPins();
  
 // testBinv();
  
  //testAdd();

  fullTest();

  resetPins();
  delay(120000);
}


void resetPins() {
  setDataA(0, 0, 0, 0);
  setDataB(0, 0, 0, 0);
  setControl(0, 0, 0, 0);
}

void setDataOneBit(int biti, int a, int b) {
  if (biti == 0) {
    setDataA(0, 0, 0, a);
    setDataB(0, 0, 0, b);
  }
  if (biti == 1) {
    setDataA(0, 0, a, 0);
    setDataB(0, 0, b, 0);
  }
  if (biti == 2) {
    setDataA(0, a, 0, 0);
    setDataB(0, b, 0, 0);
  }
  if (biti == 3) {
    setDataA(a, 0, 0, 0);
    setDataB(b, 0, 0, 0);
  }
}


void doOr() {
  setControl(1, 0, 0, 0);
}


void doAdd() {
  setControl(0, 0, 0, 0);
}


void doAnd() {
  setControl(1, 0, 0, 0);
}

void doXor() {
  setControl(1, 1, 0, 0);
}

void setControl(int vs1, int vs0, int vcin, int vbinv) {
  writeBit(controlPins[0], vs0);
  writeBit(controlPins[1], vs1);
  writeBit(controlPins[2], vcin);
  writeBit(controlPins[3], vbinv);
}

void setDataA(int v3, int v2, int v1, int v0) {
  writeBit(inputAPins[0], v0);
  writeBit(inputAPins[1], v1);
  writeBit(inputAPins[2], v2);
  writeBit(inputAPins[3], v3);
}

void setDataB(int v3, int v2, int v1, int v0) {
  writeBit(inputBPins[0], v0);
  writeBit(inputBPins[1], v1);
  writeBit(inputBPins[2], v2);
  writeBit(inputBPins[3], v3);
}

void writeBit(int bitId, int val) {

  if (debug == true) {
    Serial.print("setting pin ");
    Serial.print(bitId);
  }
  if (val == 0) {
    if (debug == true) {
      Serial.println(" to 0");
    }
    digitalWrite(bitId, LOW);
  } else {
    if (debug == true) {
      Serial.println(" to 1");
    }
    digitalWrite(bitId, HIGH);
  }
}
