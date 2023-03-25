#ifndef SELETOR_H
#define SELETOR_H


#include "mundos/springbreeze.h"

class SeletorDeMundos
{
	public:
				SeletorDeMundos();
		void	desenhaMundo();

	private:
		int mundoAtual;

		// Fases
		SpringBreeze mundo1;
};

/*
 *	Construtor da classe
 */
SeletorDeMundos::SeletorDeMundos()
{
	// Inicializa o id da mundo atual
	mundoAtual = 1;		// Eh pra ser 0
}

/*
 *	Funcao que desenha o mundo do jogo, de acordo com o valor de
 *	mundoAtual
 */
void SeletorDeMundos::desenhaMundo()
{
	switch (mundoAtual)
	{
		case 0:
			//menu.desenhar();
		break;

		case 1:
			mundo1.desenhar();
		break;
	}
}

#endif