#!/usr/bin/env python
PI = 3.1415926535897932384626433832795
R = 40.0
import Jetson.GPIO as GPIO
import wiringpi
import time
import rospy
from std_msgs.msg import Float32

encoderPinA = 16;
encoderPinB = 15;
encoderPos = 0;
Rotation=0;
encoderPinALast = 0; ##LOW
encoderPinANow = 0;  ##LOW
start_time = True

time_rotation = 0.0; 
ang_vel = 0.0;
lin_vel = 0.0;

def millis():
        return time.time()

if __name__=="__main__":
	GPIO.setmode(GPIO.BOARD)
	GPIO.setwarnings(False)
	GPIO.setup(encoderPinA, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	GPIO.setup(encoderPinB, GPIO.IN, pull_up_down=GPIO.PUD_UP)


        while True:
	##Wheel1
		pub = rospy.Publisher('ang_vel', Float32, queue_size=10)
		rospy.init_node('Encoder1', anonymous=True)
		rate = rospy.Rate(10)
		while not rospy.is_shutdown():
			encoderPinANow = GPIO.input(encoderPinA)
  			if ((encoderPinALast == 1.0) and (encoderPinANow == 0.0)):

				if(start_time):
                        	        time_1 =millis()
					start_time = False
                 
				if (GPIO.input(encoderPinB) == 1):
					encoderPos=encoderPos+1

					if(encoderPos%48 == 0):
						encoderPos = 0
						Rotation=Rotation+1
						time_2 = millis() 
						time_rotation = (time_2 - time_1)
		  				start_time = True
						ang_vel = float((2.0*PI)/time_rotation)
		  				lin_vel = ang_vel*R
						pub.publish(ang_vel)
						#rate.sleep()
				else:
					encoderPos=encoderPos-1
					if(abs(encoderPos%48) == 0):
						encoderPos = 0
						Rotation=Rotation+1
						time_2 = millis()
						time_rotation = (time_2 - time_1)
		  				start_time = True
						ang_vel = float((2.0*PI)/time_rotation)
		  				lin_vel = ang_vel*R
						pub.publish(ang_vel)
						#rate.sleep()
			
			encoderPinALast = encoderPinANow
	                ##print("ang_velo : {}".format(ang_vel))
