#include "ModbusInterface.h"

ModbusInterface::ModbusInterface(Controller& controller)
:m_modbus(Serial),
m_controller(controller)
{
}

void ModbusInterface::initialize()
{
  m_modbus.configureCoils(m_coils, 4);
  m_modbus.configureHoldingRegisters(m_holdingRegisters, 2);
  Serial.begin(9600);
  m_modbus.begin(1, 9600, SERIAL_8N1);
}

void ModbusInterface::poll()
{
  m_modbus.poll();
}
    
void ModbusInterface::updateRegisters()
{
  // Update Modbus data with the current controller state for SCADA
  m_holdingRegisters[0] = static_cast<uint16_t>(m_controller.getTemperature()*100.0F);
  m_holdingRegisters[1] = m_controller.getMotorSpeed();
  m_coils[0] = m_controller.isMotorEnabled();
  m_coils[1] = m_controller.isAlarmActive();
  m_coils[2] = m_controller.getACK();
  m_coils[3] = m_controller.getMode();
}

void ModbusInterface::processCommands()
{
  // Apply commands received from SCADA to the controller.
  m_controller.setMode(m_coils[3]);
  m_controller.setACK(m_coils[2]);
  m_controller.setMotorEnabled(m_coils[0]);
  m_controller.setMotorSpeed(m_holdingRegisters[1]);
}