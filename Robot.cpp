#include <Robot.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

VisionModule Robot::vm;

void Robot::RobotInit(){

}

	void Robot::AutonomousInit()  {

	}

	void Robot::AutonomousPeriodic()  {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit() {

	}

	void Robot::TeleopPeriodic()  {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic() {

	}


START_ROBOT_CLASS(Robot)
