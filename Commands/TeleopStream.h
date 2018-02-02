#ifndef TeleopStream_H
#define TeleopStream_H

#include "Commands/Command.h"
#include "wpilib.h"

class TeleopStream : public Command {
public:
	TeleopStream();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleopStream_H
