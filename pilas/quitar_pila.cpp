/*
Dado un puntero pila, pasos para quitar elementos del mismo, siempre se saca el que está en la cima. 

1. crear un puntero auxiliar de tipo nodo y apuntar a la misma 
    estructura que apunta pila (cima). 
2. igualar el dato de la estructura auxiliar 
    al dato que está en la estructura de la cima. 
3. Hacer que el puntero pila apunte hacia el siguiente nodo. 
4. Eliminar el puntero auxiliar. 
*/

#include <iostream>


using namespace std; 

struct Nodo{

    int dato; 
    Nodo* siguiente; 
};

void sacar(Nodo* &pila, int &n){ //el n debe ser por referencia para modificar su valor. 

    Nodo* aux=pila; //el puntero auxiliar apunta hacia la estructura de la cima de la pila.
    n=aux->dato; //guardamos el dato para poder eliminarlo
    pila=aux->siguiente; /*pila apunta hacia la estructura siguiente*/ 
    delete aux; //eliminamos el puntero a la estructura auxiliar
}

void agregar(Nodo* &pila, int n){ 

    Nodo* nuevo_nodo= new Nodo(); 
    nuevo_nodo->dato=n; 
    nuevo_nodo->siguiente=pila;
    pila=nuevo_nodo;
}

int main(){

    Nodo* pila=NULL; 
    int dato; //entero auxiliar, 

    for(int i=0;i<5; i++){
        agregar(pila, i);
    }

    while(pila !=NULL){

        sacar(pila, dato); //primero tengo que sacar un dato para que se llene la variable dato y poder imprimirla.
        cout<<dato<<endl;
    }



    return 0; 
}