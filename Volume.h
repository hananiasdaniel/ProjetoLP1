#ifndef VOLUME_H
#define VOLUME_H

class Volume
{
	protected:
		int numeroVolume;
	public:
		Volume();
		void set_numeroVolume(int);
		int get_numeroVolume();
		void aumentaVolume();
		void diminuiVolume();

};
#endif