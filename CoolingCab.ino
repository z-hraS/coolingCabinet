#include "Led.h"
#include "PushButton.h"
#include "Buzzer.h"
#include "TemperatureSensor.h"
#include "Motor.h"
#include "Display.h"
#include "Alarm.h"
#include "Controller.h"
#include "ModbusInterface.h"

constexpr uint8_t LED_PIN = 7U;
constexpr uint8_t TEMPERATURE_PIN = A1;
constexpr uint8_t BUZZER_PIN = 8U;
constexpr uint8_t MOTOR_ON_OFF_PIN = 6U;
constexpr uint8_t MOTOR_PWM_PIN = 9U;
constexpr uint8_t MOTOR_SPEED_PIN = A0;
constexpr uint8_t ACK_PIN = 10U;

Controller controller(LED_PIN, TEMPERATURE_PIN, BUZZER_PIN, MOTOR_ON_OFF_PIN, MOTOR_PWM_PIN, MOTOR_SPEED_PIN, ACK_PIN);

ModbusInterface modbus(controller);

void setup() {
  controller.initialize();
  modbus.initialize();
}

void loop() {
  modbus.poll();
  modbus.processCommands();
  controller.update();
  modbus.updateRegisters();
}