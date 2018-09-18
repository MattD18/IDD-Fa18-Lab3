# Data Logger (and using cool sensors!)

*A lab report by Matthew Dalton*

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

The range of analog values is 0 to 1023.
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

The ADC has 10 bits of resolution and we're using all 10.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

see video

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

The voltage values have to be between 0 and 5V, but the highest voltage I personally saw was 4.76V.

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

There appears to be a logarithimic relationship between voltage and the force applied.

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

Yes, to get a full range of colors and full range of ouput voltages, I bucketed the LED code using if/else statements on the readings from my FSR.

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

For the photoresistor, using five 1000 Ohm resistors in series (5k Ohms total), gave me a volage range from 2.25V-3.71V, which is sufficient using my if/else structure. 

For the flex sensor resistor, I used the 10k Ohm resistor, which gave me an analog reading range from 0.49V-1.96V, which is sufficient using my if/else structure.


For the softpot, I used the 10k Ohm resistor, which gave me an analog reading range from 1.96V-5V, which is sufficient using my if/else structure.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

For the photoresistor, there appears to be a linear relationship.

For the flex sensor resistor, there appears to be a logarithmic relationship.

For the softpot, different areas of the softpot map to different resistances.

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

see attached

### 3. IR Proximity Sensor

**a. Describe the metric change over the sensing range of the sensor. A sketch of metric vs. distance would work also. Does it match up with what you expect from the datasheet?**

The two metrics the sensor displays are ambience and proximity. Ambience increases with distance of the object and proximity decreases with distance of the object which aligns with expectations.

**b. Upload your merged code to your lab report repository and link to it here.**

see code

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

Yes, since the potentiometer continously slides, state 2 can only be reached from state 0 by passing through state 1. This mechanic enforces the order in which actions are assigned to states because if the clear action was in the middle state (state 1), nothing could ever be saved.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

The loop functions handle switching between states. If state actions occured in the loop functions they would occur repeatedly and delay the state transactions.

**c. How many byte-sized data samples can you store on the Atmega328?**

We can store 1024 byte-sized data samples.

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**




**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
