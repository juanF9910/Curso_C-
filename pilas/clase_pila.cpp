#include <iostream>

using namespace std;
  
template<typename T>
class Pila{

    private: 

            struct Nodo{
                T dato; 
                Nodo* siguiente; 
            };

            Nodo* pila; //puntero a la estructura nodo.

    public:
            Pila(); //constructor
            ~Pila();
            void agregar(T n); 
            void sacar();
            void mostrar() const;
            bool buscar(T n) const;
            int tamanio() const;
};

template<typename T>
Pila<T>::Pila():pila(nullptr){} //inicialización en línea

template<typename T>
Pila<T>::~Pila(){
    while (pila){
        sacar();
    }
}

template<typename T>
void Pila<T>::agregar(T n){ //los atributos de la clase con accesibles desde cualquier función miembro de la clase
    Nodo* nuevo= new Nodo();
    nuevo->dato=n; 
    nuevo->siguiente=pila; 
    pila=nuevo; 
}

template<typename T>
void Pila<T>::sacar() {
    if (pila) {  // Si la pila no está vacía
        Nodo* aux = pila;
        pila = aux->siguiente;
        delete aux; 
    } else {
        cout << "La pila está vacía. No se puede sacar elementos." << endl;
    }
}

template<typename T>
void Pila<T>::mostrar() const{
    Nodo* aux = pila; // Puntero auxiliar para recorrer la pila
    while (aux != nullptr) {
        cout << aux->dato << " "; // Mostrar el dato del nodo actual
        aux = aux->siguiente; // Moverse al siguiente nodo
    }
    cout << endl;
}

// Buscar un elemento en la pila
template<typename T>
bool Pila<T>::buscar(T n) const {
    Nodo* aux = pila;
    int cont = 0;
    while (aux != nullptr) {
        if (aux->dato == n) {
            cout << "El elemento " << n << " ha sido encontrado en la posición " << cont << endl;
            return true;
        }
        cont++;
        aux = aux->siguiente;
    }
    cout << "El elemento " << n << " no ha sido encontrado." << endl;
    return false;
}

template<typename T>
int Pila<T>::tamanio() const{
    Nodo* aux=pila; 
    int contador=0; 
    while(aux!=nullptr){
        contador++;
        aux=aux->siguiente;
    }
    return contador; 
}

int main(){

    Pila<int>* pila=new Pila<int>();
    int dato;
    cout<<"para terminar de ingresar digite un cero"<<endl;
    do{
        cout  <<"digite un número" <<endl;
        cin>>dato;
        if(dato!=0){ //para que no se agregue el cero a la pila
            pila->agregar(dato);
        }
    }while(dato!=0);

    pila->mostrar();
    cout<<"el tamaño de la pila es: "<<pila->tamanio()<<endl;
    pila->buscar(3);
    pila->sacar();
    pila->mostrar();
    cout<<"el tamaño de la pila es: "<<pila->tamanio()<<endl;

    return 0; 
}
