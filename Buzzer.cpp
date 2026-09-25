#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin)
   : m_pin(pin)
{
}

void Buzzer::initialize()
{
    pinMode(m_pin, OUTPUT);
    tone(m_pin, 100, 1000);
}

void Buzzer::start()
{
   tone(m_pin, 100);
}

void Buzzer::stop()
{
   noTone(m_pin);
}