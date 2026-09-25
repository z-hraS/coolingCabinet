#include "PushButton.h"

PushButton::PushButton(uint8_t pin)
    : m_pin(pin),
    m_previousState(false),
    m_state(false)
{
}

void PushButton::initialize()
{
    pinMode(m_pin, INPUT);
    update();
}

void PushButton::update()
{
    bool newState = digitalRead(m_pin);
    
    // Start a new debounce period when a state change is detected.
    if(newState != m_previousState)
    {
        m_lastDebounceTime = millis();
    }
    if(millis() - m_lastDebounceTime > m_debounceDelay)
    {
      m_state = newState;
    }
    m_previousState = newState;
}

bool PushButton::getState() const
{
   return m_state;
}