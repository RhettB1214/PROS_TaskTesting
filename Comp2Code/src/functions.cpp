//This file houses all the various control functions
#include "main.h"
#include "definitions.hpp"
#include "initializations.hpp"
#include "pros/rtos.h"
#include "variables.hpp"



void leftFlywheelController(int leftFlyRPM, int leftBBTarget)
{
	//PID Controller Activator//
	bool pidActive = false;

	//Flywheel Variables
	int leftFlySpeed = leftFlyRPM/5;
	

	//PID Constants//
	float kP = 0;
	float kI = 0;
	float kD = 0;
		
	//PID Variables//
	int currentVelocity = leftFlyRot.get_velocity()/6;
	int error = leftFlyRPM - currentVelocity;
	int lastError = 0;
	int totalError = 0;
	int integralActiveZone = 15;

	int onTargetCount = 0;
	float finalAdjustment = error * kP;

	//Temp Variable//
	int deltaTime = 0;

	if((leftFlyRot.get_velocity()/6) < leftBBTarget)
	{
		leftFlyMotor.move_velocity(leftFlySpeed * 1.5);
		pidActive = false;
	}else if ((leftFlyRot.get_velocity()/6) > leftBBTarget) {
		pidActive = true;
		
		while (pidActive == true)
		{
			if (error == 0)
			{
				lastError = 0;
			}
			if (abs(error) < integralActiveZone && error != 0)
			{
				totalError += error;
			}else {
				totalError = 0;
			}
			finalAdjustment = (error * kP) + (totalError * kI) + ((error - lastError) * kD);
			int finalFlySpeed = leftFlySpeed + finalAdjustment;
			if (finalFlySpeed > 600) 
			{
				finalFlySpeed = 600;
			}
			else if (finalFlySpeed < 0)
			{
				finalFlySpeed = 0;
			}
			leftFlyMotor.move_velocity(finalFlySpeed);
		}


	}
}
void rightFlywheelController(int rightFlyRPM, int rightBBTarget)
{
	//PID Controller Activator//
	bool pidActive = false;

	//Flywheel Variables
	int rightFlySpeed = rightFlyRPM/5;

	//PID Constants//
	float kP = 0;
	float kI = 0;
	float kD = 0;
		
	//PID Variables//
	int currentVelocity = rightFlyRot.get_velocity()/6;
	int error = rightFlyRPM - currentVelocity;
	int lastError = 0;
	int totalError = 0;
	int integralActiveZone = 15;

	int onTargetCount = 0;
	float finalAdjustment = error * kP;

	//Temp Variable//
	int deltaTime = 0;

	if((rightFlyRot.get_velocity()/6) < rightBBTarget)
	{
		rightFlyMotor.move_velocity(rightFlySpeed*1.5);
		pidActive = false;
	}else {
		pidActive = true;
		
		while (pidActive == true)
		{
			if (error == 0)
			{
				lastError = 0;
			}
			if (abs(error) < integralActiveZone && error != 0)
			{
				totalError += error;
			}else {
				totalError = 0;
			}
			finalAdjustment = (error * kP) + (totalError * kI) + ((error - lastError) * kD);
			int finalFlySpeed = rightFlySpeed + finalAdjustment;
			if (finalFlySpeed > 600) 
			{
				finalFlySpeed = 600;
			}
			else if (finalFlySpeed < 0)
			{
				finalFlySpeed = 0;
			}
			rightFlyMotor.move_velocity(finalFlySpeed);
					lastError = error;
		}


	}
}


void RPMValue(int dataInterval)
//Flywheel Data Output Function
{
	leftFlySpeed = (leftFlyRot.get_velocity()/6); //Gets the Speed of the Left Flywheel in RPM
	rightFlySpeed = (rightFlyRot.get_velocity()/6); //Gets the Speed of the Right Flywheel in RPM
	absLeftFlySpeed = abs(leftFlySpeed); //Gets the Absolute Value of the Left Flywheel Speed
	absRightFlySpeed = abs(rightFlySpeed); //Gets the Absolute Value of the Right Flywheel Speed
	std::cout << recordedTime << "," << absLeftFlySpeed << "," << absRightFlySpeed << "\n"; //Prints the Time and Flywheel Speeds to the Console
	pros::delay(dataInterval); //Delays the Function by the Specified Amount of Time
	recordedTime += dataInterval; //Adds the dataInterval to the Recorded Time to track the Time
}

void FlywheelControl(int leftFlyRPM, int rightFlyRPM, int leftBBTarget, int rightBBTarget, int dataInterval)
{
    if (master.get_digital(ButtonA))
	//Runs the Flywheel at the Specified Speeds and Starts Data output when the A Button is Pressed 
	{
		pros::Task leftFlyControlTask(leftFlyRPM, leftBBTarget); //spins the left flywheel at the specified speed
		pros::Task rightFlyControlTask(rightFlyRPM, rightBBTarget); //spins the right flywheel at the specified speed
		spinning = true; //Sets the Variable to output data to true
		flywheelStopped = false; //Sets the Variable to indicate that the Flywheel is Stopped to False
	}

	if (master.get_digital(ButtonB))
	//Stops the Flywheels when the B Button is Pressed 
	{
		leftFlyMotor.brake(); //Stops the Left Flywheel motor
		rightFlyMotor.brake(); //Stops the Right Flywheel motor
		flywheelStopped = true; //Sets the Variable to indicate that the Flywheel is Stopped to True
	}

	if (master.get_digital(ButtonY))
	//Fires the Pnuematic Actuator when the Y Button is Pressed 
	{
		flywheelActuator.set_value(true); //Moves the Actuator to Push the Disc into the Flywheel
	}else 
	{
		flywheelActuator.set_value(false); //Moves the Actuator to Pull the Disc into the Flywheel
	}

	if (leftFlySpeed < 1 && rightFlySpeed < 1 && flywheelStopped == true) 
	//Stops data output when the Flywheels stop spinning and the flywheelStopped Variable is True
	{
		spinning = false; //Sets the Variable to output data to False
	}

	if (spinning == true)
	//Runs the Data Output Function when the spinning Variable is True
	{
		RPMValue(dataInterval); //Runs the Data Output Function at the specified data interval
	}
}