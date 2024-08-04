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
void sacar(Nodo* &pila){
    Nodo* aux=pila; 
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

void buscar(Nodo* pila, int n){
    Nodo* aux=pila; 
    while(aux!=NULL){
        if(aux->dato==n){
            cout<<"el número "<<n<<" ha sido encontrado"<<endl;
        }
        aux=aux->siguiente;
    }
}

int tamanio(Nodo* pila){
    Nodo* aux=pila; 
    int contador=0; 
    while(aux!=NULL){
        contador++;
        aux=aux->siguiente;
    }
    return contador; 
}

int main(){

    Nodo* pila=NULL;  //la pila siempre se inicializa en nulo.
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
   sacar(pila);
   mostrar(pila);

    return 0; 
}