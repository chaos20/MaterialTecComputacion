#include <iostream>
#include "ArrayList.h"
#include <stdlib.h>
#include <time.h>

//rand()%21
using namespace std;

void inicializar(int pmax,int asize){
    //srand(time(0));
    ArrayList<int> arraylist(pmax);
    for(int i = 0; i < pmax; i++){
        arraylist.append(i);
        }
    cout << "la lista es: " <<endl;
    for(int i = 0; i < arraylist.getSize(); i++){
        arraylist.goToPos(i);
        cout << arraylist.getElement() << endl;
        }
    /*cout << "Se movera el indice a la posicion 5" <<endl;           //here
    arraylist.goToPos(5);                                       //here
    cout << "pos: " << arraylist.getPos()<< endl;
    cout << "Se insertara un 34 en la lista" <<endl;
    cout << endl;
    arraylist.insert(34);
    cout << "la lista es: " <<endl;
    for(int i =0; i < arraylist.getSize(); i++){
        arraylist.goToPos(i);
        cout << arraylist.getElement() << endl;
        }
        arraylist.goToPos(5);                          //here
    cout << "Se retrocedera una posicion" <<endl;
    arraylist.previous();
    cout << "Se mostrara el elemento" <<endl;
    cout << arraylist.getElement() << endl;
    cout << "se avanzara una posicion" <<endl;
    arraylist.next();
    cout << "Se va a extraer el elemento en la posicion actual" <<endl;
    cout << arraylist.remove() << endl;
    cout << "Se determinara si la posicion es la primera" <<endl;
    cout << arraylist.atStart()<<endl;
    cout << "se movera el indice al inicion y se pobara si esta ahi" <<endl;
    arraylist.goToStart();
    cout << arraylist.atStart()<<endl;
    cout << "se hara append del numero 36 y se determinara si esta ahi asi como su indice" <<endl;
    arraylist.append(36);
    cout <<arraylist.contains(36)<<endl;
    cout << arraylist.indexOf(36)<<endl;*/
    cout << endl;
    ArrayList<int> aux(asize);
    for(int i = 1; i < asize; i++){
        aux.append(i);
        }
    cout << "nueva lista a insertar en la primera lista: "<<endl;
    for(int i =0; i < aux.getSize(); i++){
        aux.goToPos(i);
        cout << aux.getElement() << endl;
    }
    arraylist.extend(aux);
    cout << endl;
    cout << "la lista es: " <<endl;
    for(int i = 0; i < arraylist.getSize(); i++){
        arraylist.goToPos(i);
        cout << arraylist.getElement() << endl;
        }

}
int main(){
    int csize = 10;
    int asize = 3;
    cout << "El tamano de la lista de 50: " << endl;
    cout <<endl;
    inicializar(csize,asize);
    return 0;
}
