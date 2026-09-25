#ifndef MY_MODBUSINTERFACE_H
#define MY_MODBUSINTERFACE_H

#include <ModbusRTUSlave.h>
#include "Controller.h"

/**
 * @brief Handles Modbus RTU communication between the controller and SCADA.
 */
class ModbusInterface
{
  private:
    Controller& m_controller;
    ModbusRTUSlave m_modbus;
    bool m_coils[4];
    uint16_t m_holdingRegisters[2];
  
  public:
    /**
     * @brief Creates a ModbusInterface object.
     *
     * @param controller Reference to the cooling cabinet controller.
     */
    ModbusInterface(Controller& controller);
    /**
     * @brief Initializes the Modbus RTU communication and data registers.
     */
    void initialize();
    /**
     * @brief Checks for and processes incoming Modbus requests from SCADA.
     */
    void poll();
    /**
     * @brief Updates Modbus data with the current controller state.
     */
    void updateRegisters();
    /**
     * @brief Applies commands received from SCADA to the controller.
     */
    void processCommands();
};

#endif