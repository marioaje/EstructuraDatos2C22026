////libreria o cabezera
//#include "Arbol.h"
//
//
//Nodo* crearNodo(int valor) {
//
//	Nodo* nuevo = new Nodo(); //reservamos memoria para el nodo
//
//	nuevo->dato = valor; //asignamos el valor al nodo
//	nuevo->izquierdo = nullptr; //inicializamos el puntero izquierdo
//	nuevo->derecho = nullptr; //inicializamos el puntero derecho
//
//	return nuevo; //retornamos el nodo creado
//}
//
////Este metodo insertar los datos en el arbol, recibe la raiz del arbol y el valor a insertar
//Nodo* insertarNodo(Nodo* raiz, int valor) {
//	if (raiz == nullptr) { //si la raiz es nula, significa que el arbol esta vacio
//		return crearNodo(valor); //creamos un nuevo nodo con el valor y lo retornamos
//	}
//	//raiz = 6   dato 3
//	if (valor < raiz->dato) {
//		raiz->izquierdo = insertarNodo(raiz->izquierdo, valor); //si el valor es menor que el dato de la raiz, insertamos en el subarbol izquierdo
//
//	}
//	else if (valor > raiz->dato) {
//		raiz->derecho = insertarNodo(raiz->derecho, valor); //si el valor es mayor que el dato de la raiz, insertamos en el subarbol derecho
//	}
//
//	return raiz; //retornamos la raiz del arbol
//
//	
//}
//
//
//void inorden(Nodo* raiz) {
//	if (raiz != nullptr) {
//		inorden(raiz->izquierdo); //recorremos el subarbol izquierdo
//		std::cout << raiz->dato << " "; //imprimimos el dato de la raiz
//		inorden(raiz->derecho); //recorremos el subarbol derecho
//	}
//}
////
////void preorden(Nodo* raiz); al inicio izquiera --- derecha
////
////void postorden(Nodo* raiz); izquierda --- derecha al final