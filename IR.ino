// Smart Hallway Lights Demo using IR + PIR sensors
// D2..D9 -> LEDs (lights)
// D10 -> IR_A (A-end sensor)
// D11 -> IR_B (B-end sensor)
// D12 -> PIR (motion hold)

const byte LEDS[8] = {2,3,4,5,6,7,8,9};
const byte IR_A = 10;
const byte IR_B = 11;
const byte PIR  = 12;

unsigned long tIdleMs   = 6000;   // lights stay ON this long after no motion
unsigned long stepOnMs  = 150;    // delay between lights ON
unsigned long stepOffMs = 120;    // delay between lights OFF

enum Mode { IDLE, SEQ_ON, ACTIVE, SEQ_OFF };
Mode mode = IDLE;
bool dirAtoB = true;
unsigned long idleDeadline = 0;

void setAllOff(){ for (byte i=0;i<8;i++) digitalWrite(LEDS[i], LOW); }

void seqOn(bool forward){
  if (forward){
    for (byte i=0;i<8;i++){ digitalWrite(LEDS[i], HIGH); delay(stepOnMs); }
  } else {
    for (int i=7;i>=0;i--){ digitalWrite(LEDS[i], HIGH); delay(stepOnMs); }
  }
}

void seqOffReverse(bool forward){
  if (forward){
    for (int i=7;i>=0;i--){ digitalWrite(LEDS[i], LOW); delay(stepOffMs); }
  } else {
    for (byte i=0;i<8;i++){ digitalWrite(LEDS[i], LOW); delay(stepOffMs); }
  }
}

void setup(){
  Serial.begin(9600);
  for (byte i=0;i<8;i++){ pinMode(LEDS[i], OUTPUT); digitalWrite(LEDS[i], LOW); }
  pinMode(IR_A, INPUT);
  pinMode(IR_B, INPUT);
  pinMode(PIR,  INPUT);
  Serial.println("Smart Hallway Light demo start");
}

void loop(){
  bool a = digitalRead(IR_A);   // HIGH or LOW depends on module type
  bool b = digitalRead(IR_B);
  bool p = digitalRead(PIR);

  // Optional: print for debugging
  // Serial.print(a); Serial.print(" "); Serial.print(b); Serial.print(" "); Serial.println(p);

  switch (mode){
    case IDLE:
      if (a){ dirAtoB = true;  mode = SEQ_ON; }
      else if (b){ dirAtoB = false; mode = SEQ_ON; }
      break;

    case SEQ_ON:
      seqOn(dirAtoB);
      idleDeadline = millis() + tIdleMs;
      mode = ACTIVE;
      break;

    case ACTIVE:
      // if motion detected, reset timer
      if (p || a || b) idleDeadline = millis() + tIdleMs;
      if (millis() > idleDeadline) mode = SEQ_OFF;
      break;

    case SEQ_OFF:
      seqOffReverse(dirAtoB);
      setAllOff();
      mode = IDLE;
      break;
  }
}
