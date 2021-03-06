/*
Integrantes: Herikc Brecher, Alecsandra Tomasi e Wesley Martins

Instituição: Universidade do Vale do Itajaí

Link Repositório GitHub: https://github.com/Herikc2/FormigaM3.1.git

TRABALHO M3.1
*/

#pragma once

#include <stdio.h>
#include <iostream>
#include "sstream"
#include "string"
#include "time.h"
#include "stdlib.h"
#include <windows.h>
#include "libMapa.h"
#include "Grafico.h"
#include "Tempo.h"
#include "Armazem.h"
#include "Formiga.h"
#include "Itens.h"
#include "telas.h"
#include "SubControle.h"


int main() {
	mapa m;
	controle_ c;
	itens_ i;
	relogio r;
	armazens a;

	//Inicialização Básica de Comandos e Ocultação de Console
	Stealth();
	pre(m, c, a);

	//Motor do Jogo, será o looping onde todo o jogo irá acontecer.
	while (!c.sair) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		if (c.modo == 0) { //Menu
			preMenu(m, c, i, a, r);
		}
		if (c.modo == 1) { //Jogar
			if (preJogar(m, c, i, a, r)) {
				c.modo = 3;
			}			
		}
		if (c.modo == 2) { //Pause
			prePause(m, c, i, a, r);
		}
		if (c.modo == 3) { //Vitória
			preVitoria(m, c, i, a, r);
			break;
		}
		al_flip_display();
	}
	finalizacao(m, c, i, a, r);
	system("Pause");
	return 0;
}