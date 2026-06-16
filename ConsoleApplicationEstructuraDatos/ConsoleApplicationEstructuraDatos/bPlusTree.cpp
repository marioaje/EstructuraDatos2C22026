#include "bplustree.h"
#include <algorithm>

Nodo::Nodo(bool esHoja) {
    hoja = esHoja;
    siguiente = nullptr;
}


bPlusTree::bPlusTree() {
    raiz = new Nodo(true);
}

void bPlusTree::insertar(int clave) {
    int claveSubida;      
    Nodo* nuevoHijo = nullptr;

    insertarEnNodo(raiz, clave, claveSubida, nuevoHijo);

    if (nuevoHijo != nullptr) {
        Nodo* nuevaRaiz = new Nodo(false); 
        nuevaRaiz->claves.push_back(claveSubida);
        nuevaRaiz->hijos.push_back(raiz);
        nuevaRaiz->hijos.push_back(nuevoHijo);
        raiz = nuevaRaiz;
    }
}

void bPlusTree::insertarEnNodo(Nodo* nodo, int clave, int& claveSubida, Nodo*& nuevoHijo) {

    if (nodo->hoja) {
        
        nodo->claves.insert(
            upper_bound(nodo->claves.begin(), nodo->claves.end(), clave),
            clave
        );

        
        if ((int)nodo->claves.size() == ORDEN) {
            Nodo* nuevaHoja = new Nodo(true);
            int mitad = ORDEN / 2;

       
            nuevaHoja->claves.assign(nodo->claves.begin() + mitad, nodo->claves.end());
            nodo->claves.erase(nodo->claves.begin() + mitad, nodo->claves.end());

           
            nuevaHoja->siguiente = nodo->siguiente;
            nodo->siguiente = nuevaHoja;

           
            claveSubida = nuevaHoja->claves[0];
            nuevoHijo = nuevaHoja;
        } else {
            nuevoHijo = nullptr; // no hubo división
        }

    } else {
   
        int i = 0;
        while (i < (int)nodo->claves.size() && clave >= nodo->claves[i]) {
            i++;
        }

        int claveSubidaHijo;
        Nodo* nuevoHijoInterno = nullptr;

        insertarEnNodo(nodo->hijos[i], clave, claveSubidaHijo, nuevoHijoInterno);

        
        if (nuevoHijoInterno != nullptr) {
            nodo->claves.insert(nodo->claves.begin() + i, claveSubidaHijo);
            nodo->hijos.insert(nodo->hijos.begin() + i + 1, nuevoHijoInterno);

          
            if ((int)nodo->claves.size() == ORDEN) {
                Nodo* nuevoInterno = new Nodo(false);
                int mitad = ORDEN / 2;

                claveSubida = nodo->claves[mitad];

                nuevoInterno->claves.assign(nodo->claves.begin() + mitad + 1, nodo->claves.end());
                nodo->claves.erase(nodo->claves.begin() + mitad, nodo->claves.end());

                nuevoInterno->hijos.assign(nodo->hijos.begin() + mitad + 1, nodo->hijos.end());
                nodo->hijos.erase(nodo->hijos.begin() + mitad + 1, nodo->hijos.end());

                nuevoHijo = nuevoInterno;
            } else {
                nuevoHijo = nullptr;
            }
        } else {
            nuevoHijo = nullptr;
        }
    }
}

void bPlusTree::buscar(int clave) {
    Nodo* actual = raiz;


    while (!actual->hoja) {
        int i = 0;
        while (i < (int)actual->claves.size() && clave >= actual->claves[i]) {
            i++;
        }
        actual = actual->hijos[i];
    }

    
    if (binary_search(actual->claves.begin(), actual->claves.end(), clave)) {
        cout << "✔ Clave " << clave << " ENCONTRADA en el árbol." << endl;
    } else {
        cout << "✘ Clave " << clave << " NO encontrada en el árbol." << endl;
    }
}


void bPlusTree::traszao() {
    
    Nodo* actual = raiz;
    while (!actual->hoja) {
        actual = actual->hijos[0];
    }

    
    cout << "Recorrido secuencial: ";
    while (actual != nullptr) {
        for (int clave : actual->claves) {
            cout << clave << " ";
        }
        actual = actual->siguiente;
    }
    cout << endl;
}


int main() {
    bPlusTree arbol;
    int opcion, valor;

  
    int datos[] = {20, 10, 15, 25, 32, 5, 8, 17, 48, 16, 18, 19};
    cout << "Insertando datos precargados: ";
    for (int d : datos) {
        cout << d << " ";
        arbol.insertar(d);
    }
    cout << "\n✔ Datos cargados correctamente." << endl;

    do {
        cout << "\n===== Árbol B+ =====" << endl;
        cout << "1. Insertar clave" << endl;
        cout << "2. Buscar clave" << endl;
        cout << "3. Recorrido secuencial (traszao)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                arbol.insertar(valor);
                cout << "✔ Valor " << valor << " insertado." << endl;
                break;
            case 2:
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                arbol.buscar(valor);
                break;
            case 3:
                arbol.traszao();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);

    return 0;
}