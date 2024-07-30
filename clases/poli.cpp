#include <iostream>
#include <string>

using namespace std; 

class Persona{

    private:
        string nombre; 
        int edad; 

    public:
        Persona(string, int);
        virtual void mostrar(); /*esto significa que 
        la función mostrar puede ser reescrita por cualquier clase que herede de Persona, es decir, mismo nombre de función, diferente acción*/  
};

class Alumno: public Persona{

    private:
        float nota;

    public: 
        Alumno(string, int, float); 
        void mostrar();
};

class Profesor: public Persona{

    private: 
        string materia;
         
    public: 
        Profesor(string, int, string);
        void mostrar();
};


Persona::Persona(string nombre, int edad){
    this->nombre=nombre; 
    this->edad=edad;  
}

Alumno::Alumno(string nombre, int edad, float nota):Persona(nombre, edad){
    this->nota=nota; 
}

Profesor::Profesor(string nombre, int edad, string materia):Persona(nombre, edad){
    this->materia=materia;
}

void Persona::mostrar(){
    cout <<"nombre: " <<nombre <<endl <<"edad: " <<edad <<endl;
}

void Alumno::mostrar(){
    Persona::mostrar(); /*con esto indico que en persona ya existe una función
     que se llama igual pero que está definida en otra clase*/
   cout << "nota final: " <<nota <<endl;
}

void Profesor::mostrar(){
    Persona::mostrar();
    cout <<"materia: " <<materia <<endl;
}

int main(){

    Alumno* a=new Alumno("alejandro", 20, 18.9); 
    a->mostrar();

    Profesor* p=new Profesor("juan", 43, "algoritmos" );
    p->mostrar();

    return 0; 
}