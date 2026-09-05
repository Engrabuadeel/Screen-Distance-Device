#include <Servo.h>

Servo radarServo;

const int buzzerPin = 6;
const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 10;

const int thresholdDistance = 15; // Alarm distance in cm

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  radarServo.attach(servoPin);
  Serial.begin(9600);
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 15,000 microseconds (15ms) timeout (~2.5m max range)
  // This prevents the Arduino from hanging if facing an open room or ceiling
  long duration = pulseIn(echoPin, HIGH, 15000); 
  
  if (duration == 0) {
    return 0; // Out of range or no echo back
  }
  
  return duration * 0.034 / 2; // Distance in cm
}

void checkAlarm(long distance) {
  // Only trigger if a valid object is detected within threshold
  if (distance > 0 && distance <= thresholdDistance) {
    tone(buzzerPin, 1000); 
  } else {
    noTone(buzzerPin); // Always turn off buzzer if out-of-range or 0
  }
}

void loop() {
  // Sweep left to right
  for (int angle = 15; angle <= 165; angle += 2) {
    radarServo.write(angle);
    delay(30);
    long distance = getDistance();
    
    checkAlarm(distance);
    
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
  
  // Sweep right to left
  for (int angle = 165; angle >= 15; angle -= 2) {
    radarServo.write(angle);
    delay(30);
    long distance = getDistance();
    
    checkAlarm(distance);
    
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
}