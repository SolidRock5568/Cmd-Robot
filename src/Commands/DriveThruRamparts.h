#ifndef DriveThruRamparts_H
#define DriveThruRamparts_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "LowerArm.h"
#include "RaiseArm.h"
#include "DriveForward.h"
#include "DriveStop.h"
#include "Robot.h"

class DriveThruRamparts: public CommandGroup
{
public:
	DriveThruRamparts();
};

#endif
