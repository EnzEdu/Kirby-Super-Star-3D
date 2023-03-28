/*
 * Atividade Game - Computacao Grafica
 * Codigo OpenGL responsavel pela definicao das estruturas locais de um mundo no jogo
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: ??/03/2023
*/

#ifndef EXTRAS_H
#define EXTRAS_H




/* Estrutura de classe de um "objeto" dentro de um mundo
 * Pode caracterizar um comida, um inimigo...
 */
class Objeto
{
	public:
		char tipo;			// c = comida, i = inimigo
		bool usarTextura;
		float coordX, coordY, coordZ;
		float corR, corG, corB;
		float texX1, texX2, texY1, texY2;
		/*
		void moveObjeto(float coordX, float coordY, float coordZ)
		{
			coordX += coordX;
			coordY += coordY;
			coordZ += coordZ;
		*/
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

		forward_list<Regiao> regioes;

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
		 * Funcao que cria um objeto e coloca na lista de objetos
		 * da regiao que esta no topo da lista de regioes
		 */
		void pushObjeto(char tipo, bool usarTextura,
						float coordX, float coordY, float coordZ,
						float corR, float corG, float corB,
						float texX1, float texX2, float texY1, float texY2)
		{
			Objeto o;
			o.tipo = tipo; o.usarTextura = usarTextura;
			o.coordX = coordX; o.coordY = coordY; o.coordZ = coordZ;
			o.corR = corR; o.corG = corG; o.corB = corB;
			o.texX1 = texX1; o.texX2 = texX2; o.texY1 = texY1; o.texY2 = texY2;

			regioes.front().objetos.push_front(o);
		}

		forward_list<Regiao> getRegioes()
		{
			return regioes;
		}

		void setEstadoObjeto(forward_list<int> dados)
		{
			// Iterador dos dados retornados (regiao e objeto)
			forward_list<int>::iterator it = dados.before_begin();

			// Identifica a regiao informada (primeiro dado catalogado)
			advance(it, 1);
			int regiaoInformada = *it;
			forward_list<Regiao>::iterator r = regioes.begin();
			advance(r, regiaoInformada);


			// Identifica o objeto anterior ao informado
			advance(it, 1);
			int objetoInformado = *it;

			// Identifica o modo informado
			advance(it, 1);
			int modoInformado = *it;

			forward_list<Objeto>::iterator o = r->objetos.before_begin();
			advance(o, objetoInformado);


			//
			if (modoInformado == 0)
			{
				// Remove o objeto seguinte (o objeto informado)
				r->getObjetos().erase_after(o);
			}
			else
			{
				
				//printf("x=%.2lf\n", o->coordX);
				//o->moveObjeto(0.01, 0.00, 0.00);
				advance(o, 1);
				Objeto obj;
				obj.tipo = o->tipo; obj.usarTextura = o->usarTextura;
				obj.coordX = o->coordX - 0.01; obj.coordY = o->coordY; obj.coordZ = o->coordZ;
				obj.corR = o->corR; obj.corG = o->corG; obj.corB = o->corB;
				obj.texX1 = o->texX1; obj.texX2 = o->texX2; obj.texY1 = o->texY1; obj.texY2 = o->texY2;
				
//				printf("a\n");
				
				forward_list<Objeto>::iterator objs = r->objetos.before_begin();
				advance(objs, objetoInformado);

//				printf("b\n");

				r->getObjetos().erase_after(objs);
				r->getObjetos().emplace_after(objs, obj);
				
//				printf("c\n");
//				printf("%ld\n", distance(r->getObjetos().begin(), r->getObjetos().end()));
			}
		}
};


#endif
