#include <Stepper.h>
#include <LiquidCrystal_I2C.h>

const int stepsPerRevolution = 48; 

Stepper myStepperY(stepsPerRevolution, 2,3,4,5);            
Stepper myStepperX(stepsPerRevolution, 11,10,8,9);  
LiquidCrystal_I2C lcd(0x27, 20, 2);

void setup() {
  // put your setup code here, to run once:
  myStepperX.setSpeed(100 );
    myStepperY.setSpeed(100 );

   lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print("LCD Tutorial");

}

void loop() {
      myStepperX.step(50);
      delay(500);
      myStepperY.step(100);
      delay(500);
      //myStepperX.step(-10);



  // put your main code here, to run repeatedly:

}
