#include <iostream>
#include <string>

using namespace std; 


struct persona{
    string nombre; 
    int edad;
};

union persona2{
    int edad; 
    char letra; 
}; /* sirve para almacenar en un mismo espacio de memoria diferentes valores, 
por ejmplo, un número o una letra pero no ambos a la vez. 
*/

int main(){
    char letra='A'; 
    char* puntero=&letra; 
    cout <<(int*)puntero <<endl; /*
    realizamos un casteo del valor que se guardó en la memoria
    */
   char* texto=(char*)"hola mundo"; //este sería el caso en el que defino el texto
   //no como un array. 


    persona* p=new  persona(); //definir una variable tipo estructura e inicializar.
    p->nombre="felipe"; 
    p->edad=23;

    cout <<p->nombre <<endl;

    persona2 x={'A'};

    return 0; 
}