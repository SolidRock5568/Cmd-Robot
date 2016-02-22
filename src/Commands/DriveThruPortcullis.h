#ifndef DriveThruPortcullis_H
#define DriveThruPortcullis_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "LowerArm.h"
#include "RaiseArm.h"
#include "DriveForward.h"
#include "DriveStop.h"
#include "DelayedRaiseArm.h"
#include "Robot.h"

class DriveThruPortcullis: public CommandGroup
{
public:
	DriveThruPortcullis();
};

#endif
