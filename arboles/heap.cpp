#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo* padre;
};

Nodo* crearNodo(int, Nodo*);
void insertar(Nodo*&, int, Nodo*);
void mostrar(Nodo*, int);
void heapifyUp(Nodo*);
void heapifyDown(Nodo*);
bool buscar(Nodo*, int);
int obtenerMax(Nodo*);
void eliminarMax(Nodo*&);

int main() {
    Nodo* monticulo = nullptr;
    int cont = 0;

    vector<int> datos = {12, 8, 7, 16, 14};

    for (auto&& i : datos) {
        insertar(monticulo, i, nullptr);
    }

    mostrar(monticulo, cont);
    cout << "Maximo: " << obtenerMax(monticulo) << endl;
    cout << buscar(monticulo, 7) << endl;

    eliminarMax(monticulo);
    cout << "Después de eliminar el máximo:" << endl;
    mostrar(monticulo, cont);

    return 0;
}

Nodo* crearNodo(int n, Nodo* padre) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    nuevo->padre = padre;
    return nuevo;
}

void insertar(Nodo*& arbol, int n, Nodo* padre) {
    if (arbol == nullptr) {
        arbol = crearNodo(n, padre);
    } else if (arbol->izq == nullptr) {
        insertar(arbol->izq, n, arbol);
        heapifyUp(arbol->izq);
    } else if (arbol->der == nullptr) {
        insertar(arbol->der, n, arbol);
        heapifyUp(arbol->der);
    } else {
        if (rand() % 2 == 0) {
            insertar(arbol->izq, n, arbol);
            heapifyUp(arbol->izq);
        } else {
            insertar(arbol->der, n, arbol);
            heapifyUp(arbol->der);
        }
    }
}

void heapifyUp(Nodo* nodo) {
    while (nodo->padre != nullptr && nodo->dato > nodo->padre->dato) {
        swap(nodo->dato, nodo->padre->dato);
        nodo = nodo->padre;
    }
}

void heapifyDown(Nodo* nodo) {
    while (nodo->izq != nullptr || nodo->der != nullptr) {
        Nodo* mayor = nodo;

        if (nodo->izq != nullptr && nodo->izq->dato > mayor->dato) {
            mayor = nodo->izq;
        }
        if (nodo->der != nullptr && nodo->der->dato > mayor->dato) {
            mayor = nodo->der;
        }

        if (mayor == nodo) {
            break;
        } else {
            swap(nodo->dato, mayor->dato);
            nodo = mayor;
        }
    }
}

void mostrar(Nodo* arbol, int cont) {
    if (arbol == nullptr) {
        return;
    } else {
        mostrar(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrar(arbol->izq, cont + 1);
    }
}

bool buscar(Nodo* arbol, int n) {
    if (arbol == nullptr) {
        return false;
    } else if (arbol->dato == n) {
        return true;
    } else {
        return buscar(arbol->izq, n) || buscar(arbol->der, n);
    }
}

int obtenerMax(Nodo* arbol) {
    if (arbol == nullptr) {
        throw runtime_error("El montículo está vacío");
    }
    return arbol->dato;
}

void eliminarMax(Nodo*& arbol) {
    if (arbol == nullptr) {
        throw runtime_error("El montículo está vacío");
    }

    Nodo* nodoEliminar = arbol;

    if (arbol->izq == nullptr && arbol->der == nullptr) {
        delete arbol;
        arbol = nullptr;
    } else {
        Nodo* ultimo = arbol;
        while (ultimo->izq != nullptr || ultimo->der != nullptr) {
            if (ultimo->der != nullptr) {
                ultimo = ultimo->der;
            } else {
                ultimo = ultimo->izq;
            }
        }

        swap(arbol->dato, ultimo->dato);

        if (ultimo->padre->izq == ultimo) {
            ultimo->padre->izq = nullptr;
        } else {
            ultimo->padre->der = nullptr;
        }
        delete ultimo;

        heapifyDown(arbol);
    }
}