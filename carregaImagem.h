#ifndef CARREGAIMAGEM_H
#define CARREGAIMAGEM_H


//#include "lib/glm.cpp"
//#include "img/grass.h"
//#include "grass.h"


void carregaImagem()
{
	// Define as coordenadas da imagem na tela
	//glRaster2d(0.0, 0.0);

	// Define o zoom na imagem?
	//glPixelZoom(zoom, zoom);
	//glPixelZoom(7, 7);

	// Desenha a imagem
	//glDrawPixels(TEXTURE_WIDTH, TEXTURE_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, texture_data);

	//glDrawPixels(grassWidth, grassHeight, GL_RGB, GL_UNSIGNED_BYTE, )
	//for (int i = 0; i < grassWidth*grassHeight; i += 4)
	//{
		//
	//}


	/*
	int pixel[256*3];
	for (int i = 0; i < 256*3; i++)
	{
		pixel[i] = 0;
	}

	for (int i = 0; i < 256*3; i++)
	{
		printf("%d, ", pixel[i]);
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}
	printf("\n\n");



	int cont = 0;
	for (int i = 0; i < 256; i++)
	{
		int corPixelAtual[3];
		HEADER_PIXEL(header_data, corPixelAtual);

		pixel[cont]   = corPixelAtual[0];
		pixel[cont+1] = corPixelAtual[1];
		pixel[cont+2] = corPixelAtual[2];

		cont += 3;
	}



	for (int i = 0; i < 256*3; i++)
	{
		printf("%d, ", pixel[i]);
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}
	*/


	/*
	// Define as coordenadas da imagem na tela
	glRasterPos2d(0.0, 0.0);

	// Define o zoom na imagem?
	glPixelZoom(3, 3);


		int numPixels = grassWidth * grassHeight;

		// Dados da textura
		int texturaRGB[numPixels * 3];

		int cont = 0;
		for (int i = 0; i < numPixels; i++)
		{
			// Salva os valores RGB do pixel atual no seu proprio vetor
			int corPixelAtual[3];
			HEADER_PIXEL(header_data, corPixelAtual);

			// Salva os valores RGB deste pixel no vetor de todos os pixels
			texturaRGB[cont]   = corPixelAtual[0];
			texturaRGB[cont+1] = corPixelAtual[1];
			texturaRGB[cont+2] = corPixelAtual[2];

			cont += 3;
		}


	// Desenha a textura
	glDrawPixels(grassWidth, grassHeight, GL_RGB, GL_INT, texturaRGB);
	*/
}

#endif