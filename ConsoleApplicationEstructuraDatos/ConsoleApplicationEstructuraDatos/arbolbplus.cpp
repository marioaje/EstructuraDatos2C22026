//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////
////#maximo va hacer variable con los elementos creamos, o necesitos establecer
////maximo de claves, por nodo
//const int ORDEN = 3; // Orden del árbol B+
//
//
//
//
////La estructura que ocupe
//class Nodo {
//public:
//	bool esHoja;
//	std::vector<int> claves;
//	std::vector<Nodo*> hijos;
//	Nodo* siguiente;// esto nos sirve para los recorridos secuencuales(como una guia)
//
//
//	Nodo(bool hoja) {
//		esHoja = hoja;
//		siguiente = nullptr;
//	}
//};
//
//
//
//class arbolbplus {
//private:
//	Nodo* raiz;
//
//
//	//busca, insertar ---> /%/%/%/%/%/%/%/??? , revisequenoestecreado o lleno
//public:
//	arbolbplus() {
//		raiz = new Nodo(true);
//	}
//
//
//	bool buscar(int datos) {
//		Nodo* actual = raiz;
//
//		while (!actual->esHoja) {
//			int i = 0;
//			while (i < actual->claves.size() && datos >= actual->claves[i]) {
//				i++;
//			}
//			actual = actual->hijos[i];
//		}
//
//		return binary_search(actual->claves.begin(), actual->claves.end(), datos);
//	}
//
//
//	void insertar() {
//
//	}
//
//
//private:
//	//esto es similar a una funcion recursiva
//	void revisequenoestecreado(Nodo* nodo, int datos) {
//		if (nodo->esHoja) {
//			nodo->claves.insert(
//				upper_bound(nodo->claves.begin(), nodo->claves.end(), datos), datos);
//		}
//		else {
//			int i = 0;
//			/*Len de la ruta completa*/
//			while (i < nodo->claves.size() && datos >= nodo->claves[i]) {
//				i++;
//
//				//const int ORDEN = 3; // Orden del árbol B+
//
//
//				if (nodo->hijos[i]->claves.size() == ORDEN) {
//					dividirHoja(nodo, i);
//					if (datos >= nodo->claves[i]) {
//						i++;
//					}
//
//				}
//
//			}
//			revisequenoestecreado(nodo->hijos[i], datos);
//		}
//
//	}
//
//
//	void dividirHoja(Nodo* padre, int indice) {
//		Nodo* hijo = padre->hijos[indice];
//		Nodo* nuevo = new Nodo(hijo->esHoja);//parte de la rotacion del elemento nuevo
//
//		int mitad = ORDEN / 2;
//
//
//		//Movemos las claves hacia el nuevo nodo
//		nuevo->claves.assign(hijo->claves.begin() + mitad, hijo->claves.end());
//		hijo->claves.erase(hijo->claves.begin() + mitad, hijo->claves.end());
//
//		//que pasa si esto no es una hoja, entonces movemos los hijos, similar al giro izquierda derecha
//		if (!hijo->esHoja) {
//			nuevo->hijos.assign(hijo->hijos.begin() + mitad + 1, hijo->hijos.end());
//			hijo->hijos.erase(hijo->hijos.begin() + mitad + 1, hijo->hijos.end());
//		}
//
//		//insertamos las claves en el nodo padre
//		padre->claves.insert(padre->claves.begin() + indice, nuevo->claves[0]);
//		padre->hijos.insert(padre->hijos.begin() + indice + 1, nuevo);
//
//
//
//		//enlazar las hojas
//		if (hijo->esHoja) {
//			nuevo->siguiente = hijo->siguiente;
//			hijo->siguiente = nuevo;
//		}
//
//
//	}
//
//
//};
//
//
////int main() {
////	arbolbplus arbol;
////	/*arbol.insertar(10);
////	arbol.insertar(20);
////	arbol.insertar(5);
////	arbol.insertar(15);
////	arbol.insertar(25);
////	cout << "Buscar 15: " << (arbol.buscar(15) ? "Encontrado" : "No encontrado") << endl;
////	cout << "Buscar 30: " << (arbol.buscar(30) ? "Encontrado" : "No encontrado") << endl;*/
////	return 0;
////}