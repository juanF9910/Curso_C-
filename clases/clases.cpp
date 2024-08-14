#include <iostream>
#include <string>

using namespace std;

class Animal { // clase base
    protected: // atributos protegidos es decir, accesibles por las clases derivadas pero no por el resto de las clases
        static int numero_animales; // atributo estático que cuenta el número de animales creados
        string alimento; // atributo que indica el alimento del animal

    public: // métodos públicos
        Animal(); // constructor
        ~Animal(); // destructor
        static int obtenerNumeroAnimales(); // método estático que devuelve el número de animales creados hasta el momento 
        //las funciones static no pueden acceder a los atributos de la clase, solo a los atributos static
        string obtenerAlimento(){ // método que devuelve el alimento del animal
            return alimento;
        };
        void comer(){
            cout<<"Este animal está comiendo " <<alimento<<"... ñom ñom"<<endl;
        };
};

int Animal::numero_animales = 0;

Animal::Animal()
{
    cout<<"Creando nuevo animal ... "<<endl;
    numero_animales += 1; //la variable static se incrementa en uno cada vez que se crea un nuevo animal
}

Animal::~Animal()
{
    cout<<"Borrando animal..."<<endl;
    numero_animales-=1;
}

int Animal::obtenerNumeroAnimales()
{
    return numero_animales;
}

class Herviboro : public Animal {
    public:
        Herviboro();
        void pastar(){
            cout<<"Este animal está pasteando ..."<<endl;
        }
};

Herviboro::Herviboro():Animal(){
    this->alimento = "plantas ";
}
class Carnivoro : public Animal {
public:
    Carnivoro():Animal(){
        this->alimento = "plantas ";
    }
    void cazar(){
        cout<<"Este animal está cazando ..."<<endl;
    }
};

class Omnivoro : public Herviboro, public Carnivoro{ //esta es una clase que hereda de dos clases, es decir, es una clase múltiple
public: 
    Omnivoro():Herviboro(),Carnivoro(){}
    void comer(){
        cout<<"Este animal come lo que sea ...."<<endl;
    }
};

int main(){
    Animal *a = new Animal();
    Herviboro *h = new Herviboro();
    Carnivoro *c = new Carnivoro();
    Omnivoro *o = new Omnivoro();

    cout<<"Numero de animeles: "<<Animal::obtenerNumeroAnimales()<<endl;
    
    a->comer();
    
    h->pastar();
    h->comer();

    c->cazar();
    c->comer();
    cout<<"omnivoro"<<endl;
    o->comer();

    delete a;
    cout<<"Numero de animales"<<Animal::obtenerNumeroAnimales()<<endl;
}