//Front-Right wheel
int In1 = 39;
int In2 = 38;
int ENA1 = 40;

//Front-Left wheel
int In3 = 2;
int In4 = 37;
int ENA2 = 31;

//Back-Left wheel
int In5 = 30;
int In6 = 7;
int ENA4 = 31;
//Back-Right Wheel
int In7 = 25;
int In8 = 24;
int ENA3 = 23;

int SPEED = 70;
int usbRead = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(In5,OUTPUT);
  pinMode(In6,OUTPUT);
  pinMode(In7,OUTPUT);
  pinMode(In8,OUTPUT);
  analogWrite(ENA1, SPEED);
  analogWrite(ENA2, SPEED);
  analogWrite(ENA3, SPEED);
  analogWrite(ENA4, SPEED);
  }

void loop() {
  if(Serial.available()){
    usbRead = Serial.read();
    if(usbRead == 'w'){
        digitalWrite(In2,LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4, HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5, HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7, LOW);
        digitalWrite(In8, HIGH);
       } 
    else if(usbRead =='s'){
        digitalWrite(In2,HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4, LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5, LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7, HIGH);
        digitalWrite(In8, LOW);
        }
        
    else if(usbRead == 'd'){
        digitalWrite(In2,HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4, HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5, HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7, HIGH);
        digitalWrite(In8, LOW);
        }
        
    else if(usbRead == 'a'){
        digitalWrite(In2, LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4, LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5, LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7, LOW);
        digitalWrite(In8, HIGH);
        }
        
    else if(usbRead == 'e'){
        digitalWrite(In2, HIGH);
        digitalWrite(In1, LOW);
        digitalWrite(In4, HIGH);
        digitalWrite(In3, LOW);
        digitalWrite(In5, LOW);
        digitalWrite(In6, HIGH);
        digitalWrite(In7, LOW);
        digitalWrite(In8, HIGH);
        }
        
    else if(usbRead == 'q'){
        digitalWrite(In2, LOW);
        digitalWrite(In1, HIGH);
        digitalWrite(In4, LOW);
        digitalWrite(In3, HIGH);
        digitalWrite(In5, HIGH);
        digitalWrite(In6, LOW);
        digitalWrite(In7, HIGH);
        digitalWrite(In8, LOW);
        }
        
    else if(usbRead == ' '){
        digitalWrite(In2, LOW);
        digitalWrite(In1, LOW);
        digitalWrite(In4, LOW);
        digitalWrite(In3, LOW);
        digitalWrite(In5, LOW);
        digitalWrite(In6, LOW);
        digitalWrite(In7, LOW);
        digitalWrite(In8, LOW);
        }       
  }
}
