#include "Display.h"

Display::Display()
  : m_lcd(12, 11, 5, 4, 3, 2),
  m_currentScreen(Screen::Normal),
  m_previousTemp(-999.0F)
{
}

void Display::initialize()
{
  m_lcd.begin(16, 2);
  m_lcd.clear();
  m_lcd.setCursor(0, 0);
  m_lcd.print("Temperature:");
}

void Display::alarm()
{
  if(m_currentScreen != Screen::Alarm)
  {
    m_lcd.clear();
    m_lcd.setCursor(5, 0);
    m_lcd.print("ALARM");
    m_currentScreen = Screen::Alarm;
  }
}

void Display::alarmACK()
{
  if(m_currentScreen != Screen::AlarmACK)
  {
    m_lcd.clear();
    m_lcd.setCursor(5, 0);
    m_lcd.print("ALARM");
    m_lcd.setCursor(6, 1);
    m_lcd.print("ACK");
    m_currentScreen = Screen::AlarmACK;
  }      
}

void Display::normalState(float temp)
{
  if(m_currentScreen != Screen::Normal)
  {
    m_lcd.clear();
    m_lcd.setCursor(0, 0);
    m_lcd.print("Temperature:");
    m_currentScreen = Screen::Normal;
  }

  if(temp != m_previousTemp)
  {
    m_lcd.setCursor(0, 1);
    m_lcd.print("                ");
    m_lcd.setCursor(0,1);
    m_lcd.print(temp);
    m_previousTemp = temp;
  }
}
