#include <iostream>
#include <DoubleLinkedList.h>

using namespace std;

int main(){
    DoubleLinkedList<int> DLL;
    cout << "se introduciran 1000 elementos: " << endl;
    for(int i = 0; i < 1000; i++){
        DLL.insert(i);
    }
    cout << endl;
    cout << endl;
    cout << "se mostrara el tamaño de la lista: " << endl;
    cout << DLL.getSize() << endl;
    cout << endl;
    cout << endl;
    cout << "se ira al inicio de la lista: " << endl;
    DLL.goToStart();
    cout << endl;
    cout << endl;
    cout << "se hara un append de -2: " << endl;
    DLL.append(-2);
    cout << endl;
    cout << endl;
    cout << "se imprimra la lista" << endl;
    for(int i = 1; i < 1002; i++){
        cout << DLL.getElement() << endl;
        DLL.goToPos(i);
    }
    cout << endl;
    cout << endl;
    cout << "se ira al final de la lista: " << endl;
    DLL.goToEnd();
    cout << DLL.atEnd() << endl;
    cout << endl;
    cout << endl;
    cout << "se regresara un espacio y se sacara el -2: " << endl;
    DLL.previous();
    cout << DLL.getElement() << endl;
    cout << endl;
    cout << endl;
    cout << "se movera a la posicion 343: " << endl;
    DLL.goToPos(343);
    cout << DLL.getPos() << endl;
    cout << endl;
    cout << endl;
    cout << "se avanzara 2 posiciones y se imprimira la posicion: " << endl;
    DLL.next();
    DLL.next();
    cout << DLL.getPos() << endl;
    cout << endl;
    cout << endl;
    cout << "se limpiara la lista y se mostrara el tamaño: " << endl;
    DLL.clear();
    cout << DLL.getSize() << endl;



    return 0;
}
