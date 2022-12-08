//This file Initializes all the motors, sensors, and other devices
#include "main.h"
#include "initializations.hpp"


//Motor Initalization
pros::Motor intakeMotor(INTAKE_MOTOR_PORT, TORQUEBOX); //Initializes the Intake Motor
pros::Motor rightFlyMotor(R_FLYWHEEL_MOTOR_PORT); //Initializes the Right Flywheel Motor
pros::Motor leftFlyMotor(L_FLYWHEEL_MOTOR_PORT,true); //Initializes the Left Flywheel Motor
pros::Motor flDrive(FL_DRIVE_PORT); //Initializes the Front Left Drive Motor
pros::Motor frDrive(FR_DRIVE_PORT); //Initializes the Front Right Drive Motor
pros::Motor blDrive(BL_DRIVE_PORT); //Initializes the Back Left Drive Motor
pros::Motor brDrive(BR_DRIVE_PORT); //Initializes the Back Right Drive Motor

//Sensor Initalization
pros::Rotation rightFlyRot(RIGHT_FLYWHEEL_ROTATION_SENSOR_PORT); //Initializes the Right Flywheel Rotation Sensor
pros::Rotation leftFlyRot(LEFT_FLYWHEEL_ROTATION_SENSOR_PORT); //Initializes the Left Flywheel Rotation Sensor
pros::Optical rollerOptical(OPTICAL_PORT); //Initializes the Optical Sensor
pros::Vision discRecognition(VISION_PORT); //Initializes the Vision Sensor
pros::Gps gps(GPS_PORT, 0.00, -0.135); //Initializes the GPS Sensor
pros::Imu imu(IMU_PORT); //Initializes the IMU Sensor
pros::Distance frontDistance(FRONT_DISTANCE_PORT); //Initializes the Front Distance Sensor
pros::Distance backDistance(BACK_DISTANCE_PORT); //Initializes the Back Distance Sensor
pros::Distance rightDistance(RIGHT_DISTANCE_PORT); //Initializes the Right Distance Sensor
pros::Distance leftDistance(LEFT_DISTANCE_PORT); //Initializes the Left Distance Sensor
pros::ADIDigitalOut flywheelActuator(FLYWHEEL_ACTUATOR); //Initializes the Flywheel Actuator
pros::ADIDigitalOut endgameActuator(ENDGAME_ACTUATOR); //Initializes the Endgame Actuator

//Controller Initilization
pros::Controller master(pros::E_CONTROLLER_MASTER); //Initializes the Master Controller