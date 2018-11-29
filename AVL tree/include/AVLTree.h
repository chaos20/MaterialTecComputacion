#ifndef AVLTREE_H
#define AVLTREE_H
#include <BSTNode.h>

template <typename E>


class AVLTree
{
    public:
        AVLTree() {}
        ~AVLTree() {}
        void insert(E element){
            root = insertAux(root,element);
        }
         E find(E pElement) throw(runtime_error){
            return findAux(root, pElement);
        }
        E remove(E element){
            E result = find(element);
            root = removeAux(root,element);
            return result;
        }

    protected:

    private:
        BSTNode<E> *root;

        BSTNode<E> * insertAux(BTSNode<E>* pRoot, E element) throw(runtime_error){
            if(pRoot == NULL){
                return new BSTNode(element);
            }
            if(element < pRoot->getElement()){
                pRoot->setLeft(insertAux(pRoot->getLeft(), element));
                rebalanceLeft(pRoot);
            }
            else if(element > pRoot->getElement()){
                pRoot->setRight(insertAux(pRoot->getRight(),element));
                rebalanceRight(pRoot);
            }
            else{
                throw runtime_error("No duplicate elements allowed");
            }

        }
        E findAux(BSTNode<E> *pRoot, E element) throw (runtime_error){
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

        BSTNode* removeAux(BSTNode<E> *pRoot, E element) throw (runtime_error){
            if(pRoot == NULL){
                throw runtime_error("Element not found");
            }
            if(element < pRoot->getElement()){
                pRoot -> setLeft(removeAux(pRoot->getLeft(),element));
                if (pRoot->getLeft() != NULL){
                /* bitch what the fuck, WHAT THE FUCK??
                pRoot = rebalanceRight(pRoot);
                */
                }
                return pRoot;
            }
            if(element > pRoot->getElement()){
                pRoot -> setRight(removeAux(pRoot -> getRigth(),element));
                if (pRoot->getRight() != NULL){
                /* bitch what the fuck, WHAT THE FUCK??
                pRoot = rebalanceLeft(pRoot);
                */
                }
                return pRoot;
            }
            else /* tres casos*/{
                    if(pRoot->isLeaf()){
                        delete pRoot;
                        return NULL;
                    }
                    if(pRoot->childrenCount() == 1){
                        BSTNode<E> *temp = pRoot->getUniqueChild()/**/;
                        delete pRoot
                        return temp;
                    }
                    else{
                        BSTNode<E> *Sucessor = pRoot->getSuccessor();/**/
                        swap(pRoot,succesor);/**/
                        pRoot->setRight(removeAux(pRoot->getRight(),element));
                        return pRoot;
                    }


            }
        }
        BSTNode<E> *rotateRight(BSTNode<E>*pRoot)throw(runtime_error){
            if(pRoot == NULL){
                throw runtime_error ("Can't rotate null");
            }
            if(pRoot->getLeft() == NULL){
                throw runtime_error ("Left child is null");
            }
            BSTNode<E> * temp = pRoot->getLeft();
            pRoot->setLeft(temp->getRight());
            temp->setRight(pRoot);
            return temp;
        }
        BSTNode<E> *rotateLeft(BSTNode<E>*pRoot)throw(runtime_error){
            if(pRoot == NULL){
                throw runtime_error ("Can't rotate null");
            }
            if(pRoot->getRight() == NULL){
                throw runtime_error ("Right child is null");
            }
            BSTNode<E> * temp = pRoot->getRight();
            pRoot->setRight(temp->getLeft());
            temp->setLeft(pRoot);
            return temp;
        }
        int height(BTSNode<E>* pRoot){
            if(pRoot == NULL){
                return 0;
            }
            if(pRoot->isLeaf()){
                return 1;
            }
            int leftHeight = height(pRoot->getLeft());
            int rightHeight = height(pRoot->getRight());
            if(leftHeight > rightHeight){
                return leftHeight + 1;
            }
            else{
                return rightHeight + 1;


            }
        }

};

#endif // AVLTREE_H
