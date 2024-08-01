#include <iostream>
/* Queremos hacer un menú que:
    1. inserte un caracter
    2. muestre todos los elementos de la cola
    3. salir
*/

using namespace std; 

struct Nodo{
    char dato; 
    Nodo* siguiente; 
};

void menu();
void agregar(Nodo* &frente, Nodo* &fin, char n);
void suprimir(Nodo* &frente, Nodo* &fin, char &n);

int main(){ 

    menu();

    return 0; 
}

void menu(){

    Nodo* frente=nullptr; 
    Nodo* fin=nullptr; 
    int opcion;
    char dato; 

    do{
        cout<<"\t MENÚ \t" <<endl;
        cout<<"1. Insertar un caracter en la cola" <<endl;
        cout <<"2. mostrar todos los elementos" <<endl;
        cout <<"3. salir" <<endl;

        cin>>opcion;

        switch(opcion){
            case 1: 
                cout <<"ingrese el caracter para agregar"<<endl;
                cin>>dato; 
                agregar(frente, fin, dato);
                break;
            case 2:
                cout<< "mostrando los elementos de la cola" <<endl;
                while(frente!=nullptr){
                    suprimir(frente, fin, dato);
                    cout<<dato<<endl;
                }
                break; 

            case 3: 
                break; 
        }
        system("clear");
    }while(opcion!=3);

}

void agregar(Nodo* &frente, Nodo* &fin, char n){

    Nodo* nuevo=new Nodo(); 
    nuevo->dato=n; 
    nuevo->siguiente=NULL; 

    if (frente==NULL){ //si no hay estructuras
        frente=nuevo; 
    }else{ //si ya hay elementos
        fin->siguiente=nuevo; 
    }
    fin=nuevo; 
}

void suprimir(Nodo* &frente, Nodo* &fin, char &n){

    n=frente->dato; //guardar el valor del dato sirve a la hora de imprimir, aunque no es necesario. 
    Nodo* aux=frente; 

    if(frente==fin){ //si hay una sola estructura
        frente=nullptr; 
        fin=nullptr; 
    }else{
        frente=frente->siguiente; 
    }

    delete aux; 

}