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
#include <forward_list>
#include "jogo.h"
#include "carregaImagem.h"
#include "mundos/extras.h"

// Declaracao de constantes e variaveis
double camX = 0.0, camY = 0.00, camZ = 1.5;
int width = 800, height = 600;


// Jogador
#include "kirby.h"
Kirby player;

#include "hud.h"
HUD hud;

#include "seletor.h"
SeletorDeMundos seletor;




/*
 * Declaracoes antecipadas (forward) das funcoes (assinaturas)
 */
void init(void);
void display(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void timer(int value);
void computeFPS();
void verificaColisao();

//double camX = 0.0, camZ = 1.5;




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


    carregaImagem();

    glutMainLoop();                                                 // Executa o loop do OpenGL

    return EXIT_SUCCESS;                                            // Retorna 0 para o tipo inteiro da funcao main()
}





// Funcao com alguns comandos para a inicializacao do OpenGL
void init(void)
{
    //Define como a textura sera aplicada ao objeto
//    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
//    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);



    //Ativa a visualizacao de texturas 2D (Texturizacao 2D)
    glEnable(GL_TEXTURE_2D);

    // Ativa o Back-face Culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

//    glShadeModel( GL_SMOOTH );

    glEnable(GL_DEPTH_TEST);                // Habilita o algoritmo Z-Buffer


    glClearColor (1.0, 1.0, 1.0, 1.0);      // Limpa a tela com a cor branca 


    
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



    // Camera que acompanha o jogador
/*
    gluLookAt(                     0.0, 1.5, player.getCoordenadaZ() + 0.9,
               player.getCoordenadaX(), 0.0, player.getCoordenadaZ() - 0.6,
                                   0.0, 1.0, 0.0);
*/

/*
    gluLookAt(camX, 1.50, camZ,
              camX, 0.00, camZ - 1.5,
              0.00, 1.00, 0.00);
*/
//    printf("%.2lf %.2lf %.2lf\n", camX, camY, camZ);
    
    // Camera teste
/*
    gluLookAt(0.0, 1.75, 2.0,   //0.0, 0.75, 2.0//
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
*/
/*
    gluLookAt(0.0, 3, 2.0,
              0.0, 3, 0.0,
              0.0, 1.0, 0.0);
*/

    // Desenha o mundo a ser jogado
    if (seletor.getMundoAtual() == 0)
    {
        // Seleciona o plano 2D
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, 0, height, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClear(GL_DEPTH_BUFFER_BIT);

        // Desenha o mundo
        seletor.desenhaMundo();
    }
    else
    {
        // Seleciona o plano 3D
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, (GLsizei) width, (GLsizei) height);
        gluPerspective(60, (float)width/(float)height, 0.5, 11.0);
        glMatrixMode(GL_MODELVIEW);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        //
        gluLookAt(0.00, camY + 1.50, camZ,
                  camX, camY, camZ - 1.5,
                  0.00, 1.00, 0.00);
        //
        /*
        gluLookAt(0.0, 0.75, 2.0,   // Costas //
                  0.0, 0.0, 0.0,
                  0.0, 1.0, 0.0);
        */
        // Desenha o mundo
        seletor.desenhaMundo();

        // Desenha o jogador
        player.desenhar();

        //
        verificaColisao();

        // Seleciona o plano 2D
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, width, height);
        glOrtho(0, width, 0, height, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glClear(GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        hud.desenhaHUD();
    }





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

    if (pause == false)
    {
        switch (key) {

            // Movimentacao do Kirby
            case 'w': case 'W':
                {
                    // Movimenta o jogador
                    player.moveKirby( 0.00,  0.00, -0.50);
                    
                    // Ajusta a camera
                    camZ -= 0.025;

                    // Ajusta a rotacao do jogador
                    player.rotacionaKirby(180.0);
                }
            break;

            case 'a': case 'A':
                {
                    // Movimenta o jogador
                    player.moveKirby(-0.50,  0.00,  0.00);
            
                    // Ajusta a camera
                    if (camX > -0.54)
                    {
                        camX -= 0.02;
                    }

                    // Ajusta a rotacao do jogador
                    player.rotacionaKirby(-90.0);
                }
            break;

            case 's': case 'S':
                {
                    // Movimenta o jogador
                    player.moveKirby( 0.00,  0.00,  0.50);
            
                    // Ajusta a camera
                    camZ += 0.025;

                    // Ajusta a rotacao do jogador
                    player.rotacionaKirby( 0.0);
                }
            break;

            case 'd': case 'D':
                {
                    // Movimenta o jogador
                    player.moveKirby( 0.50,  0.00,  0.00);
            
                    // Ajusta a camera
                    if (camX < 0.54)
                    {
                        camX += 0.02;
                    }

                    // Ajusta a rotacao do jogador
                    player.rotacionaKirby(90.0);
                }
            break;

            case 'j': case 'J':
                {
                    // Evoca a animacao SUGANDO
                    player.playAnimation(4);
                }
            break;

            case SPACE:
                {
                    // Movimenta o jogador
                    player.moveKirby( 0.00,  1.00,  0.00);

                    // Evoca a animacao PULANDO
                    player.playAnimation(3);
                }
            break;

            case 'p': case 'P':
                {
                    // Pausa o jogo
                    pause = !pause;
                }
            break;

            case ESC:
                {
                    // Sai do programa
                    exit(EXIT_SUCCESS);
                }
            break;
        }
    }

    // Comandos pro jogo pausado
    else
    {
        switch (key)
        {
            // Despausa o jogo
            case 'p': case 'P':         pause = !pause;             break;
        }
    }


    glutPostRedisplay();
}




