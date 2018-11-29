#include <iostream>
#include <BSTree.h>
#include <MaxHeap.h>
#include <LinkedList.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){
    srand(time(NULL));
    BSTree<int> arb;
    LinkedList<int> Llist;
    LinkedList<int> Hlist;
    for(int i = 1; i <= 2000; i++){
        int valor = rand()%10001;
        arb.insert(valor);
        Llist.append(valor);
    }
    arb.inOrder();
    for (int i = 1; i <= 500; i++){
        int elim = Llist.getElement();
        cout << "Was deleted: " << elim << endl;
        arb.remove(elim);
        Llist.goToPos(i);
    }
    cout << endl;
    cout << "After deleting the elements: " << endl;
    arb.inOrder();

    for (int i = 0; i <= 1000; i++){
            try{
                arb.lookFor(i);
                cout << "The element: " << i << " was found" << endl;
            }
            catch(runtime_error){
                cout << "The element: " << i << " was not found" << endl;
            }
    }
    cout << endl;
    cout << endl;
    cout << endl;

    MaxHeap<int> heap;
    int total;
    cout << "Input the amount of numbers so insert: " << endl;
    cin >> total;
    for(int i = 0; i < total; i++){
        int val = rand()%101;
        cout << "generate number: " << val << endl;
        heap.insert(val);
    }
    cout << endl;
    for(int j = 0; j < total; j++){
        int elim = heap.removeFirst();
        Hlist.append(elim);
    }
    cout << endl;
    cout << "Ordered list of the numbers: " << endl;
    Hlist.goToStart();
    for (int f = 0; f < Hlist.getSize(); f++){
        cout << Hlist.getElement() << endl;
        Hlist.next();
    }



    return 0;
}
