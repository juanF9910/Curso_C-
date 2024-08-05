/*
Un árbol binario de búsqueda es aquel tal que dado un nodo
todos los datos del subárbol izquierdo a este son menores, mientras que todos los
datos del subárbol derecho son mayores.  
*/
#include <iostream>
#include <vector>

using namespace std; 

struct Nodo{ //definición del nodo
    int dato; 
    Nodo* izq; 
    Nodo* der; 
    Nodo* padre; //este puntero es fundamental para eliminar nodos
};

Nodo* crearNodo(int, Nodo*);
void insertar(Nodo*&, int, Nodo*); /*si el arbol está vacío, sino*/

void mostrar(Nodo*, int); /*si el árbol está vacío, sinoi*/
void preorden(Nodo*);
void inorden(Nodo*);
void posorden(Nodo*);
bool buscar(Nodo*, int);

void eliminar(Nodo*, int);

/*para eliminar nodos de un árbol es necesario que el nodo sepa 
quién es su padre*/
 
int main(){
    Nodo* arbol=nullptr; 
    int cont=0; 

    vector<int> datos={12,8, 7, 16, 14};

    for ( auto &&i : datos){
      insertar(arbol, i, NULL);
    }

    mostrar(arbol, cont); //mostrar el arbol como tal
    cout<<buscar(arbol, 7)<<endl;
    preorden(arbol);/*recorrer el árbol en preorden*/
    cout<<endl;
    inorden(arbol);/*recorrer el árbol en preorden*/
    cout<<endl;
    posorden(arbol);/*recorrer el árbol en preorden*/
    cout<<endl;
    eliminar(arbol, 16);
    cout<<endl;
    cont=0;
    mostrar(arbol, cont);
    return 0; 
}


Nodo* crearNodo(int n, Nodo* padre){ 

  Nodo* nuevo=new Nodo(); 

  nuevo->dato=n; 
  nuevo->der=nullptr; 
  nuevo->izq=nullptr; 
  nuevo->padre=padre;
  return nuevo; 
}

void insertar(Nodo* &arbol, int n, Nodo* padre){ //incialmente el puntero 
  //es la raiz del árbol
  Nodo* nuevo=crearNodo(n, padre);

  if(arbol==NULL){//si el árbol está vacío 
    arbol=nuevo; 
  }else{
    //como estamos construyendo un árbol binario de búsqueda  
    /*necesitamos tener en cuenta el valor del nodo respecto a la raiz */
    int raiz=arbol->dato; 

    if(n<raiz){ /*se coloca al lado izquierdo*/
        insertar(arbol->izq, n, arbol); //recursividad, el puntero apunta hacia donde
        //quiero insertar
    }else{
        insertar(arbol->der, n,arbol);
    }
  }
}

void mostrar(Nodo* arbol, int cont){
  if(arbol==NULL){
    return;
  }else{
    mostrar(arbol->der, cont+1); 
    for(int i=0; i<cont; i++){ //para dar espacios entre nodo y nodo
      cout<<"   ";
    }
    cout<< arbol->dato<<endl;
    mostrar(arbol->izq, cont+1);
  
  }
}

bool buscar(Nodo *arbol, int n){

  if(arbol==NULL){ /*si el árbol está vacío*/
    return false; 
  }else if(arbol->dato==n){ //si el elemento es justo a donde apunta el puntero
    return true; 
  }else if(n<arbol->dato){
    return buscar(arbol->izq, n);
  }else{
    return buscar(arbol->der, n);
  }
}

void preorden(Nodo* arbol){
  if(arbol==NULL){
    return; 
  }else{
    cout<<arbol->dato<<" ";  //imprimimos la raiz
    preorden(arbol->izq);
    preorden(arbol->der);
  }
}

void inorden(Nodo* arbol){
  if(arbol==NULL){
    return; 
  }else{
    inorden(arbol->izq);
    cout<<arbol->dato<<" ";//imprimimos la raiz, el puntero no se ha movido
    inorden(arbol->der);
  }
}

void posorden(Nodo* arbol){
  if(arbol==NULL){
    return; 
  }else{
    posorden(arbol->izq);
    posorden(arbol->der);
    cout<<arbol->dato<<" ";//imprimimos la raiz, el puntero no se ha movido
  }
}

/***************************************************************************/

Nodo* minimo(Nodo* arbol){ //función que entrega el valor más a la 
/*izquierda posible dado un nodo*/
  if(arbol==NULL){
    return NULL;
  }
  if(arbol->izq){ //si tiene hijo izquierdo, nos vamos a la parte más 
  //izquierda posible
    return minimo(arbol->izq);
  }else{
    return arbol;/*si no tiene hijo izquierdo retornamos el mismo nodo*/
  }
}

void reemplazar(Nodo* arbol, Nodo* nuevo){
  /*arbol es el nodo que queremos reemplazar por nuevo*/
  if(arbol->padre){
    if(arbol->dato==arbol->padre->izq->dato){ //verificamos si quiene hijo 
    //izquierdo
      arbol->padre->izq=nuevo; /*asignamos el nuevo hijo*/
    }else if(arbol->dato==arbol->padre->der->dato){ /*verificamos si tiene
    hijo derecho*/
      arbol->padre->der=nuevo; 
    }
  }
  if(nuevo){
    /*se le asifna el nuevo padre*/
    nuevo->padre=arbol->padre;
  }
}

void destruir(Nodo* nodo){
  nodo->izq=NULL; 
  nodo->der=NULL; 
  delete nodo; 
}

void eliminarnodo(Nodo* nodo_eliminar){
  /*debemos tener en cuenta si el nodo tiene un hijo, o dos o 
  ninguno*/

  //si el nodo tiene dos hijos, derecho y luego lo más izquierdo posible
  if(nodo_eliminar->izq && nodo_eliminar->der){
    Nodo* menor= minimo(nodo_eliminar->der); //el nodo de valor mínimo en 
    //la rama derecha del nodo 

    /*reemplazo el valor del nodo a eliminar por el menor a la derecha*/
    nodo_eliminar->dato=menor->dato;
    eliminarnodo(menor);
  }else if(nodo_eliminar->izq ){ /*si el nodo tien un solo hijo, 
  entonces el hijo toma el lugar del pabre*/
    reemplazar(nodo_eliminar, nodo_eliminar->izq);
    destruir(nodo_eliminar);
  }else if(nodo_eliminar->der){ /*si en nodo tiene un solo hijo a la derecha*/
    reemplazar(nodo_eliminar, nodo_eliminar->der);
    destruir(nodo_eliminar);
  }else{
    reemplazar(nodo_eliminar, NULL);
    delete nodo_eliminar;
  }
}

void eliminar(Nodo* arbol, int n){ //qué pasa si hay más de un n igual???

  if(arbol==NULL){
    return;
  }else if(n<arbol->dato){ //nos vamos a la izquierda, esto solo funciona si tenemos un solo n, en el caso de que dato sea una estructura, no funcionará 
  //se debe modificar la función buscar para que retorne un puntero a la estructura que se quiere eliminar . 
    eliminar(arbol->izq, n);
  }else if(n>arbol->dato){
    eliminar(arbol->der, n);
  }else{
    eliminarnodo(arbol); 
  }
}

