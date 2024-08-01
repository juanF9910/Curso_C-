/*
un árbol es un conjunto de estructuras que están 
conectadas por punteros de forma no nece-
sariamente lineal. 

LONGITUD DE CAMINO: número de ramas que se
deben recorrer partiendo de un nodo para llegar
a otro. (num nodos-1)

ALTURA DE UN NODO: desde la hoja se cuenta 
cuantos nodos hay hasta llegar a él

PROFUNDIDAD(NIVEL) DE UN NODO: NÚMERO DE NODOS CON
TADOS DESDE LA RAIZ (INICIA EN CERO)

NODOS HERMANOS: deben estar en el mismo nivel 
y tener el mismo nodo padre 

ORDEN DE UN ÁRBOL: cantidad máxima de hijos que 
puede tener un nodo. 

Un árbol binario es una estructura recursiva, además 
se divide en tres partes: 
raiz, subárbol derecho y subárbol izquierdo. 
*/

#include <iostream>


using namespace std; 

struct Nodo{
    int dato; 
    Nodo* der; 
    Nodo* izq; 
};

int main(){


    return 0; 
}