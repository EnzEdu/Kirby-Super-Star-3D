#ifndef SPRINGBREEZE_H
#define SPRINGBREEZE_H


//#include "img/grass.h"
#include "extras.h"


class SpringBreeze : public Mundo
{
	public:
		SpringBreeze 				();
		void desenhar				();

	private:
		int numRegioes;
};

// Inicializador?
SpringBreeze::SpringBreeze() {


	// Instancia as regioes do mundo

		// Cria 10 regioes de campo
			for (int i = 0; i < 5; i++)
			{
				pushRegiao(0.0, 0.0, (-1.5*i), 
						   0.000, 0.333, 0.000, 0.333,
						   0.000, 0.303, 0.503, 1.000);
			}
/*
			pushRegiao(0.0, 0.0, 0.0, 
					   0.000, 0.333, 0.000, 0.333,
					   0.000, 0.303, 0.503, 1.000);
			pushRegiao(0.0, 0.0, -1.5, 
					   0.000, 0.333, 3.333, 0.333,
					   0.000, 0.303, 0.503, 1.000);
			pushRegiao(0.0, 0.0, -3.0, 
					   0.000, 1.0, 0.0, 1.0,
					   0.000, 0.303, 0.503, 1.000);
			pushRegiao(0.0, 0.0, -4.5, 
					   0.000, 1.0, 0.0, 1.0,
					   0.000, 0.303, 0.503, 1.000);
			pushRegiao(0.0, 0.0, -6.0, 
					   0.000, 1.0, 0.0, 1.0,
					   0.000, 0.303, 0.503, 1.000);
*/
	//regioes.push();

			numRegioes = distance(regioes.begin(), regioes.end());

	regioes.reverse();
}


