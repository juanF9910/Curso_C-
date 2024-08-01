/*
 Una pila es un lista de estructuras que tienen asociado un puntero que apunta a la 
 primer estructura, 
 en donde cada estructura tiene un dato y un puntero a la estructura siguiente. Sólo 
 se puede acceder a los datos desde un extremo de la lista. 

 Pasos para añadir(crear) a una pila: 

    1. definir un puntero a la estructura que se quire agregar (new)
    2. cargar el dato y el puntero dentro de la estructura
    3. asignar el puntero pila apunte hacia la nueva estructura. 
*/
 
#include <iostream> 
#include <stdlib.h>

using namespace std; 

struct Nodo{ //estructura del nodo de la pila. 
    int dato; 
    Nodo* siguiente; 
};

/*los argumentos de esta función son: puntero a la cima de la pila que voy a modificar, y el valor del dato a agregar*/

void agregarPila(Nodo* &pila, int n){ //el puntero pila apunta hacia el elemento de la cima actual de la pila, y lo pasamos por referencia. 

/*SE USA *& PORQUE SE PASA UN PUNTERO, PERO ADEMÁS SE HACE POR REFERENCIA, ES DECIR, PUEDO MODIFICAR HACIA DONDE APUNTA.*/
    Nodo* nuevo_nodo= new Nodo(); //paso 1, defino un puntero al nodo que quiero agregar. 

    nuevo_nodo->dato=n; //paso 2.
    nuevo_nodo->siguiente=pila; //paso 3, 
     
    pila=nuevo_nodo; //paso 4. el puntero a pila es igual al puntero del elemento agregado
}

int main(){

    Nodo* pila=NULL; //inicialmente el puntero apunta a la base. 

    agregarPila(pila, 4); 
    agregarPila(pila, 5);

    return 0; 
}