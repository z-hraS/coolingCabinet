#include "Controller.h"

Controller::Controller(uint8_t ledPin, uint8_t temperaturePin, uint8_t buzzerPin, uint8_t motorOnOffPin, uint8_t motorPin, uint8_t motorSpeedPin, uint8_t ackPin)
  : m_alarm(ledPin, buzzerPin),
  m_temperature(temperaturePin),
  m_motor(motorOnOffPin, motorPin, motorSpeedPin),
  m_display(),
  m_ackPB(ackPin),
  m_mode(ControlMode::Local),
  m_previousACK(false),
  m_ack(false),
  m_temperatureThreshold(35.0F)
{
}

void Controller::initialize()
{
  m_alarm.initialize();
  m_temperature.initialize();
  m_motor.initialize();
  m_ackPB.initialize();
  m_display.initialize();
}

void Controller::checkACK()
{
  m_ackPB.update();
  bool state = m_ackPB.getState();
  // Toggle acknowledgment only when a new button press is detected.
  if(state != m_previousACK)
  {
    if(state)
    {
      m_ack = !m_ack;
    }
    m_previousACK = state;
  }
}

float Controller::getTemperature() const
{
  return m_temperature.getTemperature();
}

uint16_t Controller::getMotorSpeed() const
{
  return m_motor.getMotorSpeed();
}

bool Controller::isMotorEnabled() const
{
  return m_motor.getEnable();
}

bool Controller::isAlarmActive() const
{
  return m_alarm.alarmActive();
}

bool Controller::getACK() const
{
  return m_ack;
}

bool Controller::getMode() const
{
  if(m_mode == ControlMode::Local) return false;
  else return true;
}

void Controller::setMotorEnabled(bool motorEnabled) 
{
  m_motor.setEnable(motorEnabled);
}

void Controller::setMotorSpeed(uint16_t motorSpeed)
{
  m_motor.setMotorSpeed(motorSpeed);
}


void Controller::setACK(bool ack)
{
  m_ack = ack;
}

void Controller::setMode(bool remote)
{
  m_mode = remote ? ControlMode::Remote : ControlMode::Local;
}

void Controller::update()
{
  m_temperature.temperatureReading();

  // Process local controls only when the cabinet is in local mode.
  if(m_mode == ControlMode::Local)
  {
    checkACK();
    m_motor.readEnable();
    m_motor.updateSpeed();
  }

  // Enter alarm state when the temperature exceeds the threshold.
  if(m_temperature.getTemperature() > m_temperatureThreshold)
  {
    m_motor.runAtFullSpeed();
    if(!m_ack)
    {
      m_alarm.on();
      m_display.alarm();
    }
    else
    {
      m_alarm.off();
      m_display.normalState(m_temperature.getTemperature());
    }
  }
  else
  {
    m_alarm.off();
    m_display.normalState(m_temperature.getTemperature());
    m_motor.motorRun(getMotorSpeed());
    m_ack = false;
  }
}