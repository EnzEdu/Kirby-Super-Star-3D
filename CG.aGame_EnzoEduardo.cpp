/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT que refaz o game Kirby Super Star, da plataforma SNES, em 3D
 * Autor: Enzo Eduardo
 * Data: xx/03/2023
*/






// Bibliotecas utilizadas pelo OpenGL
#ifdef __APPLE__                        // Mac OS
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else                                   // Windows/Linux
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif


// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "carregaImagem.h"

// Declaracao de constantes e variaveis
int width = 800, height = 600;
static char ultimaTecla = '0';
static int contadorAndando = 0;


#include "jogo.h"
// Jogador
#include "kirby.h"
Kirby player;

#include "hud.h"
HUD hud;


// Fases
#include "springbreeze.h"






/*
 * Declaracoes antecipadas (forward) das funcoes (assinaturas)
 */
void init(void);
void display(void);
void reshape (int w, int h);
void keyboard (unsigned char key, int x, int y);
void timer(int value);
void computeFPS();




// Funcao principal
int main(int argc, char** argv)
{
    glutInit(&argc,argv);                                           // Inicia o GLUT com a passagem de parametros C
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);       // Inicia o Display com o sistema RGB, double-buffering e z-buffering
    glutInitWindowSize(width, height);                                    // Tamanho da janela do OpenGL
    glutInitWindowPosition(500,50);                                 // Posicao inicial da janela do OpenGL
    glutCreateWindow("Computacao Grafica: Kirby Super Star 3D");    // Da nome para uma janela OpenGL

    init();                                                         // Chama a funcao init()

    glutDisplayFunc(display);                                       // Funcao callback de desenho
    glutReshapeFunc(reshape);                                       // Funcao callback para redesenhar a tela
    glutKeyboardFunc(keyboard);                                     // Funcao callback para tratar interrupcao do teclado
    glutTimerFunc(1000/fps_desejado, timer, 0);
    glutMainLoop();                                                 // Executa o loop do OpenGL

    return EXIT_SUCCESS;                                            // Retorna 0 para o tipo inteiro da funcao main()
}





// Funcao com alguns comandos para a inicializacao do OpenGL
void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);      // Limpa a tela com a cor branca
    glEnable(GL_DEPTH_TEST);                // Habilita o algoritmo Z-Buffer

    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    //glEnable(GL_TEXTURE_2D);
    //carregaTexturas();    

    /*
     *  Configurando o OpenGL para o uso de Texturas
     */
    //Define como a textura sera aplicada ao objeto
//    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    //Ativa a visualizacao de texturas 2D (Texturizacao 2D)
    glEnable(GL_TEXTURE_2D);
    
    player.carregaModelo();
    // Ativa o modelo de sombreamento de "Gouraud" (Smooth
    //glShadeModel(GL_SMOOTH);
    
    // Ativa o Back-face Culling
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    
    // Ativa o z-buffering, de modo a remover as superficies escondidas
    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);
}



// Funcao callback para o reshape da janela
void reshape(int w, int h) 
{
    glMatrixMode (GL_PROJECTION);   // Muda pro modo de projecao
    glLoadIdentity();               // Carrega a matriz identidade

    // Define o tamanho da area de desenho da janela
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    // Atualiza as variaveis que salvam o tamanho da janela
    width = w;
    height = h;

    // Define a forma do volume de visualizacao para termos uma projecao perspectiva (3D)
    // (angulo, aspecto, ponto_proximo, ponto distante)
    //gluPerspective(60, (float)w/(float)h , 0.5, 5.0);
    gluPerspective(60, (float)w/(float)h, 0.5, 11.0);
    //gluPerspective(60, (float)w/(float)h, 0.5, 20.0);
}



// Funcao callback para desenhar na janela
void display(void) 
{
    glMatrixMode(GL_MODELVIEW);                             // Muda pro modo de desenho
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Limpa o Buffer de Cores
    glLoadIdentity();                                       // Carrega a matriz identidade

    glEnable(GL_TEXTURE_2D);

    // Camera que acompanha o jogador
//
    gluLookAt(                     0.0, 1.5, player.getCoordenadaZ() + 0.9,
               player.getCoordenadaX(), 0.0, player.getCoordenadaZ() - 0.6,
                                   0.0, 1.0, 0.0);
//
    
    // Camera teste
/*
    gluLookAt(0.0, 0.75, 2.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
*/
/*
    gluLookAt(0.0, 3, 2.0,
              0.0, 3, 0.0,
              0.0, 1.0, 0.0);
*/


    computeFPS(); // Incrementa o keyframe da animacao a ser desenhado

    SpringBreeze pelsos;
    pelsos.fase1();

    player.desenhaKirby();


    // Ida ao plano 2D para desenhar o HUD
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_DEPTH_BUFFER_BIT);

    hud.desenhaHUD();
    carregaImagem();

    // Retorna pro plano 3D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    gluPerspective(60, (float)width/(float)height, 0.5, 11.0);



    // Troca os buffers, mostrando o que acabou de ser desenhado
    glutSwapBuffers();
}



/*
 * Funcao utilizada para a animacao com temporizador
 */
