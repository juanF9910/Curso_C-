#include <iostream>

/*
Cómo declarar variables, modificarlas e imprimirlas en pantalla

el comando const se usa para indicar que no se puede modificar el valor de la
variable que le sigue. 
*/
using namespace std; 

int main(){
    int edad=10; 
    edad=edad+1;
    int edades[]={1,2,3,4,5}; 
    const char letra='F'; //tiene 4 bytes, debe ponerse entre comillas simples si es un solo caracter
    cout <<"hola mundo " <<edad <<letra <<edades[2] <<endl;  
 
    return 0; 
}