#/*temp*/ bcM
import RPi_GPIO as g
import Adafruit_DHT

g.setmode(g.BCM)

while True:
    humidity,temperature=Adafruit_DHT.read_retry(Adafruit_DHT.DHT11,3)
    print("hello")
    print(humidity,temperature)
g.cleanup()

/#camera/
From Picamera import Picamera
From time import Sleep

Camera.start_preview()
for i in range(2)
sleep(2)
camera.capture('Path.jpg'%i)
camera.stop_preview()

#led
import RPi_GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(5,GPIO.OUT)

while True:
    GPIO.output(5,True)
    time.sleep(2)
    GPIO.output(5,False)
    time.sleep(2)
    
GPIO.cleanup()

#ir var==0

import RPi_GPIO as GPIO

GPIO.setmode(GPIO.BOARD)

GPIO.setwarnings(False)
GPIO.setup(5,GPIO.IN)
GPIO.setup(3,GPIO.OUT)

while True:
    var=GPIO.input(5)
    print(var)
    if var==0:
        GPIO.output(3,True)
        print('object is not detected')
        
    else:
        GPIO.output(3,False)
        print('object is detected')
        
GPIO.cleanup()

#water var==1
import RPi_GPIO as GPIO

GPIO.setmode(GPIO.BOARD)

GPIO.setup(5,GPIO.IN)
GPIO.setup(3,GPIO.OUT)

while True:
    var=GPIO.input(5)
    print(var)
    if var==1:
        GPIO.output(3,True)
        print('Water is detected')
        
    else:
        GPIO.output(3,False)
        print('Water is not detected')
        
GPIO.cleanup()