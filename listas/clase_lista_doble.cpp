#include <iostream>

using namespace std;

template<typename T>
class ListaDoble {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo* anterior;
    };
    Nodo* lista; // Puntero al primer nodo de la lista doblemente enlazada

    // Función privada para eliminar el primer nodo
    void eliminarPrimero() {
        if (lista) {
            Nodo* aux = lista;
            lista = lista->siguiente;
            if (lista) {
                lista->anterior = nullptr;
            }
            delete aux;
        }
    }

public:
    ListaDoble();
    ~ListaDoble();
    void agregar(T n);
    void sacar(T n);
    void mostrar() const;
    bool buscar(T n) const;
    int tamanio() const;
};

template<typename T>
ListaDoble<T>::ListaDoble() : lista(nullptr) {}

template<typename T>
ListaDoble<T>::~ListaDoble() {
    while (lista) {
        eliminarPrimero();
    }
}

template<typename T>
void ListaDoble<T>::agregar(T n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;

    if (lista == nullptr) {
        lista = nuevo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
}

template<typename T>
void ListaDoble<T>::sacar(T n) {
    if (lista != nullptr) {
        Nodo* aux = lista;

        while (aux != nullptr && aux->dato != n) {
            aux = aux->siguiente;
        }

        if (aux == nullptr) {
            cout << "El elemento no existe" << endl;
        } else {
            if (aux->anterior != nullptr) {
                aux->anterior->siguiente = aux->siguiente;
            } else {
                lista = aux->siguiente;
            }
            if (aux->siguiente != nullptr) {
                aux->siguiente->anterior = aux->anterior;
            }
            delete aux;
        }
    } else {
        cout << "La lista está vacía" << endl;
    }
}

template<typename T>
void ListaDoble<T>::mostrar() const {
    Nodo* aux = lista;
    while (aux) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

template<typename T>
bool ListaDoble<T>::buscar(T n) const {
    Nodo* aux = lista;
    while (aux) {
        if (aux->dato == n) {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}


template<typename T>
int ListaDoble<T>::tamanio() const {
    Nodo* aux = lista;
    int contador = 0;
    while (aux) {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}

int main() {
    ListaDoble<int>* lista = new ListaDoble<int>();
    for (int i = 5; i >= 0; i--) {
        lista->agregar(i);
    }
    lista->mostrar();
    cout << "Tamaño de la lista: " << lista->tamanio() << endl;
    lista->sacar(3);
    lista->mostrar();
    cout << "Tamaño de la lista: " << lista->tamanio() << endl;
    lista->buscar(3) ? cout << "El elemento 3 está en la lista." << endl : cout << "El elemento 3 no está en la lista." << endl;
    delete lista;
    return 0;
}