
#include <Keypad.h>
int neshto=0;
// Define the keypad layout (4x4)
const byte ROW_NUM    = 4; // Four rows
const byte COL_NUM    = 4; // Four columns

char keys[ROW_NUM][COL_NUM] = {
  {1,2,3,'+'},
  {4,5,6,'-'},
  {7,8,9,'*'},
  {'=',0,'#','/'}
};

// Connect keypad rows and columns to Arduino pins
byte pin_rows[ROW_NUM] = {2, 3, 4, 5};  // Pin numbers for rows
byte pin_cols[COL_NUM] = {6, 7, 8, 9};  // Pin numbers for columns

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_cols, ROW_NUM, COL_NUM);

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key=keypad.getKey();
  int ch
  if(key!='+'&&'-' && '/' &&'*'&&'='){
    switch (key){
      case 1: ch=key;break;
      case 2: ch=key;break;
      case 3: ch=key;break;
      case 4: ch=key;break;
      case 5: ch=key;break;
      case 6: ch=key;break;
      case 7: ch=key;break;
      case 8: ch=key;break;
      case 9: ch=key;break;
      case 0: ch=key;break;
      default: break;
    }
  }
    neshto = neshto*10 + ch;
  
    Serial.println(neshto); // Print the pressed key to Serial Monitor
  if(key=='+')

}

