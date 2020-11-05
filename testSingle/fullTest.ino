

void fullTest() {

  int delayMs = 100;

  Serial.println("");
  Serial.println("Testing operation of board");
  Serial.println("--------------------------");
  Serial.println("");

  for (byte op = 0; op < 4; op = op + 1) {

    Serial.print("Operation: ");
    Serial.print(bitRead(op, 1));
    Serial.println(bitRead(op, 0));

    Serial.println("a   b   bin cin     out cout");
    Serial.println("-----------------------------");


    for (byte i = 0; i < 4; i = i + 1) {
      operate(op, i, 0, 0);
      delay(delayMs);
    }

    for (byte i = 0; i < 4; i = i + 1) {
      operate(op, i, 0, 1);
      delay(delayMs);
    }

    for (byte i = 0; i < 4; i = i + 1) {
      operate(op, i, 1, 0);
      delay(delayMs);
    }

    for (byte i = 0; i < 4; i = i + 1) {
      operate(op, i, 1, 1);
      delay(delayMs);
    }
  }

  writeField(0, 0, 0, 0, 0, 0);
}

void operate(int operation, byte inputVal, int cin, int binv) {

  int s0 = bitRead(operation, 1);
  int s1 = bitRead(operation, 0);

  int a = bitRead(inputVal, 1);
  int b = bitRead(inputVal, 0);

  Serial.print(a);
  Serial.print("   ");
  Serial.print(b);
  Serial.print("   ");
  Serial.print(binv);
  Serial.print("   ");
  Serial.print(cin);
  Serial.print("        ");

  byte result = writeField(s0, s1, binv, cin, a, b);

  int output = bitRead(result, 0);
  int carryOut = bitRead(result, 1);

  Serial.print(output);
  Serial.print("   ");
  Serial.println(carryOut);
}
