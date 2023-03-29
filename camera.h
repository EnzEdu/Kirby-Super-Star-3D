/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel pelo controle da camera do game
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
*/


#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
	public:
		void	carregaCamera();
};

void Camera::carregaCamera()
{
	switch (tipoCamera)
	{
		case 0:		// Camera de ombro
			{
		        gluLookAt(0.00, camY + 1.50,    camZ   ,
         		          camX,     camY   , camZ - 1.5,
                		  0.00,     1.00   ,    0.00   );
			}
		break;

		case 1:		// Camera que acompanha horizontalmente
			{
		        gluLookAt(camX, camY + 1.50,    camZ   ,
        		          camX,     camY,    camZ - 1.5,
                		  0.00,     1.00,    0.00);
			}
		break;
	}


	// Mantem a camera nos limites
	if (camX >= 0.54)
	{
		camX = 0.52;
	}

	if (camY >= 0.030)
	{
		camY = 0.025;
	}

	if (camZ >= 1.6)
	{
		camZ = 1.5;
	}
}

#endif