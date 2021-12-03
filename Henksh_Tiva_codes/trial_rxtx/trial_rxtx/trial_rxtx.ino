const int led =13;
int usbRead=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    usbRead = Serial.read();
    //Serial.println(usbRead);
    if(usbRead == 1){
    digitalWrite(led, HIGH);
    //delay(5000);
    //digitalWrite(led,LOW);
    }
  }
}

/*void blink(){
  for(int x= 0; x<3; x++){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
  }
}*/
