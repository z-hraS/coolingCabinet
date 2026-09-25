#ifndef MY_LED_H
#define MY_LED_H

#include <Arduino.h>

/**
 * @brief Controls a LED.
 */
class Led
{
  private:
    const uint8_t m_pin;
    bool m_state;
  
  public:
    /**
     * @brief Creates a Led object.
     *
     * @param pin Pin connected to the LED.
     */
    Led(uint8_t pin);
    /**
     * @brief Initializes the pushbutton hardware.
     */
    void initialize();
    /**
     * @brief Sets the LED state.
     *
     * @param state True to turn LED on, otherwise false.
     */
    void setState(bool state);
    /**
     * @brief Turns the LED on.
     */
    void on();
    /**
     * @brief Turns the LED off.
     */
    void off();
    /**
     * @brief Returns the LED state.
     *
     * @return True if the LED is on, otherwise false.
     */
    bool isOn() const;
};

#endif
