// Basic Arduino sketch for ESP32 + A4988
#include <AccelStepper.h>

#define DIR_PIN 4
#define STEP_PIN 2
#define MOTOR_INTERFACE_TYPE 1

AccelStepper stepper(MOTOR_INTERFACE_TYPE, STEP_PIN, DIR_PIN);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  stepper.moveTo(200);
}

void loop() {
  if (stepper.distanceToGo() == 0)
    stepper.moveTo(-stepper.currentPosition());
  stepper.run();
}
