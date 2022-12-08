/*This file allows the motors, sensors, and other devices 
declared in initializations.cpp to be used 
wherever this header is included*/
#include "main.h"


extern pros::Motor intakeMotor;
extern pros::Motor rightFlyMotor;
extern pros::Motor leftFlyMotor;
extern pros::Motor flDrive;
extern pros::Motor frDrive;
extern pros::Motor blDrive;
extern pros::Motor brDrive;
extern pros::Rotation rightFlyRot;
extern pros::Rotation leftFlyRot;
extern pros::Optical rollerOptical;
extern pros::Vision discRecognition;
extern pros::Gps gps;
extern pros::Imu imu;
extern pros::Distance frontDistance;
extern pros::Distance backDistance;
extern pros::Distance rightDistance;
extern pros::Distance leftDistance;
extern pros::ADIDigitalOut flywheelActuator;
extern pros::ADIDigitalOut endgameActuator;
extern pros::Controller master;