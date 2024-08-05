#include <iostream>


using namespace std;

template<typename T>
class Cola{
    private:
            struct Nodo{
                T dato;
                Nodo* siguiente;
            };
            Nodo* frente;
            Nodo* final;
    public:
            Cola();
            ~Cola();
            void agregar(T n);
            void sacar();
            void mostrar() const;
            bool buscar(T n) const;
            int tamanio() const;
};

template<typename T>
Cola<T>::Cola(){
    frente = nullptr;
    final = nullptr;
}

template<typename T>
Cola<T>::~Cola(){
    while (frente) {
        sacar();
    }
}

template<typename T>
void Cola<T>::agregar(T n){
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = nullptr;
    if (frente == nullptr) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
}


template<typename T>
void Cola<T>::sacar(){
    Nodo* aux=frente;  //auxiliar apunta en la a la misma dirección que frente, 
    //es decir, puedo modificar esa parte de la memoria con cualquiera de los dos punteros. 

    if(frente==fin){ //si hay una sola estructura
        frente=nullptr; 
        fin=nullptr; 
    }else{
        frente=frente->siguiente; //si hay más de una estructura
    } 

    delete aux; 
}

template<typename T>
void Cola<T>::mostrar() const{
    Nodo* aux = frente;
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

template<typename T>
bool Cola<T>::buscar(T n) const{
    Nodo* aux = frente;
    while (aux != nullptr) {
        if (aux->dato == n) {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

template<typename T>
int Cola<T>::tamanio() const{
    Nodo* aux = frente;
    int contador = 0;
    while (aux != nullptr) {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}

int main(){
    Cola<int>* cola = new Cola<int>();
    int dato;
    cout << "para terminar de ingresar digite un cero" << endl;
    do {
        cout << "Ingrese un número: ";
        cin >> dato;
        if (dato != 0) {
            cola->agregar(dato);
        }
    } while (dato != 0);
    cout << "Elementos de la cola: ";
    cola->mostrar();
    cout << "Tamaño de la cola: " << cola->tamanio() << endl;
    cout << "Ingrese un número a buscar: ";
    cin >> dato;
    if (cola->buscar(dato)) {
        cout << "El elemento " << dato << " ha sido encontrado." << endl;
    } else {
        cout << "El elemento " << dato << " no ha sido encontrado." << endl;
    }
    delete cola;
    return 0;
}




