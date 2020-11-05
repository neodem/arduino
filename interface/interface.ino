
// LSB first in each of these
int inputAPins[] = {52, 50, 48, 46};
int inputBPins[] = {44, 42, 40, 38};
int outputPins[] = {43, 41, 39, 37};

int carryOutPin = 45;

// s0,s1,binv,cin
int controlPins[] = {53, 51, 49, 47};

int zeroField[] = {0,0,0,0,0,0,0,0,0,0,0,0};

boolean debug = false;

// the buffer from the serial port
byte buf[2] = {0,0};

// the packet to send to the hardware
int packet[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

// the result from the hardware
int result[5] = {0,0,0,0,0};

void setup() {
  Serial.begin(9600);

  for (byte i = 0; i < 4; i = i + 1) {
    pinMode(inputAPins[i], OUTPUT);
    pinMode(inputBPins[i], OUTPUT);
    pinMode(controlPins[i], OUTPUT);
    pinMode(outputPins[i], INPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    Serial.readBytes(buf, 2);
    Serial.println(buf, BIN)
    convertFromBuffer(packet, buf);
    writeField(result, packet);
    sendSerialReply(result);
  }
}

void convertFromBuffer(int * packet, byte * buf) { 
  packet[0] = bitRead(buf[0], 0);
  packet[1] = bitRead(buf[0], 1);
  packet[2] = bitRead(buf[0], 2);
  packet[3] = bitRead(buf[0], 3);
  packet[4] = bitRead(buf[0], 4);
  packet[5] = bitRead(buf[0], 5);
  packet[6] = bitRead(buf[0], 6);
  packet[7] = bitRead(buf[0], 7);
  packet[8] = bitRead(buf[1], 0);
  packet[9] = bitRead(buf[1], 1);
  packet[10] = bitRead(buf[1], 2);
  packet[11] = bitRead(buf[1], 3);
  packet[12] = bitRead(buf[1], 4);
}

// send 5 bits to the USB port
void sendSerialReply(int * reply) {
  
}


// write the field and get the result
// packet 0..3 s0,s1,binv,cin
// packet 4..7 a
// packet 8..11 b
void writeField(int * result, int * packet) {

  for (byte i = 0; i < 4; i = i + 1) {
     // write the data
    writePin(inputAPins[i], packet[i + 4]);
    writePin(inputBPins[i], packet[i + 8]);

    // write the operation
    writePin(controlPins[i], packet[i]);
  }

  // we need to wait a bit for the operation to click in...
  delay(30);

  for (byte i = 0; i < 4; i = i + 1) {
    result[i] = digitalRead(outputPins[i]);
  }
  result[5] = digitalRead(carryOutPin);
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
