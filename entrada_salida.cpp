#include <iostream>
#include <vector>

using namespace std;

int main(){

    /*
    para pedir datos usamos cout y para guardaros cin
    */
    int edad=0;
    cout <<"ingrese su edad" <<endl; 
    cin>>edad;

    cout <<"su  edad es " <<edad <<endl; 
    if(edad>=18 && edad <=40){
        cout <<"puedes votar" <<endl; 
    }else{
        cout <<"no puedes votar" <<endl;
    }

    return 0; 
}