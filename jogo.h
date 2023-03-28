#ifndef JOGO_H
#define JOGO_H


// Variaveis ASCII de teclas comuns do teclado
#define ESC 27
#define SPACE 32


// Variaveis relacionadas com o FPS do jogo
#define MAX_FPS 60	// Numero maximo de FPS do jogo
#define FPS 60 // FPS desejado atualmente
int fps_desejado = FPS/2; // Variavel para alterar os frames por segundo
int fps = 0; //contador de frames por segundo


// Variavel que define a camera selecionada
int tipoCamera = 0;


// Keyframes
#define KEYFRAME_RATE 3 // taxa de repeticoes do keyframe da animacao nos quadros da video


// Vetor de conteudos carregados por fase (texturas, objetos)
unsigned int objetosMapa[10] = 
{
	65535, 65535, 65535, 65535, 65535, 
	65535, 65535, 65535, 65535, 65535
};


// Variaveis de escolha
bool pause = false;
bool hitbox = false;


// Variavel que representa o teclado
bool teclado[255];


#endif