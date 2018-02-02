#include "TeleopStream.h"
#include "../Robot.h"

TeleopStream::TeleopStream() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::vm);
}

// Called just before this Command runs the first time
void TeleopStream::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleopStream::Execute() {
	Robot::vm.OutputRawStream();
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopStream::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopStream::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopStream::Interrupted() {

}
