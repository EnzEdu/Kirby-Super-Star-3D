#ifndef KIRBY_H
#define KIRBY_H



class Kirby
{
	private: // Variaveis
		double movimentoX			= 0.0;
		double movimentoZ			= 0.0;


	public: // Funcoes
		void   desenhaKirby			();
		void   moveKirby			(double valorX, double valorZ);
		int    verificaRegioes		(int numBlocosMapa);
		double retornaPosicaoX		();
		double retornaPosicaoZ		();
};

// Desenha o jogador
void Kirby::desenhaKirby()
{
	printf("Kirby desenhado!\n");
	glPushMatrix();
        glColor3f(1.0, 0.0, 1.0);
        glTranslatef(movimentoX, 0.85, 0.6+movimentoZ);
        glutSolidSphere(0.0625, 20, 20);
	glPopMatrix();
	printf("%.2f 0.85 %.2f\n", movimentoX, 0.6+movimentoZ);
}

// Movimentacao do jogador
void Kirby::moveKirby(double valorX, double valorZ)
{
	movimentoX += valorX;
	movimentoZ += valorZ;
}

double Kirby::retornaPosicaoX()
{
	return movimentoX;
}

double Kirby::retornaPosicaoZ()
{
	return movimentoZ;
}

// Verifica se o jogador consegue ver outra regiao, alem da regiao em que esta atualmente
// (usado para carregar regioes por demanda)
// abstracao "Regiao" = (Parede esquerda, Chao, Parede direita)
int Kirby::verificaRegioes(int numRegioesMapa)
{
	// Cria uma lista das posicoes no eixo Z que visualizam a regiao de baixo
	double limitesRegiaoBaixo[numRegioesMapa];
	for (int i = 0; i < numRegioesMapa; i++)
	{
		limitesRegiaoBaixo[i] =  0.04 - (1.5 * i);
		printf("%.2f\t", limitesRegiaoBaixo[i]);
	}
	printf("\n");

	// Verifica se a posicao do jogador no eixo Z esta na lista
	for (int i = 0; i < numRegioesMapa; i++)
	{
		if (movimentoZ+0.6 > limitesRegiaoBaixo[i])
		{
			return i;
			break;
		}
	}

	return numRegioesMapa;
}

#endif