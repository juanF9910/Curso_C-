#include <iostream>

using namespace std; 

struct Nodo{
    int dato; 
    Nodo* siguiente; 
};

void agregar(Nodo* &pila, int n){
    Nodo *nuevo= new Nodo();
    nuevo->dato=n; 
    nuevo->siguiente=pila; 
    pila=nuevo; 
} 

/*para poder acceder a los elementos de la pila toca ir eliminando uno a uno 
para llegar a los demás*/
void sacar(Nodo* &pila, int &n){
    Nodo* aux=pila; 
    n=aux->dato; 
    pila=aux->siguiente;
    delete aux;  
}

void mostrar(Nodo* pila) {
    /*si se quiere acceder a un dato en una posición específica se puede establecer un contador y una condición de parada
    */
    Nodo* aux = pila; // Puntero auxiliar para recorrer la pila
    while (aux != nullptr) {
        cout << aux->dato << " "; // Mostrar el dato del nodo actual
        aux = aux->siguiente; // Moverse al siguiente nodo
    }
    cout << endl;
}

int main(){

    Nodo* pila=NULL; 
    int dato; 
    cout<<"para terminar de ingresar digite un cero"<<endl;
    do{
        cout  <<"digite un número" <<endl;
        cin>>dato;

        agregar(pila, dato);
    }while(dato!=0);

    //ahora mostremos todos los número agregados a la pila

    cout<<"mostramos todos los elementos de la pila"<<endl;

   mostrar(pila);

    return 0; 
}