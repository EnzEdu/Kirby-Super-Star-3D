/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel pela tela inicial do game
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
*/


#ifndef START_H
#define START_H

#include "extras.h"


class Start : public Mundo
{
	public:
		void desenhar				();

	private:
		int numRegioes;
};

void Start::desenhar()
{
	// Define as coordenadas da tela de start
	// 4 = num de vertices, 2 = coordenadas xy
	GLfloat coordsVerticesHUD[4][2] = {
		{               0, 				  0},	// Vertice 0
		{ (GLfloat) width, 				  0},	// Vertice 1
		{ (GLfloat) width, (GLfloat) height},	// Vertice 2
		{               0, (GLfloat) height},	// Vertice 3
	};

	// Define a face da tela de start
	// 4 = num de vertices da unica face de um quadrado
	GLuint facesHUD[4] = {
		0, 1, 2, 3
	};

	// Define as coordenadas de textura da tela de start
	// 4 = num de vertices, 2 = coordenadas na textura de cada vertice
	GLfloat coordsTexturaHUD[4][2] = {
		{1.00, 1.00}, {0.00, 1.00}, {0.00, 0.00}, {1.00, 0.00}
	};



	// Define o modo de textura
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Seleciona o mapeamento de textura do mapa
	glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);	
	
	// Desenha a tela
	glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        for (int i=0; i<1; i++){
            for (int j=0; j<4; j++){
               /* Define o vertice j da face i */
               glTexCoord2fv(coordsTexturaHUD[j]);
               glVertex2fv(coordsVerticesHUD[facesHUD[j]]);
            }
        }
    glEnd();
}

#endif