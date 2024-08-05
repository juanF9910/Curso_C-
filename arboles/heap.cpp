#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo* padre;
};

Nodo* crearNodo(int, Nodo*);
void insertar(Nodo*&, int, Nodo*, function<bool(int, int)>);
void heapifyUp(Nodo*, function<bool(int, int)>);
void heapifyDown(Nodo*, function<bool(int, int)>);
void mostrar(Nodo*, int);
void preorden(Nodo*);
void inorden(Nodo*);
void posorden(Nodo*);
bool buscar(Nodo*, int);
void eliminar(Nodo*, function<bool(int, int)>);

int main() {
    Nodo* arbol = nullptr;
    int cont = 0;

    vector<int> datos = {12, 8, 7, 16, 14};

    // Definir la función de comparación para min-heap
    auto comparadorMaxHeap = [](int a, int b) { return a < b; };

    // Definir la función de comparación para max-heap
    // auto comparadorMaxHeap = [](int a, int b) { return a > b; };

    for (auto&& i : datos) {
        insertar(arbol, i, nullptr, comparadorMaxHeap);
    }

    mostrar(arbol, cont);
    cout << buscar(arbol, 7) << endl;
    preorden(arbol);
    cout << endl;
    inorden(arbol);
    cout << endl;
    posorden(arbol);
    cout << endl;
    eliminar(arbol, comparadorMHeap);
    cout << endl;
    cont = 0;
    mostrar(arbol, cont);
    return 0;
}

Nodo* crearNodo(int n, Nodo* padre) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->der = nullptr;
    nuevo->izq = nullptr;
    nuevo->padre = padre;
    return nuevo;
}

void insertar(Nodo*& arbol, int n, Nodo* padre, function<bool(int, int)> comparador) {
    Nodo* nuevo = crearNodo(n, padre);
    if (arbol == nullptr) {
        arbol = nuevo;
    } else {
        vector<Nodo*> queue = {arbol};
        while (!queue.empty()) {
            Nodo* temp = queue.front();
            queue.erase(queue.begin());

            if (temp->izq == nullptr) {
                temp->izq = nuevo;
                nuevo->padre = temp;
                heapifyUp(nuevo, comparador);
                return;
            } else {
                queue.push_back(temp->izq);
            }

            if (temp->der == nullptr) {
                temp->der = nuevo;
                nuevo->padre = temp;
                heapifyUp(nuevo, comparador);
                return;
            } else {
                queue.push_back(temp->der);
            }
        }
    }
}

void heapifyUp(Nodo* nodo, function<bool(int, int)> comparador) {
    while (nodo->padre != nullptr && comparador(nodo->dato, nodo->padre->dato)) {
        swap(nodo->dato, nodo->padre->dato);
        nodo = nodo->padre;
    }
}

void heapifyDown(Nodo* nodo, function<bool(int, int)> comparador) {
    while (true) {
        Nodo* min = nodo;
        if (nodo->izq != nullptr && comparador(nodo->izq->dato, min->dato)) {
            min = nodo->izq;
        }
        if (nodo->der != nullptr && comparador(nodo->der->dato, min->dato)) {
            min = nodo->der;
        }
        if (min == nodo) break;
        swap(nodo->dato, min->dato);
        nodo = min;
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

void preorden(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    } else {
        cout << arbol->dato << " ";
        preorden(arbol->izq);
        preorden(arbol->der);
    }
}

void inorden(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    } else {
        inorden(arbol->izq);
        cout << arbol->dato << " ";
        inorden(arbol->der);
    }
}

void posorden(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    } else {
        posorden(arbol->izq);
        posorden(arbol->der);
        cout << arbol->dato << " ";
    }
}

Nodo* encontrarUltimo(Nodo* arbol) {
    if (arbol == nullptr) return nullptr;
    vector<Nodo*> queue = {arbol};
    Nodo* ultimo = nullptr;
    while (!queue.empty()) {
        Nodo* temp = queue.front();
        queue.erase(queue.begin());
        ultimo = temp;
        if (temp->izq != nullptr) queue.push_back(temp->izq);
        if (temp->der != nullptr) queue.push_back(temp->der);
    }
    return ultimo;
}

void eliminar(Nodo* arbol, function<bool(int, int)> comparador) {
    if (arbol == nullptr) return;
    Nodo* ultimo = encontrarUltimo(arbol);
    if (ultimo == nullptr) return;
    arbol->dato = ultimo->dato;
    if (ultimo->padre != nullptr) {
        if (ultimo->padre->izq == ultimo) {
            ultimo->padre->izq = nullptr;
        } else {
            ultimo->padre->der = nullptr;
        }
    }
    delete ultimo;
    heapifyDown(arbol, comparador);
}