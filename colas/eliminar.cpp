#include <iostream>

using namespace std; 

/*
Para eliminar elementos de una cola debemos seguir 3 pasos: 

    1. obtener el valor del dato a eliminar
    2. crear un nodo aux y asignarle el frente. 
    3. eliminar el nodo aux
*/


struct Nodo{
    int dato; 
    Nodo* siguiente; 
};

void eliminar(Nodo* &frente, Nodo* &fin, int &n){
    n=frente->dato;  
    Nodo* aux=frente;  //auxiliar apunta en la a la misma dirección que frente, 
    //es decir, puedo modificar esa parte de la memoria con cualquiera de los dos punteros. 

    
    if(frente==fin){ //si hay una sola estructura
        frente=NULL; 
        fin=NULL; 
    }else{
        frente=frente->siguiente; //si hay más de una estructura
    } 

    delete aux; 
}

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
        // última, ahora va a apuntar hacia la estructura nueva. 
    }

    fin=nuevo; //fin siempre apunta hacia el último elemento agregado
}

int main(){

    Nodo* frente=NULL; 
    Nodo* fin=NULL; 

    int n; 
    for (int i=0; i<5; i++){
        agregar(frente, fin, i);
    }

    while(frente!=NULL){ //siempre que haya al menos un nodo
        eliminar(frente, fin, n); //estamos modificando el valor de n como tal
        cout <<n<<endl;
    }
    return 0; 
}