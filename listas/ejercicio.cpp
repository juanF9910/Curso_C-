/*
vamos a crear una lista simplemente enlazada de almacene n números enteros 
y determinaremos cuál es el mayor y cuál es el menor. 
*/

#include <iostream>
#include <vector>

using namespace std; 

struct Nodo{
    int dato; 
    Nodo* siguiente; 

}; 
void insertar(Nodo* &lista, int n){

    Nodo* nuevo=new Nodo(); 
    nuevo->siguiente=NULL; 
    nuevo->dato=n;

    /*debemos poner este elemento en la última posición*/
    if(lista==NULL){
        lista=nuevo;
    }else{ //definimos un puntero auxiliar para movernos por la lista
        Nodo* aux=lista;
        while(aux->siguiente!=NULL){//nos movemos hasta la última posición
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo; 


        /*cuando ya esté al final de la lista entonces*/
    }
}

vector<int> max_min(Nodo* lista){

    vector<int> valores; 
    Nodo* aux=lista;
    int min=aux->dato, max=min; 
    while(aux!=NULL){
        
        if(aux->dato<min){
            min=aux->dato;
        }else if(aux->dato>max){
            max=aux->dato; 
        }

        aux=aux->siguiente;
    }
    valores={min, max};
    return valores; 
}

int main(){

    Nodo* lista=NULL; 
    int n; 
    vector<int> valores; 
    while(n!=0){
        cout<<"ingrese el valor, y termine con cero"<<endl;
        cin>>n; 
        insertar(lista, n); 
    }

    valores=max_min(lista); 

    cout<<"el valor máximo es: " <<valores[1] <<endl;
    cout<<"el valor mínimo es: "<<valores[0] <<endl;


    

    return 0; 
}