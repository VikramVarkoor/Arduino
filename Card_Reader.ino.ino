#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h> 

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
byte accessUID[4] = {0xBB, 0xA0, 0xC3, 0x1B};
int greenPin = 7;
int redPin = 2;
int buzzerPin = 4;
int servoPin = 5; // Servo control pin
Servo Servo1; // Create servo object

void setup() {
    pinMode(greenPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);        // Initialize serial communications with the PC
    while (!Serial);            // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();                // Init SPI bus
    mfrc522.PCD_Init();        // Init MFRC522
    delay(4);                    // Optional delay. Some board do need more time after init to be ready, see Readme
    mfrc522.PCD_DumpVersionToSerial();    // Show details of PCD - MFRC522 Card Reader details
    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
    Servo1.attach(servoPin); // Attach the servo to the pin
    Servo1.write(0); // Initialize servo to 0 degrees
}

void loop() {
    // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Check if the scanned card matches the access UID
    if (mfrc522.uid.uidByte[0] == accessUID[0] && mfrc522.uid.uidByte[1] == accessUID[1] && 
        mfrc522.uid.uidByte[2] == accessUID[2] && mfrc522.uid.uidByte[3] == accessUID[3]) {
        Serial.println("Access Granted!");
        digitalWrite(greenPin, HIGH);
        Servo1.write(90); // Move servo to 90 degrees for granted access
        delay(2000);
        digitalWrite(greenPin, LOW);
        Servo1.write(0); // Reset servo to 0 degrees
    } else {
        Serial.println("Access Denied.");
        digitalWrite(redPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
      
        delay(1000);
        digitalWrite(redPin, LOW);
        digitalWrite(buzzerPin, LOW);
        
    }
    
    mfrc522.PICC_HaltA();
}
