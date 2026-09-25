#ifndef MY_CONTROLLER_H
#define MY_CONTROLLER_H

#include <Arduino.h>
#include "Led.h"
#include "PushButton.h"
#include "Buzzer.h"
#include "TemperatureSensor.h"
#include "Motor.h"
#include "Display.h"
#include "Alarm.h"

/**
 * @brief Coordinates the main control logic of the cooling cabinet.
 *
 * Manages temperature monitoring, motor control, alarm handling,
 * display output and local or remote control modes.
 */
class Controller
{
  private:
    enum class ControlMode
    {
      Local,
      Remote
    };
    Alarm m_alarm;
    TemperatureSensor m_temperature;
    Motor m_motor;
    Display m_display;
    PushButton m_ackPB;
    ControlMode m_mode;
    bool m_previousACK;
    bool m_ack;
    float m_temperatureThreshold;
  public:
    /**
     * @brief Creates a Controller object.
     *
     * @param ledPin Pin connected to the LED.
     * @param temperaturePin Analog pin connected to the temperature sensor.
     * @param buzzerPin Pin connected to the buzzer.
     * @param motorOnOffPin Pin connected to the motor ON/OFF button.
     * @param motorPin PWM output pin connected to the motor.
     * @param motorSpeedPin Analog input pin connected to the speed potentiometer.
     * @param ackPin Pin connected to pushbutton used to acknowledge the alarm.
     */
    Controller(uint8_t ledPin, uint8_t temperaturePin, uint8_t buzzerPin, uint8_t motorOnOffPin, uint8_t motorPin, uint8_t motorSpeedPin, uint8_t ackPin);
    /**
      * @brief Initializes all hardware components controlled by the controller.
      */
    void initialize();
    /**
     * @brief Updates the alarm acknowledged state based on the ACK pushbutton state.
     */
    void checkACK();
    /**
     * @brief Returns the current temperature measured by the sensor.
     *
     * The sensor's ADC reading is converted from the 10-bit ADC range
     * (0–1023) to voltage (0–5 V) and then converted to temperature
     * according to the sensor's characteristics.
     *
     * @return The measured temperature in degrees Celsius.
     */
    float getTemperature() const;
    /**
     * @brief Returns the current motor speed.
     *
     * @return The PWM value between 0 and 255.
     */
    uint16_t getMotorSpeed() const;
    /**
     * @brief Returns the motor state.
     *
     * @return True if motor is enabled, False otherwise.
     */
    bool isMotorEnabled() const;
    /**
     * @brief Returns the alarm state.
     *
     * @return True if alarm is active, False otherwise.
     */
    bool isAlarmActive() const;
    /**
     * @brief Returns the alarm acknowledged state.
     *
     * @return True if alarm is acknowledged, False otherwise.
     */
    bool getACK() const;
    /**
     * @brief Returns the control mode of cooling cabinet.
     *
     * @return True if mode is remote, False otherwise.
     */
    bool getMode() const;
    /**
     * @brief Sets the motor enable state.
     *
     * Used by the Modbus interface to apply a motor command received from SCADA.
     *
     * @param state Motor state received from the SCADA HMI.
     */
    void setMotorEnabled(bool motorEnable);
    /**
     * @brief Sets the motor speed.
     *
     * Used by the Modbus interface to apply a motor command received from SCADA.
     *
     * @param motorSpeed PWM value between 0 and 255 received from the SCADA HMI.
     */
    void setMotorSpeed(uint16_t motorSpeed);
    /**
     * @brief Sets the alarm acknowledgment state.
     *
     * Used by the Modbus interface to apply an alarm acknowledgment command received from SCADA.
     *
     * @param ack True if the alarm is acknowledged, otherwise false.
     */
    void setACK(bool ack);
    /**
     * @brief Sets the control mode.
     * 
     * @param remote True if the control mode is set to remote, otherwise false.
     */
    void setMode(bool remote);
    /**
     *  @brief Executes one control cycle of the cooling cabinet.
     *
     * Updates sensor readings, processes local or remote commands,
     * evaluates alarm conditions, controls the motor, and updates
     * the display and alarm outputs.
     */
    void update();
};

#endif