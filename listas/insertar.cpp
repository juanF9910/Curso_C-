/*para insertar estruturas a una lista se deben 
seguir los siguientes pasos: 
    1. crear un nuevo nodo
    2. añadir el dato al nodo 
    3. crear dos estructuras auxiliares y asignar
        el puntero lista  a uno de ellos
    4. insertar la estructura a la lista. 
*/

struct Nodo{ //creamos el nodo, o unidad fundamental de la lista. 
    int dato;
    Nodo* siguiente; 
};

void insertar_lista(Nodo* &lista, int n);

int main(){
    Nodo* lista;


    return 0; 
}

void insertar_lista(Nodo* &lista, int n){

    Nodo* nuevo=new Nodo();
}