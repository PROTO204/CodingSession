byte clockPin = 18; //Pin connected to SH_CP of 74HC595
byte latchPin = 19;  //Pin connected to ST_CP of 74HC595
byte dataPin = 20;  //Pin connected to DS    of 74HC595

byte DigitOne = 17;
byte DigitTwo = 16;
byte DigitThree = 15;
byte DigitFour = 14;


//byte clockPin = 8; //Pin connected to SH_CP of 74HC595
//byte latchPin = 7;  //Pin connected to ST_CP of 74HC595
//byte dataPin = 6;  //Pin connected to DS    of 74HC595
//
//byte DigitOne = 12;
//byte DigitTwo = 11;
//byte DigitThree = 10;
//byte DigitFour = 9;

byte digit[16]= {
  0xD7,0x12,0xDC,0x9E,0x1B,0x8F,0xCF,0x16,0xDF,0x9F,0x5F,0xCB,0xC5,0xDA,0xCD,0x4D};


void setup() {
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(DigitOne, OUTPUT);
  pinMode(DigitTwo, OUTPUT);
  pinMode(DigitThree, OUTPUT);
  pinMode(DigitFour, OUTPUT);

  digitalWrite(DigitOne, HIGH);
  digitalWrite(DigitTwo, HIGH);
  digitalWrite(DigitThree, HIGH);
  digitalWrite(DigitFour, HIGH);
}


void loop() {
  for(int j=0; j<16; j++){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ~digit[j]); // digitOne
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }
}






