#ifndef CARREGAIMAGEM_H
#define CARREGAIMAGEM_H


#include "lib/glm.cpp"
//#include "img/grass.h"
#include "img/grass.h"


unsigned char *qntImagens[2];

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

    unsigned char textura_data[grassWidth*grassHeight*3];
    printf("tamanho vetor = %d\n", grassWidth*grassHeight*3);
    int cont = 0;
    for (int i = 0; i < grassWidth*grassHeight; i++)
    {
    	int corPixel[3];
    	HEADER_PIXEL(header_data, corPixel);

    	textura_data[cont] = corPixel[0];
    	textura_data[cont+1] = corPixel[1];
    	textura_data[cont+2] = corPixel[2];

    	cont += 3;
    }

    for (int i = 0; i < 21; i++)
    {
    	printf("%d ", textura_data[i]);
    }
    printf("\n");

	//            CARREGA NA MEMORIA!!!!!!!!

//                if(grass){
                    //Gera nomes identificadores (IDs) para as texturas
                    glGenTextures(10, objetosMapa);

                    //Ativa a textura que sera criada ou usada no momento, por meio do seu ID
                    glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);

                    //Cria a extrutura da textura na memoria
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, grassWidth, grassHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, textura_data);
                    
                    //Definicao dos parametros da textura
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);


                    //glDisable(GL_COLOR_MATERIAL);
                    //glBindTexture(GL_TEXTURE_2D, );
//                    printf("AAAAAAAAAAAA\n");
//                }
                    //glClearColor(1.0, 1.0, 1.0, 1.0);
    


	/*
    unsigned char textura_data[grassWidth*grassHeight*3];
    printf("tamanho vetor = %d\n", grassWidth*grassHeight*3);
    int cont = 0;
    for (int i = 0; i < grassWidth*grassHeight; i++)
    {
    	int corPixel[3];
    	HEADER_PIXEL(header_data, corPixel);

    	textura_data[cont] = corPixel[0];
    	textura_data[cont+1] = corPixel[1];
    	textura_data[cont+2] = corPixel[2];

    	cont += 3;
    }

    printf("cont = %d\n", cont);
    printf("qntImagens inicio = %p\n", qntImagens[0]);

    unsigned char *ptr;
    ptr = &textura_data[0];
    qntImagens[0] = ptr;
    printf("%p %p %p %p\n", textura_data, &textura_data[0], ptr, qntImagens[0]);
    printf("qntImagens inicio = %p\n", qntImagens[0]);
    printf("qntImagens inicio = %p\n", qntImagens[1]);
    */


}

void desenhaImagem()
{
	//glRasterPos3d(0.00, 0.00, 0.00);
	//glPixelZoom(5, 5);
	//glDrawPixels(16, 16, GL_RGB, GL_UNSIGNED_BYTE, qntImagens[0]);
}



#endif