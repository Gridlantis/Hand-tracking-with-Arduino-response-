// ARDUINO CODE FOR HAND TRACKING CONTROL
const int redPin = 9;     // Red LED pin
const int greenPin = 10;  // Green LED pin (optional)
const int bluePin = 11;   // Blue LED pin (optional)

void setup() {
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    
    // Turn all LEDs off initially
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    
    Serial.println("Arduino Ready - Hand Tracking Control");
    Serial.println("Commands: LED_RED, LED_GREEN, LED_BLUE, LED_OFF");
    Serial.println("Waiting for hand detection...");
}

void loop() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        
        if (command == "LED_RED") {
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            Serial.println("LED: RED (Hand Closed - Fist Detected)");
        }
        else if (command == "LED_GREEN") {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, LOW);
            Serial.println("LED: GREEN");
        }
        else if (command == "LED_BLUE") {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, HIGH);
            Serial.println("LED: BLUE");
        }
        else if (command == "LED_OFF") {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            Serial.println("LED: OFF (Hand Open)");
        }
        else if (command == "HANDSHAKE") {
            Serial.println("HANDSHAKE_OK");
        }
    }
    
    // Optional: Add a heartbeat blink when connected
    static unsigned long lastBlink = 0;
    if (millis() - lastBlink > 5000) { // Every 5 seconds
        Serial.println("ALIVE");
        lastBlink = millis();
    }
}
