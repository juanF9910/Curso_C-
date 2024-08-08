#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MinHeap {

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
                heapifyUp(arbol);
            } else {
                if (!arbol->izq) {
                    insertar(arbol->izq, n, arbol);
                } else if (!arbol->der) {
                    insertar(arbol->der, n, arbol);
                } else {
                    if (altura(arbol->izq) <= altura(arbol->der)) {
                        insertar(arbol->izq, n, arbol);
                    } else {
                        insertar(arbol->der, n, arbol);
                    }
                }
            }
        }

        void heapifyUp(Nodo* nodo) {
            if (!nodo->padre) return;
            if (nodo->dato < nodo->padre->dato) {
                swap(nodo->dato, nodo->padre->dato);
                heapifyUp(nodo->padre);
            }
        }

        void mostrar(Nodo* arbol, int cont) const{
            if (!arbol) return;
            mostrar(arbol->der, cont + 1);
            for (int i = 0; i < cont; ++i) cout << "   ";
            cout << arbol->dato << endl;
            mostrar(arbol->izq, cont + 1);
        }

        int altura(Nodo* arbol) const {
            if (!arbol) return 0;
            int izqAltura = altura(arbol->izq);
            int derAltura = altura(arbol->der);
            return max(izqAltura, derAltura) + 1;
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
            if (!nodo_eliminar->izq && !nodo_eliminar->der) {
                reemplazar(nodo_eliminar, nullptr);
                destruir(nodo_eliminar);
            } else {
                Nodo* menor = minimo(nodo_eliminar->der);
                nodo_eliminar->dato = menor->dato;
                eliminarnodo(menor);
            }
        }

        void heapifyDown(Nodo* nodo) {
            if (!nodo) return;
            Nodo* menor = nodo;
            if (nodo->izq && nodo->izq->dato < menor->dato) {
                menor = nodo->izq;
            }
            if (nodo->der && nodo->der->dato < menor->dato) {
                menor = nodo->der;
            }
            if (menor != nodo) {
                swap(nodo->dato, menor->dato);
                heapifyDown(menor);
            }
        }

        void eliminar(Nodo*& arbol, T n) {
            if (!arbol) return;
            if (n == arbol->dato) {
                eliminarnodo(arbol);
                heapifyDown(arbol);
            } else {
                eliminar(arbol->izq, n);
                eliminar(arbol->der, n);
            }
        }


    public:
        MinHeap() : raiz(nullptr) {}

        void insertar(T n) {
            insertar(raiz, n, nullptr);
        }

        void mostrar() const {
            mostrar(raiz, 0);
        }

        bool buscar(T n) const {
            return buscar(raiz, n);
        }

        void eliminar(T n) {
            eliminar(raiz, n);
        }

        bool buscar(Nodo* arbol, T n) const {
            if (!arbol) return false;
            if (arbol->dato == n) return true;
            return buscar(arbol->izq, n) || buscar(arbol->der, n);
        }
};

int main() {
    MinHeap<int> heap;
    vector<int> datos = {12, 8, 7, 16, 14};

    for (const auto& i : datos) {
        heap.insertar(i);
    }

    heap.mostrar();
    cout << heap.buscar(7) << endl;
    heap.eliminar(16);
    cout << endl;
    heap.mostrar();

    return 0;
}