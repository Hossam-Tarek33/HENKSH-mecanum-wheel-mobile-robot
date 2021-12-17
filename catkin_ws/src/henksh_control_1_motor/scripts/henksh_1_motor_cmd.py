#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import sys, select, termios, tty

moveBindings = ["w","s","d","a","e","q"," "]

def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


if __name__=="__main__":
    rospy.loginfo("Hopa ya henksh!!")
    settings = termios.tcgetattr(sys.stdin)

    pub = rospy.Publisher('cmd_motor1', String, queue_size = 1)
    rospy.init_node('henksh_1_motor_pub')

    while not rospy.is_shutdown():
        key = getKey()
        if key in moveBindings:
            move_actiom = String()
            move_actiom.data= key
            rospy.loginfo(key)
            pub.publish(move_actiom)

