#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

#define LARGURA_TELA 1000
#define ALTURA_TELA 900

void exibe_menu_tutorial(mapa m, controle_ &c, itens_ i, armazens a);
void exibe_menu_tutorial2(mapa m, controle_ &c, itens_ i, armazens a);
void exibe_menu_tutorial3(mapa m, controle_ &c, itens_ i, armazens a);
void renderizar(mapa mapa, controle_ &c, armazens a);
void reiniciar(mapa &m, controle_ &c, itens_ &i, relogio &r, armazens &a);

//Função que cria janela dinâmica, de acordo com o tamanho desejado
void mostra_janela(int w, int h, controle_ &c) {
	al_draw_filled_rectangle(LARGURA_TELA / 2 - w / 2 - 5, ALTURA_TELA / 2 - h / 2 - 5, LARGURA_TELA / 2 + w / 2, ALTURA_TELA / 2 + h / 2, al_map_rgb(192, 192, 192));
	al_draw_filled_rectangle(LARGURA_TELA / 2 - w / 2, ALTURA_TELA / 2 - h / 2, LARGURA_TELA / 2 + w / 2 + 5, ALTURA_TELA / 2 + h / 2 + 5, al_map_rgb(64, 64, 64));
	al_draw_filled_rectangle(LARGURA_TELA / 2 - w / 2, ALTURA_TELA / 2 - h / 2, LARGURA_TELA / 2 + w / 2, ALTURA_TELA / 2 + h / 2, al_map_rgb(128, 128, 128));

	al_draw_filled_rounded_rectangle(LARGURA_TELA / 2 + w / 2 - al_get_text_width(c.fonte_10, "ESC") - 5,
		ALTURA_TELA / 2 + h / 2 - al_get_font_ascent(c.fonte_10) - 5,
		LARGURA_TELA / 2 + w / 2 - 1,
		ALTURA_TELA / 2 + h / 2 - 1, 2, 2, al_map_rgba(0, 0, 0, 100));
	al_draw_text(c.fonte_10, al_map_rgba(150, 150, 150, 50),
		LARGURA_TELA / 2 + w / 2 - al_get_text_width(c.fonte_10, "ESC") - 2,
		ALTURA_TELA / 2 + h / 2 - al_get_font_ascent(c.fonte_10) - 3, ALLEGRO_ALIGN_LEFT, "ESC");
}

//Exibe tela de creditos
void exibe_menu_creditos(mapa m, controle_ &c, itens_ i, armazens a) {
	while (c.tecla != 3) {
		controle_fun(m, c, i, a, true);
		mostra_janela(500, 100, c);
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 30, ALLEGRO_ALIGN_CENTRE, "Desenvolvido por Herikc Brecher, ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 5, ALLEGRO_ALIGN_CENTRE, "Alecsandra Tomasi e Wesley Martin");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 20, ALLEGRO_ALIGN_CENTRE, "Universidade do Vale do Itajai - Univali");
		al_flip_display();
	}
}

//Sequencia de 4 telas para o tutorial
void exibe_menu_tutorial4(mapa m, controle_ &c, itens_ i, armazens a) {
	c.tecla = 99;
	while (c.tecla != 3) {
		mostra_janela(850, 380, c);
		controle_fun(m, c, i, a, true);
		al_draw_text(c.fonte_30, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 175, ALLEGRO_ALIGN_CENTRE, "MENU SUPERIOR");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 130, ALLEGRO_ALIGN_CENTRE, "Quando iniciado o jogo, na parte superior ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 95, ALLEGRO_ALIGN_CENTRE, "da tela estara localizado o menu de informacoes. ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 60, ALLEGRO_ALIGN_CENTRE, "Nele, sera exibido o tempo, e se voce possui ou nao");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 25, ALLEGRO_ALIGN_CENTRE, " os itens. Juntamente sera exibido qual comida voce ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 10, ALLEGRO_ALIGN_CENTRE, "esta carregando. ");
		al_draw_text(c.fonte_30, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 45, ALLEGRO_ALIGN_CENTRE, "COMANDOS");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 80, ALLEGRO_ALIGN_CENTRE, "Use W/S/A/D para se movimentar. Para pegar qualquer item/comida, ande");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 115, ALLEGRO_ALIGN_CENTRE, " na sua direcao, como se fosse um caminho.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 150, ALLEGRO_ALIGN_CENTRE, "<----------");
		if (c.tecla == 5) {
			exibe_menu_tutorial3(m, c, i, a);
		}
		al_flip_display();
	}
}

