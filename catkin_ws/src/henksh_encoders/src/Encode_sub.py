#!/usr/bin/env python
import rospy
from std_msgs.msg import Float32

def callback(data):
    rospy.loginfo("Encoder1= %0.3f", data.data)
def callback2(data):
    rospy.loginfo("Encoder2= %0.3f", data.data)
def callback3(data):
    rospy.loginfo("Encoder3= %0.3f", data.data)
def callback4(data):
    rospy.loginfo("Encoder4= %0.3f", data.data)
    
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('Encoders_Subscriber', anonymous=True)

    rospy.Subscriber("ang_vel", Float32, callback)
    rospy.Subscriber("ang_vel2", Float32, callback2)
    rospy.Subscriber("ang_vel3", Float32, callback3)
    rospy.Subscriber("ang_vel4", Float32, callback4)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
