#ifndef HUD_H
#define HUD_H

#include "lib/glut_text.h"

class HUD
{
	private: // Variaveis
		char   poder				= '_';


	public: // Funcoes
		HUD 						();
		void   desenhaHUD			();
};


// Desenha o Kirby
HUD::HUD()
{
	//
}

void HUD::desenhaHUD()
{
	// Escreve as informacoes no espaco do HUD
    glDisable(GL_TEXTURE_2D);
    glColor3f(0.0, 0.0, 0.0);
    draw_text_stroke(85, 70, "Score: " + to_string(player.getScore()), 0.15);
    draw_text_stroke(85, 45, "Vidas: " + to_string(player.getVidas()), 0.15);

    draw_text_stroke(width - 145, 70, "Camera: ", 0.15);
    draw_text_stroke(width - 145, 45, to_string(camX).substr(0, 5), 0.10);
    draw_text_stroke(width - 145, 30, to_string(camY).substr(0, 5), 0.10);
    draw_text_stroke(width - 145, 15, to_string(camZ).substr(0, 5), 0.10);
    glEnable(GL_TEXTURE_2D);




	// Define as coordenadas do HUD
	// 4 = num de vertices, 2 = coordenadas xy
	GLfloat coordsVerticesHUD[4][2] = {
		{               0,    0},	// Vertice 0
		{ (GLfloat) width,    0},	// Vertice 1
		{ (GLfloat) width,  100},	// Vertice 2
		{               0,  100},	// Vertice 3
	};

	// Define a face do HUD
	// 4 = num de vertices da unica face de um quadrado
	GLuint facesHUD[4] = {
		0, 1, 2, 3
	};

	// Define as coordenadas de textura do HUD
	// 4 = num de vertices, 2 = coordenadas na textura de cada vertice
	GLfloat coordsTexturaHUD[4][2] = {
		{0.00, 0.00}, {0.00, 1.00}, {1.00, 1.00}, {1.00, 0.00}
	};


	// Define o modo de textura
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Seleciona o mapeamento de textura do mapa
	glBindTexture(GL_TEXTURE_2D, objetosMapa[1]);	
	
	// Desenha o HUD
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