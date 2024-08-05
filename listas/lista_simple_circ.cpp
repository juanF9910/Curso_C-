#include <iostream>

using namespace std;

template<typename T>
class ListaCircular {

private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
    };
    Nodo* lista; // puntero al objeto de la lista circular

    // Función privada para eliminar el primer nodo
    void eliminarPrimero() {
        if (lista) {
            Nodo* aux = lista;
            if (lista->siguiente == lista) { // Si solo hay un nodo en la lista
                lista = nullptr;
            } else {
                Nodo* temp = lista;
                while (temp->siguiente != lista) { // Encontrar el último nodo
                    temp = temp->siguiente;
                }
                lista = lista->siguiente;
                temp->siguiente = lista;
            }
            delete aux;
        }
    }

public:
    ListaCircular();
    ~ListaCircular();
    void agregar(T n);
    void sacar(T n);
    void mostrar() const;
    bool buscar(T n) const;
    int tamanio() const;
};

template<typename T>
ListaCircular<T>::ListaCircular() : lista(nullptr) {}

template<typename T>
ListaCircular<T>::~ListaCircular() {
    while (lista) {
        eliminarPrimero();
    }
}

template<typename T>
void ListaCircular<T>::agregar(T n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;

    if (lista == nullptr) {
        lista = nuevo;
        lista->siguiente = lista; // Apunta a sí mismo para cerrar el círculo
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != lista) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->siguiente = lista;
    }
}

template<typename T>
void ListaCircular<T>::sacar(T n) {
    if (lista != nullptr) {
        Nodo* aux = lista;
        Nodo* anterior = nullptr;

        do {
            if (aux->dato == n) {
                if (anterior == nullptr) { // Si el nodo a eliminar es el primero
                    if (aux->siguiente == lista) { // Si solo hay un nodo
                        lista = nullptr;
                    } else {
                        Nodo* temp = lista;
                        while (temp->siguiente != lista) { // Encontrar el último nodo
                            temp = temp->siguiente;
                        }
                        lista = lista->siguiente;
                        temp->siguiente = lista;
                    }
                    delete aux;
                    return;
                } else { // Nodo no está al principio
                    anterior->siguiente = aux->siguiente;
                    delete aux;
                    return;
                }
            }
            anterior = aux;
            aux = aux->siguiente;
        } while (aux != lista);

        cout << "El elemento no existe" << endl;
    } else {
        cout << "La lista está vacía" << endl;
    }
}

template<typename T>
void ListaCircular<T>::mostrar() const {
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
bool ListaCircular<T>::buscar(T n) const {
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
int ListaCircular<T>::tamanio() const {
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
    ListaCircular<int>* lista = new ListaCircular<int>();
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