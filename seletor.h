/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel pelo controle dos mundos do game
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
*/


#ifndef SELETOR_H
#define SELETOR_H

#include "mundos/start.h"
#include "mundos/springbreeze.h"

class SeletorDeMundos
{
	public:
							  SeletorDeMundos		();
						 void desenhaMundo			();
		 				  int getMundoAtual			();
		 forward_list<Objeto> getObjetos			(int idRegiao);
		 forward_list<Objeto> getHitboxes			(int idRegiao);
		 				 void alteraMundo			(int idMundo);
		 				 void houveColisao			(double idMundo, double idRegiao, double modo);
		 				 void verificaScore			();

	private:
						  int mundoAtual;
					    Start start;
				 SpringBreeze mundo1;
};

/*
 *	Inicializa o seletor, escolhendo a tela inicial
 */
SeletorDeMundos::SeletorDeMundos()
{
	mundoAtual = 0;
}



/*
 *	Funcao que desenha o mundo do jogo, de acordo com o valor de mundoAtual
 */
void SeletorDeMundos::desenhaMundo()
{
	switch (mundoAtual)
	{
		case 0:
			start.desenhar();
		break;

		case 1:
			mundo1.desenhar();
		break;
	}
}



/*
 *	Funcao que retorna o mundo que esta sendo desenhado atualmente
 */
int SeletorDeMundos::getMundoAtual()
{
	return mundoAtual;
}



/*
 *	Funcao que retorna a lista de objetos de uma dada regiao do mundo atual
 */
forward_list<Objeto> SeletorDeMundos::getObjetos(int idRegiao)
{
	if (mundoAtual == 1)
	{
		return mundo1.getListaObjetos(idRegiao);
	}

	forward_list<Objeto> nada;
	return nada;
}



/*
 *	Funcao que retorna a lista de objetos de uma dada regiao do mundo atual
 */
forward_list<Objeto> SeletorDeMundos::getHitboxes(int idRegiao)
{
	if (mundoAtual == 1)
	{
		return mundo1.getListaHitboxes(idRegiao);
	}

	forward_list<Objeto> nada;
	return nada;
}



/*
 *	Funcao responsavel por alterar o mundo atual
 */
void SeletorDeMundos::alteraMundo(int idMundo)
{
	mundoAtual = idMundo;

	mundo1 = SpringBreeze();
	player.morte();
	player.resetScore();
}



/*
 *	Funcao que repassa os dados de colisao pro mundo atualmente sendo desenhado
 */
void SeletorDeMundos::houveColisao(double idMundo, double idRegiao, double modo)
{
	forward_list<double> dados;
	dados.push_front(modo);
	dados.push_front(idRegiao);
	dados.push_front(idMundo);

	if (mundoAtual == 1)
	{
		mundo1.setEstadoObjeto(dados);
	}
}



/*
 *	Funcao que verifica se o jogador alcancou o score maximo do mundo atual
 */
void SeletorDeMundos::verificaScore()
{
	if (mundoAtual == 1)
	{
		int scoreKirby  = player.getScore();
		int scoreMundo1 = mundo1.getScoreMaximo();

		if (scoreKirby == scoreMundo1)
		{
			alteraMundo(0);
		}
	}
}

#endif