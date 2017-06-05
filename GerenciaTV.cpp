#include "GerenciaTV.h"
#include <iostream>

GerenciaTV::GerenciaTV(){}

GerenciaTV::~GerenciaTV(){}

void GerenciaTV::addCanal(Canal c)
{
	canal[nCanais] = c;
	nCanais++;
	//std::cout << nCanais << std::endl;
}

//void GerenciaTV::removerCanal(){}

void GerenciaTV::proximo_Canal(libvlc_media_list_player_t *listaMidia)
{
	libvlc_media_list_player_next(listaMidia);
	can++;
}

void GerenciaTV::anterior_Canal(libvlc_media_list_player_t *listaMidia)
{
	libvlc_media_list_player_previous(listaMidia);
	can--;
}

void GerenciaTV::ligaTV(libvlc_media_list_player_t *listaMidia)
{
	libvlc_media_list_player_play(listaMidia);
}

int GerenciaTV::desligaTV()
{
	return 0;
}