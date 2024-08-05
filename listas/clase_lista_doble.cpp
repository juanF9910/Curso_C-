#include<iostream>

using namespace std;

template<typename T>
class ListaDoble{
    private:
            struct Nodo{
                T dato;
                Nodo* siguiente;
                Nodo* anterior;
            };
            Nodo* lista;
    public:
            ListaDoble();
            ~ListaDoble();
            void agregar(T n);
            void sacar();
            void mostrar() const;
            bool buscar(T n) const;
            int tamanio() const;
};