#include <iostream>
#include <string>

using namespace std; 

/*
vamos a crear nuestra primera clase en C++, un miembro de una clase puede ser o bien un método o bien un atributo
*/

class Persona{ //por defecto la clase encapsula (restringe el acceso a la información
    
    private: //no puedo acceder a los atributos de la clase, pero sí los 
    //puedo modificar. también hay 
    //otra forma de proteger y es 
    //protected, se usa cuando definimos herencia.
        string nombre;
        int edad; 
    //definimos el constructor de los objetos, sirven para inicializar variables. 

    public:

        /*Persona(string n, int e){ //estos son los atributos que me ingresa el usuario. 
            nombre=n; //a la izquierda como se maneja en el código, a la derecha lo que se ingresa
            edad=e;
        }*/

        /*existe otra forma de definir el constructor en línea*/
        //Persona(string n, int e): nombre(n), edad(e){}
        /*también se puede usando el comando this*/
        
        static int numero_personas;  

        Persona(string nombre, int edad);
        
        ~Persona(){
            /*sólo se debe hacer limpieza manual si los atributos se definieron 
            como punteros. */
            //cout <<"destructor" <<endl;
        }

    /*podemos definir funciones que sirvan para cambiar los atributos de 
    un objeto sin necesidad de redefinirlo*/

        Persona &change_name(string nombre){ //se hace de esta manera para que podamos concatenar los cambios de atributos 
            this->nombre=nombre; /*el & se pone en señal de que devolvemos una referencia y no una copia del objeto, si lo quitamos
            estaríamos devolviendo un objeto por valor, que no se modificaría como tal, entonces no funcionaría el encadenamiento*/
            return *this;
        }

        Persona &change_edad(int edad){

            this->edad=edad; 
            return *this; //devuelve un objeto de tipo persona
        }
        //métodos 

        void saludar();
};

int Persona::numero_personas=0; //de esta forma se inicializa una variable estática
/*es muy útil definir las funciones de esta manera para que no se cree una copia cada vez que se instancie la clase*/

void Persona::saludar(){
    cout <<"hola, me llamo: " <<nombre <<" y tengo: " <<edad <<" años" <<endl;
}

Persona::Persona(string nombre, int edad){
    this->nombre=nombre; 
    this->edad=edad;
    numero_personas++;

}

int main(){

    Persona p=Persona("Felipe", 23); //puedo definirlo sin puntero
    p.saludar();
    Persona* p1=new Persona("Diana", 27); //es muy útil trabajar con punteros 
    //pues estos apuntan al inicio de la estructura que define la clase. 
    p1->saludar();
    p1->change_name("ximena").change_edad(24); //concatenamos los cambios al objeto, sin necesidad de acceder de nuevo a los atributos ni redefinir el objeto. 
    p1->saludar();

    cout <<Persona::numero_personas <<endl; 
    return 0; 
}