void timer(int value)
{
    glutTimerFunc(1000/(fps_desejado), timer, 0);
    glutPostRedisplay(); // Manda redesenhar a tela em cada frame
}



/*
 * Funcao utilizada para o tratamento do teclado comum
 */
void keyboard(unsigned char key, int x, int y) 
{
    //printf("key = %c\n", key);

    switch (key) {

        // Movimentacao do Kirby
        /*
        case 'w':
            {
                if (ultimaTecla == 'w')
                {
                    // Conta quanto segundos Kirby passou andando naquela direcao
                    if (contadorAndando != 8)
                    {
                        contadorAndando++;
                    }
                }
                else
                {
                    // Reseta o contador ao trocar de tecla
                    contadorAndando = 0;
                    ultimaTecla = 'w';
                }


                // Controla a velocidade do Kirby
                if (contadorAndando != 8)
                {
                    // Andando
                    player.moveKirby(0.00, 0.00, -0.02);
                }
                else
                {
                    // Correndo
                    player.moveKirby(0.00, 0.00, -0.04);
                }
            }
        break;

        case 'a':
            {
                if (ultimaTecla == 'a')
                {
                    // Conta quanto segundos Kirby passou andando naquela direcao
                    if (contadorAndando != 8)
                    {
                        contadorAndando++;
                    }
                }
                else
                {
                    // Reseta o contador ao trocar de tecla
                    contadorAndando = 0;
                    ultimaTecla = 'a';
                }


                // Controla a velocidade do Kirby
                if (contadorAndando != 8)
                {
                    // Andando
                    player.moveKirby(-0.02, 0.00, 0.00);
                }
                else
                {
                    // Correndo
                    player.moveKirby(-0.04, 0.00, 0.00);
                }
            }
        break;

        case 's':
            {
                if (ultimaTecla == 's')
                {
                    // Conta quanto segundos Kirby passou andando naquela direcao
                    if (contadorAndando != 8)
                    {
                        contadorAndando++;
                    }
                }
                else
                {
                    // Reseta o contador ao trocar de tecla
                    contadorAndando = 0;
                    ultimaTecla = 's';
                }


                // Controla a velocidade do Kirby
                if (contadorAndando != 8)
                {
                    // Andando
                    player.moveKirby(0.00, 0.00, 0.02);
                }
                else
                {
                    // Correndo
                    player.moveKirby(0.00, 0.00, 0.04);
                }
            }
        break;

        case 'd':
            {
                if (ultimaTecla == 'd')
                {
                    // Conta quanto segundos Kirby passou andando naquela direcao
                    if (contadorAndando != 8)
                    {
                        contadorAndando++;
                    }
                }
                else
                {
                    // Reseta o contador ao trocar de tecla
                    contadorAndando = 0;
                    ultimaTecla = 'd';
                }


                // Controla a velocidade do Kirby
                if (contadorAndando != 8)
                {
                    // Andando
                    player.moveKirby(0.02, 0.00, 0.00);
                }
                else
                {
                    // Correndo
                    player.moveKirby(0.04, 0.00, 0.00);
                }
            }
        break;

        case SPACE:
            {
                //printf("apertou espaco!\n");
                player.moveKirby(0.00, 0.04, 0.00);
            }
        break;
        */
        /*
        case 'w': case 'W':
            if(jogo.pause == false){
                if(kirby.esta_pulando == true) keyPlayAnimation(4);
                else keyPlayAnimation(2);   // Andando
                if(kirby.direcao == tras){
                    if(roty == 180.0) posz -= deslocamento;
                    else if(roty < 180.0) roty += graus;
                    else if(roty > 180.0) roty -= graus;
                }else if (direcao==frente){
                    if (roty >= 0.0) roty += graus;
                    else roty -= graus;
                }else if (direcao == direita) roty += graus;
                else roty -= graus;
                update_direcao();
            }
        break;

        case 'a': case 'A':
        break;

        case 's': case 'S':
        break;

        case 'd': case 'D':
        break;
        */

        // Pula
        case SPACE:
            if (pause == false)
            {
                player.keyPlayAnimation(2);     // Trocar. 2 eh o id para ANDANDO
            }
        break;

        // Pausa o jogo
        case 'p': case 'P':         pause = !pause;             break;

        // Sai do programa
        case ESC:                   exit(EXIT_SUCCESS);         break;
    }

    glutPostRedisplay();
}




/*
 * Computa a quantidade de frames por segundo da animacao
 */
void computeFPS()
{    
    static GLuint frames = 0;       //Conta os frames em 1000 milissegundos, computando o FPS
    static GLuint clock;            // em milissegudos
    static GLuint next_clock = 0;   // em milissegudos

    //count_rate++;
    //frames_playing++;
    frames++;
    clock = glutGet(GLUT_ELAPSED_TIME); //Número de milissegundos desde a chamada a glutInit()


    if (clock < next_clock ) return;
    fps = frames; // guarda o número de frames por segundo
    // Evita o reinicio da contagem dos frames na primeira iteracao
    if(next_clock != 0) frames = 0;//Reinicia a contagem dos frames a cada 1000 milissegundos
    next_clock = clock + 1000; //A cada 1000 milissegundos = 1 segundo
}