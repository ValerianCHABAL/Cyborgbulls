// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>
#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

void Robot::RobotInit() {}

void Robot::RobotPeriodic()
{
  frc2::CommandScheduler::GetInstance().Run();
}

void Robot::AutonomousInit() {
  
  m_container.m_Drivetrain.Drive(0.0, 0.0);
  m_count=0;
  m_timer.Reset();
  m_timer.Start();
}

void Robot::AutonomousPeriodic() {
  
  std::cout << "count: " << m_count << std::endl;
 //while (m_count < 20000) {
   while (m_timer.Get() < 1_s) {
    m_container.m_Drivetrain.Drive(0.3, 0.0);
    m_count++;
 }  
    while (m_timer.Get() > 1_s && m_timer.Get() < 2_s) {
    m_container.m_Drivetrain.Drive(-0.3, 0.0);
    m_count++;
 }  
    m_container.m_Drivetrain.Drive(0.0, 0.0);   
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
