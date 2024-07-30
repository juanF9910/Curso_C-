/*
sobrecarga de constructores
*/

#include <iostream>


using namespace std; 

class Fecha{

    private: 
        int dia, mes, anio; 

    public: 
        Fecha(int, int, int); //constructor 1
        Fecha(long); //constructor 2
        ~Fecha(); 
        void mostrarfecha();

};
/*constructor número 1, dia/mes/año */
Fecha::Fecha(int dia, int mes, int anio): dia(dia), mes(mes), anio(anio){} 
/*lo fundamental del constructor es inicializar los atributos*/

/*pero qué pasa si la persona quiere poner la fecha de forma diferente ano mes dia*/
Fecha::Fecha(long fecha){
    anio= (int) (fecha/10000); //REALIZAMOS UN CASTEO.
    mes=(int)(fecha-anio*10000)/100;
    dia=(int)(fecha-anio*10000-mes*100);
}
/*lo que se ingresa es diferente, pero de ahí tengo que sacar los atributos
del objeto, definidos en la parte de private
*/

Fecha::~Fecha(){

}

void Fecha::mostrarfecha(){
    cout <<"la fecha es: " <<dia <<"/" <<mes << "/" <<anio <<endl;
}




int main(){

    Fecha* h= new Fecha(9, 1, 2017); 
    Fecha* h1=new Fecha(20170109);
    h->mostrarfecha();
    h1->mostrarfecha();

    return 0; 
}