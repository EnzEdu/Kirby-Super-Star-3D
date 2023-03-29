/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT que refaz o game Kirby Super Star, da plataforma SNES, em 3D
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
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
#include "carregaTextura.h"


// Camera
#include "camera.h"
Camera camera;

// Jogador
#include "kirby.h"
Kirby player;

// HUD
#include "hud.h"
HUD hud;

// Seletor de Mundos
#include "mundos/extras.h"
#include "seletor.h"
SeletorDeMundos seletor;




/*
 *  Prototipos das funcoes seguintes
 */
void init(void);
void display(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void timer(int value);
void computeFPS();
void verificaColisao();




/*
 *  Funcao principal do OpenGL
 */
int main(int argc, char** argv)
{
    glutInit(&argc,argv);                                           // Inicia o GLUT com a passagem de parametros C
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);       // Inicia o Display com o sistema RGB, double-buffering e z-buffering
    glutInitWindowSize(width, height);                              // Tamanho da janela do OpenGL
    glutInitWindowPosition(500,50);                                 // Posicao inicial da janela do OpenGL
    glutCreateWindow("Computacao Grafica: Kirby Super Star 3D");    // Da nome para uma janela OpenGL

    init();                                                         // Chama a funcao init()

    glutDisplayFunc(display);                                       // Funcao callback de desenho
    glutReshapeFunc(reshape);                                       // Funcao callback para redesenhar a tela
    glutKeyboardFunc(keyboard);                                     // Funcao callback para tratar interrupcao do teclado
    glutTimerFunc(1000/fps_desejado, timer, 0);

    carregaTexturas();                                              // Funcao que carrega as texturas utilizadas

    glutMainLoop();                                                 // Executa o loop do OpenGL

    return EXIT_SUCCESS;                                            // Retorna 0 para o tipo inteiro da funcao main()
}





/*
 *  Funcao com alguns comandos para a inicializacao do OpenGL
 */
void init(void)
{
    // Ativa a visualizacao de texturas 2D
    glEnable(GL_TEXTURE_2D);

    // Ativa o Back-face Culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Ativa o Z-Buffer
    glEnable(GL_DEPTH_TEST);

    // Limpa a tela com a cor branca
    glClearColor (0.0, 0.6, 1.0, 1.0);

    // Carrega o modelo do Kirby na memoria
    player.carregaModelo();
}



/*
 *  Funcao callback para o reshape da janela
 */
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
    gluPerspective(60, (float)w/(float)h, 0.5, 11.0);
}



/*
 *  Funcao callback para desenhar na janela
 */
void display(void) 
{
    glMatrixMode(GL_MODELVIEW);                             // Muda pro modo de desenho
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Limpa o Buffer de Cores
    glLoadIdentity();                                       // Carrega a matriz identidade


    // Se o mundo atual for a tela inicial
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
        
        // Carrega a camera
        camera.carregaCamera();

        // Desenha o mundo
        seletor.desenhaMundo();

        // Desenha o jogador
        player.desenhar();

        // Verifica se houve colisoes
        verificaColisao();

        // Verifica se o jogador alcancou o score maximo
        seletor.verificaScore();

        // Seleciona o plano 2D
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, width, height);
        glOrtho(0, width, 0, height, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glClear(GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        // Desenha o HUD
        hud.desenhaHUD();
    }


    // Troca os buffers, mostrando o que acabou de ser desenhado
    glutSwapBuffers();
}



/*
 *  Funcao utilizada para a animacao com temporizador
 */
void timer(int value)
{
    glutTimerFunc(1000/(fps_desejado), timer, 0);
    glutPostRedisplay(); // Manda redesenhar a tela em cada frame
}



/*
 *  Funcao utilizada para o tratamento do teclado comum
 */
