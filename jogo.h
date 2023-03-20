#ifndef JOGO_H
#define JOGO_H


// Variaveis ASCII de teclas comuns do teclado
#define ESC 27
#define SPACE 32


// Variaveis relacionadas com o FPS do game
#define MAX_FPS 60	// Numero maximo de FPS do jogo
#define FPS 60 // FPS desejado atualmente
int fps_desejado = FPS/2; // variavel para alterar os frames por segundo desejado
int fps = 0; //contador de frames por segundo


// Keyframes
#define KEYFRAME_RATE 3 // taxa de repeticoes do keyframe da animacao nos quadros da video
//int keyframe = 0; // numero do modelo 3D (keyframe) da animacao que sera desenhado no momento
//int keyframe_rate = KEYFRAME_RATE; // alterar a taxa de repeticoes do keyframe na reproducao da animacao
//int count_rate = -1; //Conta a quantidade de repeticoes do keyframe ate atingir a taxa keyframe_rate
//int frames_playing = 0; //Conta a quantidade de quadros enquanto reproduz uma mesma animacao ate troca-la



bool pause = false;



#endif