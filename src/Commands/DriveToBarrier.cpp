#include "DriveToBarrier.h"

DriveToBarrier::DriveToBarrier() {

	AddSequential(new DriveForward(0.2,0.2,4.25)); //drive to barrier
	AddSequential(new DriveStop());

}

