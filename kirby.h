#ifndef KIRBY_H
#define KIRBY_H



class Kirby
{
	private: // Variaveis
		double movimentoX	= 0.0;
		double movimentoZ	= 0.0;


	public: // Funcoes
		void desenhaKirby	();
		void moveKirby		(double valorX, double valorZ);
		double retornaPosicaoX();
		double retornaPosicaoZ();
};

// Desenha o jogador
void Kirby::desenhaKirby()
{
	printf("Kirby desenhado!\n");
	glPushMatrix();
        glColor3f(1.0, 0.33, 0.33);
        glTranslatef(movimentoX, 0.85, 0.6+movimentoZ);
        //glTranslatef(0.0, 0.8, 0.6);
        glutSolidSphere(0.0625, 20, 20);
	glPopMatrix();
	//printf("%.2f 0.85 %.2f\n", movimentoX, 0.6+movimentoZ);
}

// Movimentacao do jogador
void Kirby::moveKirby(double valorX, double valorZ)
{
	movimentoX += valorX;
	movimentoZ += valorZ;
}

double Kirby::retornaPosicaoX()
{
	//double coordenadas[] = {movimentoX, 0.8, 0.6+movimentoZ};
	//return coordenadas;
	return movimentoX;
}

double Kirby::retornaPosicaoZ()
{
	//double coordenadas[] = {movimentoX, 0.8, 0.6+movimentoZ};
	//return coordenadas;
	return movimentoZ;
}

#endif