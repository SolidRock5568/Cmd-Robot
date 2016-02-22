#include "DriveThruRockyTerrain.h"

DriveThruRockyTerrain::DriveThruRockyTerrain() {

	AddSequential(new DriveForward(0.5,0.5,4.4)); //drive to barrier
	AddSequential(new DriveForward(0.7,0.7,5.0)); //drive over rocky terrain
	AddSequential(new DriveForward(0.3, 0.3,6.0)); //drive after barrier into endzone
	AddSequential(new DriveStop()); //stop in endzone
}

