#ifndef SPRINGBREEZE_H
#define SPRINGBREEZE_H

//#include "extras.h"


class SpringBreeze : public Mundo
{
	public:
							 SpringBreeze 		();
		void 				 desenhar			();
		forward_list<Objeto> getListaObjetos	(int idRegiao);

	private:
		int numRegioes;
};

// Inicializador?
SpringBreeze::SpringBreeze() {


	// Instancia as regioes do mundo

		// Cria 10 regioes de campo
/*
			for (int i = 0; i < 5; i++)
			{
				pushRegiao(0.0, 0.0, (-1.5*i), 
						   0.000, 0.333, 0.000, 0.333,
						   0.000, 0.303, 0.503, 1.000);
			}
*/

			pushRegiao(0.0, 0.0, 0.0, 
					   0.000, 0.333, 0.000, 0.333,
					   0.000, 0.303, 0.503, 1.000);
			pushObjeto(true, false, 0.5, 0.0, 0.0, 
				              1.0, 0.0, 1.0,
				              0.0, 0.0, 0.0, 0.0);
			pushObjeto(true, false, -0.5, 0.0, 0.4, 
				              1.0, 0.0, 1.0,
				              0.0, 0.0, 0.0, 0.0);
			pushRegiao(0.0, 0.5, -1.5, 
					   0.000, 0.333, 0.000, 0.333,
					   0.000, 0.303, 0.503, 1.000);

			for (int i = 2; i < 5; i++)
			{
				pushRegiao(0.0, 0.0, (-1.5*i),
						   0.000, 0.333, 0.000, 0.333,
						   0.000, 0.303, 0.503, 1.000);
			}


	//regioes.push();

			numRegioes = distance(regioes.begin(), regioes.end());

	regioes.reverse();
}


void SpringBreeze::desenhar()
{
	// Recupera a coordenada Z do jogador
	float kirbyZ = player.getCoordenadaZ();

	// Identifica a regiao mais distante que o jogador pode observar
	int regiaoMaisDistante = 1;
	for (forward_list<Regiao>::iterator r = regioes.begin(); r != regioes.end(); r++)
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
//	printf("lista = %d %d %d\n", listaRegioesCarregadas[0], listaRegioesCarregadas[1], listaRegioesCarregadas[2]);
//	printf("%.2lf %.2lf\n", camZ, camZ-1.5);


	// Percorre a lista de regioes do mundo
	int regiaoAtual = 0;
	for (forward_list<Regiao>::iterator r = regioes.begin(); r != regioes.end(); r++)
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



			// Carrega as regioes atuais na memoria
			if (regiaoAtual == listaRegioesCarregadas[0])
			{
				objetosMapa[6] = regiaoAtual;
			}
			else if (regiaoAtual == listaRegioesCarregadas[1])
			{
				objetosMapa[7] = regiaoAtual;
			}
			else if (regiaoAtual == listaRegioesCarregadas[2])
			{
				objetosMapa[8] = regiaoAtual;
			}



			// Desenha os objetos da regiao
			for (forward_list<Objeto>::iterator o = r->objetos.begin(); o != r->objetos.end(); o++)
			{
				if (o->desenhar == true)
				{
					if (o->usarTextura == false)
					{
						glBindTexture(GL_TEXTURE_2D, 0);

						glPushMatrix();
							glColor3f(o->corR, o->corG, o->corB);
							glTranslatef(o->coordX, 0.85 + o->coordY, o->coordZ);
							glutSolidCube(0.1);
						glPopMatrix();
					}
				}
			}
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

forward_list<Objeto> SpringBreeze::getListaObjetos(int idRegiao)
{
	int regiaoAtual = 0;
	for (forward_list<Regiao>::iterator r = regioes.begin(); r != regioes.end(); r++)
	{
		if (idRegiao == regiaoAtual)
		{
			return r->objetos;
		}

		regiaoAtual++;
	}

	forward_list<Objeto> nada;
	return nada;
}

#endif