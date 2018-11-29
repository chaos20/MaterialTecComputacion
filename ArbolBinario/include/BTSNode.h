#ifndef BTSNODE_H
#define BTSNODE_H

template <typename E>


class BTSNode{
    public:
        BTSNode(E element, BTSNode<E> *left = NULL, BTSNode<E> *right = NULL){
            this->element = element;
            this->left = left;
            this->right = right;
        }

        ~BTSNode(){}

        void setElement(E pElement){
            this->element = pElement;
        }

        E getElement(){
            return element;
        }

        void setLeft(BTSNode<E> *pLeft){
            this->left = pLeft;
        }

        BTSNode<E> * getLeft(){
            return left;
        }

        void setRight(BTSNode<E> *pRight){
            this->right = pRigth;
        }

        BTSNode<E> * getRight(){
            return rigth;
        }

        bool isLeaf(){
            return left == NULL && right == NULL;
        }

        int childrenCount(){
            return (left == NULL? 0:1) + (right == NULL? 0:1);
        }
        BTSNode<E>* getUniqueChild(){
            if left != NULL{
                return left;
            }
            if getRight() != NULL{
                return right;
            }
        }

    protected:

    private:
        E element;
        BTSNode<E> *left;
        BTSNode<E> *right;
};

#endif // BTSNODE_H
