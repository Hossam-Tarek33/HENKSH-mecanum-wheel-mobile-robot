#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
import sys, select, termios, tty

def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def talker():
    pub = rospy.Publisher('Key_Control_Topic', String, queue_size=10)
    rospy.init_node('Key_Pub_Node', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        key_str = getKey()
        rospy.loginfo(key_str)
        pub.publish(key_str)
        rate.sleep()

if __name__ == '__main__':
    settings = termios.tcgetattr(sys.stdin)
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
