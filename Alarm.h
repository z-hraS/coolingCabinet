#ifndef MY_ALARM_H
#define MY_ALARM_H

#include <Arduino.h>
#include "Led.h"
#include "Buzzer.h"

/**
 * @brief Controls the LED and buzzer based on the current temperature
 *        and whether the alarm has been acknowledged.
 */
class Alarm
{
  private:
    Led m_led;
    Buzzer m_buzzer;
    bool m_isOn;
  public:
    /**
     * @brief Creates an Alarm object.
     *
     * @param ledPin Pin connected to the LED.
     * @param buzzerPin Pin connected to the buzzer.
     */
    Alarm(uint8_t ledPin, uint8_t buzzerPin);
    /**
      * @brief Initializes the alarm hardware.
      */
    void initialize();
    /**
      * @brief Activates the alarm by turning on the LED and buzzer.
      */
    void on();
    /**
      * @brief Deactivates the alarm by turning off the LED and buzzer.
      */
    void off();
    /**
      * @brief Returns the alarm state.
      * 
      * @return True if alarm is active, otherwise False.
      */
    bool alarmActive() const;
};

#endif