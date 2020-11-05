

void fullTest() {

  int delayMs = 7000;

  for (byte biti = 0; biti < 4; biti = biti + 1) {
    Serial.print("Board: ");
    Serial.println(biti);

    for (byte op = 0; op < 4; op = op + 1) {

      Serial.print("Operation: ");
      Serial.print(bitRead(op, 1));
      Serial.println(bitRead(op, 0));

      Serial.println("a   b   bin cin     out cout");
      Serial.println("-----------------------------");
      
      for (byte i = 0; i < 16; i = i + 1) {
        operate(biti, op, i);
        delay(delayMs);
      }
    }

    resetPins();

  }

}

void operate(int biti, int operation, byte val) {

  int s0 = bitRead(operation, 1);
  int s1 = bitRead(operation, 0);

  int a = bitRead(val, 3);
  int b = bitRead(val, 2);
  int binv = bitRead(val, 1);
  int cin  = bitRead(val, 0);

  Serial.print(a);
  Serial.print("   ");
  Serial.print(b);
  Serial.print("   ");
  Serial.print(binv);
  Serial.print("   ");
  Serial.print(cin);
  Serial.print("        ");

  writeBit(controlPins[0], s0);
  writeBit(controlPins[1], s1);
  writeBit(controlPins[2], binv);
  writeBit(controlPins[3], cin);

  writeBit(inputAPins[biti], a);
  writeBit(inputBPins[biti], b);

  int result = digitalRead(outputPins[biti]);
  Serial.print(result);
  Serial.print("   ");

  int carryout = digitalRead(carryOutPins[biti]);
  Serial.println(carryout);
}
