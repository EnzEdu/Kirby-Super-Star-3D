#ifndef KIRBY_H
#define KIRBY_H


#include "lib/glm.cpp"
#include <map>

class Kirby
{
	private:
		enum animacoes_ids{PAUSADO, IDLE, ANDANDO, CORRENDO, SUGANDO};
		enum direcao_acam{FRENTE, COSTAS, ESQUERDA, DIREITA};

		//Numero de faces e vertices do objeto 3D
		int faces = 0;
		int vertices = 0;
		
		int keyframe 				= 0;
		GLuint mode 				= GLM_SMOOTH;		// Modo de sombreamento

		double raio 				= 0.0625;
		double posX =  0.00, rotX = 0;
		double posY = 15.00, rotY = 180;
		double posZ =  0.60, rotZ = 0;


	public:
		bool pulando = false;
		int animacao_id = PAUSADO;
		int direcao_id = COSTAS;

		void	carregaModelo();

		void   desenhaKirby			();
		void   moveKirby			(double valorX, double valorY, double valorZ);
		double getCoordenadaX		();
		double getCoordenadaY		();
		double getCoordenadaZ		();

		int    verificaRegioes		(int numBlocosMapa);
};

GLManimation * animation = NULL;   //Ponteiro usado no armazenamento de uma animacao
map <int, GLManimation *> animations; //Mapeamento dos identificadores com as animacoes


// Carrega o modelo 3D do Kirby
void Kirby::carregaModelo()
{
    /*
     *  Carregando Modelos 3Ds, Texturas e Animacoes
     */
    printf("Loading 3D Models, Textures and Animations");
//    animation = glmLoadAnimation("ply/anm/ironman-T-pose.obj", PAUSADO, 1);
//    animation = glmLoadAnimation("ply/anm/pausado/pausado.obj", PAUSADO, 1);
    animation = glmLoadAnimation("ply/pausado.obj", PAUSADO, 1);
    animation->name = "PAUSADO";
    animations[PAUSADO] = animation;
    faces = animation->models[0]->numtriangles;
    vertices = animation->models[0]->numvertices;
    printf(".");
    /*
    animation = glmLoadAnimation("ply/anm/idle", IDLE, 30);
    animations[IDLE] = animation;
    printf(".");
	*/
    animation = glmLoadAnimation("ply/anm/andando", ANDANDO, 30);
    animations[ANDANDO] = animation;
    printf(".");
    /*
    animation = glmLoadAnimation("ply/anm/correndo", CORRENDO, 30);
    animations[CORRENDO] = animation;
    printf(".");

    animation = glmLoadAnimation("ply/anm/sugando", SUGANDO, 30);
    animations[SUGANDO] = animation;
    */
    printf(" done.\n");
}


// Desenha o Kirby
void Kirby::desenhaKirby()
{
	//printf("Kirby desenhado!\n");
	/*
	glPushMatrix();
        glColor3f(1.0, 0.0, 1.0);
        glTranslatef(posX, posY, posZ);
        glutSolidSphere(raio, 20, 20);
	glPopMatrix();
	*/

	glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
    	glScaled(0.05, 0.05, 0.05);
        glRotatef(rotX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotY, 0.0f, 1.0f, 0.0f);
        glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
        glTranslated(posX, posY, posZ);
        //drawAnimation(animation_id, mode);
        glmDrawAnimation(animations[animacao_id], keyframe, (GLM_SMOOTH | GLM_TEXTURE));
    glPopMatrix();

	//printf("POSICAO KIRBY = %.2f %.2f %.2f\n", posX, posY, posZ);

	// Caso esteja inflado, realiza uma queda livre ate a altura original
	if ((int) (posY * 100) != 1500)
	{
		posY -= 0.001;
		glutPostRedisplay();
	}
}



// Funcao que atualiza as coordenadas do Kirby a cada aperto de botao
void Kirby::moveKirby(double valorX, double valorY, double valorZ)
{
	posX += valorX;
	posY += valorY;
	posZ += valorZ;
}


// Funcoes que retornam as coordenadas do Kirby
double Kirby::getCoordenadaX()
{
	return posX;
}

double Kirby::getCoordenadaY()
{
	return posY;
}

double Kirby::getCoordenadaZ()
{
	return posZ;
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
		if (posZ > limitesRegiaoBaixo[i])
		{
			return i;
			break;
		}
	}

	return numRegioesMapa;
}

#endif