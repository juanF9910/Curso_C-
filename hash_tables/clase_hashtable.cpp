#include <iostream>
#include <vector>

using namespace std;

template<class K, class V> //la palabra class es equivalente a typename en plantillas de clase 
class HashTable {

    private:

        struct Nodo { //estructura que se guarda en cada celda de la tabla hash
            K clave;
            V valor;
            Nodo* siguiente; //este nodo se usa para manejar colisiones en la tabla hash, como una lista enlazada simple
        };

        vector<Nodo*> tabla; // Vector de punteros a cada celda de la tabla hash, cada puntero apunta a una lista simplemente enlazada
        int capacidad; // Capacidad de la tabla hash, variable global
        int tamanio; // Número de elementos en la tabla, variable global se puede acceder desde cualquier método de la clase

        // Función hash, esta función no es única, se puede cambiar por otra función hash según las necesidades del problema a resolver. 
        int hashFunc(K clave) const {
            return hash<K>()(clave) % capacidad; // Usar hash de la clave
        }

        // Función privada para eliminar todos los nodos de una lista enlazada
        void eliminarLista(Nodo* lista) {
            while (lista) {
                Nodo* aux = lista;
                lista = lista->siguiente;
                delete aux;
            }
        }

    public:

        HashTable(int); // Constructor, en entero  representa la capacidad de la tabla hash
        ~HashTable();
        void insertar(K clave, V valor);
        void eliminar(K clave);
        bool buscar(K clave) const;
        V obtener(K clave) const;
        void mostrar() const;
        int obtenerTamanio() const;
};

template<typename K, typename V>
HashTable<K, V>::HashTable(int cap) : capacidad(cap), tamanio(0) {
    tabla.resize(capacidad, nullptr); //este método redimensiona el vector y asigna nullptr a cada celda, cada puntero en la tabla apunta a nullptr
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() {
    for (int i = 0; i < capacidad; ++i) {
        eliminarLista(tabla[i]); //acá se eliminan todos los elementos de la lista simplemente enlazada de cada celda de la tabla hash, 
        //el puntero tabla[i] apunta hacia el inicio de la lista enlazada
    }
}


template<typename K, typename V>
void HashTable<K, V>::insertar(K clave, V valor) {
    int indice = hashFunc(clave);
    Nodo* nuevo = new Nodo{clave, valor, nullptr}; // Se crea un nuevo nodo con la clave y valor

    if (tabla[indice] == nullptr) {
        // Si la celda está vacía, se asigna el nuevo nodo
        tabla[indice] = nuevo;
    } else {
        // Si la celda ya tiene un nodo, se recorre la lista enlazada hasta el final
        Nodo* aux = tabla[indice]; //tengo dos punteros apuntando al mismo lugar, actual y tabla[indice]
        //tabla[indice] siempre apunta hacia el inicio de la lista enlazada
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        // Se añade el nuevo nodo al final de la lista enlazada
        aux->siguiente = nuevo;
    }
    ++tamanio;
}

template<typename K, typename V>
void HashTable<K, V>::eliminar(K clave) { //función eliminar teniendo en cuenta que puede haber colisiones
    int indice = hashFunc(clave);
    Nodo* anterior = nullptr; //el puntero que va atrás
    Nodo* aux = tabla[indice]; //el puntero que va al frente

    while (aux != nullptr && aux->clave != clave) { //esto se realiza para el caso de que la clave a eliminar no esté en la primera celda de la tabla hash, es decir, que haya una colisión
        anterior = aux;
        aux = aux->siguiente;
    } //movemos el puntero hasta que encontremos el nodo con la clave a eliminar o lleguemos al final de la lista

    if (aux == nullptr) {
        cout << "El elemento no existe" << endl;
    } else {
        if (anterior == nullptr) { //significa que el nodo a eliminar es el primero de la lista
            tabla[indice] = aux->siguiente; //el inicio de la lista apunta al siguiente nodo
        } else {
            anterior->siguiente = aux->siguiente;
        }
        delete aux;
        --tamanio;
    }
}

template<typename K, typename V>
bool HashTable<K, V>::buscar(K clave) const {
    int indice = hashFunc(clave);
    Nodo* aux = tabla[indice]; //función buscar teniendo en cuenta que puede haber colisiones
    while (aux) {
        if (aux->clave == clave) {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

template<typename K, typename V>
V HashTable<K, V>::obtener(K clave) const {
    int indice = hashFunc(clave);
    Nodo* aux = tabla[indice];
    while (aux) {
        if (aux->clave == clave) {
            return aux->valor;
        }
        aux = aux->siguiente;
    }
    throw runtime_error("Clave no encontrada");
}

template<typename K, typename V>
void HashTable<K, V>::mostrar() const {
    for (int i = 0; i < capacidad; ++i) {
        Nodo* aux = tabla[i];
        cout << "Indice " << i << ": ";
        while (aux) {
            cout << "(" << aux->clave << ", " << aux->valor << ") -> ";
            aux = aux->siguiente;
        }
        cout << "nullptr" << endl;
    }
}

template<typename K, typename V>
int HashTable<K, V>::obtenerTamanio() const {
    return tamanio;
}

int main() {
    HashTable<int, string> hashTable(10); // Tabla hash con capacidad 10, el primer tipo de dato es la clave y el segundo el valor
    hashTable.insertar(1, "Uno");
    hashTable.insertar(2, "Dos");
    hashTable.insertar(3, "Tres");
    hashTable.insertar(4, "Cuatro");
    hashTable.insertar(5, "Cinco");
    hashTable.insertar(5, "Cinco");

    hashTable.mostrar();
    cout << "Tamaño de la tabla: " << hashTable.obtenerTamanio() << endl;

    cout << "Valor para clave 3: " << hashTable.obtener(3) << endl;

    hashTable.eliminar(3);
    hashTable.mostrar();
    cout << "Tamaño de la tabla: " << hashTable.obtenerTamanio() << endl;

    cout << (hashTable.buscar(3) ? "El elemento 3 está en la tabla." : "El elemento 3 no está en la tabla.") << endl;

    return 0;
}