void exibe_menu_tutorial3(mapa m, controle_ &c, itens_ i, armazens a) {
	c.tecla = 99;
	while (c.tecla != 3) {
		mostra_janela(850, 380, c);
		controle_fun(m, c, i, a, true);
		al_draw_text(c.fonte_30, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 175, ALLEGRO_ALIGN_CENTRE, "ARMAZENS DE COMIDA");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 130, ALLEGRO_ALIGN_CENTRE, "Os armazens de comida sao 3.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 95, ALLEGRO_ALIGN_CENTRE, " Somente um inicia com as comidas, o peso");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 60, ALLEGRO_ALIGN_CENTRE, " das comidas, e determinado pela cor das folhas.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 25, ALLEGRO_ALIGN_CENTRE, "A folha verde e a mais leve, apos a roxa, laranja e ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 10, ALLEGRO_ALIGN_CENTRE, "vermelha. Os armazens possuem o fundo verde musgo.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 45, ALLEGRO_ALIGN_CENTRE, "Caso o armazem nao possua comida, nao tera folha o ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 80, ALLEGRO_ALIGN_CENTRE, "representando. A folha visivel, sempre sera a do topo. A ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 115, ALLEGRO_ALIGN_CENTRE, "comida que voce carrega, sempre sera verde, desconsiderando o peso.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 150, ALLEGRO_ALIGN_CENTRE, "<--------->");
		if (c.tecla == 5) { 
			exibe_menu_tutorial2(m, c, i, a);
		}
		else if (c.tecla == 4) {
			exibe_menu_tutorial4(m, c, i, a);
		}
		al_flip_display();
	}
}

void exibe_menu_tutorial2(mapa m, controle_ &c, itens_ i, armazens a) {
	c.tecla = 99;
	while (c.tecla != 3) {
		mostra_janela(850, 380, c);
		controle_fun(m, c, i, a, true);
		al_draw_text(c.fonte_30, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 175, ALLEGRO_ALIGN_CENTRE, "DESAFIO DA TORRE DE HANOI");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 130, ALLEGRO_ALIGN_CENTRE, "O desafio da torre de Hanoi consiste ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 95, ALLEGRO_ALIGN_CENTRE, "em retirar as 4 comidas de um armazem A");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 60, ALLEGRO_ALIGN_CENTRE, "e transferir para um unico armazem, B ou C.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 25, ALLEGRO_ALIGN_CENTRE, "O jogador pode ficar alternando as comidas");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 10, ALLEGRO_ALIGN_CENTRE, "entre os 3 armazens. Alem disso, as comidas");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 45, ALLEGRO_ALIGN_CENTRE, "possuem peso. A mais leve sempre tem que");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 80, ALLEGRO_ALIGN_CENTRE, "ficar no topo do armazem.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 115, ALLEGRO_ALIGN_CENTRE, "<---------->");	
		if (c.tecla == 5) {
			exibe_menu_tutorial(m, c, i, a);
		}
		else if (c.tecla == 4) {
			exibe_menu_tutorial3(m, c, i, a);
		}
		al_flip_display();
	}
}

