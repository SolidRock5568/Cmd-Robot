#ifndef DriveToBarrier_H
#define DriveToBarrier_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "RaiseArm.h"
#include "LowerArm.h"
#include "DriveForward.h"
#include "DriveStop.h"
#include "Robot.h"

class DriveToBarrier: public CommandGroup
{
public:
	DriveToBarrier();
};

#endif
