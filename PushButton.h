#ifndef MY_PB_H
#define MY_PB_H

#include <Arduino.h>

/**
 * @brief Controls a pushbutton.
 */
class PushButton
{
  private:
    const uint8_t m_pin;
    bool m_state;
    bool m_previousState;
    unsigned long m_lastDebounceTime = 0;
    const uint8_t m_debounceDelay = 50;
  public:
    /**
     * @brief Creates a PushButton object.
     *
     * @param pin Pin connected to the pushbutton.
     */
    PushButton(uint8_t pin);
    /**
     * @brief Initializes the pushbutton hardware.
     */
    void initialize();
    /**
     * @brief Updates the button state using software debouncing.
     */
    void update();
    /**
     * @brief Returns the current button state.
     *
     * @return True if the button is pressed, otherwise false.
     */
    bool getState() const;
};

#endif