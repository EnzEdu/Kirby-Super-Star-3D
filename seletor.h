#ifndef SELETOR_H
#define SELETOR_H


#include "fases/springbreeze.h"

class SeletorDeFases
{
	public:
				SeletorDeFases();
		void	desenhaFase();

	private:
		int faseAtual;

		// Fases
		SpringBreeze fase1;
};

/*
 *	Construtor da classe
 */
SeletorDeFases::SeletorDeFases()
{
	// Inicializa o id da fase atual
	faseAtual = 1;		// Eh pra ser 0
}

/*
 *	Funcao que desenha a fase do jogo, de acordo com o valor de
 *	faseAtual
 */
void SeletorDeFases::desenhaFase()
{
	switch (faseAtual)
	{
		case 0:
			//menu.desenhar();
		break;

		case 1:
			fase1.desenhar();
		break;
	}
}

#endif