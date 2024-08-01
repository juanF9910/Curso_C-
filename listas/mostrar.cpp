#include <iostream>

/*
para mostrar los elementos de la lista debemos seguir 3 pasos: 
    1. crear un nodo
    2. igualar dicho nodo a la lista
    3. recorrer la lista de inicio a fin
*/

using namespace std; 

struct Nodo{
    int dato; 
    Nodo* siguiente; 
};

void mostrar(Nodo* lista){

    Nodo* actual=new Nodo(); 
    actual=lista; 

    while(actual!=nullptr){
        cout<<actual->dato; 
        cout <<endl;
        actual=actual->siguiente; 
    }
}

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
        // Si la lista no está vacía, buscamos el último nodo
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
   
    mostrar(lista) ;

    return 0; 
}