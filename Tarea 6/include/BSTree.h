#ifndef BSTREE_H
#define BSTREE_H
#include "BSTNode.h"
#include <stdexcept>

using namespace std;

template <typename E>
class BSTree {
private:
    BSTNode<E>* root;

    void inOrderAux(BSTNode<E>* pRoot) {
        if (pRoot == NULL){
            return;
        }
        inOrderAux(pRoot->getLeft());
        visit(pRoot);
        inOrderAux(pRoot->getRight());
    }

    // insert
    BSTNode<E>* insertAux(BSTNode<E>* pRoot, E element) {
       if(pRoot == NULL){
            return new BSTNode<E>(element);
        }
        if (element < pRoot->getElement()){
            pRoot -> setLeft(insertAux(pRoot->getLeft(),element));
            return pRoot;
        }
        else{
            pRoot -> setRight(insertAux(pRoot->getRight(),element));
            return pRoot;
        }
    }

    // find
    E findAux(BSTNode<E>* pRoot, E element)throw (runtime_error){
         if(pRoot == NULL){
            throw runtime_error("Element not found");
        }
        if(pRoot->getElement() == element){
            return pRoot->getElement();
        }
        if(element < pRoot->getElement()){
            return findAux(pRoot->getLeft(), element);
        }
        else{
            return findAux(pRoot->getRight(), element);
        }
    }

    // remove
    BSTNode<E>* removeAux(BSTNode<E>* pRoot, E element) throw (runtime_error) {
           if(pRoot == NULL){
                throw runtime_error("Element not found");
            }
            if(element < pRoot->getElement()){
                pRoot -> setLeft(removeAux(pRoot->getLeft(),element));
                return pRoot;
            }
            if(element > pRoot->getElement()){
                pRoot -> setRight(removeAux(pRoot -> getRight(),element));
                return pRoot;
            }
            else /* tres casos*/{
                    if(pRoot->isLeaf()){
                        delete pRoot;
                        return NULL;
                    }
                    if(pRoot->childrenCount() == 1){
                        BSTNode<E> *temp = pRoot->getUniqueChild();
                        delete pRoot;
                        return temp;
                    }
                    else{
                        BSTNode<E> *Successor = pRoot->getSuccessor();
                        swap(pRoot,Successor);
                        pRoot->setRight(removeAux(pRoot->getRight(),element));
                        return pRoot;
                    }


            }
    }
    void swap(BSTNode<E>* node1, BSTNode<E>* node2) {
        E temp = node1->getElement();
        node1->setElement(node2->getElement());
        node2->setElement(temp);
    }
    void printAux(BSTNode<E>* pRoot, int depth) {
        if (pRoot == NULL) {
            return;
        }
        for (int i = 0; i < depth; i++) {
            cout << "  ";
        }
        cout << "+-" << pRoot->getElement() << endl;
        printAux(pRoot->getLeft(), depth + 1);
        printAux(pRoot->getRight(), depth + 1);
    }
    void visit(BSTNode<E>* pRoot){
        cout << pRoot->getElement() << "->" << "  ";
    }
    int searchAux(BSTNode<E>* pRoot, E element){
        if(pRoot == NULL){
            return -1;
        }
        if(pRoot->getElement() == element){
            return 1;
        }
        if(element < pRoot->getElement()){
            return findAux(pRoot->getLeft(), element);
        }
        else{
            return findAux(pRoot->getRight(), element);
        }
    }

public:
    BSTree() {
        root = NULL;
    }
    void insert(E element) {
        root = insertAux(root, element);
    }
    void inOrder() {
        inOrderAux(root);
        cout << endl;
    }
    E find(E element) {
        return findAux(root, element);
    }
    E remove(E element) {
        E result = find(element);
        root = removeAux(root, element);
        return result;
    }
    void print() {
        printAux(root, 0);
    }
    int lookFor(E element){
        return searchAux(root,element);
    }
};

#endif // BSTREE_H
