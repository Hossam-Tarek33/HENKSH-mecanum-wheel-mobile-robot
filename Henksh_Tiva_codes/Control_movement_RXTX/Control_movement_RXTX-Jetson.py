#!/usr/bin/env python

from serial import Serial
import sys, select, termios, tty

usbCom = Serial('/dev/ttyTHS1',115200)
##usbCom.open()
def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

if __name__=="__main__":
	settings = termios.tcgetattr(sys.stdin)
	while True:
		key = getKey()
		##print('you have entered ', key)
		while(key == 'w'):
		    usbCom.write(key)
		    print('Forward')
		    break
		while(key == 's'):
		    usbCom.write(key)
		    print('Backward')
		    break
		while(key == 'a'):
		    usbCom.write(key)
		    print('Left')
		    break
		while(key == 'd'):
		    usbCom.write(key)
		    print('Right')
		    break
		while(key == 'q'):
		    usbCom.write(key)
		    print('Rotate-Left')
		    break
		while(key == 'e'):
		    usbCom.write(key)
		    print('Rotate-Right')
		    break
		while(key == ' '):
		    usbCom.write(key)
		    print('STOP')
		    break
