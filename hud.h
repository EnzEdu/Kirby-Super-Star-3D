#ifndef HUD_H
#define HUD_H



class HUD
{
	private: // Variaveis
		char   poder				= '_';


	public: // Funcoes
		HUD 						();
		void   desenhaHUD			();
};


// Desenha o Kirby
HUD::HUD()
{
	//
}

void HUD::desenhaHUD()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(width, 0);
		glVertex2f(width, 100);
		glVertex2f(0, 100);
	glEnd();
}


#endif