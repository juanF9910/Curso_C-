#include <iostream>
#include <vector>
#include <cstring>
#include <bitset> //se usa para convertir un char a su representación binaria;
#include <string>
#include <fstream> //se usa para leer archivos
#include <cmath> //se usa para elevar un número a una potencia
#include <unordered_map> //se usa para contar las frecuencias de los valores hash
using namespace std;


unsigned long int hashFunc1(string clave, int L){ 
    unsigned long int num = 0; 
    int len = clave.size();  // Calcular la longitud de la cadena una vez

    for(int i = 0; i < len; i++){
        num += clave[i];
    }

    if (L == 8){
        return num & 0xFF; // Usar hash de la clave
    } else if(L == 14){
        return num & 0x3FFF; // Usar hash de la clave
    } else {
        return -1; //unvalor negativo para indicar que la longitud no es válida
    }
}

unsigned long int hashFunc2(const string clave, int L){ 
    unsigned long int num = 1; 
    int len = clave.size();  // Calcular la longitud de la cadena una vez

    for(int i=0; i<len; i++){
        num*=clave[i];
    }

    if (L == 8){
        return num & 0xFF; // devolvemos los 8 bits menos significativos
    } else if(L == 14){
        return num & 0x3FFF; // devolvemos los 14 bits menos significativos
    } else {
        return -1; //unvalor negativo para indicar que la longitud no es válida
    }
}

string charToBinary(const string array) { //convierte un string a su representación binaria en una cadena de bits 
    string binaryString;

    for (int i = 0; i < array.size(); ++i) {
        bitset<8> bits(array[i]); 
        binaryString += bits.to_string();
    }

    return binaryString;
}

unsigned long int hashFunc3(const string array, int L) { //esta es una función hash que usa la representación binaria de la cadena

    string input=charToBinary(array);
    unsigned long int valor = 0; // Inicializar valor a 0
    size_t length = input.length();

    for (size_t i = 0; i < length; i += L) {

        string part = input.substr(i, L); // este comando extrae una subcadena de longitud L de la cadena de entrada, iniciando en la posición i
        bitset<64> bits(part);  // Usar un bitset suficientemente grande para contener hasta 64 bits
        valor ^= static_cast<unsigned long int>(bits.to_ulong());
    }

    if (L == 8){
        return valor & 0xFF; // devolvemos los 8 bits menos significativos
    } else if(L == 14){
        return valor & 0x3FFF; // devolvemos los 14 bits menos significativos
    } else {
        return -1; //unvalor negativo para indicar que la longitud no es válida
    }
}


vector<unsigned long int> countFrequencies(vector<unsigned long int>& numbers) { //se le entrega un vector con 
/* los resultados de la función hash para clave y retorna un vector de frecuencias de cada valor hash*/
    // Crear un unordered_map para almacenar las frecuencias
    unordered_map<unsigned long int, int> frequencyMap;
    vector<unsigned long int> result;

    // Recorrer la lista de números y contar las frecuencias
    for (unsigned long int number : numbers) {
        frequencyMap[number]++;
    }
    for (const auto& entry : frequencyMap) {
        result.push_back(entry.second);
    }
    return result;
}

double desviacion(const std::vector<unsigned long int>& frecuencias, int L, unsigned long int tam) {   
    double promedio = static_cast<double>(tam) / pow(2, L); //valor promedio de colisiones
    double desviacion = 0.0;
    for (unsigned long int frecuencia : frecuencias) {
        desviacion += pow(frecuencia - promedio, 2);
    }

    return sqrt(desviacion / frecuencias.size());
}

int main(){

   string filePath = "/usr/share/dict/words";

    // Crear un objeto ifstream para manejar la entrada del archivo
    ifstream inputFile(filePath);

    // Verificar si el archivo se abrió correctamente
    if (!inputFile.is_open()) {
        cout<<"No se pudo abrir el archivo: " << filePath <<endl;
        return 1;
    }
   
    int l[]={8,14};
    int L=8;
    unsigned long int tam=0;

    

 
    string Line;
 
    while(getline(inputFile, Line)){
        tam++;
    }
    vector<unsigned long int> numbers={};
    for(auto L: l){

        inputFile.clear(); 
        inputFile.seekg(0);
        

        while(getline(inputFile, Line)){
            numbers.push_back(hashFunc3(Line, L));
        }

        vector<unsigned long int> frecuencias = countFrequencies(numbers);
        double colisiones = desviacion(frecuencias, L, tam);
        cout << "Desviación para L= "<< L<<" es: " <<colisiones << "para la función 1"<<endl;
        numbers.clear();
    }




    inputFile.close();

    return 0;
}
