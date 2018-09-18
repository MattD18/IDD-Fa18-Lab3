


void doRecord() {

  
   prox_val = vcnl.readProximity();
   note_val = map(prox_val, 2000, 5000, 0, 7);

   lcd.setCursor(4, 0);
   lcd.print(note_names[note_val]);
   delay(200);
   if (digitalRead(buttonPin) == HIGH){
      EEPROM.write(melody_count, note_val);
      melody_count++;
      Serial.println(note_names[note_val]);   
      Serial.println(melody_count);
      lcd.setCursor(4, 0);
      lcd.print("Recorded");
      delay(200);
      lcd.clear();
   }
   if (melody_count == 4){
      state = not(state);
      delay(1000);
   }
   lcd.clear();
}
