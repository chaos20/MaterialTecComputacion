#include <iostream>
#include <stdexcept>
#include <OrderedArrayList.h>
#include <OrderedLinkedList.h>
#include <time.h>

using namespace std;

int main(){
    char Op;
    cout << "Que tipo de lista desea: Array(A) o Linked(L), escriba su respuesta: " << endl;
    cin >> Op;
    if(Op == 'A'){
        int val;
        int bus;
        OrderedArrayList<int> Lista1(10);
        for(int i = 0; i < 10; i++){
            cout << "introdusca el valor: " << endl;
            cin >> val;
            Lista1.insert(val);
        }
        cout << endl;
        cout << endl;
        for(int i = 0; i<10; i++){
            Lista1.goToPos(i);
            cout << Lista1.getElement() << endl;
        }
        cout << endl;
        cout << endl;
        cout << "Introdusca el numero para buscar su indice: ";
        cin >> bus;
        cout << Lista1.indexOf(bus);
        }
    if(Op == 'L'){
        int val;
        int bus;
        OrderedLinkedList<int> Lista2;
        for(int i = 0; i < 10; i++){
            cout << "introdusca el valor: " << endl;
            cin >> val;
            Lista2.insert(val);
        }
        cout << endl;
        cout << endl;
        for(int i = 0; i < 10; i++){
            Lista2.goToPos(i);
            cout << Lista2.getElement() << endl;
        }
        cout << endl;
        cout << endl;
        cout << "Introdusca el numero para buscar su indice: ";
        cin >> bus;
        cout << Lista2.indexOf(bus);
    }

    return 0;
}
