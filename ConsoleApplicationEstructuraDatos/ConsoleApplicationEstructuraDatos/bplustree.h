#pragma once
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
#include <vector>

using namespace std;


struct Nodo
{
	/*int dato; ==> vectores*/
	bool hoja; // Indica si el nodo es una hoja
	vector<int> claves;
	vector<Nodo*> hijos;
	Nodo* siguiente;

	Nodo(bool esHoja);
};

class bPlusTree {


private:
	Nodo* raiz;

public:
	bPlusTree();

	void insertar(int claves);

	void buscar(int clave);
	
	void traszao();

};
