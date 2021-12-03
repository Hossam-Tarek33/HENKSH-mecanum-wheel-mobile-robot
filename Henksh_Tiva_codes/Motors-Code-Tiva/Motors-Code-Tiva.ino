//Front-Right wheel
int In1 = 38;
int In2 = 37;
int ENA1 = 19;

//Front-Left wheel
int In3 = 36;
int In4 = 35;
int ENA2 = 34;

//Back-Right wheel
int In5 = 32;
int In6 = 31;
int ENA4 = 33;
//Back-Left Wheel
int In7 = 15;
int In8 = 14;
int ENA3 = 30;

int SPEED = 70;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(In5,OUTPUT);
  pinMode(In6,OUTPUT);
  pinMode(In7,OUTPUT);
  pinMode(In8,OUTPUT);
  analogWrite(ENA1, 95);
  analogWrite(ENA2, 200);
  analogWrite(ENA3, 95);
  analogWrite(ENA4, 95);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()>0){
    int rx= Serial.read();
    Serial.println(rx);
    switch (rx){
      case 119:
      //FOWARD w
        digitalWrite(In2,LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4,HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5,HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7,LOW);
        digitalWrite(In8, HIGH);
        break;
      case 115:
      //BACKWARD S
        digitalWrite(In2,HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4,LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5,LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7,HIGH);
        digitalWrite(In8, LOW);
        break;
        case 100:
      //RIGHT d
        digitalWrite(In2,HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4,HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5,HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7,HIGH);
        digitalWrite(In8, LOW);
        break;
       case 97:
      //LEFT a
        digitalWrite(In2,LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4,LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5,LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7,LOW);
        digitalWrite(In8, HIGH);
        break;
        case 101:
      //ROTATE LEFT e
        digitalWrite(In2,HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4,HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5,LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7,LOW);
        digitalWrite(In8, HIGH);
        break;
        case 122:
        //ROTATE LEFT q
        digitalWrite(In2, LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4,LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5,HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7,HIGH);
        digitalWrite(In8, LOW);
        break;
      case 32:
      //STOP SPACE
        digitalWrite(In2,LOW);
        digitalWrite(In1, LOW);
        digitalWrite(In4,LOW);
        digitalWrite(In3, LOW);
        digitalWrite(In5,LOW);
        digitalWrite(In6, LOW);
        digitalWrite(In7,LOW);
        digitalWrite(In8, LOW);
        break;

    }

  
//ENA 255 means high speed and 0 means low speed
 analogWrite(ENA1, SPEED);
 analogWrite(ENA2, SPEED);
 analogWrite(ENA3, SPEED);
 analogWrite(ENA4, SPEED);
  }

}
