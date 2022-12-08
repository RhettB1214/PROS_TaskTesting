#include "main.h"
#include "initializations.hpp"
#include "pros/imu.hpp"
#include "variables.hpp"

//Variable Definitions

//Flywheel Variables
int recordedTime = 0;
bool spinning = false;
bool flywheelStopped = true;
int leftFlySpeed;
int rightFlySpeed;
int absLeftFlySpeed;
int absRightFlySpeed;
int leftFlyMotorTemp = leftFlyMotor.get_temperature();
int rightFlyMotorTemp = rightFlyMotor.get_temperature();
int theoreticalLeftFlywheelSpeed;
int theoreticalRightFlywheelSpeed;
int leftFlyRPM = 1600;
int rightFlyRPM = 2000;
int leftBBTarget = 1500;
int rightBBTarget = 1900;
int dataInterval = 25;


//Roller Variables
std::string rollerOwner;
bool rollerOwned = false;
double opticalHue = rollerOptical.get_hue();

// Alliance Variables
bool red = false;
bool blue = false;
bool skills = false;
int allianceValue;

//Intake Variables
bool lastKnownStateOfButtonIntake = false;
bool shouldIntakeRun = false;

//IMU/GPS Variables
double currentHeading = imu.get_rotation();
double xGPSOffset = 0;
double yGPSOffset = 0;
double xBlueGPSInital = 0;
double yBlueGPSInital = 0;
double xRedGPSInital = 0;
double yRedGPSInital = 0;
double xSkillsGPSInital = 0;
double ySkillsGPSInital = 0;


//PID Constants//
float leftkP = 0;
float leftkI = 0;
float leftkD = 0;
float rightkP = 0;
float rightkI = 0;
float rightkD = 0;


//PID Variables//
int leftCurrentVelocity = leftFlyRot.get_velocity()/6;
int leftError = leftFlyRPM - leftCurrentVelocity;
int leftLastError = 0;
int leftTotalError = 0;
int leftIntergralActiveZone = 15;
int rightCurrentVelocity = rightFlyRot.get_velocity()/6;
int rightError = rightFlyRPM - rightCurrentVelocity;
int rightLastError = 0;
int rightTotalError = 0;
int rightIntergralActiveZone = 15;



