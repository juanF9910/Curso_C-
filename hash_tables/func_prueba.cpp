#include <iostream>
#include <vector>
#include <cstring>
#include <bitset> //se usa para convertir un char a su representación binaria;
#include <string>
#include <fstream> //se usa para leer archivos
#include <cmath> //se usa para elevar un número a una potencia
#include <unordered_map>
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
    unsigned int valor = 0; // Inicializar valor a 0
    size_t length = input.length();

    for (size_t i = 0; i < length; i += L) {

        string part = input.substr(i, L); // Extraer una subcadena de longitud L
        bitset<64> bits(part);  // Usar un bitset suficientemente grande para contener hasta 64 bits
        valor ^= static_cast<unsigned int>(bits.to_ulong());
    }

    if (L == 8){
        return valor & 0xFF; // devolvemos los 8 bits menos significativos
    } else if(L == 14){
        return valor & 0x3FFF; // devolvemos los 14 bits menos significativos
    } else {
        return -1; //unvalor negativo para indicar que la longitud no es válida
    }
}


vector<unsigned long int> countFrequencies(vector<unsigned long int>& numbers) { //entrega el número de colisiones por clave en la tabla hash
    // Crear un unordered_map para almacenar las frecuencias
    unordered_map<unsigned long int, int> frequencyMap;
    vector<unsigned long int> result;

    // Recorrer la lista de números y contar las frecuencias
    for (unsigned long int number : numbers) {
        frequencyMap[number]++;
    }

    // Mostrar los resultados
    
    //cout << "Valor\tFrecuencia" << std::endl;
    for (const auto& entry : frequencyMap) {
        result.push_back(entry.second);
    }

    return result;
}

unsigned long int desviacion(vector<unsigned long int>& frecuencias, int L, unsigned long int tam) { //entrega el número de colisiones por clave en la tabla hash   

    long int promedio=tam/pow(2,L);
    long int desviacion=0;
    for (unsigned long int frecuencia : frecuencias) {
        desviacion+=pow((frecuencia-promedio),2);
    }

    return desviacion;
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
    // Leer el archivo línea por línea
    string line; //vamos a guardar cada palabra en esta variable
    //int L[]={8,14}; //longitudes de los hash que vamos a probar
    int L=8;
    int tam=0;
    while(getline(inputFile, line)){
        tam++;
    }

    
    //for(auto l:L){
      //  vector<unsigned long int> numbers;
        //while(getline(inputFile, line)){
          
          //  numbers.push_back(hashFunc1(line, l));
        //}

        // Mostrar las frecuencias de los números
        //long int Desviación=desviacion(countFrequencies(numbers), l, tam);

    //}
    
    vector<unsigned long int> numbers;
    
    while(getline(inputFile, line)){
      numbers.push_back(hashFunc1(line, L));
    
    }

    // Mostrar las frecuencias de los números
    vector<unsigned long int> Vector=countFrequencies(numbers);
    long int Desviación=desviacion(Vector, L, tam);
    cout<<"Desviación: "<<Desviación<<endl;

    // Cerrar el archivo
    inputFile.close();

    return 0;
}