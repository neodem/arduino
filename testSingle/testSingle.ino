// single board test

int aPin = 45;
int bPin = 43;

int s0Pin = 53;
int s1Pin = 51;
int binvPin = 49;
int cinPin = 47;

int outPin = 39;
int coutPin = 41;

boolean debug = false;

void setup() {
  Serial.begin(9600);

  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(s0Pin, OUTPUT);
  pinMode(s1Pin, OUTPUT);
  pinMode(binvPin, OUTPUT);
  pinMode(cinPin, OUTPUT);

  pinMode(outPin, INPUT);
  pinMode(coutPin, INPUT);

  // reset all output pins
  writeField(0, 0, 0, 0, 0, 0);
}

void loop() {
  delay(1000);
  
  debug = true;
  ringOutPins();
  debug = false;

  delay(4000);
  fullTest();
  delay(120000);
}

// write the field and get the result
byte writeField(int s0, int s1, int binv, int cin, int a, int b) {
  writePin(aPin, a);
  writePin(bPin, b);
  writePin(s0Pin, s0);
  writePin(s1Pin, s1);
  writePin(binvPin, binv);
  writePin(cinPin, cin);

  delay(30);

  int output = digitalRead(outPin);
  int carryOut = digitalRead(coutPin);

  byte result = 0b00;
  bitWrite(result, 0, output);
  bitWrite(result, 1, carryOut);

  return result;
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
