#include <iostream>
#include <string>

using namespace std; 

class Persona{
    //cuando estamos dentro de la misma clase, podemos usar los 
    //atributos de la misma en cualquier parte. 

    private: /*encapsulamiento, es decir, ocultar estos datos y que 
    no puedan ser modificados*/
        int edad; 
        string nombre; 

 
    public: //métodos, o acciones que realiza este objeto
        Persona(); //método constructor, inicializa los atributos 
        void leer(); 
        void correr(); 
        void set(int, string);
}; 

Persona::Persona(){ }

void Persona::set(int edad, string nombre){
    this->edad=edad; 
    this->nombre=nombre; 
}

void Persona::leer(){ //el método leer pertenece a la clase persona
    cout  <<"soy " <<nombre <<" y estoy leyendo" <<endl;
}

void Persona::correr(){ //el método correr pertenece a la clase persona
    cout  <<"soy " <<nombre <<" y estoy corriendo" <<endl;
}


int main(){

    Persona* p;
    p->set(23, "juan felipe"); 
    p->leer();  
    p->correr();


    //el destructor del objeto va antes de liberar la memoria. 
    return 0; 

}