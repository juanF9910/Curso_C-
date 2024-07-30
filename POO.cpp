#include <iostream>
#include <string>

using namespace std; 

/*
Vamos a crear nuestra primera clase en C++, un miembro de una clase puede ser o bien un método o bien un atributo.
*/

class Persona { // Por defecto, la clase encapsula (restringe el acceso a la información).
    
    private: 
        string nombre;
        int edad;

    public:
        static int numero_personas;

        // Constructor
        Persona(string nombre, int edad);
        
        // Destructor
        ~Persona();

        // Métodos para cambiar los atributos, devuelve una referencia a la instancia de la clase para poder concatenar los cambios al objeto 
        Persona &change_name(string nombre);
        Persona &change_edad(int edad);

        // Método para saludar
        void saludar();
};

// Inicialización de la variable estática
int Persona::numero_personas = 0;

// Definición del constructor
Persona::Persona(string nombre, int edad) {
    this->nombre = nombre; 
    this->edad = edad;
    // Incrementa el número de personas cada vez que se crea un objeto de la clase Persona
    numero_personas++;
}

// Definición del destructor
Persona::~Persona() {
    cout << "Se ha destruido el objeto" << endl;
    numero_personas--;
}

// Método para saludar
void Persona::saludar() {
    cout << "Hola, me llamo " << nombre << " y tengo " << edad << " años" << endl;
}

// Método para cambiar el nombre
Persona &Persona::change_name(string nombre) {
    this->nombre = nombre; 
    return *this;
}

// Método para cambiar la edad
Persona &Persona::change_edad(int edad) {
    this->edad = edad; 
    return *this;
}

// Función principal
int main() {
    Persona p = Persona("Felipe", 23); // Puedo definirlo sin puntero
    p.saludar();

    Persona* p1 = new Persona("Diana", 27); // Es muy útil trabajar con punteros
    p1->saludar();
    p1->change_name("Ximena").change_edad(24); // Concatenamos los cambios al objeto
    p1->saludar();

    cout << "Número de personas: " << Persona::numero_personas << endl; 

    // Libera la memoria asignada con new
    delete p1;

    return 0; 
}