void keyboard(unsigned char key, int x, int y) 
{

    if (key == ESC)
    {
        // Sai do programa
        exit(EXIT_SUCCESS);
    }

    else
    {
        // Tela inicial do jogo
        if (seletor.getMundoAtual() == 0)
        {
            // Desenha o primeiro mundo ao apertar S
            if (key == 's' || key == 'S')
            {
                seletor.alteraMundo(1);
            }
        }

        else if (pause == false)
        {
            switch (key) {

                // Movimentacao do Kirby
                case 'w': case 'W':
                    {
                        // Movimenta o jogador
                        player.moveKirby( 0.00,  0.00, -0.50);
                    
                        // Ajusta a camera
                        camZ -= 0.025;
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
                    }
                break;

                case 's': case 'S':
                    {
                        // Movimenta o jogador
                        player.moveKirby( 0.00,  0.00,  0.50);
                
                        // Ajusta a camera
                        camZ += 0.025;
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
                    }
                break;

                case SPACE:
                    {
                        // Movimenta o jogador
                        player.moveKirby( 0.00,  1.00,  0.00);

                        // Ajusta a camera
                        camY += 0.005;

                        // Evoca a animacao PULANDO
                        player.playAnimation(3);
                    }
                break;

                case 'j': case 'J':
                    {
                        // Evoca a animacao ASPIRANDO
                        player.playAnimation(4);
                    }
                break;



                case 'c': case 'C':
                    {
                        // Muda a camera do jogo
                        if (tipoCamera < 1)
                        {
                            tipoCamera++;
                        }
                        else
                        {
                            tipoCamera = 0;
                        }
                    }
                break;

                case 'h': case 'H':
                    {
                        // Ativa e desativa as hitbox
                        hitbox = !hitbox;
                    }
                break;

                case 'p': case 'P':
                    {
                        // Pausa o jogo
                        pause = !pause;
                    }
                break;
            }
        }

        // Comandos durante o jogo pausado
        else
        {
            if (key == 'p' || key == 'P')
            {
                pause = !pause;
            }
        }
    }


    glutPostRedisplay();
}



/*
 *  Funcao responsavel por verificar as colisoes do game
 */
