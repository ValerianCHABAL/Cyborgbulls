// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc2/command/SubsystemBase.h>

class Drivetrain : public frc2::SubsystemBase
{
public:
  Drivetrain();
  void Drive(float forward, float turn);


private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_MotorRight{CAN_ID_DRIVETRAIN_MOTOR_RIGHT};
  ctre::phoenix::motorcontrol::can::VictorSPX m_MotorRightFollow{CAN_ID_DRIVETRAIN_MOTOR_RIGHT_FOLLOW};
  ctre::phoenix::motorcontrol::can::VictorSPX	m_MotorLeft{CAN_ID_DRIVETRAIN_MOTOR_LEFT};
  ctre::phoenix::motorcontrol::can::VictorSPX	m_MotorLeftFollow{CAN_ID_DRIVETRAIN_MOTOR_LEFT_FOLLOW};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
