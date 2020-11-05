
void testAdd() {
  int delayMs = 1000;

  Serial.println("Testing Add functionality...");
  for (byte biti = 0; biti < 4; biti = biti + 1) {
    Serial.print("Testing Add for bit: ");
    Serial.println(biti);
    testAdd(biti);
  }
}

void testAdd(int biti) {
  testAdd(biti, 0, 0);
  testAdd(biti, 0, 1);
  testAdd(biti, 1, 0);
  testAdd(biti, 1, 1);
}

void testAdd(int biti, int a, int b) {

 int delayMs = 250;
  
  Serial.print("input: a: ");
  Serial.print(a);
  Serial.print(" b: ");
  Serial.println(b);

  writeBit(inputAPins[biti], a);
  writeBit(inputBPins[biti], b);

  // ADD
  setControl(0, 0, 0, 0);
  Serial.print("ADD: ");
  int result = digitalRead(outputPins[biti]);
  Serial.println(result);
  delay(delayMs);

  //ADD + binv
  setControl(0, 0, 0, 1);
  Serial.print("ADD + binv: ");
  result = digitalRead(outputPins[biti]);
  Serial.println(result);
  delay(delayMs);

  //ADD + cin
  setControl(0, 0, 1, 0);
  Serial.print("ADD + cin: ");
  result = digitalRead(outputPins[biti]);
  Serial.println(result);
  delay(delayMs);

  //ADD + cin + binv
  setControl(0, 0, 1, 1);
  Serial.print("ADD + cin + binv: ");
  result = digitalRead(outputPins[biti]);
  Serial.println(result);
}
