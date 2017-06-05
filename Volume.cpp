#include "Volume.h"

Volume::Volume(){}

void Volume::set_numeroVolume(int v)
{
	numeroVolume = v;
}

int Volume::get_numeroVolume()
{	
	return numeroVolume;
}

void Volume::aumentaVolume()
{
	volume++;
}

void Volume::diminuiVolume()
{
	volume--;
}