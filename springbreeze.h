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
		void felcos					();
};

// Inicializador?
SpringBreeze::SpringBreeze() {
	//printf("Iniciou?\n");
}

//
void SpringBreeze::carregaTexturas()
{
}

// Primeira fase?
void SpringBreeze::fase1()
{
}

void SpringBreeze::felcos()
{
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
	int numFaces = 6;
	int numVertices = 8;

	// Define os vertices do cubo
	GLfloat coordsVertices[numVertices][3] = {
		// Sentido anti-horario?

		{-0.75, -0.75, -0.75}, // Vertice 0
		{ 0.75, -0.75, -0.75}, // Vertice 1
		{ 0.75, -0.75,  0.75}, // Vertice 2
		{-0.75, -0.75,  0.75}, // Vertice 3

		{-0.75,  0.75, -0.75}, // Vertice 4
		{ 0.75,  0.75, -0.75}, // Vertice 5
		{ 0.75,  0.75,  0.75}, // Vertice 6
		{-0.75,  0.75,  0.75}  // Vertice 7
	};

	// Define as faces do cubo
	GLuint coordsFaces[numFaces][4] = {
		// Faces laterais = sentido anti-horario comecando do vert sup-esq
		{4, 0, 1, 5},	// Face 0
		{5, 1, 2, 6},	// Face 1
		{6, 2, 3, 7},	// Face 2
		{7, 3, 0, 4},	// Face 3

		// Faces horizontais = sentido horario comecando do vert inf-esq
		{0, 3, 2, 1},	// Face 4
		{4, 7, 6, 3}	// Face 5
	};

	// Define as coordenadas de textura do cubo
	GLfloat coordsTextura[numFaces][4][2] = {
		{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}},
		{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}},
		{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}},
		{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}},
		{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}},
		{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}
	};



	for (int i = -1; i < 2; i++)
	{
		// Chao
		glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(0.0, 0.0, -(1.5)*i);
			glBegin(GL_QUADS);
				for (int i = 0; i < numFaces; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						// Define o vertice j da face i
						glTexCoord2fv(coordsTextura[i][j]);
						glVertex3fv(coordsVertices[coordsFaces[i][j]]);
					}
				}
			glEnd();
		glPopMatrix();


		// Parede esquerda
		glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(-1.5, 1.5, -(1.5)*i);
			glBegin(GL_QUADS);
				for (int i = 0; i < numFaces; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						// Define o vertice j da face i
						glTexCoord2fv(coordsTextura[i][j]);
						glVertex3fv(coordsVertices[coordsFaces[i][j]]);
					}
				}
			glEnd();
		glPopMatrix();


		// Parede direita
		glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(1.5, 1.5, -(1.5)*i);
			glBegin(GL_QUADS);
				for (int i = 0; i < numFaces; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						// Define o vertice j da face i
						glTexCoord2fv(coordsTextura[i][j]);
						glVertex3fv(coordsVertices[coordsFaces[i][j]]);
					}
				}
			glEnd();
		glPopMatrix();
	}

}


#endif