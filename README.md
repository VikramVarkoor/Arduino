Card Reader :

This project implements an RFID-based access control system using an Arduino. When an RFID card is scanned:
	•	Green LED blinks and the buzzer remains silent if the card is authorized.
	•	Red LED blinks and the buzzer sounds if the card is unauthorized.

 Components Used
	•	Arduino Uno
	•	RFID Module (MFRC522)
	•	LEDs (Red & Green)
	•	Buzzer
	•	RFID Cards & Key Tags
	•	Resistors & Jumper Wires

 How It Works
	1.	The RFID scanner detects a card.
	2.	If the card ID matches an authorized list, the green LED blinks.
	3.	If the card ID is not recognized, the red LED blinks and the buzzer sounds.
	4.	The system can be expanded for multiple users & logging access attempts.

Watch the demo here: https://www.dropbox.com/scl/fi/om6olsuig0jtwnd22pawi/Arduino_Card_reader.mp4?rlkey=8foh4rz1p7c2j8ta8s4yx5byt&st=lfyvscyu&raw=1
