#include <Servo.h>
#include <Stepper.h>
#include <Vector.h>
#include <LiquidCrystal.h>

#define WORD_SIZE 5
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int wordPosition=0;
String letterList=  "abcdefghijklmnopqrstuvwxyz"; //list of characters to select from to write
int nextLetter =0;
int newLetter = 6;
int finishLetter = 7;
String finalWord;
void setup() {
    pinMode(nextLetter, INPUT); // declare push button as input
    pinMode(newLetter, INPUT); // declare push button as input
  Serial.begin( 9600 );
   lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");

}

void loop() 
{
    if(finalWord.length() >4 || (digitalRead(finishLetter) == LOW)){
      lcd.clear();
      lcd.print("Executing Print");
      lcd.setCursor(2, 2);
      lcd.print("PRINTING NOW");
    }
    if(digitalRead(nextLetter) == LOW){
      lcd.clear();
      if(wordPosition == letterList.length() -1 ){
          wordPosition = 0;
      }
      else{
      wordPosition++;
      }

      delay(500);
      lcd.print(finalWord);
      lcd.print(String(letterList[wordPosition]));
    }
 


    if(digitalRead(newLetter) == LOW){

            delay(100);
              if(digitalRead(newLetter) == LOW){
              String temp = String(letterList[wordPosition]);
            

              finalWord = finalWord + temp;
    
              lcd.clear();
              lcd.print(finalWord);
              wordPosition = 0;
              lcd.print(String(letterList[wordPosition]));
            }
        }
    

}



// void executeWriting(char words[]){

//     Seria.print()


// }