void SpringBreeze::desenhar()
{
//		int numVerticesCubo = 8;
//	int numFacesCubo = 6;
	/*
	// Versao sem textura
	for (int i = 0; i < 2; i++)
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
	*/

	// Variaveis de um cubo
	/*
	int numFaces = 6;
	int numVertices = 8;

	// Define os vertices do cubo
	GLfloat coordsVertices[numVertices][3] = {
		{-0.75, -0.75,  0.75},	// Vertice 0
		{ 0.75, -0.75,  0.75},	// Vertice 1
		{ 0.75, -0.75, -0.75},	// Vertice 2
		{-0.75, -0.75, -0.75},	// Vertice 3

		{-0.75,  0.75,  0.75},	// Vertice 4
		{ 0.75,  0.75,  0.75},	// Vertice 5
		{ 0.75,  0.75, -0.75},	// Vertice 6
		{-0.75,  0.75, -0.75} 	// Vertice 7
	};

	// Define as faces do cubo
	GLuint coordsFaces[numFaces][4] = {
		// Faces laterais
		{4, 0, 1, 5},	// Face 0 (frente)
		{5, 1, 2, 6},	// Face 1 (direita)
		{6, 2, 3, 7},	// Face 2 (costas)
		{7, 3, 0, 4},	// Face 3 (esquerda)

		// Faces horizontais
		{0, 3, 2, 1},	// Face 4 (inferior)
		{4, 5, 6, 7}	// Face 5 (superior)
	};
	

	int numFacesCubo = 6;
	int numVerticesCubo = 8;


	// Coordenadas de texturas
	GLfloat coordsTexturaChaoUm[numFacesCubo][4][2] = {
		// Faces laterais
		{{0.0, 0.0}, {0.0, 0.333}, {0.333, 0.333}, {0.333, 0.0}},	// Face 0 (frente)
		{{0.0, 0.0}, {0.0, 0.333}, {0.333, 0.333}, {0.333, 0.0}},	// Face 1 (direita)
		{{0.0, 0.0}, {0.0, 0.333}, {0.333, 0.333}, {0.333, 0.0}},	// Face 2 (costas)
		{{0.0, 0.0}, {0.0, 0.333}, {0.333, 0.333}, {0.333, 0.0}},	// Face 3 (esquerda)

		// Faces horizontais
		{{0.0, 0.333}, {0.0, 0.0}, {0.333, 0.0}, {0.333, 0.333}},	// Face 4 (inferior)
		{{0.0, 0.333}, {0.333, 0.333}, {0.333, 0.0}, {0.0, 0.0}}	// Face 5 (superior)
	};

	GLfloat coordsTexturaPaisagemUm[numFacesCubo][4][2] = {
		// Faces laterais
		{{0.0, 0.503}, {0.0, 1.0}, {0.303, 1.0}, {0.303, 0.503}},	// Face 0 (frente)
		{{0.0, 0.503}, {0.0, 1.0}, {0.303, 1.0}, {0.303, 0.503}},	// Face 1 (direita)
		{{0.0, 0.503}, {0.0, 1.0}, {0.303, 1.0}, {0.303, 0.503}},	// Face 2 (costas)
		{{0.0, 0.503}, {0.0, 1.0}, {0.303, 1.0}, {0.303, 0.503}},	// Face 3 (esquerda)

		// Faces horizontais
		{{0.0, 1.0}, {0.0, 0.503}, {0.303, 0.503}, {0.303, 1.0}},	// Face 4 (inferior)
		{{0.0, 1.0}, {0.303, 1.0}, {0.303, 0.503}, {0.0, 0.503}}	// Face 5 (superior)
	};
	*/

	// Recupera a coordenada Z do jogador
	float kirbyZ = player.getCoordenadaZ();

	// Identifica a regiao mais distante que o jogador pode observar
	int regiaoMaisDistante = 1;
	for (forward_list<regiao>::iterator r = regioes.begin(); r != regioes.end(); r++)
	{
		if (kirbyZ > -9.50 + -30*(regiaoMaisDistante-1))
		{
			break;
		}

		regiaoMaisDistante++;
	}

	// Cria a lista de regioes a serem carregadas
	int listaRegioesCarregadas[3];
	if (regiaoMaisDistante < 3)
	{
		// Caso o jogador esteja entre as regioes 0 e 2 (inicio)
		listaRegioesCarregadas[0] = 0;
		listaRegioesCarregadas[1] = 1;
		listaRegioesCarregadas[2] = 2;
	}
	else if (regiaoMaisDistante == numRegioes)
	{
		// Caso o jogador esteja na ultima regiao
		listaRegioesCarregadas[0] = regiaoMaisDistante-2;
		listaRegioesCarregadas[1] = regiaoMaisDistante-1;
		listaRegioesCarregadas[2] = regiaoMaisDistante;
	}
	else
	{
		listaRegioesCarregadas[0] = regiaoMaisDistante-2;
		listaRegioesCarregadas[1] = regiaoMaisDistante-1;
		listaRegioesCarregadas[2] = regiaoMaisDistante;
	}

//	printf("kirbyY = %.2lf\tkirbyZ = %.2lf\tregiaoMaisDistante = %d\n", player.getCoordenadaY(), player.getCoordenadaZ(), regiaoMaisDistante);
	printf("lista = %d %d %d\n", listaRegioesCarregadas[0], listaRegioesCarregadas[1], listaRegioesCarregadas[2]);
//	printf("%.2lf %.2lf\n", camZ, camZ-1.5);


	// Percorre a lista de regioes do mundo
	int regiaoAtual = 0;
	for (forward_list<regiao>::iterator r = regioes.begin(); r != regioes.end(); r++)
	{
		/* 
		 * Desenha apenas tres regioes na tela:
		 *   - A regiao mais distante que o jogador consegue ver
		 *   - As duas regioes que a antecedem (o jogador esta em uma delas)
		 * (garante o carregamento dinamico das regioes, transparente ao jogador)
		 *
		 */
		if (regiaoAtual == listaRegioesCarregadas[0] ||
			regiaoAtual == listaRegioesCarregadas[1] ||
			regiaoAtual == listaRegioesCarregadas[2])
		{
		
		//if (1+1 == 2) {
			// Seleciona o mapeamento de textura do mapa
			glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);



			// Define as coordenadas de textura do chao
			GLfloat coordsTexturaChao[6][4][2] = 
			{
				// Faces laterais (frente, direita, costas, esquerda)
				{{r->chTexX1, r->chTexY1}, {r->chTexX1, r->chTexY2}, {r->chTexX2, r->chTexY2}, {r->chTexX2, r->chTexY1}},
				{{r->chTexX1, r->chTexY1}, {r->chTexX1, r->chTexY2}, {r->chTexX2, r->chTexY2}, {r->chTexX2, r->chTexY1}},
				{{r->chTexX1, r->chTexY1}, {r->chTexX1, r->chTexY2}, {r->chTexX2, r->chTexY2}, {r->chTexX2, r->chTexY1}},
				{{r->chTexX1, r->chTexY1}, {r->chTexX1, r->chTexY2}, {r->chTexX2, r->chTexY2}, {r->chTexX2, r->chTexY1}},

				// Faces horizontais (inferior, superior)
				{{r->chTexX1, r->chTexY2}, {r->chTexX1, r->chTexY1}, {r->chTexX2, r->chTexY1}, {r->chTexX2, r->chTexY2}},
				{{r->chTexX1, r->chTexY2}, {r->chTexX2, r->chTexY2}, {r->chTexX2, r->chTexY1}, {r->chTexX1, r->chTexY1}}
			};

			// Desenha o chao
			glPushMatrix();
				glTranslatef(r->chCoordX, r->chCoordY, r->chCoordZ);
				glBegin(GL_QUADS);
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							// Associa as coordenadas da textura do vertice j
							glTexCoord2fv(coordsTexturaChao[i][j]);

							// Desenha o vertice j da face i
							glVertex3fv(coordsVertices[coordsFaces[i][j]]);
						}
					}
				glEnd();
			glPopMatrix();



			// Define as coordenadas de textura das paredes
			GLfloat coordsTexturaParedes[6][4][2] = 
			{
				// Faces laterais (frente, direita, costas, esquerda)
				{{r->paTexX1, r->paTexY1}, {r->paTexX1, r->paTexY2}, {r->paTexX2, r->paTexY2}, {r->paTexX2, r->paTexY1}},
				{{r->paTexX1, r->paTexY1}, {r->paTexX1, r->paTexY2}, {r->paTexX2, r->paTexY2}, {r->paTexX2, r->paTexY1}},
				{{r->paTexX1, r->paTexY1}, {r->paTexX1, r->paTexY2}, {r->paTexX2, r->paTexY2}, {r->paTexX2, r->paTexY1}},
				{{r->paTexX1, r->paTexY1}, {r->paTexX1, r->paTexY2}, {r->paTexX2, r->paTexY2}, {r->paTexX2, r->paTexY1}},

				// Faces horizontais (inferior, superior)
				{{r->paTexX1, r->paTexY2}, {r->paTexX1, r->paTexY1}, {r->paTexX2, r->paTexY1}, {r->paTexX2, r->paTexY2}},
				{{r->paTexX1, r->paTexY2}, {r->paTexX2, r->paTexY2}, {r->paTexX2, r->paTexY1}, {r->paTexX1, r->paTexY1}}
			};


			// Desenha a parede esquerda
			glPushMatrix();
				glTranslatef(r->chCoordX - 1.5, r->chCoordY + 1.5, r->chCoordZ);
				glBegin(GL_QUADS);
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							// Associa as coordenadas da textura do vertice j
							glTexCoord2fv(coordsTexturaParedes[i][j]);

							// Desenha o vertice j da face i
							glVertex3fv(coordsVertices[coordsFaces[i][j]]);
						}
					}
				glEnd();
			glPopMatrix();


			// Desenha a parede direita
			glPushMatrix();
				glTranslatef(r->chCoordX + 1.5, r->chCoordY + 1.5, r->chCoordZ);
				glBegin(GL_QUADS);
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							// Associa as coordenadas da textura do vertice j
							glTexCoord2fv(coordsTexturaParedes[i][j]);

							// Desenha o vertice j da face i
							glVertex3fv(coordsVertices[coordsFaces[i][j]]);
						}
					}
				glEnd();
			glPopMatrix();
		}

		else if (regiaoAtual == listaRegioesCarregadas[2] + 1)
		{
			break;
		}

		regiaoAtual++;
	}


	/*
	for (int i = 0; i < numRegioes; i++)
	{
		// Chao
		glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(0.0, 0.0, -(1.5)*i);
			glBegin(GL_QUADS);
				for (int i = 0; i < numFacesCubo; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						// Define o vertice j da face i
						glTexCoord2fv(coordsTexturaChaoUm[i][j]);
						glVertex3fv(coordsVertices[coordsFaces[i][j]]);
					}
				}
			glEnd();
		glPopMatrix();

		
		// Parede esquerda
		glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(-1.5, 1.5, -(1.5)*i - (0.001*i));
			glBegin(GL_QUADS);
				for (int i = 0; i < numFacesCubo; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						// Define o vertice j da face i
						glTexCoord2fv(coordsTexturaPaisagemUm[i][j]);
						glVertex3fv(coordsVertices[coordsFaces[i][j]]);
					}
				}
			glEnd();
		glPopMatrix();

		
		// Parede direita
		glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(1.5, 1.5, -(1.5)*i - (0.001*i));
			glBegin(GL_QUADS);
				for (int i = 0; i < numFacesCubo; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						// Define o vertice j da face i
						glTexCoord2fv(coordsTexturaPaisagemUm[i][j]);
						glVertex3fv(coordsVertices[coordsFaces[i][j]]);
					}
				}
			glEnd();
		glPopMatrix();
	}
	*/
}


#endif