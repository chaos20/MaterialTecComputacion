#ifndef BSTREE_H
#define BSTREE_H
#include "BTSNode.h"


template <typename E>

class BSTree{
    public:
        BSTree() {
            root = NULL;
        }
        virtual ~BSTree() {
            clear();
        }
        E find(E pElement) throw(runtime_error){
            return findAux(root, pElement);
        }
        void insert(E pElement){
            root = insertAux(root,pElement);
        }
        E remove(E element) throw (runtime_error){
            E result = find(element);
            root = removeAux(root, element);
            return element;
        }

    protected:

    private:
        BTSNode<E>* root;
        E findAux(BTSNode<E> *pRoot, E element) throw (runtime_error){
            if(pRoot == NULL){
                throw runtime_error ("Element not found");
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
        BTSNode* insertAux(BTSNode *pRoot, E element){
            if(pRoot == NULL){
                return new BTSNode<E>(element);
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
        BTSNode* removeAux(BTSNode<E> *pRoot, E element) throw (runtime_error){
            if(pRoot == NULL){
                throw runtime_error("Element not found");
            }
            if(element < pRoot->getElement()){
                pRoot -> setLeft(removeAux(pRoot->getLeft(),element));
                return pRoot;
            }
            if(element > pRoot->getElement()){
                pRoot -> setRight(removeAux(pRoot -> getRigth(),element));
                return pRoot;
            }
            else /* tres casos*/{
                    if(pRoot->isLeaf()){
                        delete pRoot;
                        return NULL;
                    }
                    if(pRoot->childrenCount() == 1){
                        BTSNode<E> *temp = pRoot->getUniqueChild();
                        delete pRoot
                        return temp;
                    }
                    else{
                        BTSNode<E> *Sucessor = pRoot->getSuccessor();/**/
                        swap(pRoot,succesor);/**/
                        pRoot->setRight(removeAux(pRoot->getRight(),element));
                        return pRoot;
                    }


            }
        }
};

#endif // BSTREE_H
