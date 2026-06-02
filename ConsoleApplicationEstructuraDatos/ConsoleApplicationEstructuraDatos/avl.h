#pragma once
//Árbol Balanceado
//
//Desarrolle un programa que implemente un árbol balanceado.(Base de datos, archivos, gestion de busquedas
// El sistema debe permitir al usuario :
//
//Insertar valores numéricos en el árbol mediante una interfaz en consola.
//
//Elegir si desea insertar más datos o visualizar los recorridos del árbol.
//
//Observar que el árbol se mantiene balanceado automáticamente tras cada inserción, 
// evitando que se degrade en una lista.
//
//El objetivo es que el estudiante compare el funcionamiento entre un árbol binario de búsqueda
// tradicional y un árbol balanceado, analizando las diferencias en la forma del árbol y en la eficiencia de búsqueda.

#include <iostream>

using namespace std;


struct Nodo
{
	int dato;
	Nodo* izquierdo;
	Nodo* derecho;
	int altura; // Altura del nodo para el balanceo

	Nodo(int valor);
};

class AVL {


	private:
		Nodo* raiz;

		//Funciones auxiliares para el balanceo
		int obtenerAltura(Nodo* nodo);

		int obtenerBalance(Nodo* nodo);

		Nodo* rotarDerecha(Nodo* nodo);

		Nodo* rotarIzquierda(Nodo* nodo);

		Nodo* insertarNodo(Nodo* nodo, int valor );

		void inOrden(Nodo* nodo);

		void preOrden(Nodo* nodo);

		void postOrden(Nodo* nodo);

		//balance
		//giro a la derecha
		//giro a la izquierda
		//inserta
		//in
		//pre
		//post

	public:
		AVL();
		void insertar(int valor);

		void inOrden();

		void preOrden();

		void postOrden();
};
