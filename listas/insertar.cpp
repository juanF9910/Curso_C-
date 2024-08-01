
/*para insertar estruturas a una lista se deben 
seguir los siguientes pasos:  
    1. crear un nuevo nodo
    2. añadir el dato al nodo 
    3. crear dos estructuras auxiliares y asignar
        el puntero lista  a uno de ellos
    4. insertar la estructura a la lista. 
*/

#include <iostream>

using namespace std; 

struct Nodo{ //creamos el nodo, o unidad fundamental de la lista. 
    int dato;
    Nodo* siguiente; 
};


void insertar_orden(Nodo* &lista, int n){
    //esta función lo que hace es insertar en orden
    Nodo* nuevo=new Nodo();
    nuevo->dato=n; 

    Nodo* aux1=lista; 
    Nodo* aux2; 
   
    while((aux1!= nullptr) && (aux1->dato < n)){
        aux2=aux1; 
        aux1=aux1->siguiente;
    }
  
    if(lista==aux1){
        lista=nuevo;
    }else{
        aux2->siguiente=nuevo;
    }

    nuevo->siguiente=aux1; 
}

void insertar_lista(Nodo* &lista, int n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = nullptr; // El nuevo nodo siempre apuntará a nullptr

    if (lista == nullptr) {
        // Si la lista está vacía, el nuevo nodo será el primer elemento
        lista = nuevo;
    } else {
        // Si la lista no está vacía, buscamos el último nodo, movemos el
        //puntero. 
        Nodo* aux = lista;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
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
    return 0; 
}
