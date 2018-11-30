#pragma once

//Oculta Console
void Stealth()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}

//Pré loading de informações básicas
void pre(mapa &m, controle_ &c, armazens &a) {
	iniciar(c);
	carrega_arquivos(c);
	gerador_mapa(m);
	sorteia_formiga(m, c);
	sorteia_armazem(m, a);
}

//Carregamento do menu
void preMenu(mapa m, controle_ &c, itens_ &i, armazens a, relogio &r) {
	al_attach_audio_stream_to_mixer(c.musica_menu, al_get_default_mixer());
	al_set_audio_stream_playmode(c.musica_menu, ALLEGRO_PLAYMODE_LOOP);
	exibe_menu_principal(m, c, i, a);
	al_set_audio_stream_playing(c.musica_menu, 0);
	sorteador_itens(i, m);
	c.start = clock();
	r.tempo_inicial_principal = clock();
}

//Carregamento das operações do jogo
bool preJogar(mapa &m, controle_ &c, itens_ &i, armazens &a, relogio &r) {
	al_attach_audio_stream_to_mixer(c.game, al_get_default_mixer());
	al_set_audio_stream_playmode(c.game, ALLEGRO_PLAYMODE_LOOP);
	controle_fun(m, c, i, a, false);
	renderizar(m, c, a);
	controle_de_tempo_principal(r, c, i, true);
	c.end = clock();
	r.tempo_terremoto = ((c.end - c.start) / (double)CLOCKS_PER_SEC) - r.aux_eventos_pause;
	if (r.tempo_terremoto >= i.VELOCIDADE_EVENTO) {
		i.USOS_BOTA = 0;
		c.USOS_TOCHA = 0;
		i.USOS_KIT = 0;
		gerador_mapa(m);
		sorteia_formiga(m, c);
		sorteador_itens(i, m);
		sorteia_armazem(m, a);
		r.aux_eventos_pause = 0;
		c.start = clock();
	}
	if (checkFimGame(a) == true) {
		return true;
	}
	return false;
}

//Carregamento da tela de pause 
void prePause(mapa &m, controle_ &c, itens_ &i, armazens &a, relogio &r) {
	r.tempo_inicial_pause = clock();
	al_set_audio_stream_playing(c.game, 0);
	pause_mode(m, c, i, a, r, false);
	al_set_audio_stream_playing(c.game, 1);
	c.tecla = 0;
	r.aux_eventos_pause += r.exe_eventos_pause;
	r.aux_pause += r.tempo_exe_pause;
}

//Carregamento da tela de vitória
void preVitoria(mapa m, controle_ &c, itens_ &i, armazens &a, relogio r) {
	al_attach_audio_stream_to_mixer(c.win, al_get_default_mixer());
	al_set_audio_stream_playmode(c.win, ALLEGRO_PLAYMODE_LOOP);
	while (c.tecla != 3) {
		controle_fun(m, c, i, a, true);
		al_clear_to_color(al_map_rgb(0, 255, 0));
		al_draw_text(c.fonte_40, al_map_rgb(0, 0, 0), LARGURA_TELA - 400, 400, ALLEGRO_ALIGN_RIGHT, "TEMPO DE JOGO: ");
		al_draw_text(c.fonte_40, al_map_rgb(0, 0, 0), LARGURA_TELA - 380, 400, ALLEGRO_ALIGN_RIGHT, r.minuto_principal_char);
		al_draw_text(c.fonte_40, al_map_rgb(0, 0, 0), LARGURA_TELA - 360, 400, ALLEGRO_ALIGN_RIGHT, ":");
		al_draw_text(c.fonte_40, al_map_rgb(0, 0, 0), LARGURA_TELA - 310, 400, ALLEGRO_ALIGN_RIGHT, r.segundo_principal_char);
		al_draw_text(c.fonte_40, al_map_rgb(0, 0, 0), LARGURA_TELA - 280, 500, ALLEGRO_ALIGN_RIGHT, "APERTE ESC PARA SAIR");
		al_flip_display();
	}
}

//Destruição de todos vestigios do jogo
void finalizacao(mapa m, controle_ c, itens_ i, armazens a, relogio r) {
	al_destroy_display(c.janela);
	al_destroy_event_queue(c.fila_eventos);
	al_destroy_font(c.fonte_10);
	al_destroy_font(c.fonte_14);
	al_destroy_font(c.fonte_16);
	al_destroy_font(c.fonte_18);
	al_destroy_font(c.fonte_20);
	al_destroy_font(c.fonte_30);
	al_destroy_font(c.fonte_40);
	al_destroy_bitmap(c.MENU);
	al_destroy_bitmap(c.MENU_SUPERIOR);
	al_destroy_bitmap(c.BACKGROUND);
	al_destroy_bitmap(c.CAMINHO);
	al_destroy_bitmap(c.PAREDE);
	al_destroy_bitmap(c.FORMIGA_CIMA);
	al_destroy_bitmap(c.FORMIGA_BAIXO);
	al_destroy_bitmap(c.FORMIGA_ESQUERDA);
	al_destroy_bitmap(c.FORMIGA_DIREITA);
	al_destroy_bitmap(c.FORMIGA_ALIMENTO_CIMA);
	al_destroy_bitmap(c.FORMIGA_ALIMENTO_BAIXO);
	al_destroy_bitmap(c.FORMIGA_ALIMENTO_ESQUERDA);
	al_destroy_bitmap(c.FORMIGA_ALIMENTO_DIREITA);
	al_destroy_bitmap(c.FOLHA_SETA);
	al_destroy_bitmap(c.PA);
	al_destroy_bitmap(c.BOTA);
	al_destroy_bitmap(c.TOCHA);
	al_destroy_bitmap(c.KIT);
	al_destroy_bitmap(c.COMIDA_PESO0);
	al_destroy_bitmap(c.COMIDA_PESO1);
	al_destroy_bitmap(c.COMIDA_PESO2);
	al_destroy_bitmap(c.COMIDA_PESO3);
	al_destroy_bitmap(c.COMIDA_PESO4);
	al_destroy_bitmap(c.COMIDA_PESO0_CORROMPIDO);
	al_destroy_bitmap(c.COMIDA_PESO1_CORROMPIDO);
	al_destroy_bitmap(c.COMIDA_PESO2_CORROMPIDO);
	al_destroy_bitmap(c.COMIDA_PESO3_CORROMPIDO);
	al_destroy_bitmap(c.COMIDA_PESO4_CORROMPIDO);
	al_destroy_bitmap(c.PENUMBRA_150);
	al_destroy_bitmap(c.PENUMBRA_250);
	al_destroy_audio_stream(c.musica_menu);
	al_destroy_audio_stream(c.game);
	al_destroy_audio_stream(c.win);
	al_destroy_sample(c.scroll);
	al_destroy_sample(c.click);
	al_destroy_sample(c.pa);
	al_destroy_sample(c.pa_pegando);
	al_destroy_sample(c.tocha);
	al_destroy_sample(c.kit);
	al_destroy_sample(c.bota);
	al_destroy_sample(c.pega_entrega_armazem);
}