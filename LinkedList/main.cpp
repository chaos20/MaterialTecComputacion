#include <iostream>
#include <LinkedList.h>
#include <stdlib.h>


using namespace std;

int main(){
    LinkedList<int> linkedlist;   // cuando se invoca a un constructor que no requiere parametros, no se usa el ()
    for(int i = 0; i < 4; i++){
        linkedlist.append(i);
    }
    while(!linkedlist.atEnd()){
        cout << linkedlist.getElement() <<endl;
        linkedlist.next();
    }
    cout <<endl;
    linkedlist.previous();
    cout << linkedlist.remove() <<" se elimino" << endl;
    linkedlist.goToStart();
    cout << linkedlist.atStart() << " al inicio" << endl;
    cout << endl;
    while(!linkedlist.atEnd()){
        cout << linkedlist.getElement() <<endl;
        linkedlist.next();
    }
    cout << endl;
    cout << linkedlist.atEnd() << " al final" << endl;
    cout <<endl;
    cout << "se movera a la posicion 3" << endl;
    linkedlist.goToPos(2);
    cout << linkedlist.getPos() << " posicion" << endl;
    cout <<endl;
    cout << "se revertira la lista" << endl;
    cout <<endl;

    //cout << linkedlist.compare(aux) <<endl;
    linkedlist.reverse();
    linkedlist.goToStart();
    while(!linkedlist.atEnd()){
        cout << linkedlist.getElement() <<endl;
        linkedlist.next();
    }
    cout << endl;
    cout << "se limpiara la lista" << endl;
    linkedlist.clear();
    cout << linkedlist.getSize() << " tamanio de la lista" << endl;
    return 0;
}
