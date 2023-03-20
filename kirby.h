#ifndef KIRBY_H
#define KIRBY_H


#include "lib/glm.cpp"
#include <map>

class Kirby
{
	private:
		enum animacoes_ids {PAUSADO, IDLE, ANDANDO, CORRENDO, SUGANDO, PULANDO};
		enum direcao_acam  {FRENTE, COSTAS, ESQUERDA, DIREITA};

		//Numero de faces e vertices do objeto 3D
		int faces = 0;
		int vertices = 0;
		
		int keyframe 				= 0;
		GLuint mode 				= GLM_SMOOTH;		// Modo de sombreamento
		int count_rate = -1; //Conta a quantidade de repeticoes do keyframe ate atingir a taxa keyframe_rate
		int frames_playing = 0; //Conta a quantidade de quadros enquanto reproduz uma mesma animacao ate troca-la

		double raio 				= 0.0625;
		double posX =  0.00, rotX = 0;
		double posY = 15.00, rotY = 180;
		double posZ =  0.60, rotZ = 0;


	public:
		bool pulando = false;
		int animacao_id = IDLE;
		int animacao_atual = IDLE;
		int direcao_id = COSTAS;

		void	carregaModelo		();
		void atualizaKeyframe		();
		void playAnimation 			(int id);
		void keyPlayAnimation		(int id);

		void   desenhaKirby			();
		void   moveKirby			(double valorX, double valorY, double valorZ);
		double getCoordenadaX		();
		double getCoordenadaY		();
		double getCoordenadaZ		();

		int    verificaRegioes		(int numBlocosMapa);
};

GLManimation *animation = NULL;   //Ponteiro usado no armazenamento de uma animacao
map <int, GLManimation *> animations; //Mapeamento dos identificadores com as animacoes


// Carrega o modelo 3D do Kirby
void Kirby::carregaModelo()
{
    /*
     *  Carregando Modelos 3Ds, Texturas e Animacoes
     */
    printf("Loading 3D Models, Textures and Animations");

    animation = glmLoadAnimation("ply/pausado.obj", PAUSADO, 1);
    animation->name = "PAUSADO";
    animations[PAUSADO] = animation;
    faces = animation->models[0]->numtriangles;
    vertices = animation->models[0]->numvertices;
    printf(".");
    
    animation = glmLoadAnimation("ply/anm/idle", IDLE, 30);
    animations[IDLE] = animation;
    printf(".");
	
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
	glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
    	glScaled(0.05, 0.05, 0.05);
        glRotatef(rotX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotY, 0.0f, 1.0f, 0.0f);
        glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
        glTranslated(posX, posY, posZ);
        glmDrawAnimation(animations[animacao_id], keyframe, (GLM_SMOOTH | GLM_TEXTURE));
    glPopMatrix();

	//printf("POSICAO KIRBY = %.2f %.2f %.2f\n", posX, posY, posZ);
    
    atualizaKeyframe();

	// Caso esteja inflado, realiza uma queda livre ate a altura original
	if ((int) (posY * 100) != 1500)
	{
		posY -= 0.001;
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
        

        // Verifica se foi alterada a animacacao atual e reinicia os contadores para a nova animacao
        if (animacao_atual != animacao_id)
        {
        	playAnimation(animacao_id);
        }

        // Se uma animacao diferente de idle ou bored nao for mais reiniciada, reproduz a animacao idle
        else if (animacao_id != IDLE && keyframe >= size && frames_playing >= size)
        {
        	playAnimation(IDLE);
        }

        // Reinicia a mesma animacao
        else if (keyframe >= size)
        {
        	keyframe = 0;
        }
    }
}



/*
 * Coloca para reproduzir a animacao identificada
 */
void Kirby::playAnimation(int id)
{
    keyframe = 0; // atribui o modelo 3D (keyframe) zero da animacao selecionada para ser desenhado
    frames_playing = 1; // reinicia a contagem de frames da reproducao da mesma animacao
    count_rate = 0; // Reinicia o contador de repeticoes do mesmo keyframe
    animacao_id = id; // ativa a animacao com o identificador id
    animacao_atual = animacao_id; // salva qual e a animacao atual
}



/*
 * Reproduz uma animacao acionada por uma tecla
 */
void Kirby::keyPlayAnimation(int id){
    frames_playing = 0;
    animacao_id = id;
    if(id == PULANDO) pulando = true;
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