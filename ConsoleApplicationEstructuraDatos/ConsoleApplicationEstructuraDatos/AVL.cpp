#include "avl.h"
#include <algorithm>

using namespace std;

//Primero ajustamos en nodo base
Nodo::Nodo(int valor) 
{
	dato = valor;
	izquierdo = nullptr;
	derecho = nullptr;
	altura = 1; // Altura del nodo para el balanceo
}

//Consturctor incial AVL
AVL::AVL() {
	raiz = nullptr;
}

//Funciones auxiliares para el balanceo

int AVL::obtenerAltura(Nodo* nodo) {
	if (nodo == nullptr) {
		return 0;
	}
	return nodo->altura;
}



int AVL::obtenerBalance(Nodo* nodo) {
	if (nodo == nullptr) {
		return 0;
	}
	/*return izquieda - derecha (en sus alturas);*/
}


Nodo* AVL::rotarDerecha(Nodo* izq) {//Paso 1

	Nodo* derc = izq->izquierdo;//Paso 1
	Nodo* temporal = derc->derecho;//paso 2

	derc->derecho = izq;//Paso 1
	izq->izquierdo = temporal;//Paso 2	

	izq->altura = max(obtenerAltura(izq->izquierdo), obtenerAltura(izq->derecho)) + 1;//Paso 3
	derc->altura = max(obtenerAltura(derc->izquierdo), obtenerAltura(derc->derecho)) + 1;//Paso 3

	// Implementación de la rotación a la derecha
	return derc;//Paso 4
}

//Lo mismo pero al reves para la rotacion a la izquierda
//Nodo* AVL::rotarDerecha(Nodo* izq) {//Paso 1
//
//	Nodo* derc = izq->izquierdo;//Paso 1
//	Nodo* temporal = derc->derecho;//paso 2
//
//	derc->derecho = izq;//Paso 1
//	izq->izquierdo = temporal;//Paso 2	
//
//	izq->altura = max(obtenerAltura(izq->izquierdo), obtenerAltura(izq->derecho)) + 1;//Paso 3
//	derc->altura = max(obtenerAltura(derc->izquierdo), obtenerAltura(derc->derecho)) + 1;//Paso 3
//
//	// Implementación de la rotación a la derecha
//	return derc;//Paso 4
//}

Nodo* AVL::insertarNodo(Nodo* nodo, int valor) {
	/*paso 1 si es null
	paso 2 si es mayor el dato
	paso 3 si es menor el dato

retur nodo*/


	//sacan altura // 1+ max(obtenerAltura(derc->izquierdo), obtenerAltura(derc->derecho));//similar al Paso 3

	//balance = obtieneBalance

	//si el balance > 1  && //	valor a la izquierda
	//	retorna a la derecha

	//	si el balance < -1 && //	valor a la derecha
	//	retorna a la izquierda
}


//Los recorridos son similares al ejemplo 1