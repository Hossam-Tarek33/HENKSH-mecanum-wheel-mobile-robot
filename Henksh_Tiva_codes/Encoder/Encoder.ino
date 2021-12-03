
#define PI 3.1415926535897932384626433832795
#define R  40.0

int encoderPinA = 6;
int encoderPinB = 7;
int encoderPos = 0;
int Rotation=0;
int encoderPinALast = LOW;
int encoderPinANow = LOW;
bool start_time = false;

double time_1 , time_2, time_rotation =0.0;
double ang_vel = 0.0;
double lin_vel = 0.0;

void setup() {
  pinMode (encoderPinA, INPUT_PULLUP);
  pinMode (encoderPinB, INPUT_PULLUP);
  Serial.begin (9600);
}

void loop() 
  {
  encoderPinANow = digitalRead(encoderPinA);
  if ((encoderPinALast == HIGH) && (encoderPinANow == LOW)) 
    {
     if (!start_time)
      {
      time_1 = millis();
      start_time = true;
      }
      if (digitalRead(encoderPinB) == HIGH) 
      {
      encoderPos++;
      //////////////////////////
      if(encoderPos%48 ==0)
        {
          encoderPos =0;
          Rotation++;
          time_2= millis(); 
          time_rotation = (time_2 - time_1)/1000.0;
          start_time = false;
          ang_vel = (2.0*PI)/time_rotation;
          lin_vel = ang_vel*R;
        }
      /////////////////////////
      }   
      else 
        {
          encoderPos--;
          //////////////////////////
          if(abs(encoderPos)%48 ==0)
            {
            encoderPos =0;
            Rotation++;
            time_2= millis(); 
            time_rotation = time_2 - time_1;
            start_time = false;
            ang_vel = (2*PI)/time_rotation;
            lin_vel = ang_vel*R;
            }
            /////////////////////////
        }
    //Serial.println(encoderPos);
    //Serial.println(Rotation);
    //Serial.println("Timer");
    //Serial.println(time_1);
    //Serial.println(time_2);
    //Serial.println(String("time rotation: ") + String(time_rotation));
    //Serial.println(time_rotation);
    //Serial.println(String("angular vel: ") + String(ang_vel));
    Serial.println(ang_vel);
    //Serial.println(String("linaer vel: ") + String(lin_vel));
    //Serial.println(ang_vel);
    //Serial.println("/////////////////");
    }
  encoderPinALast = encoderPinANow;
}
