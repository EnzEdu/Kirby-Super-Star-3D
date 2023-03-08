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
static int rotacaoDDD = 0;
static char ultimaTecla = '0';
static int contadorAndando = 0;


// Jogador
#include "kirby.h"
Kirby player;

#include "hud.h"
HUD hud;


// Fases
#include "springbreeze.h"




// Teclas do teclado e seus valores ASCII
#define ESC 27
#define SPACE 32





/*
 * Declaracoes antecipadas (forward) das funcoes (assinaturas)
 */
void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);





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
    glutMainLoop();                                                 // Executa o loop do OpenGL

    return EXIT_SUCCESS;                                            // Retorna 0 para o tipo inteiro da funcao main()
}





// Funcao com alguns comandos para a inicializacao do OpenGL
void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);      // Limpa a tela com a cor branca
    glEnable(GL_DEPTH_TEST);                // Habilita o algoritmo Z-Buffer
}



// Funcao callback para controle das teclas comuns
void keyboard(unsigned char key, int x, int y) 
{
    //printf("key = %c\n", key);

    switch (key) {

        // lowerCase = sentido horario
        // upperCase = sentido anti-horario
        /*
        case 'o':          ombro = (ombro - 5) % 120;               break;
        case 'O':          ombro = (ombro + 5) % 120;               break;
        case 'c':       cotovelo = (cotovelo - 5) % 120;            break;
        case 'C':       cotovelo = (cotovelo + 5) % 120;            break;
        case 'm':            mao = (mao - 5) % 120;                 break;
        case 'M':            mao = (mao + 5) % 120;                 break;

        case 'i': garraIndicador = (garraIndicador - 5) % 120;      break;
        case 'I': garraIndicador = (garraIndicador + 5) % 120;      break;
        case 'p':   garraPolegar = (garraPolegar - 5) % 120;        break;
        case 'P':   garraPolegar = (garraPolegar + 5) % 120;        break;
        case 'a':    garraAnelar = (garraAnelar - 5) % 120;         break;
        case 'A':    garraAnelar = (garraAnelar + 5) % 120;         break;

        case 'y':     rotacaoDDD = (rotacaoDDD - 5) % 360;          break;
        case 'Y':     rotacaoDDD = (rotacaoDDD + 5) % 360;          break;
        */




        // Movimentacao do Kirby
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



        // Sai do programa
        case ESC: exit(EXIT_SUCCESS);                               break;
    }

    glutPostRedisplay();
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



    // Retorna pro plano 3D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    gluPerspective(60, (float)width/(float)height, 0.5, 11.0);



    // Troca os buffers, mostrando o que acabou de ser desenhado
    glutSwapBuffers();
}

