#include <Wire.h>
#include "Adafruit_VCNL4010.h"
#include "pitches.h"
#include <EEPROM.h>


// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Adafruit_VCNL4010 vcnl;

int prox_val = 0;
int note_val = 0;
const int buttonPin = 7;
int state = false;
int melody_count = 0;
// tones in C major:
int tones[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

String note_names[] = {
  "C4", "D4", "E4", "F4", "G4", "A4", "B4", "C5"
};

// melody
int melody[] = {
  0,4,2,6
};


void setup() {
  Serial.begin(9600);
  Serial.println("VCNL4010 test");
  pinMode(buttonPin, INPUT);
  if (! vcnl.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.println("Found VCNL4010");
}


void loop() {
      
  if ((digitalRead(buttonPin) == HIGH) and (state)) {
    state = not(state);
    melody_count = 0;
    Serial.println("Press");
    delay(100);
  }
  if (state) {
    doPlay();
  }
  else{
    doRecord();    
  }
}
