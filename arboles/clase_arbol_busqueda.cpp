#include <iostream>

using namespace std;

template<typename T>
class ArbolBusqueda {
    private:
        struct Nodo{ //definimos la estructura del nodo
            T dato;
            Nodo* izquierdo;
            Nodo* derecho;
            Nodo* padre; // Puntero al nodo padre, útil para ciertas operaciones como eliminar

            Nodo(T val, Nodo* p = nullptr)
                : dato(val), izquierdo(nullptr), derecho(nullptr), padre(p) {}
        };

        Nodo* raiz; // Puntero a la raíz del árbol

    // Función privada para eliminar todos los nodos en el árbol
    void eliminarNodo(Nodo* nodo) {
        if (nodo) {
            eliminarNodo(nodo->izquierdo);
            eliminarNodo(nodo->derecho);
            delete nodo;
        }
    }

    // Función privada para agregar un nuevo nodo recursivamente
    Nodo* agregarRec(Nodo* nodo, T valor, Nodo* padre) {
        if (!nodo) {
            return new Nodo(valor, padre);
        }
        if (valor < nodo->dato) {
            nodo->izquierdo = agregarRec(nodo->izquierdo, valor, nodo);
        } else if (valor > nodo->dato) {
            nodo->derecho = agregarRec(nodo->derecho, valor, nodo);
        }
        return nodo;
    }


    void agregarRec(Nodo* &arbol, int n, Nodo* padre){ //incialmente el puntero 
  //es la raiz del árbol
  Nodo* nuevo=crearNodo(n, padre);

  if(arbol==NULL){//si el árbol está vacío 
    arbol=nuevo; 
  }else{
    //como estamos construyendo un árbol binario de búsqueda  
    /*necesitamos tener en cuenta el valor del nodo respecto a la raiz */
    int raiz=arbol->dato; 

    if(n<raiz){ /*se coloca al lado izquierdo*/
        insertar(arbol->izq, n, arbol); //recursividad, el puntero apunta hacia donde
        //quiero insertar
    }else{
        insertar(arbol->der, n,arbol);
    }
  }
}

    // Función privada para buscar un valor en el árbol
    Nodo* buscarRec(Nodo* nodo, T valor) const {
        if (!nodo || nodo->dato == valor) {
            return nodo;
        }
        if (valor < nodo->dato) {
            return buscarRec(nodo->izquierdo, valor);
        } else {
            return buscarRec(nodo->derecho, valor);
        }
    }

    void mostrar(Nodo* arbol, int cont){
        if(arbol==NULL){
            return;
        }else{
            mostrar(arbol->der, cont+1); 
            for(int i=0; i<cont; i++){ //para dar espacios entre nodo y nodo
            cout<<"   ";
            }
            cout<< arbol->dato<<endl;
            mostrar(arbol->izq, cont+1);
        
        }
    }

    // Función privada para obtener el tamaño del árbol
    int tamanioRec(Nodo* nodo) const {
        if (!nodo) {
            return 0;
        }
        return 1 + tamanioRec(nodo->izquierdo) + tamanioRec(nodo->derecho);
    }

public:
    ArbolBusqueda();
    ~ArbolBusqueda();
    void agregar(T valor);
    void eliminar(T valor);
    bool buscar(T valor) const;
    void mostrar() const;
    int tamanio() const;
};

template<typename T>
ArbolBusqueda<T>::ArbolBusqueda() : raiz(nullptr) {}

template<typename T>
ArbolBusqueda<T>::~ArbolBusqueda() {
    eliminarNodo(raiz);
}

template<typename T>
void ArbolBusqueda<T>::agregar(T valor) {
    raiz = agregarRec(raiz, valor, nullptr);
}

template<typename T>
bool ArbolBusqueda<T>::buscar(T valor) const {
    return buscarRec(raiz, valor) != nullptr;
}

template<typename T>
void ArbolBusqueda<T>::mostrar() const {
    mostrarRec(raiz);
    cout << endl;
}

template<typename T>
int ArbolBusqueda<T>::tamanio() const {
    return tamanioRec(raiz);
}

int main() {
    ArbolBusqueda<int> arbol;
    arbol.agregar(5);
    arbol.agregar(3);
    arbol.agregar(7);
    arbol.agregar(2);
    arbol.agregar(4);

    cout << "Árbol en orden: ";
    arbol.mostrar();

    cout << "Tamaño del árbol: " << arbol.tamanio() << endl;

    int buscarValor = 3;
    cout << (arbol.buscar(buscarValor) ? "El valor " + to_string(buscarValor) + " está en el árbol." : "El valor " + to_string(buscarValor) + " no está en el árbol.") << endl;

    return 0;
}