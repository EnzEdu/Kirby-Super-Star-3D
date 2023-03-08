#ifndef KIRBY_H
#define KIRBY_H



class Kirby
{
	private: // Variaveis
		double raio 				= 0.0625;
		double coordX 				= 0.00;
		double coordY 				= 0.82;
		double coordZ 				= 0.60;


	public: // Funcoes
		void   desenhaKirby			();
		void   moveKirby			(double valorX, double valorY, double valorZ);
		double getCoordenadaX		();
		double getCoordenadaY		();
		double getCoordenadaZ		();

		int    verificaRegioes		(int numBlocosMapa);
};


// Desenha o Kirby
void Kirby::desenhaKirby()
{
	//printf("Kirby desenhado!\n");
	glPushMatrix();
        glColor3f(1.0, 0.0, 1.0);
        glTranslatef(coordX, coordY, coordZ);
        glutSolidSphere(raio, 20, 20);
	glPopMatrix();

	//printf("POSICAO KIRBY = %.2f %.2f %.2f\n", coordX, coordY, coordZ);

	// Caso esteja inflado, realiza uma queda livre ate a altura original
	if ((int) (coordY * 100) != 82)
	{
		coordY -= 0.001;
		glutPostRedisplay();
	}
}



// Funcao que atualiza as coordenadas do Kirby a cada aperto de botao
void Kirby::moveKirby(double valorX, double valorY, double valorZ)
{
	coordX += valorX;
	coordY += valorY;
	coordZ += valorZ;
}


// Funcoes que retornam as coordenadas do Kirby
double Kirby::getCoordenadaX()
{
	return coordX;
}

double Kirby::getCoordenadaY()
{
	return coordY;
}

double Kirby::getCoordenadaZ()
{
	return coordZ;
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
		if (coordZ > limitesRegiaoBaixo[i])
		{
			return i;
			break;
		}
	}

	return numRegioesMapa;
}

#endif