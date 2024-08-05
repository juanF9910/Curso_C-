#include <iostream>

using namespace std; 

template<typename T>
class Arbol_busqueda{
    private:
        struct Nodo{ //definición del nodo
            T dato; 
            Nodo* izq; 
            Nodo* der; 
            Nodo* padre; //este puntero es fundamental para eliminar nodos
        }; 

        Nodo* arbol;
        Nodo* padre; 

    public:
            Arbol_busqueda();
            Nodo* crearNodo(T n, Nodo* padre);
            void agregar(T n);

};

template<typename T>
Arbol_busqueda<T>::Arbol_busqueda() : arbol(nullptr), padre(nullptr) {}



template<typename T>   
typename Arbol_busqueda<T>::Nodo* Arbol_busqueda<T>::crearNodo(T n, Nodo* padre){ 

/*Estamos devolviendo un tipo de dato que está dentro de la clase Arbol_busqueda, por eso se pone así.*/

  Nodo* nuevo=new Nodo(); 

  nuevo->dato=n; 
  nuevo->der=nullptr; 
  nuevo->izq=nullptr; 
  nuevo->padre=padre; 

  return nuevo; 
}


template<typename T>
void Arbol_busqueda<T>::agregar(Nodo*& arbol, T n, Nodo* padre) {
    if (arbol == nullptr) {
        arbol = crearNodo(n, padre);
    } else {
        if (n < arbol->dato) {
            insertar(arbol->izq, n, arbol);
        } else {
            insertar(arbol->der, n, arbol);
        }
    }
}



int main(){
    Arbol_busqueda<int>* arbol=new Arbol_busqueda<int>();
    arbol->agregar(5);
    arbol->agregar(3);
    arbol->agregar(7);
    arbol->agregar(2);
    arbol->agregar(4);

    return 0; 
}