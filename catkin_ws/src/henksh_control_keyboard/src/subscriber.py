#!/usr/bin/env python
from serial import Serial
import rospy
from std_msgs.msg import String
usbCom = Serial('/dev/ttyTHS1',115200)
def callback(data):
    ##rospy.loginfo(data.data)
    if (data.data =='w'):
        usbCom.write('w')
	rospy.loginfo('Forward')
    elif (data.data =='s'):
        usbCom.write('s')
	rospy.loginfo('Backward')
    elif (data.data =='a'):
        usbCom.write('a')
	rospy.loginfo('Right')
    elif (data.data =='d'):
        usbCom.write('d')
	rospy.loginfo('Left')
    elif (data.data =='q'):
        usbCom.write('q')
	rospy.loginfo('Rotate-Left')
    elif (data.data =='e'):
        usbCom.write('e')
	rospy.loginfo('Rotate-Right')
    elif (data.data ==' '):
        usbCom.write(' ')
	rospy.loginfo('STOP')
    else:
        rospy.loginfo('Invalid Control Key !!')
    
def listener():

    rospy.init_node('Key_Sub_Node', anonymous=True)

    rospy.Subscriber('Key_Control_Topic', String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    while not rospy.is_shutdown():
	listener()
