/*vamos a aprender sobre los métodos constructores y modificadores*/

#include  <iostream>

using namespace std; 

class Punto{

    private: //NO LAS PUEDO MODIFICAR NI ACCEDER A ELLAS
        int x, y; 

    public:

        Punto(); 
        void setpunto(int, int); //los setters siempre son vacíos
        int getpuntox(); //los getters son del tipo de las variables que devuelven
        int getpuntoy();
};


Punto::Punto(){}

void Punto::setpunto(int x, int y){ /*sirve para cambiar los atributos de 
nuestro objeto en cualquier momento */
    this->y=y;
    this->x=x; 
}

int Punto::getpuntox() //sirve para obtener los atributos. 
{
    return x;
}

int Punto::getpuntoy()
{
    return y;
}

int main(){

    Punto *p= new Punto();
    p->setpunto(1, 2); 
    cout <<"(" << p->getpuntox() <<"," <<p->getpuntoy() << ")"<<endl;

    p->setpunto(3, 4);
    cout <<"(" << p->getpuntox() <<"," <<p->getpuntoy() << ")"<<endl;
    delete p; 
    return 0; 
}