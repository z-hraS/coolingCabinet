#ifndef MY_MOTOR_H
#define MY_MOTOR_H

#include <Arduino.h>
#include "PushButton.h"

/**
 * @brief Controls a DC motor using a push button and PWM output.
 */
class Motor
{
  private:
    const uint8_t m_motorPin;
    const uint8_t m_speedPin;
    PushButton m_onOffPB;
    bool m_motorEnabled;
    bool m_previousState;
    uint16_t m_motorSpeed;
  public:
    /**
     * @brief Creates a Motor object.
     *
     * @param onOffPin Pin connected to the motor ON/OFF button.
     * @param motorPin PWM output pin connected to the motor.
     * @param speedPin Analog input pin connected to the speed potentiometer.
     */
    Motor(uint8_t onOffPin, uint8_t motorPin, uint8_t speedPin);
    /**
     * @brief Initializes the motor hardware.
      */
    void initialize();
    /**
     * @brief Returns the current motor speed.
     *
     * @return PWM value between 0 and 255.
     */
    uint16_t getMotorSpeed() const;
    /**
     * @brief Returns whether the motor is enabled.
     *
     * @return True if the motor is enabled, otherwise false.
     */
    bool getEnable() const;
    /**
     * @brief Enables the motor.
     *
     * @param state Motor state recieved from SCADA HMI.
     */
    void setEnable(bool state);
    /**
     * @brief Sets motor speed.
     *
     * @param speed PWM value between 0 and 255 recieved from SCADA HMI.
     */
    void setMotorSpeed(uint16_t speed);
    /**
     * @brief Reads the speed potentiometer (0-1023) and scales its value to the PWM range (0-255).
     */
    void updateSpeed();
    /**
     * @brief Reads the pushbutton state and toggles the motor enable state on each press. 
     */
    void readEnable();
    /**
     * @brief Runs the motor at the specified speed if it is enabled
     *
     * @param speed PWM value between 0 and 255.
     */
    void motorRun(uint16_t speed);
    /**
     * @brief Runs the motor at maximum speed (PWM value 255).
     */
    void runAtFullSpeed();
};

#endif