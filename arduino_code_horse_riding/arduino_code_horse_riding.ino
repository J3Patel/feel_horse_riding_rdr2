float incomingByte = 0; // for incoming serial data
float maxspeed = 1000; 
float minDelay = 100;
float maxDelay = 1200;
float calDelay = 0;
bool up = true;
long lastRecordTime = millis();
void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();
    moveHorseWithSpeed(incomingByte);
  }
}

void moveHorseWithSpeed(int speed) {
       if (speed <= 0) {
        return;
       }
         float speedPerc = (speed / maxspeed) * 100;
        calDelay = maxDelay - ((maxDelay - minDelay) * (speedPerc / 100.0));
        if (calDelay < minDelay) {
          calDelay = minDelay;
        }
        long elapseTime = millis() - lastRecordTime;
        if (elapseTime > calDelay) {
            if (up) {
             digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)  
             digitalWrite(8, HIGH);
             digitalWrite(9, LOW);
             digitalWrite(10, LOW);
              up = false;
            } else {
             digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
             digitalWrite(8, LOW);
             digitalWrite(9, HIGH);
             digitalWrite(10, HIGH);
             up = true;
            }
            lastRecordTime = millis();
       }
}
