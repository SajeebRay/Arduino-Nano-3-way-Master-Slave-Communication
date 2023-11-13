#include <SoftwareSerial.h>

#define BT_NAME   "BT_Master"

#define SLAVE_ADDRESS "98d3,31,8095c3"  //98d3:31:8095c3

SoftwareSerial mySerial(2, 3); // RX, TX
const int buttonPin = 7;
const int buttonPin2 = 8;
const int bpin9 = 9;
int buttonState = 0;  
int buttonState2 = 0; 
int button3 = 0;
void setup()
{
  Serial.begin(38400);

  mySerial.begin(38400);
  Serial.println("Arduino Sender");
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(bpin9, INPUT);

  mySerial.print("AT\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+RMAAD\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+ROLE=1\r\n");
  updateSerial();
  delay(200);  
  mySerial.print("AT+NAME="+String(BT_NAME)+"\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+PSWD=\"1234\"\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+BIND="+String(SLAVE_ADDRESS)+"\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+UART=38400,0,0\r\n");
  updateSerial();
  delay(500);
  mySerial.print("AT+UART?\r\n");
  updateSerial();
  delay(200);
}

void updateSerial(void)
{
}

void loop()
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  //if (Serial.available())
    //mySerial.write(Serial.read());
    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  button3 = digitalRead(bpin9);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if(buttonState == LOW and buttonState2 == LOW and button3 == LOW){
     mySerial.write('Z');
  }
  if (buttonState == HIGH) {
    mySerial.write('A');
    delay(125);
  }
  if (buttonState2 == HIGH) {
    mySerial.write('B');
    delay(125);
  }
  if (button3 == HIGH) {
    mySerial.write('D');
    delay(125);
  }
}
