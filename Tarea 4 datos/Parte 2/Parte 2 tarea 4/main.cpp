#include <iostream>
#include <ArrayQueue.h>
#include <LinkedQueue.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));
    char opc;
    cout << "elija el tipo de Cola a usar: A=Array Queue o L=Linked Queue" << endl;
    cin >> opc;
    if(opc == 'A'){
        int cantOp;
        ArrayQueue<int> ArQ;
        cout << "ingrese la cantidad de operaciones a realizar: " << endl;
        cin >> cantOp;
         while(cantOp > 0){
            if (0 <= ArQ.getSize() && ArQ.getSize() < 1024){
                int realizar = rand()%(6-1);
                if(realizar == 1){
                    int val = rand();
                    ArQ.enqueue(val);
                    cout << "se realizara un enqueue" << endl;
                    cout << "elemento a insertar: " << val << endl;
                    cout << "tamaño de la cola: " << ArQ.getSize() << endl;
                    cout << "los elementos de la cola: " << endl;
                    ArQ.print();
                    cantOp--;
                    cout << endl;
                    cout << endl;
                }
                if(realizar == 2 && ArQ.getSize() != 0){
                    int val = ArQ.dequeue();
                    cout << "se realizara un dequeue" << endl;
                    cout << "elemento a sacar: " << val << endl;
                    cout << "tamaño de la cola: " << ArQ.getSize() << endl;
                    cout << "los elementos de la cola: " << endl;
                    ArQ.print();
                    cantOp--;
                    cout << endl;
                    cout << endl;
                }
                if(realizar == 3){
                    int val = rand();
                    ArQ.enqueueFront(val);
                    cout << "se realizara un enqueue Front" << endl;
                    cout << "elemento a insertar: " << val << endl;
                    cout << "tamaño de la cola: " << ArQ.getSize() << endl;
                    cout << "los elementos de la cola: " << endl;
                    ArQ.print();
                    cantOp--;
                    cout << endl;
                    cout << endl;
                }
                if(realizar == 4 && ArQ.getSize() != 0){
                    int val = ArQ.dequeueRear();
                    cout << "se realizara un dequeue rear" << endl;
                    cout << "elemento a sacar: " << val << endl;
                    cout << "tamaño de la cola: " << ArQ.getSize() << endl;
                    cout << "los elementos de la cola: " << endl;
                    ArQ.print();
                    cantOp--;
                    cout << endl;
                    cout << endl;
                }
            }
            else{
                cout << "la cola esta al maximo de tamaño" << endl;
                break;
            }
        }
        ArQ.clear();
    } //next opcion
    if(opc == 'L'){
        int cantOp;
        LinkedQueue<int> LnQ;
        cout << "ingrese la cantidad de operaciones a realizar: " << endl;
        cin >> cantOp;
         while(cantOp > 0){
            int realizar = (rand()%(6-1));
            cout << realizar << endl;
            if(realizar == 1){
                int val = rand();
                LnQ.enqueue(val);
                cout << "se realizara un enqueue" << endl;
                cout << "elemento a insertar: " << val << endl;
                cout << "tamaño de la cola: " << LnQ.getSize() << endl;
                cout << "los elementos de la cola: " << endl;
                LnQ.print();
                cantOp--;
                cout << endl;
                cout << endl;
            }
            if(realizar == 2 && LnQ.getSize() != 0){
                int val = LnQ.dequeue();
                cout << "se realizara un dequeue" << endl;
                cout << "elemento a sacar: " << val << endl;
                cout << "tamaño de la cola: " << LnQ.getSize() << endl;
                cout << "los elementos de la cola: " << endl;
                if (LnQ.getSize()!=0){
                    LnQ.print();
                }
                cantOp--;
                cout << endl;
                cout << endl;
            }
            if(realizar == 3){
                int val = rand();
                LnQ.enqueueFront(val);
                cout << "se realizara un enqueue Front" << endl;
                cout << "elemento a insertar: " << val << endl;
                cout << "tamaño de la cola: " << LnQ.getSize() << endl;
                cout << "los elementos de la cola: " << endl;
                LnQ.print();
                cantOp--;
                cout << endl;
                cout << endl;
            }
            if(realizar == 4 && LnQ.getSize() != 0){
                int val = LnQ.dequeueRear();
                cout << "se realizara un dequeue Rear" << endl;
                cout << "elemento a sacar: " << val << endl;
                cout << "tamaño de la cola: " << LnQ.getSize() << endl;
                cout << "los elementos de la cola: " << endl;
                if (LnQ.getSize()!=0){
                    LnQ.print();
                }
                cantOp--;
                cout << endl;
                cout << endl;
            }
        }
        LnQ.clear();
    }
    char as;
    cout << "desea volver a intentarlo? s = si, cualquier otra tecla = no" << endl;
    cin >> as;
    if(as == 's'){
        main();
    }
    else{
        return 0;
    }
}
