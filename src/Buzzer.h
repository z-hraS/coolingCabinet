#ifndef MY_BUZZER_H
#define MY_BUZZER_H

#include <Arduino.h>

/**
 * @brief Controls a buzzer.
 */
class Buzzer
{
  private:
    const uint8_t m_pin;
  public:
     /**
     * @brief Creates a Buzzer object.
     *
     * @param pin Pin connected to the buzzer.
     */
    Buzzer(uint8_t pin);
    /**
     * @brief Initializes the buzzer hardware.
     */
    void initialize();
    /**
     * @brief Starts the buzzer that emits the 100 Hz sound.
     */
    void start();
    /**
     * @brief Stops the buzzer.
     */
    void stop();
};

#endif
