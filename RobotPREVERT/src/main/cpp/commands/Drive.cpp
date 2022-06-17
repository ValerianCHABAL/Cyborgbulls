// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Drive.h"
#include "lib/Utils.h"
#include <iostream>

Drive::Drive(std::function<double()> forward, std::function<double()> turn, Drivetrain *pdrivetrain)
    : m_Forward(forward), m_Turn(turn), m_pDrivetrain(pdrivetrain)
{
  AddRequirements(m_pDrivetrain);
}

void Drive::Initialize()
{
}

void Drive::Execute()
{
  double forward = utils::Deadband(m_Forward());
  double turn = utils::Deadband(m_Turn());
  forward *= 0.5;
  turn *= 0.5;

  m_pDrivetrain->Drive(forward, turn);
}

void Drive::End(bool interrupted) {}

bool Drive::IsFinished()
{
  return false;
}