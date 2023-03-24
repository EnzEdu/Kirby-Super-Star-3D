#ifndef CARREGAIMAGEM_H
#define CARREGAIMAGEM_H


#include "lib/glm.cpp"
//#include "img/grass.h"
//#include "img/grass.h"
#include "img/texturasMapa.h"



void carregaImagem()
{
	// Vetor com as cores de cada pixel da textura
    unsigned char textura_data[tilesWidth*tilesHeight*3];
    printf("tamanho vetor = %d\n", tilesWidth*tilesHeight*3);

    // Extrai os valores RGB de cada pixel a partir de um caractere de informacao
    // e os salva no vetor
    int cont = 0;
    for (int i = 0; i < tilesWidth*tilesHeight; i++)
    {
    	int corPixel[3];
    	HEADER_PIXEL(header_data_tiles, corPixel);

    	textura_data[cont] = corPixel[0];
    	textura_data[cont+1] = corPixel[1];
    	textura_data[cont+2] = corPixel[2];

    	cont += 3;
    }

    /*
    for (int i = 0; i < 21; i++)
    {
    	printf("%d ", textura_data[i]);
    }
    printf("\n");
    */

	//            CARREGA NA MEMORIA!!!!!!!!

//                if(grass){
                    // Gera nomes identificadores (IDs) para as texturas
                    glGenTextures(10, objetosMapa);

                    // Ativa a textura que sera criada ou usada no momento, por meio do seu ID
                    glBindTexture(GL_TEXTURE_2D, objetosMapa[0]);

                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

                    // Cria a extrutura da textura na memoria
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tilesWidth, tilesHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, textura_data);
                    
                    // Definicao dos parametros da textura
                    //glGenerateMipmap(GL_TEXTURE_2D);

                    /*
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
                    */




                    //glDisable(GL_COLOR_MATERIAL);
                    //glBindTexture(GL_TEXTURE_2D, );
//                    printf("AAAAAAAAAAAA\n");
//                }
                    //glClearColor(1.0, 1.0, 1.0, 1.0);
    
}




#endif