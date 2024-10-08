// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Shooter.h"
#include "Constants.h"

Shooter::Shooter(){
    leftMotor.setFollow(25, true);

    rightMotor.setPIDValues(0.1,0,0,0,0.065);
    rightMotor.setSensorToMechanism(ConstantsSh::ShooterGearRatio);
    rightMotor.setRotorToSensorRatio(ConstantsSh::ShooterMotorToSensor);

    rightMotor.setClosedLoopVoltageRamp(0.1);
    rightMotor.setSupplyCurrentLimit(true, 40, 60, 0.25);
}

void Shooter::setVoltage(units::volt_t voltage){
    rightMotor.SetVoltage(voltage);
}

double Shooter::getVelocityVoltage(){
    return rightMotor.GetVelocity().GetValueAsDouble();
}

void Shooter::setObjectiveVelocity(double velocity){
    rightMotor.setVelocityVoltage(velocity, 0, false);
}

frc2::CommandPtr Shooter::setObjectiveVelocityPtr(){
    return this->RunOnce([this] {this->setObjectiveVelocity(ConstantsSh::StopShooterSpeaker);});
}

bool Shooter::getObjectiveVelocity(double velocity){
    double shooterError = velocity - rightMotor.GetVelocity().GetValueAsDouble();

    if(std::abs(shooterError < 5)){
        return true;
    } else {
        return false;
    }
}


// This method will be called once per scheduler run
void Shooter::Periodic() {}
