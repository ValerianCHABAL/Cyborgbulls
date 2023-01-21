// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

void Robot::RobotInit() {}

void Robot::RobotPeriodic()
{
  frc2::CommandScheduler::GetInstance().Run();
}

void Robot::AutonomousInit() {
  m_container.m_drivetrain.Drive(0.3, 0.0);
  double m_count=0;
}

void Robot::AutonomousPeriodic() {
  m_count++;
  std::cout << "count: " << m_count << std::endl;
  if (m_count > 100) {
    m_container.m_drivetrain.Drive(0.3, 0.0);
  }
}


void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
