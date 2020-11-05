
void testBinv() {
  int delayMs = 1000;
  
  Serial.println("Testing Binv functionality...");
  for (byte biti = 0; biti < 4; biti = biti + 1) {
    Serial.print("ringing out input pins for board/bit ");
    Serial.println(biti);

    Serial.println("setting to ADD");
    setControl(1, 0, 0, 0);

    Serial.println("setting B");
    writeBit(inputBPins[biti], 1);
    delay(delayMs);

    Serial.println("output: ");
    int result = digitalRead(outputPins[biti]);
    Serial.println(result);
    
    Serial.println("setting Binv");
    setControl(1, 0, 1, 0);
    
    Serial.println("output: ");
    result = digitalRead(outputPins[biti]);
    Serial.println(result);
  }
}
