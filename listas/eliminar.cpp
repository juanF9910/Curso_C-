/*
para eliminar un elemento de una lista se deben seguir los siguientes pasos: 
    1. preguntar si la lista está vacía
    2. crear dos puntero a estructura auxiliar y a estructura anterior
    3. apuntar auxiliar a la misma posición que lista
    4. recorrer la lista y eliminar el elemento
*/
#include <iostream>

using namespace std; 

struct Nodo{ //esto es un nodo de una lista simplemente enlazada
    int dato; 
    Nodo* siguiente; 

};

void eliminar(Nodo* &lista, int n){

    if(lista!=nullptr){
        Nodo* aux=lista; //el auxiliar apunta a la misma dirección 
        //de la lista
        Nodo* anterior=NULL;

        while(aux!=nullptr && aux->dato!=n){ //qué pasa si hay repetidos???
            /*movemos los punteros hasta que encontremos 
            el dato que queremos eliminar*/
            anterior=aux; 
            aux=aux->siguiente;
        } 
        //si no existe el elemento
        if(aux==NULL){
            cout<<"El elemento no existe"<<endl;
        }else if(anterior==NULL){ /*si el dato a eliminar es el primer 
        elemento entonces el puntero anterior no se ha movido*/
            lista=lista->siguiente;
            delete aux; 
        }else{ //si no está al principio 
            anterior->siguiente=aux->siguiente;
            delete aux; 
        }
    }else{
        cout<<"la lista está vacía"<<endl;
    }
}

void eliminar_lista(Nodo* &lista){

    while(lista!=NULL){
        Nodo* aux=lista; /*1. creamos un nodo inicial y  lo igualalos al 
        inicio de la lista*/
        lista=aux->siguiente;
        delete aux; 
    }

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
        while(aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        // El último nodo apunta al nuevo nodo
        aux->siguiente = nuevo;
    }
}

void mostrar(Nodo* lista){
    Nodo* actual=lista; //definimos un nodo auxiliar para recorrer la lista- 
    while(actual!=nullptr){
        cout<<actual->dato<<endl;
        actual=actual->siguiente; 
    }
}

int main(){

    Nodo* lista=NULL; 

    for(int i=5; i>=0; i--){
        insertar_lista(lista, i);
    }

    mostrar(lista);
    eliminar(lista, 1);
    mostrar(lista);
    cout<<"*******" <<endl;
    eliminar_lista(lista);
    mostrar(lista);
    return 0; 
}