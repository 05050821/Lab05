#include<Keypad.h>
const byte rows=4;
const byte cols=4;
char keys[rows][cols]={{'F','B','A','0'},{'E','3','2','1'},
                       {'D','6','5','4'},{'C','9','8','7'}};
byte rowPins[rows]={13,12,11,10};
byte colPins[cols]={9,8,7,6};
Keypad keypad =Keypad( makeKeymap(keys), rowPins,colPins, rows, cols);
void setup() {
  Serial.begin(9600); 
}

void loop() {
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
        Serial.println(key);
    }

}
