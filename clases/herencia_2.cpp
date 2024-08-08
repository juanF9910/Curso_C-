
/*estudiamos el caso de heredar de una clase que ya es heredera*/
#include <iostream>
#include <string>

using namespace std; 


class Persona{
    private: 
        string nombre; 
        int edad; 
    public: 
        Persona(string, int); 
        void mostrarpersona();
}; 


class Empleado: public Persona{
    private: 
        float sueldo; 
    public: 
        Empleado(string, int, float); 
        void mostrarempleado(); 
};

class Estudiante: public Persona{
    private: 
        float nota; 
    public: 
        Estudiante(string, int, float); //los atributos se inicializan en el constructor de la clase base y kuego en el constructor de la clase derivada hasta lo sde
        //la clase propia.
        void mostrarestudiante();
};

class Universitario:public Estudiante{

    private: 
        string carrera; 
    public: 
        Universitario(string, int, float, string); 
        void mostraruni(); 
};

Persona::Persona(string nombre, int edad){
    this->nombre=nombre;
    this->edad=edad; 
}

Empleado::Empleado(string nombre, int edad, float sueldo) : Persona(nombre, edad){ //en el extremo derecho ya se ponen sine especificar el tipo de dato. 
    this->sueldo=sueldo; 
}


Estudiante::Estudiante(string nombre, int edad, float nota):Persona( nombre, edad){
    this->nota=nota;
}

Universitario::Universitario(string nombre, int edad, float nota, string carrera) : Estudiante(nombre, edad, nota){
    this->carrera=carrera; 
}

void Persona::mostrarpersona(){
    cout <<"nombre: "<<nombre <<endl <<"edad: " <<edad <<endl;
}

void Empleado::mostrarempleado(){
    mostrarpersona();
    cout <<"sueldo " <<sueldo <<endl; 
}
 
void Estudiante::mostrarestudiante(){
    mostrarpersona(); 
    cout <<"nota final: " <<nota <<endl;
}

void Universitario::mostraruni(){
    mostrarestudiante();
    cout <<"carrera: " <<carrera <<endl;
}

int main(){
    Empleado* e= new Empleado("felipe", 34, 1300);
    e->mostrarempleado();

    Estudiante* E=new Estudiante("alejo", 20, 4.5);
    E->mostrarestudiante();
    
    Universitario* U=new Universitario("camila", 23, 4.7, "física");
    U->mostraruni();
    return 0; 
}