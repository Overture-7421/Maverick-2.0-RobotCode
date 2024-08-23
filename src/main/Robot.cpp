// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/MathUtil.h>

void Robot::RobotInit() {
  #ifndef __FRC_ROBORIO__
	simMotorManager.Init({
	  {2, "Offseason 2024/motors/back_right_drive"},
	  {4, "Offseason 2024/motors/back_left_drive"},
	  {6, "Offseason 2024/motors/front_left_drive"},
	  {8, "Offseason 2024/motors/front_right_drive"},

	  {1, "Offseason 2024/motors/back_right_rotation"},
	  {3, "Offseason 2024/motors/back_left_rotation"},
	  {5, "Offseason 2024/motors/front_left_rotation"},
	  {7, "Offseason 2024/motors/front_right_rotation"},

    {11, "Offseason 2024/motors/lower_arm"},
    {12, "Offseason 2024/motors/upper_arm"}


		});

	simPigeonManager.Init("Offseason 2024/imu");

	simCANCoderManager.Init({
	  {9, "Offseason 2024/cancoders/back_right_cancoder"},
	  {10, "Offseason 2024/cancoders/back_left_cancoder"},
	  {11, "Offseason 2024/cancoders/front_left_cancoder"},
	  {12, "Offseason 2024/cancoders/front_right_cancoder"},

	  {29, "Offseason 2024/cancoders/upper_cancoder"},
	  {28, "Offseason 2024/cancoders/lower_cancoder"}


		});

	simDutyCycleEncoderManager.Init({});
#endif
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

  frc::ChassisSpeeds speeds{
    joystickForwardBack.GetRawAxis(1) * chassis.getMaxModuleSpeed(),  // Forward/backward
    joystickLeftRight.GetRawAxis(0) * chassis.getMaxModuleSpeed(),  // Left/right
    joystickRotation.GetRawAxis(2) * 7_rad_per_s // Rotation
  };

  
  chassis.Drive(speeds);
  
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
