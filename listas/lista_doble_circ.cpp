#include <iostream>

using namespace std;

template<typename T>
class ListaCircularDoble {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo* anterior;
    };
    Nodo* lista; // Puntero al primer nodo de la lista circular doblemente enlazada

    // Función privada para eliminar el primer nodo
    void eliminarPrimero() {
        if (lista) {
            Nodo* aux = lista;
            if (lista->siguiente == lista) { // Si solo hay un nodo
                lista = nullptr;
            } else {
                lista->anterior->siguiente = lista->siguiente;
                lista->siguiente->anterior = lista->anterior;
                lista = lista->siguiente;
            }
            delete aux;
        }
    }

public:
    ListaCircularDoble();
    ~ListaCircularDoble();
    void agregar(T n);
    void sacar(T n);
    void mostrar() const;
    bool buscar(T n) const;
    int tamanio() const;
};

template<typename T>
ListaCircularDoble<T>::ListaCircularDoble() : lista(nullptr) {}

template<typename T>
ListaCircularDoble<T>::~ListaCircularDoble() {
    while (lista) {
        eliminarPrimero();
    }
}

template<typename T>
void ListaCircularDoble<T>::agregar(T n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;

    if (lista == nullptr) {
        lista = nuevo;
        lista->siguiente = lista;
        lista->anterior = lista;
    } else {
        Nodo* ultimo = lista->anterior;
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = lista;
        lista->anterior = nuevo;
    }
}

template<typename T>
void ListaCircularDoble<T>::sacar(T n) {
    if (lista != nullptr) {
        Nodo* aux = lista;

        do {
            if (aux->dato == n) {
                if (aux->siguiente == aux) { // Si solo hay un nodo
                    lista = nullptr;
                } else {
                    aux->anterior->siguiente = aux->siguiente;
                    aux->siguiente->anterior = aux->anterior;
                    if (aux == lista) {
                        lista = aux->siguiente;
                    }
                }
                delete aux;
                return;
            }
            aux = aux->siguiente;
        } while (aux != lista);

        cout << "El elemento no existe" << endl;
    } else {
        cout << "La lista está vacía" << endl;
    }
}

template<typename T>
void ListaCircularDoble<T>::mostrar() const {
    if (lista != nullptr) {
        Nodo* aux = lista;
        do {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        } while (aux != lista);
        cout << endl;
    }
}

template<typename T>
bool ListaCircularDoble<T>::buscar(T n) const {
    if (lista != nullptr) {
        Nodo* aux = lista;
        do {
            if (aux->dato == n) {
                return true;
            }
            aux = aux->siguiente;
        } while (aux != lista);
    }
    return false;
}

template<typename T>
int ListaCircularDoble<T>::tamanio() const {
    if (lista == nullptr) {
        return 0;
    }
    Nodo* aux = lista;
    int contador = 0;
    do {
        contador++;
        aux = aux->siguiente;
    } while (aux != lista);
    return contador;
}

int main() {
    ListaCircularDoble<int>* lista = new ListaCircularDoble<int>();
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