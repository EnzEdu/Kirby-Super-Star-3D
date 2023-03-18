#ifndef SPRINGBREEZE_H
#define SPRINGBREEZE_H


//#include "img/grass.h"

class SpringBreeze
{
	private: // Variaveis
		int numRegioes 				= 10;

	public: // Funcoes
		SpringBreeze 				();
		void fase1					();
		void carregaTexturas		();
};

// Inicializador?
SpringBreeze::SpringBreeze() {
	printf("Iniciou?\n");
}

//
void SpringBreeze::carregaTexturas()
{
    /*
     *  Configurando o OpenGL para o uso de Texturas
     */
	/*
	int QUANT_TEX = 1;
	unsigned int id_texturas[QUANT_TEX];

    //Gera nomes identificadores (IDs) para as texturas
    glGenTextures(QUANT_TEX, id_texturas);
    
    //Ativa a textura que sera criada ou usada no momento, por meio do seu ID.
    glBindTexture(GL_TEXTURE_2D, id_texturas[0]);
    
    //Cria a extrutura da textura na mem—ria
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
    
    //Definicao dos parametros da textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    //Define como a textura sera aplicada ao objeto
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, apply_texture);

    //Ativa a visualizacao de texturas 2D (Texturizacao 2D)
    glEnable(GL_TEXTURE_2D);
    
    // Ativa o modelo de sombreamento de "Gouraud" (Smooth
    glShadeModel( GL_SMOOTH );
    // Ativa o z-buffering, de modo a remover as superficies escondidas
    glEnable(GL_DEPTH_TEST);
    // Define a cor de fundo (branco)
    glClearColor(1.0, 1.0, 1.0, 1.0);
    */
}

// Primeira fase?
void SpringBreeze::fase1()
{
	// Cria nome-identificador de texturas
//	const int qntTexturas = 4;
//	unsigned int texturas[qntTexturas];
//	glGenTextures(qntTexturas, texturas);

	// Carrega a textura do chao
//	Imagem loader;
//	unsigned char *chao = loader.carregaImagem("img/grass.png");

//	if (chao)
//	{
		/*
		// Ativa a textura
		glBindTexture(GL_TEXTURE_2D, texturas[0]);

		// Carrega a textura do chao
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, loader.getImgWidth(), loader.getImgHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, chao);


		// Define os parametros da textura
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Como a textura vai ser aplicada
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// Ativa a visualizacao de texturas pelo OpenGL
		glEnable(GL_TEXTURE_2D);

		
		const GLfloat tex_coords[4][3][2] = {
		{{0.5, 0.000}, {0.0, 0.875}, {1.0, 0.875}},
		{{0.5, 0.000}, {0.0, 0.875}, {1.0, 0.875}},
		{{0.0, 0.875}, {1.0, 0.875}, {0.5, 0.000}},
		{{0.5, 0.000}, {1.0, 0.875}, {0.0, 0.875}}
		};
		
		/*
		const GLfloat tex_coords[4][4][2] = {
			{0.0, 0.0},	// Inf esq
			1.0, 0.0,	// Inf dir
			1.0, 1.0,	// Sup dir
			0.0, 1.0 	// Sup esq
		};
		//


		printf("a\n");
		glBegin(GL_TRIANGLES);
		for (int i=0; i<4; i++){
			for (int j=0; j<3; j++){
				glTexCoord2fv(tex_coords[i][j]);
				glNormal3fv(vertex_normals[faces[i][j]]);
				glVertex3fv(vertex_coords[faces[i][j]]);
			}
		}
		glEnd();
		*/
		/*
    	glPushMatrix();

        	// Rotacao 3D
        	glRotatef((GLfloat) rotacaoDDD, 0.0, 1.0, 0.0);

	        glPushMatrix();
    	        //glTranslatef(0.0, -1.90, 0.0);
        	    //glTranslatef(0.0, 0.0, 5.0);
            	//glTranslatef(0.0, -1.6, 5.0);
	            glColor3f(0.33, 0.33, 0.33);
    	        //glutWireCube(1.5);
    	        glutSolidCube(1.5);
        	glPopMatrix();

	    glPopMatrix();
	    */
	    
//	}




	/*
	// Carrega as regioes do mapa conforme posicao do jogador
	int multiplicador = player.verificaRegioes(numRegioes);
	if (multiplicador != -1)
	{
		//printf("multiplicador = %d\n", multiplicador);
		// Regiao de tras

			// Chao
			glPushMatrix();
				glColor3f(0.33, 0.33, 0.33);
				glTranslatef(0.0, 0.0, (-1.5)*(multiplicador-1));
				glutWireCube(1.5);
			glPopMatrix();

			// Parede esquerda
			glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glTranslatef(-1.5, 1.5, (-1.5)*(multiplicador-1));
			glutWireCube(1.5);
			glPopMatrix();

			// Parede direita
			glPushMatrix();
				glColor3f(0.0, 0.0, 1.0);
				glTranslatef(1.5, 1.5, (-1.5)*(multiplicador-1));
				glutWireCube(1.5);
			glPopMatrix();


		// Regiao atual

			// Chao
			glPushMatrix();
				glColor3f(0.33, 0.33, 0.33);
				glTranslatef(0.0, 0.0, (-1.5)*(multiplicador));
				glutWireCube(1.5);
			glPopMatrix();

			// Parede esquerda
			glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glTranslatef(-1.5, 1.5, (-1.5)*(multiplicador));
				glutWireCube(1.5);
			glPopMatrix();

			// Parede direita
			glPushMatrix();
				glColor3f(0.0, 0.0, 1.0);
				glTranslatef(1.5, 1.5, (-1.5)*(multiplicador));
				glutWireCube(1.5);
			glPopMatrix();


		// Regiao da frente

			// Chao
			glPushMatrix();
				glColor3f(0.33, 0.33, 0.33);
				glTranslatef(0.0, 0.0, (-1.5)*(multiplicador+1));
				glutWireCube(1.5);
			glPopMatrix();

			// Parede esquerda
			glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glTranslatef(-1.5, 1.5, (-1.5)*(multiplicador+1));
				glutWireCube(1.5);
			glPopMatrix();

			// Parede direita
			glPushMatrix();
				glColor3f(0.0, 0.0, 1.0);
				glTranslatef(1.5, 1.5, (-1.5)*(multiplicador+1));
				glutWireCube(1.5);
			glPopMatrix();
	}
	*/

















	//for (int i = 0; i < numRegioes; i++)
	for (int i = 0; i < 1; i++)
	{
		int pec = 16;
			// Chao
			glPushMatrix();
				//glScaled(3, 3, 3);
				glColor3f(0.33, 0.33, 0.33);
				glTranslatef(0.0, 0.0, (-1.5)*(i));
				glutWireCube(1.5);
				//glmReadPPM((char*)"./img/grass2.ppm", &pec, &pec);
			glPopMatrix();

			// Parede esquerda
			glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glTranslatef(-1.5, 1.5, (-1.5)*(i));
				glutWireCube(1.5);
			glPopMatrix();

			// Parede direita
			glPushMatrix();
				glColor3f(0.0, 0.0, 1.0);
				glTranslatef(1.5, 1.5, (-1.5)*(i));
				glutWireCube(1.5);
			glPopMatrix();
	}


	// Detecta colisao com o cubo da esquerda?
	//double diferenca[] = {player.getCoordenadaX() - (-1.5), player.getCoordenadaY() - 1.5, player.getCoordenadaZ() - 0};
	//printf("%.2f %.2f %.2f\n", diferenca[0], diferenca[1], diferenca[2]);











	
	//stbi_image_free(chao);
}


#endif