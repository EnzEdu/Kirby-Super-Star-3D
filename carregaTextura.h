/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel por carregar as texturas usadas no game
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
*/


#ifndef CARREGAIMAGEM_H
#define CARREGAIMAGEM_H


#include "lib/glm.cpp"

#include "img/telaInicial.h"
#include "img/texturaHUD.h"
#include "img/texturaMundo1.h"
#include "img/texturaInimigo.h"



void carregaTexturas()
{
	// Numero de texturas
	int numTexturas = 3;

	// Instancia ids de textura
	glGenTextures(numTexturas, objetosMapa);

	// Carrega as texturas
	for (int textura = 0; textura < numTexturas; textura++)
	{
		switch (textura)
		{
			case 0:		// Tela inicial
				{
					// Vetor com as cores de cada pixel da textura
    				unsigned char dadosTextura[telaInicialWidth*telaInicialHeight*3];

				    // Extrai os valores RGB de cada pixel a partir de um caractere de informacao
    				// e os salva no vetor
			    	int cont = 0;
	    			for (int i = 0; i < telaInicialWidth*telaInicialHeight; i++)
				    {
    					int corPixel[3];
    					HEADER_PIXEL(header_data_telaInicial, corPixel);

				    	dadosTextura[cont] = corPixel[0];
    					dadosTextura[cont+1] = corPixel[1];
    					dadosTextura[cont+2] = corPixel[2];

				    	cont += 3;
    				}

				    // Ativa a textura que sera criada ou usada no momento, por meio do seu ID
				    glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);

				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    				// Cria a extrutura da textura na memoria
    				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, telaInicialWidth, telaInicialHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, dadosTextura);
    			}
			break;

	    	case 1:		// HUD
	    		{
					// Vetor com as cores de cada pixel da textura
    				unsigned char dadosTextura[hudWidth*hudHeight*3];

				    // Extrai os valores RGB de cada pixel a partir de um caractere de informacao
    				// e os salva no vetor
			    	int cont = 0;
	    			for (int i = 0; i < hudWidth*hudHeight; i++)
				    {
    					int corPixel[3];
    					HEADER_PIXEL(header_data_hud, corPixel);

				    	dadosTextura[cont] = corPixel[0];
    					dadosTextura[cont+1] = corPixel[1];
    					dadosTextura[cont+2] = corPixel[2];

				    	cont += 3;
    				}

				    // Ativa a textura que sera criada ou usada no momento, por meio do seu ID
				    glBindTexture(GL_TEXTURE_2D, objetosMapa[1]);

				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    				// Cria a extrutura da textura na memoria
    				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, hudWidth, hudHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, dadosTextura);
	    		}
	    	break;

			case 2:		// Mundo 1 = SpringBreeze
				{
					// Vetor com as cores de cada pixel da textura
    				unsigned char dadosTextura[springBreezeWidth*springBreezeHeight*3];

				    // Extrai os valores RGB de cada pixel a partir de um caractere de informacao
    				// e os salva no vetor
			    	int cont = 0;
	    			for (int i = 0; i < springBreezeWidth*springBreezeHeight; i++)
				    {
    					int corPixel[3];
    					HEADER_PIXEL(header_data_springBreeze, corPixel);

				    	dadosTextura[cont] = corPixel[0];
    					dadosTextura[cont+1] = corPixel[1];
    					dadosTextura[cont+2] = corPixel[2];

				    	cont += 3;
    				}

				    // Ativa a textura que sera criada ou usada no momento, por meio do seu ID
				    glBindTexture(GL_TEXTURE_2D, objetosMapa[2]);

				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    				// Cria a extrutura da textura na memoria
    				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, springBreezeWidth, springBreezeHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, dadosTextura);
    			}
    		break;

	    	case 3:
	    		{
					// Vetor com as cores de cada pixel da textura
    				unsigned char dadosTextura[inimigoWidth*inimigoHeight*3];

				    // Extrai os valores RGB de cada pixel a partir de um caractere de informacao
    				// e os salva no vetor
			    	int cont = 0;
	    			for (int i = 0; i < inimigoWidth*inimigoHeight; i++)
				    {
    					int corPixel[3];
    					HEADER_PIXEL(header_data_inimigo, corPixel);

				    	dadosTextura[cont] = corPixel[0];
    					dadosTextura[cont+1] = corPixel[1];
    					dadosTextura[cont+2] = corPixel[2];

				    	cont += 3;
    				}

				    // Ativa a textura que sera criada ou usada no momento, por meio do seu ID
				    glBindTexture(GL_TEXTURE_2D, objetosMapa[3]);

				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    				// Cria a extrutura da textura na memoria
    				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, inimigoWidth, inimigoHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, dadosTextura);
	    		}
	    	break;
    	}

    }
}




#endif