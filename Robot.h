//#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef ROBOT_H
#define ROBOT_H

#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>

#include <OI.h>
#include "WPILib.h"
#include "Subsystems/VisionModule.h"

class Robot: public frc::IterativeRobot{
public:

	static VisionModule vm;

private:
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};

#endif  // OI_H
