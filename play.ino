String value;


void doPlay() {

   for (int i = 0; i < 4; i++) {
     melody[i] = tones[EEPROM.read(i)];
   } 
  
   lcd.setCursor(4, 0);
   lcd.print("Playing");
   delay(200);
   lcd.clear();

   for (int thisNote = 0; thisNote < 4; thisNote++) {
    tone(8, melody[thisNote], 125);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = 125 * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
