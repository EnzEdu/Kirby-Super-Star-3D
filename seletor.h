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
		 				 void houveColisao			(int idRegiao, int idObjeto);

	private:
					    Start start;
				 SpringBreeze mundo1;

						  int mundoAtual;
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
			start.desenhar();
		break;

		case 1:
			mundo1.desenhar();
		break;
	}
}


int SeletorDeMundos::getMundoAtual()
{
	return mundoAtual;
}


forward_list<Objeto> SeletorDeMundos::getObjetos(int idRegiao)
{
	if (mundoAtual == 1)
	{
		return mundo1.getListaObjetos(idRegiao);
	}

	forward_list<Objeto> nada;
	return nada;
}

void SeletorDeMundos::houveColisao(int idRegiao, int idObjeto)
{
	forward_list<int> dados;
	dados.push_front(idObjeto);
	dados.push_front(idRegiao);
	
	if (mundoAtual == 1)
	{
		mundo1.setEstadoObjeto(dados);
	}
}

#endif