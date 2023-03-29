/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel pelo controle do desenho do jogador, Kirby
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Modelo: Kirby by Miaru3d - licensed under Creative Commons Attribution
 * Data: 29/03/2023
*/


#ifndef KIRBY_H
#define KIRBY_H

#include <map>

class Kirby
{
	private:
		// Estados de animacao e direcao
		enum animacoes_ids {PAUSADO, IDLE, ANDANDO, PULANDO, ASPIRANDO, CHEIO};
		enum direcoes_ids {FRENTE, ESQUERDA, COSTAS, DIREITA};

		GLManimation *animation = NULL; 		// Ponteiro usado no armazenamento de uma animacao
		map <int, GLManimation *> animations; 	// Mapeamento dos identificadores com as animacoes

		int keyframe       = 0;
		int count_rate     = -1; // Conta a quantidade de repeticoes do keyframe ate atingir keyframe_rate
		int frames_playing = 0;  // Conta a quantidade de quadros da animacao

		double raio = 0.0625;
		double posX =  0.00, rotX = 0;
		double posY = 15.00, rotY = 180;
		double posZ = 10.00, rotZ = 0;

		int vidas = 3;
		int score = 0;

	public:
		bool pulando = false;
		bool estaCheio = false;
		int direcao = FRENTE;
		int animacao_id = IDLE;
		int animacao_atual = IDLE;
		int contadorParado = 0;
		int contadorInvulneravel = 0;

		void	carregaModelo		();
		void	desenhar			();
		void	atualizaKeyframe	();
		void	playAnimation 		(int id);
		void	keyPlayAnimation	(int id);

		void	moveKirby			(double valorX, double valorY, double valorZ);
		void	absorverObjeto		();
		void	perdeVida			();
		void 	morte				();
		void 	incrementaScore		();
		void	resetScore			();

		double	getCoordenadaX		();
		double	getCoordenadaY		();
		double	getCoordenadaZ		();
		int 	getAnimacao			();
		int 	getDirecao			();
		int 	getVidas			();
		int 	getScore			();
};


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
    			switch (direcao)
	    		{
		    		case FRENTE:	glTranslated(posX, posY+1.7, posZ-3.0);		break;
			    	case COSTAS:	glTranslated(posX, posY+1.7, posZ+3.0);		break;
			    	case ESQUERDA:	glTranslated(posX-2.5, posY+1.7, posZ);		break;
			    	case DIREITA:	glTranslated(posX+2.5, posY+1.7, posZ);		break;
    			}
    			glutWireSphere(2.5, 20, 20);
		    glPopMatrix();
	    }
    }

    
    // Atualizacao de estados do modelo do personagem
    atualizaKeyframe();


	// Queda livre do Kirby caso tenha pulado
	if (pause == false && (int) (posY * 100) > 1500)
	{
		posY -= 0.02;
		camY -= 0.0001;
		playAnimation(PULANDO);
		glutPostRedisplay();
	}

	// Decrementa o tempo de invulnerabilidade
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
            keyframe++; 	// Incrementa o keyframe atual
            count_rate = 0; // Reinicia o contador da taxa de keyframes
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
	// Reseta as variaveis de animacao
    keyframe = 0; // Atribui o modelo 3D zero da animacao selecionada para ser desenhado
    frames_playing = 1; // Reinicia a contagem de frames da reproducao da mesma animacao
    count_rate = 0; // Reinicia o contador de repeticoes do mesmo keyframe

    // Redefine a animacao atual
    animacao_id = id;
    animacao_atual = animacao_id;

    // Reinicia o contador parado
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

	if (posY + valorY < 23.00)
	{
		posY += valorY;
	}

	if (posZ + valorZ > -285.00 && posZ + valorZ < 15.00)
	{
		posZ += valorZ;
	}


	// Atualiza a direcao pra onde esta olhando
	if (valorZ < 0)
	{
		direcao = FRENTE;
		rotY = 180.0;
	}
	else if (valorX < 0)
	{
		direcao = ESQUERDA;
		rotY = -90.0;
	}
	else if (valorZ > 0)
	{
		direcao = COSTAS;
		rotY = 0.0;
	}
	else if (valorX > 0)
	{
		direcao = DIREITA;
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
	return direcao;
}


void Kirby::absorverObjeto()
{
	keyPlayAnimation(CHEIO);
}


void Kirby::incrementaScore()
{
	score += 1200;
}


int Kirby::getScore()
{
	return score;
}



void Kirby::resetScore()
{
	score = 0;
}



void Kirby::perdeVida()
{
	if (contadorInvulneravel == 0)
	{
		vidas--;
		contadorInvulneravel = 100;

		if (vidas == 0)
		{
			morte();
		}
	}
}



int Kirby::getVidas()
{
	return vidas;
}



/*
 *	Funcao que redefine valores das variaveis caso Kirby perca suas vidas
 */
void Kirby::morte()
{
	posX =  0.00;
	posY = 15.00;
	posZ = 10.00;
	rotY = 180;
	direcao = FRENTE;
	vidas = 3;

	camX = 0.0;
	camY = 0.0;
	camZ = 1.5;
}



#endif