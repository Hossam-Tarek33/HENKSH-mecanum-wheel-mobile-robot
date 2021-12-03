#include <ros.h>
#include <std_msgs/String.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1);

int In1 = 7;
int In2 = 8;

int In3 = 12;
int In4 = 13;

int In5 = 11;
int In6 = 10;

int In7 = 2;
int In8 = 4;

int ENA1 = 5;
int ENA2 = 6;
int ENA3 = 3;
int ENA4 = 9;

int SPEED = 50;


ros::NodeHandle nh;

void messageCb( const std_msgs::String& motor1_cmd)
{
    nh.loginfo(motor1_cmd.data);
            
    if (String(motor1_cmd.data) == String("w"))
    {
        digitalWrite(In2,LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4, HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5, HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7, LOW);
        digitalWrite(In8, HIGH);
        analogWrite(ENA1, SPEED);
        analogWrite(ENA2, SPEED);
        analogWrite(ENA3, SPEED);
        analogWrite(ENA4, SPEED);}

    else if (String(motor1_cmd.data) ==String("s")){
        digitalWrite(In2,HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4, LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5, LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7, HIGH);
        digitalWrite(In8, LOW);
        analogWrite(ENA1, SPEED);
        analogWrite(ENA2, SPEED);
        analogWrite(ENA3, SPEED);
        analogWrite(ENA4, SPEED);} 
        
    else if (String(motor1_cmd.data) ==String("d")){
        digitalWrite(In2,HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4, HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5, HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7, HIGH);
        digitalWrite(In8, LOW);
        analogWrite(ENA1, SPEED);
        analogWrite(ENA2, SPEED);
        analogWrite(ENA3, SPEED);
        analogWrite(ENA4, SPEED);} 

    else if (String(motor1_cmd.data) ==String("a")){
        digitalWrite(In2, LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4, LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5, LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7, LOW);
        digitalWrite(In8, HIGH);
        analogWrite(ENA1, SPEED);
        analogWrite(ENA2, SPEED);
        analogWrite(ENA3, SPEED);
        analogWrite(ENA4, SPEED);} 

    else if (String(motor1_cmd.data) ==String("e")){
        digitalWrite(In2, HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4, HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5, LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7, LOW);
        digitalWrite(In8, HIGH);
        analogWrite(ENA1, SPEED);
        analogWrite(ENA2, SPEED);
        analogWrite(ENA3, SPEED);
        analogWrite(ENA4, SPEED);} 

    else if (String(motor1_cmd.data) ==String("q")){
        digitalWrite(In2, LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4, LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5, HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7, HIGH);
        digitalWrite(In8, LOW);
        analogWrite(ENA1, SPEED);
        analogWrite(ENA2, SPEED);
        analogWrite(ENA3, SPEED);
        analogWrite(ENA4, SPEED);}

    else if (String(motor1_cmd.data) == String(" ")){
        digitalWrite(In2, LOW);
        digitalWrite(In1, LOW);
        digitalWrite(In4, LOW);
        digitalWrite(In3, LOW);
        digitalWrite(In5, LOW);
        digitalWrite(In6, LOW);
        digitalWrite(In7, LOW);
        digitalWrite(In8, LOW);
        analogWrite(ENA1, SPEED);
        analogWrite(ENA2, SPEED);
        analogWrite(ENA3, SPEED);
        analogWrite(ENA4, SPEED);}
}        
ros::Subscriber<std_msgs::String> sub("cmd_motor1", &messageCb);


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  //mySerial.begin(57600);
  nh.getHardware()->setBaud(57600);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(In5,OUTPUT);
  pinMode(In6,OUTPUT);
  pinMode(In7,OUTPUT);
  pinMode(In8,OUTPUT);
  //analogWrite(ENA1, 95);
  nh.initNode();
  nh.subscribe(sub);
  }

void loop() {
  nh.spinOnce();
  delay(500);
  
}
