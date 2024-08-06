#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class ArbolBinarioBusqueda {
private:
    struct Nodo {
        T dato;
        Nodo* izq;
        Nodo* der;
        Nodo* padre;

        Nodo(T n, Nodo* p) : dato(n), izq(nullptr), der(nullptr), padre(p) {}
    };

    Nodo* raiz;

    void insertar(Nodo*& arbol, T n, Nodo* padre) {
        if (!arbol) {
            arbol = new Nodo(n, padre);
        } else {
            if (n < arbol->dato) {
                insertar(arbol->izq, n, arbol);
            } else {
                insertar(arbol->der, n, arbol);
            }
        }
    }

    void mostrar(Nodo* arbol, int cont) const {
        if (!arbol) return;
        mostrar(arbol->der, cont + 1);
        for (int i = 0; i < cont; ++i) cout << "   ";
        cout << arbol->dato << endl;
        mostrar(arbol->izq, cont + 1);
    }

    bool buscar(Nodo* arbol, T n) const {
        if (!arbol) return false;
        if (arbol->dato == n) return true;
        return n < arbol->dato ? buscar(arbol->izq, n) : buscar(arbol->der, n);
    }

    void preorden(Nodo* arbol) const {
        if (!arbol) return;
        cout << arbol->dato << " ";
        preorden(arbol->izq);
        preorden(arbol->der);
    }

    void inorden(Nodo* arbol) const {
        if (!arbol) return;
        inorden(arbol->izq);
        cout << arbol->dato << " ";
        inorden(arbol->der);
    }

    void posorden(Nodo* arbol) const {
        if (!arbol) return;
        posorden(arbol->izq);
        posorden(arbol->der);
        cout << arbol->dato << " ";
    }

    Nodo* minimo(Nodo* arbol) const {
        return arbol->izq ? minimo(arbol->izq) : arbol;
    }

    void reemplazar(Nodo* arbol, Nodo* nuevo) {
        if (arbol->padre) {
            if (arbol == arbol->padre->izq) {
                arbol->padre->izq = nuevo;
            } else {
                arbol->padre->der = nuevo;
            }
        }
        if (nuevo) {
            nuevo->padre = arbol->padre;
        }
    }

    void destruir(Nodo* nodo) {
        delete nodo;
    }

    void eliminarnodo(Nodo* nodo_eliminar) {
        if (nodo_eliminar->izq && nodo_eliminar->der) { // Tiene dos hijos 
            Nodo* menor = minimo(nodo_eliminar->der);
            nodo_eliminar->dato = menor->dato;
            eliminarnodo(menor);
        } else if (nodo_eliminar->izq) { // Tiene un hijo izquierdo
            reemplazar(nodo_eliminar, nodo_eliminar->izq);
            destruir(nodo_eliminar);
        } else if (nodo_eliminar->der) { // Tiene un hijo derecho
            reemplazar(nodo_eliminar, nodo_eliminar->der);
            destruir(nodo_eliminar);
        } else { // No tiene hijos
            reemplazar(nodo_eliminar, nullptr);
            destruir(nodo_eliminar);
        }
    }

    void eliminar(Nodo*& arbol, T n) {
        if (!arbol) return;
        if (n < arbol->dato) {
            eliminar(arbol->izq, n);
        } else if (n > arbol->dato) {
            eliminar(arbol->der, n);
        } else {
            eliminarnodo(arbol);
        }
    }

public:
    ArbolBinarioBusqueda() : raiz(nullptr) {}

    void insertar(T n) {
        insertar(raiz, n, nullptr);
    }

    void mostrar() const {
        mostrar(raiz, 0);
    }

    bool buscar(T n) const {
        return buscar(raiz, n);
    }

    void preorden() const {
        preorden(raiz);
        cout << endl;
    }

    void inorden() const {
        inorden(raiz);
        cout << endl;
    }

    void posorden() const {
        posorden(raiz);
        cout << endl;
    }

    void eliminar(T n) {
        eliminar(raiz, n);
    }
};

int main() {
    ArbolBinarioBusqueda<int> arbol;
    vector<int> datos = {12, 8, 7, 16, 14};

    for (const auto&i : datos) {
        arbol.insertar(i);
    }

    arbol.mostrar();
    cout << arbol.buscar(7) << endl;
    arbol.preorden();
    arbol.inorden();
    arbol.posorden();
    arbol.eliminar(16);
    cout << endl;
    arbol.mostrar();

    return 0;
}