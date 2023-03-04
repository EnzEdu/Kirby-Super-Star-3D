/*
 * Atividade XX - Computacao Grafica
 * Codigo OpenGL/GLUT que 
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
static int rotacaoDDD = 0;
//static int ombro = 0, cotovelo = 0, mao = 0;
//static int garraIndicador = 0, garraPolegar = 0, garraAnelar = 0;
static float pil = 0;
static float teste = 0;
static double numero = 0.0;


// Fases
#include "springbreeze.h"


#include "kirby.h"
Kirby player;


// Teclas do teclado e seus valores ASCII
#define ESC 27





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
    glutInitWindowSize(800,600);                                    // Tamanho da janela do OpenGL
    glutInitWindowPosition(100,50);                                // Posicao inicial da janela do OpenGL
    glutCreateWindow("Computacao Grafica: Braco Robotico");         // Da nome para uma janela OpenGL

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
        */

        case 'w':           player.moveKirby( 0.00,-0.02); break;
        case 'a':           player.moveKirby(-0.02, 0.00); break;
        case 's':           player.moveKirby( 0.00, 0.02); break;
        case 'd':           player.moveKirby( 0.02, 0.00); break;


        case 'y':     rotacaoDDD = (rotacaoDDD - 5) % 360;          break;
        case 'Y':     rotacaoDDD = (rotacaoDDD + 5) % 360;          break;


        case 'l': pil += 0.1; break;
        case 'L': pil -= 0.1; break;
        case 'v': teste += 0.1; break;
        case 'b': teste -= 0.1; break;


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
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    // Define a forma do volume de visualizacao para termos uma projecao perspectiva (3D)
    // (angulo, aspecto, ponto_proximo, ponto distante)
    gluPerspective(60, (float)w/(float)h , 1.0, 11.0);

    /*
    gluLookAt(0.0, 0.0, 7.0,     // Posicao da camera
              0.0, -1.0, 0.0,   // Olho da camera (esq/dir, cim/bai, ??/??)
              0.0, 1.0, 0.0);  // Sentido ou orientacao da camera  ^^^^ |=| vvvv
    */
    

}



// Funcao callback para desenhar na janela
void display(void) 
{
    glMatrixMode(GL_MODELVIEW);                             // Muda pro modo de desenho
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Limpa o Buffer de Cores
    glLoadIdentity();                                       // Carrega a matriz identidade


    // Camera que acompanha o jogador
    
    gluLookAt(                      0.0, 1.5, 1.5 + player.retornaPosicaoZ(),
               player.retornaPosicaoX(), 0.0,       player.retornaPosicaoZ(),
                                    0.0, 1.0, 0.0);
    
    /*
    // Camera teste
    gluLookAt(0.0, 0.75, 2.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    */
    /*
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(200, 0);
        glVertex2f(200, 200);
        glVertex2f(200, 0);
    glEnd();
    */

    /*
    // Braco robotico
    glPushMatrix();

        // Rotacao 3D
        glRotatef((GLfloat) rotacaoDDD, 0.0, 1.0, 0.0);

        glPushMatrix();
            //glTranslatef(0.0, -1.90, 0.0);
            //glTranslatef(0.0, 0.0, 5.0);
            //glTranslatef(0.0, -1.6, 5.0);
            glColor3f(0.33, 0.33, 0.33);
            glutWireCube(1.5);
        glPopMatrix();



    glPopMatrix();
//    printf("pil %.2f\n", pil);

    
    // Numero de texture units do meu sistema (eh 32)
    int texture_units = 0;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texture_units);
    //printf("Numero de texture units = %d\n", texture_units);
    */

    SpringBreeze pelsos;
    pelsos.fase1();

    player.desenhaKirby();

    // Troca os buffers, mostrando o que acabou de ser desenhado
    glutSwapBuffers();
}

