/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel pela definicao de certas variaveis globais
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
*/


#ifndef JOGO_H
#define JOGO_H


// Variaveis ASCII de teclas comuns do teclado
#define ESC 27
#define SPACE 32


// Variaveis relacionadas com o FPS do jogo
#define FPS 60 // FPS desejado
int fps_desejado = FPS/2; // Variavel para alterar os frames por segundo


// Keyframes
#define KEYFRAME_RATE 3 // taxa de repeticoes do keyframe da animacao nos quadros da video


// Variaveis de camera
int tipoCamera = 0;
double camX = 0.0, camY = 0.00, camZ = 1.5;


// Variaveis que guardam a dimensao da janela
int width = 800, height = 600;


// Vetor de conteudos carregados por fase (texturas e regioes)
unsigned int objetosMapa[10] = 
{
	65535, 65535, 65535, 65535, 65535, 	// Dedicados a texturas
	65535, 65535, 65535, 65535, 65535	// Dedicados a regioes
};


// Variaveis de escolha
bool pause = false;
bool hitbox = false;


#endif