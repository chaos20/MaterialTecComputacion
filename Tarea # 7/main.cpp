#include <iostream>
#include "include\AVLTree.h"
#include "KVPair.h"

using namespace std;

int main(){

    AVLTree<KVPair<int, int> >* t = new AVLTree<KVPair<int, int> >();
    for (int i = 0; i < 50; i++) {
        KVPair<int, int> p(i, i);
        t->insert(p);
    }
    for (int i = 99; i >= 50; i--) {
        KVPair<int, int> p(i, i);
        t->insert(p);
    }
    t->print();
    for (int i = 1; i<21; i++) {
        KVPair<int, int> p(i);
        t->remove(p);
    }
    t->print();
    cout << endl;
    delete t;
    return 0;
}
