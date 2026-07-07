#pragma once
#include <iostream>
#include <vector>

using namespace std;

const int ORDEN = 4; // Orden del árbol B+ (máximo de claves por nodo = ORDEN - 1)

struct Nodo {
    bool hoja;
    vector<int> claves;
    vector<Nodo*> hijos;
    Nodo* siguiente;

    Nodo(bool esHoja);
};

class bPlusTree {
private:
    Nodo* raiz;

    // Función recursiva interna para insertar
    void insertarEnNodo(Nodo* nodo, int clave, int& claveSubida, Nodo*& nuevoHijo);

    // Divide un nodo hijo cuando está lleno
    void dividir(Nodo* padre, int indicePadre, int& claveSubida, Nodo*& nuevoHijo);

public:
    bPlusTree();

    void insertar(int clave);

    void buscar(int clave);

    void traszao(); // Recorrido secuencial por hojas
};