void exibe_menu_tutorial(mapa m, controle_ &c, itens_ i, armazens a) {
	c.tecla = 99;
	while (c.tecla != 3) {
		mostra_janela(850, 380, c);
		controle_fun(m, c, i, a, true);
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 165, ALLEGRO_ALIGN_CENTRE, "Voce deve pegar as comidas nos armazens");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 130, ALLEGRO_ALIGN_CENTRE, "e completar o desafio da Torre de Hanoi.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 95, ALLEGRO_ALIGN_CENTRE, "Movimente-se usando as teclas W/S/A/D.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 60, ALLEGRO_ALIGN_CENTRE, "No meio do caminho podem ter itens ou armadilhas");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - 25, ALLEGRO_ALIGN_CENTRE, "a Bota ira deixar voce mais rapido. A pa");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 10, ALLEGRO_ALIGN_CENTRE, "ira permitir voce quebrar paredes. ");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 45, ALLEGRO_ALIGN_CENTRE, "O kit ira aumentar o tempo que ocorrem os terremotos.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 80, ALLEGRO_ALIGN_CENTRE, "E a tocha ira aumentar seu campo de visao.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 115, ALLEGRO_ALIGN_CENTRE, "Pressione P para pausar.");
		al_draw_text(c.fonte_20, al_map_rgb(0, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 + 150, ALLEGRO_ALIGN_CENTRE, "---------->");		
		if (c.tecla == 4) {
			exibe_menu_tutorial2(m, c, i, a);
		}
		al_flip_display();
	}
}

//Define o status das opções, de acordo com as escolhidas
void status_options(controle_ &c) {
	if (c.music_status) {
		al_set_audio_stream_gain(c.musica_menu, 1.0);
		al_set_audio_stream_gain(c.game, 1.0);
	}
	else {
		al_set_audio_stream_gain(c.musica_menu, 0.0);
		al_set_audio_stream_gain(c.game, 0.0);
	}		
}

//Exibe as opções de jogo
void exibe_opcoes(mapa m, controle_ &c, itens_ i, armazens a, bool aux) {
	c.tecla = 0;
	int tam_menu = 2;
	int imenu = -1;
	char op_menu[2][50] = { "Music: ","Sound Effects: " }; //texto das opcoes do menu
	float y_menu = (3 * ALTURA_TELA / (tam_menu + 3)) - 150;
	float x_menu = LARGURA_TELA / 2;
	float menu_inc = (ALTURA_TELA - y_menu) / tam_menu;
	ALLEGRO_COLOR cor_menu;
	while (c.tecla != 3) {
		if (aux == true) {
			renderizar(m, c, a);
		}
		mostra_janela(400, 180, c);
		controle_fun(m, c, i, a, true);
		status_options(c);
		if (c.tecla == 0) {
			imenu++;
			if (c.sfx) 
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);		
			if (imenu == 2)
				imenu = 0;
			c.tecla = 99;
		}
		else if (c.tecla == 1) {
			imenu--;
			if (c.sfx) 
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);		
			if (imenu == -1)
				imenu = 1;

			c.tecla = 99;
		}
		else if (c.tecla == 2) {
			if (c.sfx) 
				al_play_sample(c.click, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);	
			if (imenu == 0) {
				if (c.music_status) 
					c.music_status = false;			
				else 
					c.music_status = true;			
			}
			else if (imenu == 1) {
				if (c.sfx)
					c.sfx = false;
				else
					c.sfx = true;
			}
			c.tecla = 99;
		}

		for (int i = 0; i <= tam_menu; i++) {
			if (i == imenu) 
				cor_menu = al_map_rgb(0, 255, 0);	
			else
				cor_menu = al_map_rgb(255, 255, 255);
			al_draw_text(c.fonte_30, cor_menu, x_menu - 190, y_menu + i * menu_inc * 0.3, ALLEGRO_ALIGN_LEFT, op_menu[i]);
			if (i == 0) {
				if (c.music_status==true) 
					al_draw_text(c.fonte_30, cor_menu, x_menu - 100, y_menu + i * menu_inc * 0.3, ALLEGRO_ALIGN_LEFT, "On");				
				else 
					al_draw_text(c.fonte_30, cor_menu, x_menu - 100, y_menu + i * menu_inc * 0.3, ALLEGRO_ALIGN_LEFT, "Off");						
			}
			if (i == 1) {
				if (c.sfx == true)
					al_draw_text(c.fonte_30, cor_menu, x_menu + 5, y_menu + i * menu_inc * 0.3, ALLEGRO_ALIGN_LEFT, "On");
				else
					al_draw_text(c.fonte_30, cor_menu, x_menu + 5, y_menu + i * menu_inc * 0.3, ALLEGRO_ALIGN_LEFT, "Off");
			}
		}
		al_flip_display();
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	renderizar(m, c, a);
}