void verificaColisao()
{
    // Pega as coordenadas do Kirby
    double kirbyX = player.getCoordenadaX();
    double kirbyY = player.getCoordenadaY();
    double kirbyZ = player.getCoordenadaZ();


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
            if (hitbox == true)
            {
                // Hitbox do objeto
                glPushMatrix();
                    glColor3f(0.0, 0.0, 0.0);
                    glTranslatef(o->coordX, o->coordY + 0.85, o->coordZ);
                    glutWireSphere(0.1, 20, 20);
                glPopMatrix();
            }


            /* 
             *  Verifica colisao direta do Kirby com um objeto
             *  (Esfera-Esfera)
             */
            if (player.getAnimacao() != 4)
            {
                // Identifica os valores relacionados a hitbox do Kirby
                double raioKirby = 0.05*1.3;
                double hitboxKirby[3] =
                {
                    0.05*kirbyX        ,
                    0.05*(kirbyY + 1.7),
                    0.05*kirbyZ
                };

                // Identifica os valores relacionados a hitbox do objeto
                double tamanhoHitboxObjeto = 0.1;
                double hitboxObjetoAABB[3] =
                {
                    o->coordX, 
                    o->coordY + 0.85, 
                    o->coordZ
                };

                // Calcula a distancia entre as hitbox
                double distancia = sqrt(
                    pow(abs(hitboxKirby[0] - hitboxObjetoAABB[0]), 2) +
                    pow(abs(hitboxKirby[1] - hitboxObjetoAABB[1]), 2) +
                    pow(abs(hitboxKirby[2] - hitboxObjetoAABB[2]), 2)
                );

                // Calcula a soma dos raios
                double somaRaios = raioKirby + tamanhoHitboxObjeto;


                // Verifica se houve colisao
                if (distancia <= somaRaios)
                {
                    if (o->tipo == 'c')
                    {
                        // Se o objeto for um coletavel, o remove da cena
                        seletor.houveColisao(regiaoCarregada, objetoCarregado, 0);
                        player.incrementaScore();
                    }
                    else
                    {
                        // Se o objeto for um inimigo, Kirby recebe dano e sofre repulsao (knockback)
                        switch (player.getDirecao())
                        {
                            case 0: player.moveKirby( 0.00,  0.00,  1.00); camZ += 0.025; break;    // FRENTE
                            case 1: player.moveKirby( 1.00,  0.00,  0.00); camX += 0.04;  break;    // ESQUERDA
                            case 2: player.moveKirby( 0.00,  0.00, -1.00); camZ -= 0.025; break;    // COSTAS
                            case 3: player.moveKirby(-1.00,  0.00,  0.00); camX -= 0.04;  break;    // DIREITA
                        }

                        player.perdeVida();
                    }
                }
            }

            /* 
             *  Verifica colisao do Kirby potencialmente absorvendo um objeto
             *  (Esfera-Esfera)
             */
            else
            {
                if (o->tipo == 'i')
                {
                    // Identifica os valores relacionados a hitbox do Kirby aspirando ar
                    double tamanhoHitboxAr = 2.5;
                    double hitboxArAspirado[3];
                    switch (player.getDirecao())
                    {
                        case 0: // Olhando pra FRENTE
                            {
                                hitboxArAspirado[0] = 0.05*kirbyX;
                                hitboxArAspirado[1] = 0.05*(kirbyY + 1.7);
                                hitboxArAspirado[2] = 0.05*(kirbyZ - 3.0);
                            }
                        break;
                        case 1: // Olhando pra ESQUERDA
                            {
                                hitboxArAspirado[0] = 0.05*(kirbyX - 2.5);
                                hitboxArAspirado[1] = 0.05*(kirbyY + 1.7);
                                hitboxArAspirado[2] = 0.05*kirbyZ;
                            }
                        break;
                        case 2: // Olhando pra COSTAS
                            {
                                hitboxArAspirado[0] = 0.05*kirbyX;
                                hitboxArAspirado[1] = 0.05*(kirbyY + 1.7);
                                hitboxArAspirado[2] = 0.05*(kirbyZ + 3.0);
                            }
                        break;
                        case 3: // Olhando pra DIREITA
                            {
                                hitboxArAspirado[0] = 0.05*(kirbyX + 2.5);
                                hitboxArAspirado[1] = 0.05*(kirbyY + 1.7);
                                hitboxArAspirado[2] = 0.05*kirbyZ;
                            }
                        break;
                    }

                    // Identifica os valores relacionados a hitbox do objeto
                    double tamanhoHitboxObjeto = 0.1;
                    double hitboxObjetoAABB[3] =
                    {
                        o->coordX,
                        o->coordY + 0.85, 
                        o->coordZ
                    };

                
                    // Calcula a distancia entre as hitboxes
                    double distancia = sqrt(
                        pow(abs(hitboxObjetoAABB[0] - hitboxArAspirado[0]), 2) +
                        pow(abs(hitboxObjetoAABB[1] - hitboxArAspirado[1]), 2) +
                        pow(abs(hitboxObjetoAABB[2] - hitboxArAspirado[2]), 2)
                    );


                    // Com base na distancia entre Kirby e o inimigo
                    if (distancia < 0.12)
                    {
                        forward_list<double> dados;

                        // Simula uma animacao de "absorcao" do inimigo
                        if (distancia > 0.08)
                        {
                            seletor.houveColisao(regiaoCarregada, objetoCarregado, 1);
                        }

                        // Absorve o inimigo
                        else
                        {
                            seletor.houveColisao(regiaoCarregada, objetoCarregado, 0);

                            player.incrementaScore();
                            player.absorverObjeto();
                        }
                    }
                }
            }

            objetoCarregado++;
        }
    }
}