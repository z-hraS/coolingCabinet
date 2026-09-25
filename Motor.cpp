#include "Motor.h"

Motor::Motor(uint8_t onOffPin, uint8_t motorPin, uint8_t speedPin)
  : m_onOffPB(onOffPin),
  m_motorPin(motorPin),
  m_speedPin(speedPin),
  m_motorEnabled(false),
  m_previousState(false),
  m_motorSpeed(0)
{
}

void Motor::initialize()
{
    m_onOffPB.initialize();
    pinMode(m_motorPin, OUTPUT);
    pinMode(m_speedPin, INPUT);
}

uint16_t Motor::getMotorSpeed() const
{
  return m_motorSpeed;
}

bool Motor::getEnable() const
{
  return m_motorEnabled;
}

void Motor::setEnable(bool state)
{
  m_motorEnabled = state;
}

void Motor::setMotorSpeed(uint16_t motorSpeed)
{
  m_motorSpeed = motorSpeed;
}

void Motor::updateSpeed()
{
    // Map the 10-bit ADC reading to the Arduino's 8-bit PWM range.
    m_motorSpeed = analogRead(m_speedPin)/4U;
}

void Motor::readEnable()
{
    m_onOffPB.update();
    bool state = m_onOffPB.getState();
    // Toggle only on a state transition to avoid repeated toggling
    // while the button remains pressed.
    if(state != m_previousState)
    {
      if(state)
      {
        m_motorEnabled = !m_motorEnabled;
      }
      m_previousState = state;
    }
}

void Motor::motorRun(uint16_t speed)
{
    if(m_motorEnabled)
    {
      analogWrite(m_motorPin, speed);
    }
    else
    {
      analogWrite(m_motorPin, 0);
    }
}

void Motor::runAtFullSpeed()
{
    m_motorEnabled = true;
    analogWrite(m_motorPin, 255);
}