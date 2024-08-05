#include <iostream>

using namespace std;

template<typename T>
class ListaSimple {

    private:
        struct Nodo {
            T dato;
            Nodo* siguiente;
        };
        Nodo* lista; //puntero al objeto de la lista simple 

        // Función privada para eliminar el primer nodo
        void eliminar_lista(){
            if (lista) { //para eliminar desde el principio hasta el final
                Nodo* aux = lista;
                lista = lista->siguiente;
                delete aux;
            }
        }

    public:
        ListaSimple();
        ~ListaSimple();
        void agregar(T n);
        void sacar(T n);
        void mostrar() const;
        bool buscar(T n) const;
        int tamanio() const;
};

template<typename T>
ListaSimple<T>::ListaSimple() : lista(nullptr) {}

template<typename T>
ListaSimple<T>::~ListaSimple() {
    while (lista) {
        eliminar_lista();
    }
}

template<typename T>
void ListaSimple<T>::agregar(T n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = nullptr;

    if (lista == nullptr) {
        lista = nuevo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

template<typename T>
void ListaSimple<T>::sacar(T n) {
    if (lista != nullptr) {
        Nodo* aux = lista;
        Nodo* anterior = nullptr;

        while (aux != nullptr && aux->dato != n) {
            anterior = aux;
            aux = aux->siguiente;
        } //correra hasta que encuentre el elemento o hasta que llegue al final de la lista

        if (aux == nullptr) { //si no existe el elemento
            cout << "El elemento no existe" << endl;
        } else if (anterior == nullptr) { //si el dato a eliminar es el primer elemento entonces el puntero anterior no se ha movido
            lista = lista->siguiente;
            delete aux;
        } else { //si no está al principio
            anterior->siguiente = aux->siguiente;
            delete aux;
        }
    } else {
        cout << "La lista está vacía" << endl;
    }
}


template<typename T>
void ListaSimple<T>::mostrar() const {
    Nodo* aux = lista;
    while (aux) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

template<typename T>
bool ListaSimple<T>::buscar(T n) const {
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
int ListaSimple<T>::tamanio() const {
    Nodo* aux = lista;
    int contador = 0;
    while (aux) {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}

int main() {
    ListaSimple<int>* lista = new ListaSimple<int>();
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