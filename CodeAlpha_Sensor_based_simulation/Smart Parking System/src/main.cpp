#include <Arduino.h>
#include <ESP32Servo.h>

// -------------------- Pin Definitions --------------------

#define ENTRY_TRIG 25
#define ENTRY_ECHO 34

#define SLOT_TRIG 5
#define SLOT_ECHO 18

#define GREEN_LED 26
#define RED_LED 27

#define SERVO_PIN 23

Servo gateServo;

// ----------------------------------------------------------

float getDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.0343 / 2;

  return distance;
}

void setup()
{
  Serial.begin(115200);

  pinMode(ENTRY_TRIG, OUTPUT);
  pinMode(ENTRY_ECHO, INPUT);

  pinMode(SLOT_TRIG, OUTPUT);
  pinMode(SLOT_ECHO, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  gateServo.attach(SERVO_PIN);

  gateServo.write(0);

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  Serial.println("Smart Parking System Started");
}

void loop()
{
  float entryDistance = getDistance(ENTRY_TRIG, ENTRY_ECHO);
  float slotDistance = getDistance(SLOT_TRIG, SLOT_ECHO);

  Serial.print("Entry: ");
  Serial.print(entryDistance);
  Serial.print(" cm");

  Serial.print(" | Slot: ");
  Serial.print(slotDistance);
  Serial.println(" cm");

  // ---------------- Gate Control ----------------

  if (entryDistance < 10)
  {
    Serial.println("Vehicle Detected");
    Serial.println("Opening Gate");

    gateServo.write(90);

    delay(3000);

    gateServo.write(0);

    Serial.println("Gate Closed");
  }

  // ---------------- Parking Status ----------------

  if (slotDistance < 15)
  {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    Serial.println("Parking Occupied");
  }
  else
  {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    Serial.println("Parking Available");
  }

  delay(500);
}