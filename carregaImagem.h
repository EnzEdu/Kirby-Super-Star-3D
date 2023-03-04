#ifndef IMAGEM_H
#define IMAGEM_H

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Imagem
{
	private: // Variaveis
        int 			imagemWidth     = 0;
        int 			imagemHeight    = 0;
        int 			numCanaisCor    = 0;

	public: // Funcoes
		unsigned char 	*carregaImagem	(const char* caminho);
		int 			getImgWidth		();
		int 			getImgHeight	();
		int  			getNumCanaisCor	();
};


// Funcao que carrega uma imagem na memoria
unsigned char *Imagem::carregaImagem(const char* caminho)
{
	//
    unsigned char *data = stbi_load(caminho, &imagemWidth, &imagemHeight, &numCanaisCor, 0);
    return data;
}


// Funcoes que retornam os valores da imagem carregados
int Imagem::getImgWidth()
{
	return imagemWidth;
}


int Imagem::getImgHeight()
{
	return imagemHeight;
}


int Imagem::getNumCanaisCor()
{
	return numCanaisCor;
}

#endif