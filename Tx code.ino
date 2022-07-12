import serial
import time
import cv2
from cvzone.HandTrackingModule import HandDetector

#arduino = serial.Serial(port='COM5', baudrate= 9600, timeout=0)
cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=2)

while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)
    cv2.imshow("Image", img)


    if len(hands) == 1:
        hand1=hands[0]
        handType1 = hand1["type"]
        if (handType1 == 'Right'):
            #arduino.write(str.encode('2'))
            print(handType1, "Hand 1")

        elif(handType1 == 'Left'):
           # arduino.write(str.encode('1'))
            print(handType1, "Hand 2")
    elif len(hands)==2:
        hand1=hands[0]
        hand2=hands[0]
        handType1 = hand1["type"]
        handType2 = hand2["type"]
       # arduino.write(str.encode('3'))
        print("Both Hands 3")
    else:
       # arduino.write(str.encode('0'))
        print("No hands")


    if cv2.waitKey(20)& 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
