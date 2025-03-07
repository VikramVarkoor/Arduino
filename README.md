# RFID Card Reader – Access Control System

This project implements an **RFID-based access control system** using an Arduino. When an **RFID card** is scanned:  
- **Green LED blinks**, the buzzer remains **silent**, and the **servo gate rotates 90 degrees** if the card is **authorized**.  
- **Red LED blinks**, the **buzzer sounds**, and the **servo remains still** if the card is **unauthorized**.  

---

## Components Used
- **Arduino Uno**
- **RFID Module (MFRC522)**
- **Servo Motor**
- **LEDs (Red & Green)**
- **Buzzer**
- **RFID Cards & Key Tags**
- **Resistors & Jumper Wires**

---

## How It Works
1. The RFID **scanner detects a card**.
2. If the **card ID matches** an authorized list, the **green LED blinks**, and the **servo rotates 90 degrees** to open the gate.
3. If the **card ID is not recognized**, the **red LED blinks**, the **buzzer sounds**, and the **servo remains in its original position**.
   
---

## Demo Video
- **Watch the demo**: [Arduino Card Reader](https://www.dropbox.com/scl/fi/om6olsuig0jtwnd22pawi/Arduino_Card_reader.mp4?rlkey=8foh4rz1p7c2j8ta8s4yx5byt&st=lfyvscyu&raw=1)
- **Watch the demo (with a Servo Motor)**: [Arduino Card Reader with LED, Buzzer, and Servo Motor](https://www.dropbox.com/scl/fi/54g4hv33gukrrjkybgzmc/Arduino_CardReader_with_LED_Buzzer_Sevro_motor.mp4?rlkey=s2l7opba16mn0t2p5arhay9jh&st=fqzd81ih&raw=1)
---



