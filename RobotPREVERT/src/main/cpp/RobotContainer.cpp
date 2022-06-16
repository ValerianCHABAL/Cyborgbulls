#include "RobotContainer.h"

RobotContainer::RobotContainer()
{

  ConfigureButtonBindings();

  m_Drivetrain.SetDefaultCommand(Drive(
      [=]
      { return -m_DriverLeftJoystick.GetY(); },
      [=]
      { return m_DriverRightJoystick.GetZ(); },
      &m_Drivetrain));