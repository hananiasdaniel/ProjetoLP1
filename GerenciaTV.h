#ifndef GERENCIATV_H
#define GERENCIATV_H
#include <string>
#include "Canal.h"
#include <vlc/vlc.h>


class GerenciaTV  : public Canal
{
	protected:
		int nCanais; //numero de canais
		int can; //numero do canal

	private:
		Canal canal[100];
	public:
		GerenciaTV();
		~GerenciaTV();

		void addCanal(Canal);
		void proximo_Canal(libvlc_media_list_player_t *);
		void anterior_Canal(libvlc_media_list_player_t *);
		//void removerCanal();

		void ligaTV(libvlc_media_list_player_t *);
		int desligaTV();
		
};
#endif