/*
para buscar un elemento en una lista dbemos seguir 3 pasos: 
    1. crear un nuevo nodo
    2. igualar el nodo a la lista
    3. recorrer la lista
    4. determinar si el elemento existe o no en la lista
*/

#include <iostream>

using namespace std; 

struct Nodo{
    int dato; 
    Nodo* siguiente; 
};

bool buscar_lista(Nodo* lista, int n) {
    Nodo* actual = lista;
    while (actual != nullptr) {
        if (actual->dato == n) {
            return true; // Elemento encontrado
        }
        actual = actual->siguiente;
    }
    return false; // Elemento no encontrado
}

void insertar_lista(Nodo* &lista, int n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = nullptr; // El nuevo nodo siempre apuntará a nullptr

    if (lista == nullptr) {
        // Si la lista está vacía, el nuevo nodo será el primer elemento
        lista = nuevo;
    } else {
        // Si la lista no está vacía, buscamos el último nodo
        Nodo* aux = lista;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente; //muevo el puntero auxiliar hasta 
            //el último elemento de la lista
        }
        // El último nodo apunta al nuevo nodo
        aux->siguiente = nuevo;
    }
}

int main(){

    Nodo* lista=NULL;
    for(int i=5; i>=0; i--){
        insertar_lista(lista, i);
    }

    cout<<buscar_lista(lista, 7)<<endl;

    return 0; 
}