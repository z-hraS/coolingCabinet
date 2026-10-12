#include "Led.h"

Led::Led(uint8_t pin)
    : m_pin(pin)
{
}

void Led::initialize()
{
    pinMode(m_pin, OUTPUT);
    setState(m_state);
}

void Led::setState(bool state)
{
    m_state = state;
    digitalWrite(m_pin, m_state ? HIGH : LOW);
}

void Led::on()
{
    setState(true);
}

void Led::off()
{
    setState(false);
}

bool Led::isOn() const
{
    return m_state;
}
