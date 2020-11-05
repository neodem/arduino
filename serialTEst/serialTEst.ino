

int a0Pin = 52;
int a1Pin = 50;
int a2Pin = 48;
int a3Pin = 46;
int b0Pin = 44;
int b1Pin = 42;
int b2Pin = 40;
int b3Pin = 38;

int outputPins[] = {43, 41, 39, 37};

int carryOutPin = 45;

// s0,s1,binv,cin
int s0Pin = 53;
int s1Pin = 51;
int binvPin = 49;
int cinPin = 47;

boolean debug = true;

// input buffers
int a0 = 0;
int a1 = 0;
int a2 = 0;
int a3 = 0;
int b0 = 0;
int b1 = 0;
int b2 = 0;
int b3 = 0;
int s0 = 0;
int s1 = 0;
int cin = 0;
int binv = 0;

// the result from the hardware
int result[5] = {0, 0, 0, 0, 0};

void setup() {

  // computer
  Serial.begin(9600);

  // usb
  Serial1.begin(9600);

  pinMode(a0Pin, OUTPUT);
  pinMode(a1Pin, OUTPUT);
  pinMode(a2Pin, OUTPUT);
  pinMode(a3Pin, OUTPUT);
  pinMode(b0Pin, OUTPUT);
  pinMode(b1Pin, OUTPUT);
  pinMode(b2Pin, OUTPUT);
  pinMode(b3Pin, OUTPUT);

  for (byte i = 0; i < 4; i = i + 1) {
    pinMode(outputPins[i], INPUT);
  }

  pinMode(s0Pin, OUTPUT);
  pinMode(s1Pin, OUTPUT);
  pinMode(binvPin, OUTPUT);
  pinMode(cinPin, OUTPUT);
  pinMode(carryOutPin, INPUT);

  // reset all pins
  digitalWrite(a0Pin, LOW);
  digitalWrite(a1Pin, LOW);
  digitalWrite(a2Pin, LOW);
  digitalWrite(a3Pin, LOW);
  digitalWrite(b0Pin, LOW);
  digitalWrite(b1Pin, LOW);
  digitalWrite(b2Pin, LOW);
  digitalWrite(b3Pin, LOW);
  digitalWrite(s0Pin, LOW);
  digitalWrite(s1Pin, LOW);
  digitalWrite(binvPin, LOW);
  digitalWrite(cinPin, LOW);
}

// buffers from the USB serial operations
int dataByte = -1;
int opByte = -1;

void loop() {
  byte buff[2];
  if (Serial1.available() > 0) {

    Serial1.readBytes(buff, 2);
    dataByte = buff[0];
    opByte = buff[1];
    buff[0] = 0;
    buff[1] = 0;

    if (debug) {
      Serial.print("dataByte:");
      Serial.println(dataByte, BIN);
      Serial.print("opByte:");
      Serial.println(opByte, BIN);
    }
    int result = process();

    if (debug) {
      Serial.print("data sent back:");
      Serial.println(result, BIN);
      Serial.println();
    }

    Serial1.write(result);
  }
}

int process() {
  a0 = bitRead(dataByte, 4);
  a1 = bitRead(dataByte, 5);
  a2 = bitRead(dataByte, 6);
  a3 = bitRead(dataByte, 7);

  b0 = bitRead(dataByte, 0);
  b1 = bitRead(dataByte, 1);
  b2 = bitRead(dataByte, 2);
  b3 = bitRead(dataByte, 3);

  s1 = bitRead(opByte, 2);
  s0 = bitRead(opByte, 3);
  binv = bitRead(opByte, 0);
  cin = bitRead(opByte, 1);

  writeField();

  int retval = 0;
  bitWrite(retval, 0, result[0]);
  bitWrite(retval, 1, result[1]);
  bitWrite(retval, 2, result[2]);
  bitWrite(retval, 3, result[3]);
  bitWrite(retval, 4, result[4]);

  return retval;
}

// write the field and get the result
// packet 0..3 s0,s1,binv,cin
// packet 4..7 a
// packet 8..11 b
void writeField() {

  if (debug) {
    Serial.print("sending data to hardware: a");

    Serial.print(a3);
    Serial.print(a2);
    Serial.print(a1);
    Serial.print(a0);

    Serial.print(" b");
    Serial.print(b3);
    Serial.print(b2);
    Serial.print(b1);
    Serial.print(b0);

    Serial.print(" op");
    Serial.print(s1);
    Serial.print(s0);

    Serial.print(" cin");
    Serial.print(cin);

    Serial.print(" binv");
    Serial.print(binv);

    Serial.println();
  }

  Serial.println();

  writePin(a0Pin, a0);
  writePin(a1Pin, a1);
  writePin(a2Pin, a2);
  writePin(a3Pin, a3);
  Serial.println();
  writePin(b0Pin, b0);
  writePin(b1Pin, b1);
  writePin(b2Pin, b2);
  writePin(b3Pin, b3);

  Serial.println();

  writePin(s0Pin, s0);
  writePin(s1Pin, s1);
  writePin(binvPin, binv);
  writePin(cinPin, cin);

  // we need to wait a bit for the operation to click in...
  delay(15);

  for (byte i = 0; i < 4; i = i + 1) {
    result[i] = digitalRead(outputPins[i]);
  }
  result[4] = digitalRead(carryOutPin);

  if (debug) {
    Serial.println();
    Serial.print("result from hardware: out");
    Serial.print(result[3]);
    Serial.print(result[2]);
    Serial.print(result[1]);
    Serial.print(result[0]);
    Serial.print(" carryOut=");
    Serial.println(result[4]);
  }
}

void writePin(int bitId, int val) {

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
