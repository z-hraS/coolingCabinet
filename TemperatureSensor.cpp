#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(uint8_t pin)
    : m_pin(pin),
    m_sensorValue(0),
    m_voltage(0.0F),
    m_temperature(0.0F)
{
}

void TemperatureSensor::initialize()
{
    pinMode(m_pin, INPUT);
}

void TemperatureSensor::temperatureReading()
{
    m_sensorValue = analogRead(m_pin);
    m_voltage = (m_sensorValue/ADC_MAX_VALUE) * ADC_REFERENCE_VOLTAGE;
    m_temperature = (m_voltage - NOMINAL_OUTPUT_VOLTAGE) * 100;
}

float TemperatureSensor::getTemperature() const
{
    return m_temperature;
}