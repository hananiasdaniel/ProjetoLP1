 #include <stdio.h>
 #include <stdlib.h>
 #include <vlc/vlc.h>
 #include <unistd.h>
 #include <string>
 #include "GerenciaTV.h"
 #include "Canal.h"
 #include <iostream>
 using namespace std;

int main(int argc, char* argv[])
{
	int i, command, control;
	libvlc_media_player_t *mediaPlayer; //mp
	libvlc_instance_t *vlc;
	libvlc_media_list_t *lista; //ml
	libvlc_media_list_player_t *listaMidia; //mlp
	libvlc_media_t *md;
	
	Canal c1(1);
	Canal c2(2);
	Canal c3(3);
	Canal c4(4);
	
	GerenciaTV *TV = new GerenciaTV();
	// Carrega a engine VLC 
	vlc = libvlc_new (0, NULL);
	// Cria uma lista vazia
	lista = libvlc_media_list_new(vlc);	 
	// Cria um novo media_list_player
	listaMidia = libvlc_media_list_player_new(vlc);
	// Cria um objeto media_player vazio
	mediaPlayer = libvlc_media_player_new(vlc);

	//testa se as playlists foram adicionadas
	/*argc = 3;
	for(i=0; i < argc ; i++) { 		
        // Cria uma midia para certo arquivo 		
        md = libvlc_media_new_path (vlc, "/home/hananias/Desktop/vlc_test/videos/Christina Perri - A Thousand Years.mp4"); 		
        // Adiciona a instancia da midia a lista de midia 		
        libvlc_media_list_add_media (lista, md); 		 		
        printf (" > %s added to the playlist! \n", dir[i]);
	}*/

	
	
	TV->addCanal(c1);
		//Cria um item, aqui voce pode carregar qualquer arquivo de mídia 
		md = libvlc_media_new_path (vlc, "/home/hananias/Desktop/vlc_test/videos/Temer.mp4");
		libvlc_media_list_add_media (lista, md);

	TV->addCanal(c2);
		//Cria um item, aqui voce pode carregar qualquer arquivo de mídia 
		md = libvlc_media_new_path (vlc, "/home/hananias/Desktop/vlc_test/videos/Jorel.mp4");
		// Adiciona a instancia da midia a lista de midia 
		libvlc_media_list_add_media (lista, md);

	TV->addCanal(c3);
		// Cria um item, aqui voce pode carregar qualquer arquivo de mídia 
		md = libvlc_media_new_path (vlc, "/home/hananias/Desktop/vlc_test/videos/Drake & Josh.mp4");
		// Adiciona a instancia da midia a lista de midia 
		libvlc_media_list_add_media (lista, md);

	TV->addCanal(c4);
		md = libvlc_media_new_path (vlc, "/home/hananias/Desktop/vlc_test/videos/ben 10.mp4");
		libvlc_media_list_add_media (lista, md);




	// Configura a lista de midia associada com o player
	libvlc_media_list_player_set_media_list (listaMidia, lista);  
	// Substitui o media player em media_list_player com esta instancia
	libvlc_media_list_player_set_media_player(listaMidia, mediaPlayer);
	
	control = 1;
		while(control) {
		command = getchar();
		switch(command)
		{
			case 'l':
				// Abre o player
				//libvlc_media_list_player_play(listaMidia);
				TV->ligaTV(listaMidia);
				printf("ABRIU\n");
				break;
			case 's':	// para de tocar
				if(listaMidia) {
					libvlc_media_list_player_stop(listaMidia);
					printf ("STOP\n");
				}
				break;
				
			case 'n':	// proxima midia da lista
				if(listaMidia) {
					//libvlc_media_list_player_next(listaMidia);
					TV->proximo_Canal(listaMidia);
					printf ("PROXIMA\n");
				}
				break;
				
			case 'b':	// midia anterior da lista
				if(listaMidia) {
					//libvlc_media_list_player_previous(listaMidia);
					TV->anterior_Canal(listaMidia);
					printf ("ANTERIOR\n");
				}
				break;
				
			case 'q':	// sai e encerra o player
				control = TV->desligaTV();
				printf("ADEUS!\n");
				//control=0;
				break;
			
			case 'o':   /* pausa a midia atual */
				if(listaMidia) {
					libvlc_media_list_player_pause(listaMidia); 
					printf ("PAUSE\n");
				}
			break;
				
			case 'p':	// toca a lista
				if (listaMidia) {
					libvlc_media_list_player_play(listaMidia);
					printf ("PLAY\n");
				}
				break;			
		}
	}

	libvlc_release (vlc);

	return 0;
}