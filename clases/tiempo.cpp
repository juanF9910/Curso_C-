#include <iostream>

using namespace std; 

class Tiempo{
 
    private: 
        int horas, minutos, segundos; 

    public: 

        Tiempo(int, int, int); //constructor 1
        Tiempo(int); //constructor 2
        ~Tiempo();

        void mostrarTiempo(); /*si voy a usar los mismos parámetros de la clase
        no es necesario pasarlos como  parámetros porque las funciones miembro
        pueden acceder a estos de forma automática.
        */
}; 

//en el constructor se deben inicializar los atributos de la clase. 
Tiempo::Tiempo(int horas, int minutos, int segundos): horas(horas), minutos(minutos),
segundos(segundos){}

Tiempo::Tiempo(int tiemposeg){
    /*inicializamos los atributos de la clase*/
    horas=tiemposeg/3600;
    tiemposeg %=3600;
    minutos= tiemposeg/60; 
}
Tiempo::~Tiempo(){

}

void Tiempo::mostrarTiempo(){
    cout <<"la hora es: " <<horas <<":" <<minutos <<":" <<segundos <<endl;
}

int main(){

    Tiempo* h1= new Tiempo(16, 23, 30); //ensayo del constructor 1
    h1->mostrarTiempo();
    Tiempo* h2=new Tiempo(3600); //ensayo del constructor 2
    h2->mostrarTiempo();

    delete h1; 
    delete h2; 

    return 0;
}