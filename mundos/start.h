#ifndef START_H
#define START_H

#include "extras.h"


class Start : public Mundo
{
	public:
		Start 						();
		void desenhar				();

	private:
		int numRegioes;
};

// Inicializador?
Start::Start() {
	//
}

void Start::desenhar()
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(width, 0);
		glVertex2f(width, height);
		glVertex2f(0, height);
	glEnd();
}

#endif