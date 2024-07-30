#include <iostream>
#include <string>

using namespace std; 

class Perro{

    private: 
        string raza, nombre; //no importa el orden en esta parte, 
        //el orden importa es en el constructor. 
    
    public: 
        Perro(string, string); //constructor
        ~Perro(); 
        void mostrardatos(); 
        void jugar(); 
};


/*inicializamos los atributos de la clase*/
Perro::Perro(string nombre, string raza): nombre(nombre), raza(raza){}
Perro::~Perro(){}

void Perro::mostrardatos(){

    cout <<"nombre: " <<nombre <<"raza: " <<raza <<endl;
}

void Perro::jugar(){

    cout <<"el perro está jugando" <<endl;
}


int main(){

    Perro* p=new Perro("luna", "pincher");
    p->mostrardatos();
    p->jugar();
    p->~Perro(); //destruimos el objeto


    delete p; //liberamos el espacio de memoria
    return 0; 
}