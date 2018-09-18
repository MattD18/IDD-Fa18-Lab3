/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int color = 0;

//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  Serial.begin(9600); 
}



void loop()
{
  color = analogRead(A0);
  Serial.println(color);
  if (color < 150){ 
  setColor(80, 0, 80);  // purple
  }
  else if (color < 300){ 
  setColor(0, 0, 255);  // blue
  }
  else if (color < 450){
  setColor(0, 255, 255);  // aqua
  }
  else if (color < 600){ 
  setColor(0, 255, 0);  // green
  }
  else if (color < 750){ 
  setColor(255, 255, 0);  // yellow
  }
  else{ 
  setColor(255, 0, 0);  // red
  }



}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