/*
 * Computa a quantidade de frames por segundo da animacao
 *
void computeFPS()
{    
    static GLuint frames = 0;       //Conta os frames em 1000 milissegundos, computando o FPS
    static GLuint clock;            // em milissegudos
    static GLuint next_clock = 0;   // em milissegudos

    frames++;
    clock = glutGet(GLUT_ELAPSED_TIME); //Número de milissegundos desde a chamada a glutInit()


    if (clock < next_clock ) return;
    fps = frames; // guarda o número de frames por segundo
    // Evita o reinicio da contagem dos frames na primeira iteracao
    if(next_clock != 0) frames = 0;//Reinicia a contagem dos frames a cada 1000 milissegundos
    next_clock = clock + 1000; //A cada 1000 milissegundos = 1 segundo
}
*/



/*
 * Computa a quantidade de frames por segundo da animacao
 */
void verificaColisao()
{
    double kirbyX = player.getCoordenadaX();
    double kirbyY = player.getCoordenadaY();
    double kirbyZ = player.getCoordenadaZ();

    // Hitbox do corpo do Kirby
    //double hitboxKirby[3] = {0.0, 0.0, 0.0};

    // Centro da hitbox?
    double centroKirby[3] = {kirbyX, kirbyY, kirbyZ};




    // Itera sobre as regioes carregadas
    for (int i = 6; i < 9; i++)
    {
        int regiaoCarregada = objetosMapa[i];

        // Recebe a lista de objetos da regiao
        forward_list<Objeto> objetos = seletor.getObjetos(regiaoCarregada);

        // Itera sobre os objetos carregados naquela regiao
        int objetoCarregado = 0;
        for (forward_list<Objeto>::iterator o = objetos.begin(); o != objetos.end(); o++)
        {
            /*
            // Hitbox da coisa
            glPushMatrix();
                glColor3f(0.0, 0.0, 0.0);
                glTranslatef(o->coordX, o->coordY + 0.85, o->coordZ);
                glutWireSphere(0.09, 20, 20);
            glPopMatrix();
            */

            // Calcula a distancia entre os centros
            double distancia2 = sqrt(
                pow((o->coordX - (0.05*kirbyX)), 2) +
                pow((o->coordY+0.85 - (0.05*(kirbyY+1.7))), 2) +
                pow((o->coordZ - (0.05*kirbyZ)), 2)
            );

            // Soma dos raios
            double somaRaios = (0.05*1.3) + 0.09;
            if (distancia2 <= somaRaios)
            {
                //printf("aaaaaaaa\tdist = %.2lf somaRaios = %.2lf\n", distancia2, somaRaios);
                printf("Colisao!!!!!!!!!!!\n");
                
                Objeto o2;
                o2.desenhar = true; o2.usarTextura = o->usarTextura;
                o2.coordX = o->coordX+1.0; o2.coordY = o->coordY; o2.coordZ = o->coordZ;
                o2.corR = o->corR; o2.corG = o->corG; o2.corB = o->corB;
                o2.texX1 = o->texX1; o2.texX2 = o->texX2; o2.texY1 = o->texY1; o2.texY2 = o->texY2;
                objetos.push_front(o2);

                seletor.houveColisao(regiaoCarregada, objetoCarregado);
            }

            objetoCarregado++;
        }
    }
}