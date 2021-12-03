#!/usr/bin/env python

from serial import Serial
import sys, select, termios, tty

usbCom = Serial('/dev/ttyTHS1',9600)

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
		print('you have entered ', key)
		while (key == '1'):	
			usbCom.write(1)
			break
