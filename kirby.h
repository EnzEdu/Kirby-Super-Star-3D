// Kirby by Miaru3d is licensed under Creative Commons Attribution

#ifndef KIRBY_H
#define KIRBY_H

//#include "lib/glm.cpp"
#include <map>

class Kirby
{
	private:
		enum animacoes_ids {PAUSADO, IDLE, ANDANDO, PULANDO, SUGANDO};

		int keyframe 				= 0;
		//GLuint mode 				= GLM_SMOOTH;		// Modo de sombreamento
		int count_rate = -1; //Conta a quantidade de repeticoes do keyframe ate atingir a taxa keyframe_rate
		int frames_playing = 0; //Conta a quantidade de quadros enquanto reproduz uma mesma animacao ate troca-la

		double raio = 0.0625;
		double posX =  0.00, rotX = 0;
		double posY = 15.00, rotY = 180;
		double posZ =  10.00, rotZ = 0;


	public:
		bool pulando = false;
		int animacao_id = IDLE;
		int animacao_atual = IDLE;
		int contadorParado = 0;

		void	carregaModelo		();
		void atualizaKeyframe		();
		void    playAnimation 		(int id);
		void keyPlayAnimation		(int id);

		void   desenhar				();
		void   moveKirby			(double valorX, double valorY, double valorZ);
		void   rotacionaKirby		(double valorY);
		double getCoordenadaX		();
		double getCoordenadaY		();
		double getCoordenadaZ		();
		double getRotacaoY			();

		int    verificaRegioes		(int numBlocosMapa);
};

GLManimation *animation = NULL;   //Ponteiro usado no armazenamento de uma animacao
map <int, GLManimation *> animations; //Mapeamento dos identificadores com as animacoes


// Carrega o modelo 3D do Kirby
void Kirby::carregaModelo()
{
    /*
     *  Carregando Modelo, Textura e Animacoes
     */
    printf("Carregando");
    animation = glmLoadAnimation("player/anm/idle", IDLE, 30);
    animations[IDLE] = animation;
    printf(".");
	
    animation = glmLoadAnimation("player/anm/andando", ANDANDO, 30);
    animations[ANDANDO] = animation;
    printf(".");
    
    animation = glmLoadAnimation("player/anm/pulando/pulando.obj", PULANDO, 1);
    animations[PULANDO] = animation;
    printf(".");
    
    animation = glmLoadAnimation("player/anm/sugando/sugando.obj", SUGANDO, 1);
    animations[SUGANDO] = animation;
    printf(".\n");
}


// Desenha o Kirby
void Kirby::desenhar()
{
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
    glPushMatrix();
	    glColor3f(1.0, 0.0, 1.0);
    	glScaled(0.05, 0.05, 0.05);
    	glTranslated(posX, posY, posZ);
        glRotatef(rotX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotY, 0.0f, 1.0f, 0.0f);
        glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
        glmDrawAnimation(animations[animacao_id], keyframe, GLM_TEXTURE);
    glPopMatrix();

    // Hitbox?
    glPushMatrix();
    	glColor3f(1.0, 0.0, 1.0);
    	glScaled(0.05, 0.05, 0.05);
    	glTranslated(posX, posY+1.7, posZ);
        glutWireSphere(1.3, 20, 20);
    glPopMatrix();

//	printf("POSICAO KIRBY = %.2f %.2f %.2f\n", posX, posY, posZ);
    
    // Atualizacao de estados do modelo do personagem
    atualizaKeyframe();

	// Caso esteja inflado, realiza uma queda livre ate a altura original
	if (pause == false && (int) (posY * 100) > 1500)
	{
		posY -= 0.02;

		playAnimation(PULANDO);
		glutPostRedisplay();
	}
}



/*
 * Funcao que atualiza o keyframe da animacao, com base no FPS e no framerate atual
 */
void Kirby::atualizaKeyframe()
{
	// Verifica se a animacao esta em pausa
    if (pause == false)
    {
    	// Incrementa o contador
    	count_rate++;

    	// Ao atingir a taxa de keyframes
        if (count_rate == KEYFRAME_RATE)
        {
            keyframe++; 	// incrementa o keyframe atual
            count_rate = 0; // reinicia o contador da taxa de keyframes
        }
        
        // Quantidade de frames da animacao atual
        int size = animations[animacao_atual]->keyframes;
        


        // Verifica se foi alterada a animacao atual e reinicia os contadores para a nova animacao
        if (animacao_atual != animacao_id)
        {
        	playAnimation(animacao_id);
        }

        // Contabiliza os segundos em que Kirby nao se movimentou
        else if (animacao_id != IDLE && contadorParado > 1)
        {
        	contadorParado--;
        }

        else if (keyframe >= size && contadorParado == 1)
        {
        	contadorParado--;
        }

        // Reinicia a mesma animacao
        else if (keyframe >= size)
        {
        	keyframe = 0;
        }


        // Coloca Kirby no estado IDLE caso Kirby zere o contador do tempo em que ficou parado
        if (contadorParado == 0)
        {
        	playAnimation(IDLE);
        }
    }
}



/*
 * Coloca para reproduzir a animacao identificada
 */
void Kirby::playAnimation(int id)
{
    keyframe = 0; // Atribui o modelo 3D zero da animacao selecionada para ser desenhado
    frames_playing = 1; // Reinicia a contagem de frames da reproducao da mesma animacao
    count_rate = 0; // Reinicia o contador de repeticoes do mesmo keyframe
    animacao_id = id; // Ativa a animacao com o identificador id
    animacao_atual = animacao_id; // Salva qual e a animacao atual
    contadorParado = animations[animacao_atual]->keyframes;

    // Verifica se Kirby comecou a pular
    if (id == PULANDO)
    {
    	pulando = true;
    }
    else
    {
    	pulando = false;
    }
}



/*
 * Funcao que reproduz uma animacao sem reiniciar os keyframes
 */
void Kirby::keyPlayAnimation(int id)
{
    frames_playing = 0;
    animacao_id = id;
}




/*
 * Funcao de movimentacao do Kirby basesado no incremento das coordenadas
 */
void Kirby::moveKirby(double valorX, double valorY, double valorZ)
{
	// Evoca a animacao de andar
	if ((valorX != 0.0 || valorZ != 0.00) && (pulando == false))
	{
		keyPlayAnimation(ANDANDO);
	}

	// Mantem Kirby dentro do caminho
	if (posX + valorX > -14.00 && posX + valorX < 14.00)
	{
		posX += valorX;
	}

	posY += valorY;
	posZ += valorZ;
}

void Kirby::rotacionaKirby(double valorY)
{
	rotY = valorY;
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

double Kirby::getRotacaoY()
{
	return rotY;
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