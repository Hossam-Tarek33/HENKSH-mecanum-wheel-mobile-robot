#!/usr/bin/env python
PI = 3.1415926535897932384626433832795
R = 40.0
import Jetson.GPIO as GPIO
import wiringpi
import time
import rospy
from std_msgs.msg import Float32

encoderPinA = 31;
encoderPinB = 32;
encoderPos = 0;

Rotation=0;
encoderPinALast = 0; ##LOW
encoderPinANow = 0;  ##LOW

encoderPinBLast = 0; ##LOW
encoderPinBNow = 0;  ##LOW
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
		pub = rospy.Publisher('ang_vel4', Float32, queue_size=10)
		rospy.init_node('Encoder4', anonymous=True)
		rate = rospy.Rate(10)
		while not rospy.is_shutdown():
			encoderPinANow = GPIO.input(encoderPinA)
			encoderPinBNow = GPIO.input(encoderPinB)
	  		if ((encoderPinALast == 1.0) and (encoderPinANow == 0.0)):

				if(start_time):
		                        time_1 =millis()
					start_time = False

				if (GPIO.input(encoderPinB) == 1 and GPIO.input(encoderPinA) == 0):
					encoderPos=encoderPos+1

					if(encoderPos%48 == 0):
						encoderPos = 0
						Rotation=Rotation+1
						time_2 = millis() 
						time_rotation = (time_2 - time_1)
			  			start_time = True
			  			ang_vel = (2.0*PI)/time_rotation
			  			lin_vel = ang_vel*R
						pub.publish(ang_vel)

	  		elif ((encoderPinBLast == 1.0) and (encoderPinBNow == 0.0)):

				if(start_time):
		                        time_1 =millis()
					start_time = False

		         
				if (GPIO.input(encoderPinA) == 1 and GPIO.input(encoderPinB) == 0):
					encoderPos=encoderPos+1

					if(encoderPos%48 == 0):
						encoderPos = 0
						Rotation=Rotation+1
						time_2 = millis() 
						time_rotation = (time_2 - time_1)
			  			start_time = True
			  			ang_vel = (2.0*PI)/time_rotation
			  			lin_vel = ang_vel*R
						pub.publish(ang_vel)


				
					
			encoderPinALast = encoderPinANow
			encoderPinBLast = encoderPinBNow

		        ##print("ang_velo : {}".format(ang_vel))
