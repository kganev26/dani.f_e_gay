#include <Keypad.h>

// Variable to store the current number input
int neshto = 0;

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
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {  // Check if a key is pressed
    if (key >= '0' && key <= '9') {
      // If the key is a number, update neshto (current input)
      neshto = neshto * 10 + (key - '0'); // Convert char to int and update
      Serial.println(neshto);
    }
    else if (key == '=') {
      // If "=" is pressed, print the result (or just reset for this case)
      Serial.print("Result: ");
      Serial.println(neshto);
      neshto = 0;  // Reset after calculation
    }
    else {
      // Handle operators (+, -, *, /)
      // In this case, you might want to process operations or store them.
      Serial.print("Operator pressed: ");
      Serial.println(key);
      // You can handle calculations or store operator for future logic here.
    }
  }
}
