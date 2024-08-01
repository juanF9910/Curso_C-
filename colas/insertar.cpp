/*
Una cola  es un lista de estructuras que tienen asociado un puntero que apunta a la 
primer estructura y otro que apunta a la última

para insertar elementos en una cola se siguen 3 pasos:

    1. definir el puntero a la estructura que se quiere agregar
    2. cargar el dato y el puntero dentro de la estructura
    3. asignar los punteros frente y fin hacia la nueva estructura
*/

/*los punteros que apuntan a estructuras apuntan a la primer componente
y se mueven en el orden de los datos.
*/

#include <iostream>

struct Nodo{
    int dato; 
    Nodo* siguiente; 

};

/*la clave para entender esto está en que si se definen varios punteros 
a la misma dirección, yo puedo modificar con cualquiera de ellos*/

void agregar(Nodo* &frente, Nodo* &fin, int n){

    Nodo* nuevo=new Nodo(); //puntero a la estructura que quiero agregar

    nuevo->dato=n; //agrego el dato
    nuevo->siguiente=NULL ; /*la última estructura que se agrega va a apuntar
    hacia el valor nulo*/ 

    if(frente==NULL){ //si no hay ningún nodo
        frente=nuevo; //si es null le asigna el valor de la nueva estructura
    }else{ //si hay nodos. 
        fin->siguiente=nuevo; //el puntero de la estructura que antes era la
        // última, ahora va a apuntar hacia la estructura nueva. el puntero dentro de fin
        //va a dejar de apuntar a null y va a pasar a apuntar a nuevo. 
    }

    fin=nuevo; //fin siempre apunta hacia el último elemento agregado, el puntero dentro de nuevo apunta hacia null. 
}

int main(){

    Nodo* frente=NULL; 
    Nodo* fin=NULL;

    agregar(frente, fin, 5); 



    return 0; 
}
