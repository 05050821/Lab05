#include<Keypad.h>
const byte rows=4;
const byte cols=4;
char keys[rows][cols]={{'F','B','A','0'},{'E','3','2','1'},
                       {'D','6','5','4'},{'C','9','8','7'}};
byte rowPins[rows]={13,12,11,10};
byte colPins[cols]={9,8,7,6};
byte num[10]={B0111111,B0000110,B1011011,B1001111,B1100110,B1101101,
              B1111101,B0000111,B1111111,B1101111};
byte ledPins[]={2,3,4,5,14,15,16};
Keypad keypad =Keypad( makeKeymap(keys), rowPins,colPins, rows, cols);
void setup() {
  Serial.begin(9600); 
  int i;
  pinMode(17,OUTPUT);
  for(i=0;i<8;i++)
    pinMode(ledPins[i],OUTPUT);
}

void loop() {
    char key = keypad.getKey();
    int i,x;
    if (key != NO_KEY)
    {
        x=key-48;
        Serial.println(key);
    }
    for(i=0;i<7;i++)
      if(bitRead(num[x],i))
        digitalWrite(ledPins[i],1);
      else
        digitalWrite(ledPins[i],0);

}
