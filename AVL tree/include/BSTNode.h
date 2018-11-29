#ifndef BSTNODE_H
#define BSTNODE_H


class BSTNode{
    public:
        BSTNode(E element, BTSNode<E> *left = NULL, BTSNode<E> *right = NULL){
            this->element = element;
            this->left = left;
            this->right = right;
        }

        ~BSTNode(){}

        void setElement(E pElement){
            this->element = pElement;
        }

        E getElement(){
            return element;
        }

        void setLeft(BSTNode<E> *pLeft){
            this->left = pLeft;
        }

        BSTNode<E> * getLeft(){
            return left;
        }

        void setRight(BSTNode<E> *pRight){
            this->right = pRigth;
        }

        BSTNode<E> * getRight(){
            return rigth;
        }

        bool isLeaf(){
            return left == NULL && right == NULL;
        }

        int childrenCount(){
            return (left == NULL? 0:1) + (right == NULL? 0:1);
        }

    protected:

    private:
        E element;
        BSTNode<E> *left;
        BSTNode<E> *right;
};


#endif // BSTNODE_H
