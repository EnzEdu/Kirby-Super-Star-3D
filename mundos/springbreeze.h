/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel pelo primeiro mundo do jogo, Spring Breeze
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
*/


#ifndef SPRINGBREEZE_H
#define SPRINGBREEZE_H



class SpringBreeze : public Mundo
{
	public:
							 SpringBreeze 		();
		void 				 desenhar			();
		forward_list<Objeto> getListaObjetos	(int idRegiao);
		forward_list<Objeto> getListaHitboxes	(int idRegiao);
		int 				 getScoreMaximo		();

	private:
		int numRegioes;
		int scoreMaximo = 18000;
};


SpringBreeze::SpringBreeze() {

	// Instancia as regioes do mundo
	pushRegiao(0.0, 0.0,   0.0, 0.000, 0.333, 0.000, 0.500, 0.000, 0.333, 0.500, 1.000);
	pushObjeto('c', 0.3, 0.0, -1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushRegiao(0.0, 0.0,  -1.5, 0.000, 0.333, 0.000, 0.500, 0.000, 0.333, 0.500, 1.000);
	pushObjeto('c', -0.5, 0.0, -1.5, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushObjeto('c',  0.5, 0.2, -2.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushObjeto('c', -0.5, 0.0, -2.5, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushRegiao(0.0, 0.0,  -3.0, 0.000, 0.333, 0.000, 0.500, 0.000, 0.333, 0.500, 1.000);
	pushObjeto('c', -0.4, 0.0, -3.4, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushObjeto('c', -0.1, 0.0, -3.9, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushObjeto('c',  0.5, 0.1, -4.2, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushRegiao(0.0, 0.0,  -4.5, 0.000, 0.333, 0.000, 0.500, 0.000, 0.333, 0.500, 1.000);
	pushObjeto('c', 0.3, 0.0, -5.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushRegiao(0.0, 0.0,  -6.0, 0.000, 0.333, 0.000, 0.500, 0.000, 0.333, 0.500, 1.000);

	pushRegiao(0.0, 0.0,  -7.5, 0.333, 0.666, 0.000, 0.500, 0.334, 0.666, 0.500, 1.000);
	pushObjeto('i',  0.5, 0.0, -7.5, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0);
	pushObjeto('i', -0.5, 0.0, -7.5, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0);
	pushObjeto('i',  0.3, 0.0, -8.6, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0);
	pushRegiao(0.0, 0.0,  -9.0, 0.333, 0.666, 0.000, 0.500, 0.334, 0.666, 0.500, 1.000);
	pushObjeto('i', -0.2, 0.0, -9.3, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0);
	pushObjeto('i',  0.4, 0.0, -9.8, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0);
	pushRegiao(0.0, 0.0, -10.5, 0.333, 0.666, 0.000, 0.500, 0.334, 0.666, 0.500, 1.000);
	pushRegiao(0.0, 0.0, -12.0, 0.333, 0.666, 0.000, 0.500, 0.334, 0.666, 0.500, 1.000);
	pushObjeto('i', 0.0, 0.0, -12.5, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0);
	
	pushRegiao(0.0, 0.0, -13.5, 0.666, 1.000, 0.000, 0.500, 0.334, 0.666, 0.500, 1.000);
	pushObjeto('c',  0.0, 0.2, -13.5, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	pushRegiao(1.5, 0.0, -15.0, 0.666, 1.000, 0.000, 0.500, 0.334, 0.666, 0.500, 1.000);

	// Contabiliza o numero de regioes
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



	/*
	 *	Carregamento Dinamico das Regioes
	 */
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
			// Define o modo de textura
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

			// Seleciona o mapeamento de textura do mapa
			glBindTexture(GL_TEXTURE_2D, objetosMapa[2]);



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
			int idObjeto = 0;
			for (forward_list<Objeto>::iterator o = r->objetos.begin(); o != r->objetos.end(); o++)
			{
				// Desativa a textura
				glBindTexture(GL_TEXTURE_2D, 0);

				glPushMatrix();
					glColor3f(o->corR, o->corG, o->corB);
					glTranslatef(o->coordX, 0.85 + o->coordY, o->coordZ);
					glutSolidCube(0.1);
				glPopMatrix();

				idObjeto++;
			}
		}

		else if (regiaoAtual == listaRegioesCarregadas[2] + 1)
		{
			break;
		}

		regiaoAtual++;
	}
}



/*
 *	Funcao que retorna a lista de objetos de uma regiao
 */
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



/*
 *	Funcao que retorna a lista de hitboxes de uma regiao
 */
forward_list<Objeto> SpringBreeze::getListaHitboxes(int idRegiao)
{
	int regiaoAtual = 0;
	for (forward_list<Regiao>::iterator r = regioes.begin(); r != regioes.end(); r++)
	{
		if (idRegiao == regiaoAtual)
		{
			return r->hitboxes;
		}

		regiaoAtual++;
	}

	forward_list<Objeto> nada;
	return nada;
}



/*
 *	Funcao que retorna o score maximo alcancavel na fase
 */
int SpringBreeze::getScoreMaximo()
{
	return scoreMaximo;
}



#endif