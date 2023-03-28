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
         		          0.00,     camY   , camZ - 1.5,
                		  0.00,     1.00   ,    0.00   );
			}
		break;

		case 1:		// Camera estatica nas costas
			{
		        gluLookAt(0.0, 0.75, 2.0,
        		          0.0, 0.0, 0.0,
                		  0.0, 1.0, 0.0);
			}
		break;
	}
}

#endif