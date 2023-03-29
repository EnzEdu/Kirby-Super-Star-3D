/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL/GLUT responsavel pelas estruturas que compoem um mundo
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 29/03/2023
*/


#ifndef EXTRAS_H
#define EXTRAS_H




/* Estrutura de classe de um "objeto" dentro de um mundo
 * Pode caracterizar um comida, um inimigo...
 */
class Objeto
{
	public:
		char tipo;
		float coordX, coordY, coordZ;
		float corR, corG, corB;
		float texX1, texX2, texY1, texY2;
};


/* Estrutura de classe de uma "regiao" dentro de um mundo
 * Uma regiao caracteriza um chao e duas paredes (ou 3 cubos ao todo)
 * Uma regiao tambem pode conter objetos ou nao
 * Um "mundo" eh formado por um conjunto de regioes
 */
class Regiao
{
	public:
		// Chao
		float chCoordX, chCoordY, chCoordZ;
		float chTexX1, chTexX2, chTexY1, chTexY2;

		// Paredes
		float paTexX1, paTexX2, paTexY1, paTexY2;

		// Lista de objetos
		forward_list<Objeto> objetos;

		/*
		 *	Funcao que retorna a lista de objetos da regiao
		 */
		forward_list<Objeto> getObjetos()
		{
			return objetos;
		}
};


class Mundo
{
	public:
		// Define as coordenadas dos vertices de um cubo
		// 8 = num de vertices de um cubo, 3 = coordenadas xyz
		GLfloat coordsVertices[8][3] = {
			{-0.75, -0.75,  0.75},	// Vertice 0
			{ 0.75, -0.75,  0.75},	// Vertice 1
			{ 0.75, -0.75, -0.75},	// Vertice 2
			{-0.75, -0.75, -0.75},	// Vertice 3

			{-0.75,  0.75,  0.75},	// Vertice 4
			{ 0.75,  0.75,  0.75},	// Vertice 5
			{ 0.75,  0.75, -0.75},	// Vertice 6
			{-0.75,  0.75, -0.75} 	// Vertice 7
		};

		// Define as faces de um cubo, com base na ordem dos vertices
		// 6 = num de faces de um cubo, 4 = num de vertices em uma face
		GLuint coordsFaces[6][4] = {
			// Faces laterais
			{4, 0, 1, 5},	// Face 0 (frente)
			{5, 1, 2, 6},	// Face 1 (direita)
			{6, 2, 3, 7},	// Face 2 (costas)
			{7, 3, 0, 4},	// Face 3 (esquerda)

			// Faces horizontais
			{0, 3, 2, 1},	// Face 4 (inferior)
			{4, 5, 6, 7}	// Face 5 (superior)
		};

		// Lista de regioes do mundo
		forward_list<Regiao> regioes;


		/*
		 *	Funcao que instancia uma regiao e salva na lista de regioes do mundo
		 */
		void pushRegiao(float chCoordX, float chCoordY, float chCoordZ,
			            float chTexX1, float chTexX2, float chTexY1, float chTexY2,
			            float paTexX1, float paTexX2, float paTexY1, float paTexY2)
		{
			Regiao r;
			r.chCoordX = chCoordX; r.chCoordY = chCoordY; r.chCoordZ = chCoordZ;
			r.chTexX1 = chTexX1; r.chTexX2 = chTexX2; r.chTexY1 = chTexY1; r.chTexY2 = chTexY2;
			r.paTexX1 = paTexX1; r.paTexX2 = paTexX2; r.paTexY1 = paTexY1; r.paTexY2 = paTexY2;

			regioes.push_front(r);
		}


		/* 
		 *	Funcao que instancia um objeto e salva na lista de objetos da regiao
		 *	que esta no topo da lista
		 */
		void pushObjeto(char tipo,
						float coordX, float coordY, float coordZ,
						float corR, float corG, float corB,
						float texX1, float texX2, float texY1, float texY2)
		{
			Objeto o;
			o.tipo = tipo;
			o.coordX = coordX; o.coordY = coordY; o.coordZ = coordZ;
			o.corR = corR; o.corG = corG; o.corB = corB;
			o.texX1 = texX1; o.texX2 = texX2; o.texY1 = texY1; o.texY2 = texY2;
			regioes.front().objetos.push_front(o);
		}

		/*
		 *	Funcao que retorna a lista de regioes do mundo
		 */
		forward_list<Regiao> getRegioes()
		{
			return regioes;
		}

		/*
		 *	Funcao que modifica o estado do objeto durante a execucao,
		 *	apos o contato com Kirby
		 */
		void setEstadoObjeto(forward_list<double> dados)
		{
			// Iterador dos dados retornados
			forward_list<double>::iterator it = dados.before_begin();


			// Identifica a regiao informada (primeiro dado catalogado)
			advance(it, 1);
			int regiaoInformada = *it;
			forward_list<Regiao>::iterator r = regioes.begin();
			advance(r, regiaoInformada);

			// Identifica o objeto informado (segundo dado catalogado)
			advance(it, 1);
			int objetoInformado = *it;

			// Identifica o modo informado (terceiro dado catalogado)
			advance(it, 1);
			int modoInformado = *it;


			// Iterador dos objetos do mundo, que avanca ate o objeto anterior ao informado
			forward_list<Objeto>::iterator o = r->objetos.before_begin();
			advance(o, objetoInformado);


			// Tratamento do objeto com base no modo
			switch (modoInformado)
			{
				case 0:
					{
						// Remove o objeto seguinte (o objeto informado)
						r->getObjetos().erase_after(o);
					}
				break;

				case 1:
					{
						// Movimenta o objeto, recriando-o com a nova coordenada e re-inserindo na lista de objetos
						advance(o, 1);

						Objeto obj;
						obj.tipo = o->tipo;
						obj.coordX = o->coordX; obj.coordY = o->coordY; obj.coordZ = o->coordZ;
						
						// Objeto se desloca com base na direcao do Kirby
						switch (player.getDirecao())
						{
							case 0: obj.coordZ += 0.01; break;	// FRENTE
							case 1: obj.coordX += 0.01; break;  // ESQUERDA
							case 2: obj.coordZ -= 0.01; break;  // COSTAS
							case 3: obj.coordX -= 0.01; break;  // DIREITA
						}

						obj.corR = o->corR; obj.corG = o->corG; obj.corB = o->corB;
						obj.texX1 = o->texX1; obj.texX2 = o->texX2; obj.texY1 = o->texY1; obj.texY2 = o->texY2;

						forward_list<Objeto>::iterator objs = r->objetos.before_begin();
						advance(objs, objetoInformado);

						r->getObjetos().erase_after(objs);
						r->getObjetos().emplace_after(objs, obj);
					}
				break;
			}
		}
};


#endif
