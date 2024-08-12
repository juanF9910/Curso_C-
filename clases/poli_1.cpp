#include <iostream>
#include <string>

using namespace std; 

class Animal{


    private:
        int edad; 

    public: 
        Animal(int); 
        virtual void comer(); //virtual significa que se puede sobreescribir en las clases derivadas
};

Animal::Animal(int edad){
    this->edad=edad;
}

void Animal::comer(){
    cout <<"yo como ";
}

class Humano:public Animal{

    private:
        string nombre;
    public: 
        Humano(int, string);
        void comer();
};

Humano::Humano(int edad, string nomnbre):Animal(edad){
    this->nombre=nombre; 
}

void Humano::comer(){
    //Animal::comer(); //puedo acceder a las funciones miebro de la clase base que sean públicas. 
    cout <<"en una mesa, sentado en una silla"<<endl;
}


class Perro: public Animal{

    private: 
        string nombre, raza;
    public: 
        Perro(int, string, string);
        void comer();
};

Perro::Perro(int edad, string nombre, string raza):Animal(edad){
    this->nombre=nombre; 
    this->raza=raza;
}

void Perro::comer(){
    Animal::comer();
    cout <<"en el suelo" <<endl;
}


int main(){
    Perro* p1=new Perro(5, "bobby", "pastor alemán");
    p1->comer();
    Humano* h1=new Humano(18, "juan");
    h1->comer();

    return 0; 
}