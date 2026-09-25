#ifndef MY_DISPLAY_H
#define MY_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

/**
 * @brief Controls the messages displayed on LCD.
 */
class Display
{
  private:
    enum class Screen
    {
      Normal,
      Alarm,
      AlarmACK
    };
    LiquidCrystal m_lcd;
    Screen m_currentScreen;
    float m_previousTemp;

  public:
    /**
     * @brief Creates a Display object.
     */
    Display();
    /**
     * @brief Initializes the LCD hardware.
     */
    void initialize();
    /**
     * @brief Sets the alarm screen.
     */
    void alarm();
    /**
     * @brief Sets the alarm acknowledged screen.
     */
    void alarmACK();
    /**
     * @brief Sets the normal operating screen with the current temperature.
     *
     * @param temp Current temperature.
     */
    void normalState(float temp);
};

#endif