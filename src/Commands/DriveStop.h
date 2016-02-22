#ifndef DriveStop_H
#define DriveStop_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStop: public CommandBase
{
public:
	DriveStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
