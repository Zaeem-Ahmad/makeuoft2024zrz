#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

rgb_lcd lcd;
const int colorR = 178;
const int colorG = 255;
const int colorB = 255;

const int buttonPin = 8;
const int servoPin = 9;
const int motorPin = 10;

Servo servo;
int counter  = 0;
int medicineRemaining = 4;

void setup() 
{
    servo.attach(servoPin);
    pinMode(buttonPin, INPUT);
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.

    delay(1000);
}

void loop() 
{   

    int buttonState;
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW)  // light the LED
  {
    counter++;
    delay(500);
  }

  

  if (counter == 0) {
    servo.write(20);
    //digitalWrite(motorPin, LOW); 
  }

  else if (counter == 1){

    digitalWrite(motorPin, HIGH);
    delay(20);
    
    digitalWrite(motorPin, LOW);

    medicineRemaining--;
    counter++;
  }

  else if (counter == 2){
    servo.write(100);
    
  }
  //else reset the counter to 0 which resets thr servo to 0 degrees
  else
    counter = 0;

  if (medicineRemaining == 5){
    medicineRemaining = 0;
  }


  Serial.println(counter);
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0);
    lcd.print(medicineRemaining);
    lcd.print(" Meds Remain");

    lcd.setCursor(0, 1);
    lcd.print(4-medicineRemaining);
    lcd.print(" Meds Taken");
    // print the number of seconds since reset:
    //lcd.print(millis()/1000);

    delay(100);
}