//Altera a dificuldade do jogo
void status_dificuldade(itens_ &i, int aux) {
	if (aux == 0) {
		i.VELOCIDADE_EVENTO = 60;
		i.dificuldade = 0;
	}
	else if (aux == 1) {
		i.VELOCIDADE_EVENTO = 40;
		i.dificuldade = 1;
	}
	else if (aux == 2) {
		i.VELOCIDADE_EVENTO = 20;
		i.dificuldade = 2;
	}
}

//Exibe a tela de dificuldade
void exibe_dificuldade(mapa m, controle_ &c, itens_ &i, armazens a) {
	c.tecla = 0;
	int tam_menu = 3;
	int imenu = -1;
	char op_menu[3][50] = { "FACIL","NORMAL","DIFICIL" }; //texto das opcoes do menu
	float y_menu = (3 * ALTURA_TELA / (tam_menu + 3)) - 100;
	float x_menu = LARGURA_TELA / 2;
	float menu_inc = (ALTURA_TELA - y_menu) / tam_menu;
	ALLEGRO_COLOR cor_menu;

	while (c.tecla != 3) {
		mostra_janela(400, 250, c);
		controle_fun(m, c, i, a, true);
		if (c.tecla == 0) {
			imenu++;
			if (c.sfx)
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			if (imenu == 3)
				imenu = 0;

			c.tecla = 99;
		}
		else if (c.tecla == 1) {
			imenu--;
			if (c.sfx)
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			if (imenu == -1)
				imenu = 2;

			c.tecla = 99;
		}
		else if (c.tecla == 2) {
			if (c.sfx)
				al_play_sample(c.click, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			if (imenu == 0) {
				status_dificuldade(i, 0);
				c.tecla = 3;
			}
			else if (imenu == 1) {
				status_dificuldade(i, 1);
				c.tecla = 3;
			}
			else if (imenu == 2) {
				status_dificuldade(i, 2);
				c.tecla = 3;
			}
		}

		for (int i = 0; i <= tam_menu; i++) {
			if (i == imenu) {
				cor_menu = al_map_rgb(0, 255, 0);
			}
			else
				cor_menu = al_map_rgb(255, 255, 255);
			al_draw_text(c.fonte_30, cor_menu, x_menu, y_menu + i * menu_inc * 0.3, ALLEGRO_ALIGN_CENTRE, op_menu[i]);
			if (imenu == 0) {
				al_draw_text(c.fonte_30, al_map_rgb(0, 0, 0), x_menu, y_menu + 170, ALLEGRO_ALIGN_CENTRE, "Troca de Mapa: 60 segundos");
			}
			else if (imenu == 1) {
				al_draw_text(c.fonte_30, al_map_rgb(0, 0, 0), x_menu, y_menu + 170, ALLEGRO_ALIGN_CENTRE, "Troca de Mapa: 40 segundos");
			}
			else if (imenu == 2) {
				al_draw_text(c.fonte_30, al_map_rgb(0, 0, 0), x_menu, y_menu + 170, ALLEGRO_ALIGN_CENTRE, "Troca de Mapa: 20 segundos");
			}
		}
		al_flip_display();
	}
}

//Função do menu
void exibe_menu_principal(mapa m, controle_ &c, itens_ &i, armazens a) {
	int tam_menu = 8;
	int imenu = -1;
	char op_menu[8][50] = { "INICIAR","TUTORIAL","DIFICULDADE","PLACAR","CARREGAR","OPCOES","CREDITOS","SAIR" }; //texto das opcoes do menu
	float y_menu = 3 * ALTURA_TELA / (tam_menu + 3);
	float x_menu = LARGURA_TELA / 2;
	float menu_inc = (ALTURA_TELA - y_menu) / tam_menu;
	float largura_flecha = 125; //flecha do menu, do ponteiro do mouse
	float altura_flecha = largura_flecha * al_get_bitmap_height(c.FOLHA_SETA) / al_get_bitmap_width(c.FOLHA_SETA);
	float y_flecha = al_get_font_ascent(c.fonte_40) / 2 - altura_flecha / 2;
	float x_flecha = al_get_text_width(c.fonte_40, op_menu[imenu]) / 2 + 20;
	ALLEGRO_COLOR cor_menu;
	ALLEGRO_EVENT evento;
	while (!c.sair) {
		al_draw_bitmap(c.MENU, 0, 0, 0);
		controle_fun(m, c, i, a, true);
		if (c.tecla == 0) {
			if (c.sfx)
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			imenu++;
			if (imenu == 8)
				imenu = 0;

			c.tecla = 99;
		}
		else if (c.tecla == 1) {
			if (c.sfx)
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			imenu--;
			if (imenu == -1)
				imenu = 7;

			c.tecla = 99;
		}
		else if (c.tecla == 2) {
			if (c.sfx)
				al_play_sample(c.click, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			if (imenu == 0) {
				c.tecla = 0;
				c.modo = 1;
				break;
			}
			else if (imenu == 1) {
				exibe_menu_tutorial(m, c, i, a);
			}
			else if (imenu == 2) {
				exibe_dificuldade(m, c, i, a);
			}
			else if (imenu == 5) {
				exibe_opcoes(m, c, i, a, false);
			}
			else if (imenu == 6) {
				exibe_menu_creditos(m, c, i, a);
			}
			if (imenu == 7) {
				c.sair = 1;
				break;
			}
		}

		//flecha do menu
		al_draw_scaled_bitmap(c.FOLHA_SETA, 0, 0, al_get_bitmap_width(c.FOLHA_SETA), al_get_bitmap_height(c.FOLHA_SETA),
			x_menu - x_flecha - largura_flecha - 85, y_menu + imenu * menu_inc + y_flecha, largura_flecha, altura_flecha, 0);
		al_draw_scaled_bitmap(c.FOLHA_SETA, 0, 0, al_get_bitmap_width(c.FOLHA_SETA), al_get_bitmap_height(c.FOLHA_SETA),
			x_menu + x_flecha + 85, y_menu + imenu * menu_inc + y_flecha, largura_flecha, altura_flecha, ALLEGRO_FLIP_HORIZONTAL);

		for (int i = 0; i <= tam_menu; i++) {
			if (i == imenu) {
				cor_menu = al_map_rgb(0, 255, 0);
				//al_draw_bitmap(c.FOLHA_SETA, x_menu - 200, y_menu + i * menu_inc - 30, 0);
			}
			else
				cor_menu = al_map_rgb(255, 255, 255);
			al_draw_text(c.fonte_30, cor_menu, x_menu, y_menu + i * menu_inc, ALLEGRO_ALIGN_CENTRE, op_menu[i]);
		}
		al_flip_display();
	}
}

//Exibe a tela de pause, realizando todas suas sub-rotinas necessárias
void pause_mode(mapa &m, controle_ &c, itens_ &i, armazens &a, relogio &r, bool aux) {
	int tam_menu = 5;
	int imenu = -1;
	char op_menu[5][50] = { "CONTINUAR","SALVAR","OPCOES","REINICIAR","SAIR" }; //texto das opcoes do menu
	float y_menu = (3 * ALTURA_TELA / (tam_menu + 3)) + 10;
	float x_menu = LARGURA_TELA / 2;
	float menu_inc = (ALTURA_TELA - y_menu) / tam_menu;
	ALLEGRO_COLOR cor_menu;

	while (!c.sair) {
		mostra_janela(250, 250, c);
		controle_de_tempo_principal(r, c, i, false);
		controle_fun(m, c, i, a, true);
		if (c.tecla == 0) {
			imenu++;
			if (c.sfx)
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			if (imenu == 5)
				imenu = 0;

			c.tecla = 99;
		}
		else if (c.tecla == 1) {
			imenu--;
			if (c.sfx)
				al_play_sample(c.scroll, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			if (imenu == -1)
				imenu = 4;

			c.tecla = 99;
		}
		else if (c.tecla == 2) {
			if (c.sfx)
				al_play_sample(c.click, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			if (imenu == 0) {
				c.modo = 1;
				break;
			}
			else if (imenu == 2) {
				exibe_opcoes(m, c, i, a, true); 
			}
			else if (imenu == 3) {
				reiniciar(m, c, i, r, a);
				break;
			}
			else if (imenu == 4) {
				c.sair = 1;
				break;
			}
		}

		for (int i = 0; i <= tam_menu; i++) {
			if (i == imenu) {
				cor_menu = al_map_rgb(0, 255, 0);
			}				
			else
				cor_menu = al_map_rgb(255, 255, 255);
			al_draw_text(c.fonte_30, cor_menu, x_menu, y_menu + i * menu_inc * 0.4, ALLEGRO_ALIGN_CENTRE, op_menu[i]);
		}
		al_flip_display();
	}
	c.modo = 1;
}

//Reinicia as variaveis necessarias para o jogo voltar a acontecer novamente
void reiniciar(mapa &m, controle_ &c, itens_ &i, relogio &r, armazens &a) {
	int comida = 13;
	for (int i = 0; i < TAMANHO_ARMAZEM_LINHA; i++) {
		a.armazens_comida[i][0] = comida;
		comida--;
	}
	for (int i = 0; i < TAMANHO_ARMAZEM_LINHA; i++) 
		for (int j = 1; j < TAMANHO_ARMAZEM_COLUNA; j++) 
			a.armazens_comida[i][j] = 0;
		

	if (i.dificuldade == 0) 
		i.VELOCIDADE_EVENTO = 60;
	else if (i.dificuldade == 1) 
		i.VELOCIDADE_EVENTO = 40;
	else if (i.dificuldade == 2) 
		i.VELOCIDADE_EVENTO = 20;

	i.pa = 0;
	i.bota = 0;
	i.tocha = 0;
	i.kit = 0;
	i.USOS_PA = 0;
	i.VELOCIDADE_FORMIGA = 200;
	i.USOS_BOTA = 0;
	i.USOS_KIT = 0;
	r.minuto_principal = 0;
	r.segundo_principal = 0;
	r.minuto_pause = 0;
	r.segundo_pause = 0;
	r.tempo_inicial_principal = 0;
	r.tempo_final_principal = 0;
	r.tempo_exe_principal = 0;
	r.tempo_inicial_pause = 0;
	r.tempo_final_pause = 0;
	r.tempo_exe_pause = 0;
	r.tempo_terremoto = 0;
	r.aux_eventos_pause = 0;
	r.exe_eventos_pause = 0;
	r.aux_pause = 0;
	gerador_mapa(m);
	sorteia_formiga(m, c);
	sorteador_itens(i, m);
	sorteia_armazem(m, a);
	c.start = clock();
	r.tempo_inicial_principal = clock();
	c.modo = 1;
}