#pragma once
#include "Itens.h"

//Struct usada para exibição de tempo
struct relogio {
	char minuto_principal_char[256];
	char segundo_principal_char[256];
	int minuto_principal = 0;
	int segundo_principal = 0;
	int minuto_pause = 0;
	int segundo_pause = 0;
	clock_t tempo_inicial_principal = 0;
	clock_t tempo_final_principal = 0;
	clock_t tempo_exe_principal = 0;
	clock_t tempo_inicial_pause = 0;
	clock_t tempo_final_pause = 0;
	clock_t tempo_exe_pause = 0;
	int tempo_terremoto = 0;
	clock_t exe_eventos_pause = 0;
	int aux_eventos_pause = 0;
	int aux_pause = 0;
};


//Função de tempo
void tempo_converte(int tempo_total_segundos, relogio &r, bool aux) {
	int minuto = tempo_total_segundos / 60; //Atribuição do valor do minuto;
	int segundo = tempo_total_segundos % 60;

	//Atribui os valores de tempo a struct relogio.
	r.minuto_principal = minuto;
	r.segundo_principal = segundo;
	if (aux == true) {
		r.minuto_pause = minuto;
		r.segundo_pause = segundo;
	}
}

//Função que controla o tempo e informações do menu superior
void controle_de_tempo_principal(relogio &r, controle_ c, itens_ i, bool aux) {
	int corrige_tempo = 0;

	r.tempo_final_principal = clock();
	r.tempo_exe_principal = (r.tempo_final_principal - r.tempo_inicial_principal) / (double)CLOCKS_PER_SEC;
	corrige_tempo = r.tempo_exe_principal - r.aux_pause;
	tempo_converte(corrige_tempo, r, false);

	if (aux == true) {
		int aux = 0;
		char usos_pa[256], usos_tocha[256], usos_bota[256], tempo_terremoto[256];
		if (i.dificuldade == 0) {
			if (i.USOS_KIT > 0) 
				aux = 120 - r.tempo_terremoto;
			else
				aux = 60 - r.tempo_terremoto;
		}
		else if (i.dificuldade == 1) {
			if (i.USOS_KIT > 0)
				aux = 80 - r.tempo_terremoto;
			else
				aux = 40 - r.tempo_terremoto;
		}
		else if (i.dificuldade == 2) {
			if (i.USOS_KIT > 0)
				aux = 40 - r.tempo_terremoto;
			else
				aux = 20 - r.tempo_terremoto;
		}
		sprintf_s(r.minuto_principal_char, "%d", r.minuto_principal);
		sprintf_s(r.segundo_principal_char, "%d", r.segundo_principal);
		sprintf_s(usos_pa, "%d", i.USOS_PA);
		sprintf_s(usos_tocha, "%d", c.USOS_TOCHA);
		sprintf_s(usos_bota, "%d", i.USOS_BOTA);
		sprintf_s(tempo_terremoto, "%d", aux);
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 290, 40, ALLEGRO_ALIGN_RIGHT, "TEMPO: ");
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 280, 40, ALLEGRO_ALIGN_RIGHT, r.minuto_principal_char);
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 270, 40, ALLEGRO_ALIGN_RIGHT, ":");
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 252, 40, ALLEGRO_ALIGN_RIGHT, r.segundo_principal_char);

		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 205, 55, ALLEGRO_ALIGN_RIGHT, "Tempo ate terremoto: ");
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 185, 55, ALLEGRO_ALIGN_RIGHT, tempo_terremoto);

		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 285, 70, ALLEGRO_ALIGN_RIGHT, "Usos Pa: ");
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 270, 70, ALLEGRO_ALIGN_RIGHT, usos_pa);

		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 263, 85, ALLEGRO_ALIGN_RIGHT, "Usos Tocha: ");
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 253, 85, ALLEGRO_ALIGN_RIGHT, usos_tocha);

		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 273, 100, ALLEGRO_ALIGN_RIGHT, "Usos Bota: ");
		al_draw_text(c.fonte_14, al_map_rgb(0, 0, 0), LARGURA_TELA - 263, 100, ALLEGRO_ALIGN_RIGHT, usos_bota);
	}
	else {
		r.tempo_final_pause = clock();
		r.tempo_exe_pause = (r.tempo_final_pause - r.tempo_inicial_pause) / (double)CLOCKS_PER_SEC;
		r.exe_eventos_pause = (r.tempo_final_pause - r.tempo_inicial_pause) / (double)CLOCKS_PER_SEC;
		tempo_converte(r.tempo_exe_pause, r, true);
	}
}