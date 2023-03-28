// Kirby by Miaru3d is licensed under Creative Commons Attribution

#ifndef KIRBY_H
#define KIRBY_H

//#include "lib/glm.cpp"
#include <map>

class Kirby
{
	private:
		enum animacoes_ids {PAUSADO, IDLE, ANDANDO, PULANDO, ASPIRANDO, CHEIO};
		enum direcoes_ids {FRENTE, ESQUERDA, COSTAS, DIREITA};

		int keyframe 				= 0;
		//GLuint mode 				= GLM_SMOOTH;		// Modo de sombreamento
		int count_rate = -1; //Conta a quantidade de repeticoes do keyframe ate atingir a taxa keyframe_rate
		int frames_playing = 0; //Conta a quantidade de quadros enquanto reproduz uma mesma animacao ate troca-la

		double raio = 0.0625;
		double posX =  0.00, rotX = 0;
		double posY = 15.00, rotY = 180;
		double posZ = 10.00, rotZ = 0;

		int vidas = 3;
		int score = 0;
		Objeto boca;

	public:
		bool pulando = false;
		bool estaCheio = false;
		int olhando = FRENTE;
		int animacao_id = IDLE;
		int animacao_atual = IDLE;
		int contadorParado = 0;
		int contadorInvulneravel = 0;


		void	carregaModelo		();
		void	atualizaKeyframe	();
		void	playAnimation 		(int id);
		void	keyPlayAnimation	(int id);

		void	desenhar			();
		void	moveKirby			(double valorX, double valorY, double valorZ);
		void 	incrementaScore		();
		void	absorverObjeto		(Objeto obj);
		void 	soltarObjeto		();
		void	perdeVida			();
		void 	reset				();
		double	getCoordenadaX		();
		double	getCoordenadaY		();
		double	getCoordenadaZ		();
		int 	getAnimacao			();
		int 	getDirecao			();
		int 	getVidas			();
		int 	getScore			();
};

GLManimation *animation = NULL;   // Ponteiro usado no armazenamento de uma animacao
map <int, GLManimation *> animations; // Mapeamento dos identificadores com as animacoes


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
    
    animation = glmLoadAnimation("player/anm/aspirando/aspirando.obj", ASPIRANDO, 1);
    animations[ASPIRANDO] = animation;
    printf(".");

    animation = glmLoadAnimation("player/anm/cheio/cheio.obj", CHEIO, 1);
    animations[CHEIO] = animation;
    printf(".\n");
}


// Desenha o Kirby
void Kirby::desenhar()
{
	// Situacao usual
	if (contadorInvulneravel == 0)
	{
		// Define o modo de textura
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
    }

    // Recebimento de dano
    else
    {
    	// Define o modo de textura
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
	
	    glPushMatrix();

	    	// Kirby mudando de cor frame a frame
		    if (contadorInvulneravel % 2 == 0)
		    {
			    glColor3f(1.0, 0.0, 0.0);
			}
			else
			{
				glColor3f(0.0, 0.0, 1.0);
			}

    		glScaled(0.05, 0.05, 0.05);
	    	glTranslated(posX, posY, posZ);
    	    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
        	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	        glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    	    glmDrawAnimation(animations[animacao_id], keyframe, GLM_TEXTURE);
    	glPopMatrix();
    }

    if (hitbox == true)
    {
    	// Hitbox do Kirby
	    glPushMatrix();
    		glColor3f(1.0, 0.0, 1.0);
    		glScaled(0.05, 0.05, 0.05);
	    	glTranslated(posX, posY+1.7, posZ);
    	    glutWireSphere(1.3, 20, 20);
    	glPopMatrix();

    	// Hitbox do ar aspirado
	    if (animacao_id == ASPIRANDO)
    	{
	    	glPushMatrix();
    			glColor3f(1.0, 1.0, 1.0);
    			glScaled(0.05, 0.05, 0.05);
    			switch (olhando)
	    		{
		    		case FRENTE:	glTranslated(posX, posY+1.7, posZ-3.0);		break;
			    	case COSTAS:	glTranslated(posX, posY+1.7, posZ+3.0);		break;
			    	case ESQUERDA:	glTranslated(posX-2.5, posY+1.7, posZ);		break;
			    	case DIREITA:	glTranslated(posX+2.5, posY+1.7, posZ);		break;
    			}
    		    glutWireCube(2.5);
		    glPopMatrix();
	    }
    }

//	printf("POSICAO KIRBY = %.2f %.2f %.2f\n", posX, posY, posZ);
    
    // Atualizacao de estados do modelo do personagem
    atualizaKeyframe();

	// Caso esteja inflado, realiza uma queda livre ate a altura original
	if (pause == false && (int) (posY * 100) > 1500)
	{
		posY -= 0.02;
		camY -= 0.0025;
		playAnimation(PULANDO);
		glutPostRedisplay();
	}

	//
	if (contadorInvulneravel != 0)
	{
		contadorInvulneravel--;
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


	// Atualiza a direcao pra onde esta olhando
	if (valorZ < 0)
	{
		olhando = FRENTE;
		rotY = 180.0;
	}
	else if (valorX < 0)
	{
		olhando = ESQUERDA;
		rotY = -90.0;
	}
	else if (valorZ > 0)
	{
		olhando = COSTAS;
		rotY = 0.0;
	}
	else if (valorX > 0)
	{
		olhando = DIREITA;
		rotY = 90.0;
	}
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

int Kirby::getAnimacao()
{
	return animacao_id;
}

int Kirby::getDirecao()
{
	return olhando;
}


void Kirby::absorverObjeto(Objeto obj)
{
	keyPlayAnimation(CHEIO);
//	if (obj.tipo ==)
	printf("%.2lf\n", obj.coordX);
}


void Kirby::soltarObjeto()
{
	/*
		glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
    		glScaled(0.05, 0.05, 0.05);
    		switch (olhando)
    		{
		    	case FRENTE:	glTranslated(posX, posY+1.7, posZ-3.0);		break;
		    	case COSTAS:	glTranslated(posX, posY+1.7, posZ+3.0);		break;
		    	case ESQUERDA:	glTranslated(posX-2.5, posY+1.7, posZ);		break;
		    	case DIREITA:	glTranslated(posX+2.5, posY+1.7, posZ);		break;
    		}
    	    //glutWireCube(2.5);
			glutSolidCube(0.1);
		glPopMatrix();
		*/
	//estaCheio = false;

}


void Kirby::incrementaScore()
{
	score += 1200;
}


int Kirby::getScore()
{
	return score;
}


void Kirby::perdeVida()
{
	if (contadorInvulneravel == 0)
	{
		vidas--;
		contadorInvulneravel = 100;

		if (vidas == 0)
		{
			reset();
		}
	}
}

int Kirby::getVidas()
{
	return vidas;
}

void Kirby::reset()
{
	posX =  0.00;
	posY = 15.00;
	posZ = 10.00;
	rotY = 180;
	olhando = FRENTE;
	vidas = 3;

	camX = 0.0;
	camY = 0.0;
	camZ = 1.5;
}

#endif