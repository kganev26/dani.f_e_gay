#include <LCD_I2C.h>
#include <Keypad.h>
LCD_I2C lcd(0x27);
// Variables to store the current number inputs and the operator
int neshto = 0, vtoroNeshto = 0;
char symbol = '0';
int result = 0;
// Define the keypad layout (4x4)
const byte ROW_NUM = 4; // Four rows
const byte COL_NUM = 4; // Four columns

char keys[ROW_NUM][COL_NUM] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'=','0','#','/'}
};

// Connect keypad rows and columns to Arduino pins
byte pin_rows[ROW_NUM] = {2, 3, 4, 5};  // Pin numbers for rows
byte pin_cols[COL_NUM] = {6, 7, 8, 9};  // Pin numbers for columns

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_cols, ROW_NUM, COL_NUM);

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  char key = keypad.getKey();
  if (key != NO_KEY) {  // Check if a key is pressed
    if (key >= '0' && key <= '9') {
      // If the key is a number, update neshto (current input)
      if (symbol == '0') {
        neshto = neshto * 10 + (key - '0'); // Update the first number
        lcd.print(neshto);
        delay(1000);
        lcd.clear();
      } else {
        vtoroNeshto = vtoroNeshto * 10 + (key - '0'); // Update the second number
        lcd.print(vtoroNeshto);
        delay(1000);
        lcd.clear();
      }
      Serial.println(neshto);
    }
    else if (key == '=') {
      // If "=" is pressed, perform the calculation based on the operator
      switch (symbol) {
        case '+': result = neshto + vtoroNeshto; break;
        case '-': result = neshto - vtoroNeshto; break;
        case '*': result = neshto * vtoroNeshto; break;
        case '/': 
          if (vtoroNeshto != 0) {
            result = neshto / vtoroNeshto; 
          } else {
            Serial.println("Error: Division by zero!");
          }
          break;
      }
      // Display the result and reset values for the next calculation
      Serial.print("Result: ");
      Serial.println(result);
        lcd.print("Result:");
  lcd.setCursor(8, 0);
  lcd.print(result);
      neshto = 0;
      vtoroNeshto = 0;
      symbol = '0';  // Reset the operator
    }
    else {
      // If an operator is pressed, store it and wait for the second number
      switch(key) {
        case '+': symbol = '+'; break;
        case '-': symbol = '-'; break;
        case '*': symbol = '*'; break;
        case '/': symbol = '/'; break;
      }
      lcd.print(symbol);
      delay(1000);
      lcd.clear();
    }
  }
}
