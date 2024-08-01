/*
Un árbol binario de búsqueda es aquel tal que dado un nodo
todos los datos del subárbol izquierdo a este son menores, mientras que todos los
datos del subárbol derecho son mayores.  
*/
#include <iostream>

using namespace std; 

struct Nodo{ //definición del nodo
    int dato; 
    Nodo* izq; 
    Nodo* der; 
};


//inicialización del nodo 
Nodo* crearNodo(int n){ 

    Nodo* nuevo=new Nodo(); 

    nuevo->dato=n; 
    nuevo->der=NULL; 
    nuevo->izq=NULL; 

    return nuevo; 
}

/*
para insertar hay que tener en cuenta dos cosas: 
 1. el árbol puede estar vacío. 
 2. el arbol tiene un nodo o más de uno
*/

void insertar(Nodo* &arbol, int n){ //incialmente el puntero 
  //es la raiz del árbol

 Nodo* nuevo=crearNodo(n);

  if(arbol==NULL){//si el árbol está vacío 
    arbol=nuevo; 
  }else{
    //como estamos construyendo un árbol binario de búsqueda  
    /*necesitamos tener en cuenta el valor del nodo respecto a la raiz */
    int raiz=arbol->dato; 

    if(n<raiz){ /*se coloca al lado izquierdo*/
        insertar(arbol->izq, n); //recursividad, el puntero apunta hacia donde
        //quiero insertar
    }else{
        insertar(arbol->der, n);
    }
  }
}

int main(){
    Nodo* arbol=nullptr; 
    
    for(int i=0; i<5; i++){
        insertar(arbol, i); 
    }
    return 0; 
}

