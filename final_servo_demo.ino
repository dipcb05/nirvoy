#include <Servo.h>
Servo servo1;
Servo servo2;
int pos = 0, pos1 = 0;
char input;
bool check = true;
const int buttonPin = 2;
int buttonState;
int up_button = 11;
int down_button = 4;
//int up_button1 = 7;
//int down_button1 = 8;
int counter; //bosha mane 0. darano mane 1.

void setup() {
  servo1.attach(5);
  Serial.begin(9600);
  servo2.attach(9);
  Serial.begin(9600);
  //pinMode(inp, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {
   //buttonState = digitalRead(up_button);
   
  /*if(buttonState == HIGH) {
  digitalWrite(13, HIGH);
  counter = 1;
  delay(150);
}
if (digitalRead(down_button) == HIGH) {
  digitalWrite(13, LOW);
  counter = 0;
  delay(150);
}*/
  if(digitalRead(up_button) == HIGH) 
  {
    input = '2';
    Serial.println("Button Pressed");
  } 
  else if (digitalRead(down_button) == HIGH)
  {
    input = '1';
    Serial.println("Button Chharo");
  }
  /*else if(digitalRead(up_button1) == HIGH) 
  {
    input = '2';
    Serial.println("Button Pressed");
  } 
   else if (digitalRead(down_button1) == HIGH)
  {
    input = '1';
    Serial.println("Button Chharo");
  }*/
  if(input > 0)
  {
  //input = Serial.read();
  if((input == '1') && (check == false))
  {
    for (pos = 0, pos1 = 90; pos <= 90, pos1 >= 0; pos++, pos1--) {
     // delay(3);
    servo1.write(pos);
    servo2.write(pos1);
    //delay(35);    
  }
  check = true;
  }
  if((input == '2') && (check == true)){
    for (pos = 90, pos1 = 0; pos >= 0, pos1 < 90; pos --, pos1++) {
    servo1.write(pos);
    servo2.write(pos1);
    //delay(35);  
  }
  check = false;
  }
  }
}
