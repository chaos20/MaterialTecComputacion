#include <iostream>
#include <DoubleCircleList.h>

using namespace std;

int main(){
    cout << "se introduciran 1000 elementos: " << endl;
    DoubleCircleList<int> DCL;
    for(int i = 0; i < 1001; i++){
        DCL.insert(i);
    }
    cout << endl;
    cout << endl;
    cout << "el tamaño de la lista es de: " << endl;
    cout << DCL.getSize() << endl;
    cout << endl;
    cout << endl;
    cout << " se regresara 5 posiciones y se eliminara el elemento en dicha posicion: " << endl;
    DCL.previous();
    DCL.previous();
    DCL.previous();
    DCL.previous();
    DCL.previous();
    cout << DCL.remove() << endl;
    cout << endl;
    cout << endl;
    cout << "se imprimira la lista al derecho y al revez: " << endl;
    for (int i = 0; i < 1001; i++){
        DCL.next();
        cout << DCL.getBack() << endl;
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < 11; i++){
        DCL.previous();
        cout << DCL.getFront() << endl;
    }
    cout << endl;
    cout << endl;
    cout << "funcion getElements: " << endl;
    cout << DCL.getElements(false) <<  endl;
    cout << endl;
    cout << endl;
    cout << "se eliminara la lista y se mostrara su tamaño: " << endl;
    DCL.clear();
    cout << endl;
    cout << endl;
    cout << DCL.getSize() << endl;

    return 0;
}
