/*
 Una pila es una lista(todos los elementos del mismo tipo) de estructuras (nodos), 
 en donde cada estructura tiene un dato y un puntero a la estructura siguiente. Sólo 
 se puede acceder a los datos desde un extremo de la lista. 

 Pasos para crear una pila: 
    1. reservar un espacio de memoria para almacenar un nodo (new)
    2. cargar el dato dentro del nodo. 
    3. cargar el puntero dentro del nodo.
    4. insertar el nuevo nodo a la pila. 
*/
 
#include <iostream> 

using namespace std; 

struct Nodo{ //estructura del nodo de la pila. 
    int dato; 
    Nodo* siguiente; 
};

/*los argumentos de esta función son un puntero a la cima de la pila que voy a modificar, y el valor del dato a agregar*/

void agregarPila(Nodo* &pila, int n){ //el puntero pila apunta hacia el elemento de la cima de la pila. 

    Nodo* nuevo_nodo= new Nodo(); //paso 1, defino un puntero al nodo que quiero agregar. 

    nuevo_nodo->dato=n; //paso 2.
    nuevo_nodo->siguiente=pila; //paso 3, 
     
    pila=nuevo_nodo; //paso 4. el puntero a pila es igual al puntero del elemento agregado
}

int main(){

    Nodo *pila=NULL; //inicialmente el puntero apunta a la base. 
    return 0; 
}