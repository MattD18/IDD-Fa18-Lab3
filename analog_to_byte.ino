/*
Adafruit Arduino - Lesson 3. RGB LED
*/


int analog_input = 0;
int byte_output = 0;


void setup()
{
  Serial.begin(9600); 
}



void loop()
{
  analog_input = analogRead(A0);
  byte_output = map(analog_input, 0, 1023, 0, 255);
  Serial.println(byte_output);
  delay(200);
}
