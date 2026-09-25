#include "Alarm.h"

Alarm::Alarm(uint8_t ledPin, uint8_t buzzerPin)
  : m_led(ledPin),
  m_buzzer(buzzerPin),
  m_isOn(false)
{
}

void Alarm::initialize()
{
  m_led.initialize();
  m_buzzer.initialize();
}

void Alarm::on()
{
  m_isOn = true;
  m_led.on();
  m_buzzer.start();
}

void Alarm::off()
{
  m_isOn = false;
  m_led.off();
  m_buzzer.stop();
}

bool Alarm::alarmActive() const
{
  return m_isOn;
}
