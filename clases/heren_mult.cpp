/*vamos a definir una clase que es hija de otras dos, que son completamente independientes 
en este caso también podemos usar polimorfismo de herencia, es decir, dentro de diferentes clases tengo funciones que se llaman igual, pero hacen cosas distintas*/

#include <iostream>
#include <string>

using namespace std; 


class Carnivoro{

    private: 
        string comida; 

    public: 
        Carnivoro(string); 
        virtual void mostrar();
}; 

class Herbivoro{

    private: 
        string comida; 

    public: 
        Herbivoro(string); 
        virtual void mostrar(); //la palabra clave es que las clases padres tengas en las funciones que se van a redefinir el virtual. 
};

class Omnivoro: public Carnivoro, public Herbivoro{

    //no tenemos ningún atributo nuevo, por eso no ponemos private. 
    public: 
        Omnivoro(string, string); /*podemos los argumentos en el orden de las clases*/
        void mostrar(); 
};


Carnivoro::Carnivoro(string comida){
    this->comida=comida; 
}

Herbivoro::Herbivoro(string comida){
    this->comida=comida;
}

Omnivoro::Omnivoro(string comida, string comida1): Carnivoro(comida), Herbivoro(comida1){
}

void Herbivoro::mostrar(){
    cout <<"soy herbivoro y como " <<comida <<endl;
}

void Carnivoro::mostrar(){
    cout <<"soy carnivoro y como " <<comida <<endl;
}

void Omnivoro::mostrar(){
    Carnivoro::mostrar();
    Herbivoro::mostrar();
}

int main(){

    Omnivoro* o=new Omnivoro("pechuga", "ensalada"); 
    o->mostrar();

    return 0;
}