#ifndef CANAL_H
#define CANAL_H
#include <vlc/vlc.h>
#include <string>

class Canal
{
	protected:
		int numeroCanal;
	public:
		Canal();
		Canal(int);
		~Canal();
		void set_numeroCanal(int);
		int get_numeroCanal();
		
};
#endif