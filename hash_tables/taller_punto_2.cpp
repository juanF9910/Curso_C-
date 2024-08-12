#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
#include <string>
#include <fstream>
#include <cmath>
#include <unordered_map>
using namespace std;

template<class V>
class HashTable {
    private:

        struct Nodo {
            string clave;
            V valor;
            Nodo* siguiente;
        };

        vector<Nodo*> tabla; // Vector de punteros a nodos, que en realidad apuntan a listas enlazadas
        int capacidad; // Capacidad de la tabla hash, número de valores hash diferentes que se pueden almacenar
        int tamanio; // Tamaño de la tabla hash, número de elementos almacenados
        int L;  //número de bits que entrega la función hash

        string charToBinary(const string& array) const { //convierte un string a su representación binaria en una cadena de bits
            string binaryString;
            for (int i = 0; i < array.size(); ++i) {
                bitset<8> bits(array[i]);  // Usar un bitset de 8 bits para convertir un char a su representación binaria
                binaryString += bits.to_string(); // Agregar la representación binaria al string
            }
            return binaryString;
        }

        unsigned long int hashFunc(const string& array, int L) const {
            string input = charToBinary(array);
            unsigned long int valor = 0;
            size_t length = input.length();

            for (size_t i = 0; i < length; i += L) {
                string part = input.substr(i, L); //toma una subcadena de longitud L
                bitset<64> bits(part); //convierte la subcadena a un bitset de 64 bits, un bitset es un vector de bits      
                valor ^= static_cast<unsigned long int>(bits.to_ulong()); // XOR de los bits de la subcadena
            }
            return valor & 0x3FFF; // devolvemos los 14 bits menos significativos
        }

        unsigned long int hashFunc1(const string& clave, int L) const {
            unsigned long int num = 0;
            int len = clave.size();

            for (int i = 0; i < len; i++) {
                num += clave[i];
            }
            return num & 0xFF; // devolvemos los 8 bits menos significativos
        }

        unsigned long int calcularHash(const string& clave) const { // Calcular el hash de la clave en función de la longitud L
            if (L == 8) {
                return hashFunc1(clave, L);
            } else if (L == 14) {
                return hashFunc(clave, L);
            } else {
                throw runtime_error("Longitud L no soportada");
            }
        }

        void eliminarLista(Nodo* lista) { //le entrego 
            while (lista) {
                Nodo* aux = lista;
                lista = lista->siguiente;
                delete aux;
            }
        }

    public:
        HashTable(int cap, int L); // Constructor, se le ingresa la capacidad y la longitud L
        ~HashTable();
        void insertar(string clave, V valor);
        void eliminar(string clave);
        bool buscar(string clave) const;
        V obtener(string clave) const;
        void mostrar() const;
        int obtenerTamanio() const;
};

template<typename V>
HashTable<V>::HashTable(int cap, int L) : capacidad(cap), tamanio(0), L(L) {
    tabla.resize(capacidad, nullptr); //incializamos el tamaño de la tabla y todos los elementos en nullptr
}

template<typename V>
HashTable<V>::~HashTable() {
    for (int i = 0; i < capacidad; ++i) {
        eliminarLista(tabla[i]);
    }
}

template<typename V>
void HashTable<V>::insertar(string clave, V valor) {
    int indice = calcularHash(clave);
    Nodo* nuevo = new Nodo{clave, valor, nullptr};

    if (tabla[indice] == nullptr) {
        tabla[indice] = nuevo;
    } else {
        Nodo* aux = tabla[indice];
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    ++tamanio;
}

template<typename V>
void HashTable<V>::eliminar(string clave) {
    int indice = calcularHash(clave);
    Nodo* anterior = nullptr;
    Nodo* aux = tabla[indice];

    while (aux != nullptr && aux->clave != clave) {
        anterior = aux;
        aux = aux->siguiente;
    }

    if (aux == nullptr) {
        cout << "El elemento no existe" << endl;
    } else {
        if (anterior == nullptr) {
            tabla[indice] = aux->siguiente;
        } else {
            anterior->siguiente = aux->siguiente;
        }
        delete aux;
        --tamanio;
    }
}

template<typename V>
bool HashTable<V>::buscar(string clave) const {
    int indice = calcularHash(clave);
    Nodo* aux = tabla[indice];
    while (aux) {
        if (aux->clave == clave) {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

template<typename V>
V HashTable<V>::obtener(string clave) const {
    int indice = calcularHash(clave);
    Nodo* aux = tabla[indice];
    while (aux) {
        if (aux->clave == clave) {
            return aux->valor;
        }
        aux = aux->siguiente;
    }
    throw runtime_error("Clave no encontrada");
}

template<typename V>
void HashTable<V>::mostrar() const {
    for (int i = 0; i < capacidad; ++i) {
        Nodo* aux = tabla[i];
        cout << "Indice " << i << ": ";
        while (aux) {
            cout << "(" << aux->clave << ", " << aux->valor << ") -> ";
            aux = aux->siguiente;
        }
        cout << "nullptr" << endl <<endl<<endl;
    }
}

template<typename V>
int HashTable<V>::obtenerTamanio() const {
    return tamanio;
}

int main() {
    int L = 14;
    
    string filePath = "/usr/share/dict/words";
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cout << "No se pudo abrir el archivo: " << filePath << endl;
        return 1;
    }

    string Line;
    unsigned long int tam = 0;
    while (getline(inputFile, Line)) {
        tam++;
    }
 
    HashTable<int> *hashTable = new HashTable<int>(pow(2, L), L);  //defino el objeto hashTable
    inputFile.clear(); // Limpiar el estado del archivo, llevar el puntero al inicio
    inputFile.seekg(0);

    for (unsigned long int i = 0; i < tam; i++) {
        getline(inputFile, Line);
        hashTable->insertar(Line, i); // Insertar la palabra y el valor en la tabla hash
        Line.clear();
    }

    hashTable->mostrar();
    cout << "Tamaño de la tabla: " << hashTable->obtenerTamanio() << endl;
    
    cout << hashTable->buscar("wonkier") << endl;
    
    cout << hashTable->obtener("wonkier") << endl;
    delete hashTable; // Eliminar la tabla hash
    return 0;
}