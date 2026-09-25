#ifndef MY_TEMP_H
#define MY_TEMP_H

#include <Arduino.h>

/**
 * @brief Processes the current temperature sensor reading.
 */
class TemperatureSensor
{
  private:
    const uint8_t m_pin;
    uint16_t m_sensorValue;
    float m_voltage;
    float m_temperature;
    static constexpr float ADC_MAX_VALUE = 1023.0F;
    static constexpr float ADC_REFERENCE_VOLTAGE = 5.0F;
    static constexpr float NOMINAL_OUTPUT_VOLTAGE = 0.5F;
  public:
    /**
     * @brief Creates a TemperatureSensor object.
     *
     * @param pin Pin connected to the temperature sensor.
     */
    TemperatureSensor(uint8_t pin);
    /**
      * @brief Initializes the temperature sensor hardware.
      */
    void initialize();
    /**
     * @brief Reads the sensor's analog output and converts it to temperature.
     */
    void temperatureReading();
    /**
     * @brief Returns the current temperature.
     *
     * @return The current temperature in degrees Celsius.
     */
    float getTemperature() const;
};

#endif