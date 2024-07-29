#include <iostream>
#include <vector>
using namespace std; 


int main(int argc, char const *argv[] ){

    vector<int> vector1={1, 2, 3, 4, 5}; 

    for( auto &&i : vector1){ //esta es una manera de usar el for sobre una lista
        cout <<i <<endl;
    }

    for( int i=0; i< vector1.size(); i++){
        cout <<vector1[i] <<endl;
    

    }
    return 0; 
}