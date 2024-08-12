/*lo más importante en la programación orientada a objetos
pues ahorra muchas líneas de código
*/

#include <iostream>


using namespace std; 

class Persona{

    private: //atrubutos, pueden ser manipulados por clases herederas
        string nombre; 
        int edad; 
    
    public: 
        Persona(string, int); //constructor
        void mostrar();
};

class Alumno: public Persona{ /*public significa que voy a poder acceder a todo lo 
público de la clase persona*/

    private: //atributos adicionales a parte de los que ya se heredan
        string codigo; 
        float nota; 
    public:  //métodos adicionales a parte de los que hereda
        Alumno(string, int, string, float);/*se ponen los argumentos
        del constructor de la clase padre y luego los de la clase hija
        */
       void mostraralumno();
};


Persona::Persona(string nombre, int edad){
    this->nombre=nombre; 
    this->edad=edad; 
}

Alumno::Alumno(string nombre, int edad, string codigo, float nota):Persona(nombre, edad){
    /*solamenter debo inicializar los atributos propios*/
    this->codigo=codigo; 
    this->nota=nota;
}

void Persona::mostrar(){
    cout <<"el nombre es: " <<nombre <<" su edad es: "<<edad <<endl; 
}

void Alumno::mostraralumno(){
    Persona::mostrar(); //llamo la función miembro que ha sido heredada
    /*puedo llamar los miembros de la clase padre dentro de 
    cualquier método de la clase hija, siempre y cuando sean accesibles*/
    cout <<"codigo: " <<codigo  <<" nota: " << nota <<endl;
}

int main(){

    Persona* p=new Persona("juan felipe", 24); 
    p->mostrar();

    Alumno* p1=new Alumno( "juan felipe", 24, "123", 4.5); //cuando se define la clase heredada, en el 
    /*constructor debemos poner todos los parámetros*/
    p1->mostraralumno();
    p1->mostrar();
    
    delete p;
    delete p1; 
    return 0; 
}