#ifndef BSTNODE_H
#define BSTNODE_H

using namespace std;

template <typename E>
class BSTNode{
private:
    E element;
    BSTNode<E>* left;
    BSTNode<E>* right;
public:
    BSTNode(BSTNode<E>* left = NULL, BSTNode<E>* right = NULL) {
        this->left = left;
        this->right = right;
    }
    BSTNode(E element, BSTNode<E>* left = NULL, BSTNode<E>* right = NULL) {
        this->element = element;
        this->left = left;
        this->right = right;
    }
    ~BSTNode() {}
    E getElement() {
        return element;
    }
    void setElement(E element) {
        this->element = element;
    }
    BSTNode<E>* getLeft() {
        return left;
    }
    void setLeft(BSTNode<E>* left) {
        this->left = left;
    }
    BSTNode<E>* getRight() {
        return right;
    }
    void setRight(BSTNode<E>* right) {
        this->right = right;
    }
    bool isLeaf() {
        return (left == NULL) && (right == NULL);
    }
    int childrenCount() {
        return (left == NULL? 0 : 1) + (right == NULL? 0 : 1);
    }
    BSTNode<E>* getUniqueChild() {
        if (left != NULL){
            return left;
        }
        else{
            return right;
        }
    }
    BSTNode<E>* getSuccessorAux(BSTNode<E>* pRoot) {
        if(pRoot->getLeft() == NULL){
            return pRoot;
        }
        else{
            return getSuccessorAux(pRoot->getLeft());
        }
    }
    BSTNode<E>* getSuccessor() {
        return getSuccessorAux(right);
    }
};

#endif // BSTNODE_H

