


#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 3;
int i = 0;

const int rs = 6, en = A0, d4=10 , d5=9 , d6=8 , d7=7 ;
byte rowPins[ROWS] = {5,4,3,2};
byte colPins[COLS] = {11,12,13};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char Keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
Keypad customKeypad = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop() {
  char button = customKeypad.getKey();
  if (button)
  {
    if (i = 15){
      lcd.autoscroll();
      i = 0;
    }
    else {
      lcd.print(button);
      i++;
    }
  }
}
