#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stdexcept>

using namespace std;

template <typename E>
class MaxHeap {
private:
    int maxSize;
    int size;
    E* elements;

    int leftChild(int pos) {
        return 2 * pos + 1;
    }
    int rightChild(int pos) {
        return 2 * pos + 2;
    }
    int parent(int pos) {
        if (pos == 0) {
            return -1;
        }
        return (pos - 1) / 2;
    }
    int isLeaf(int pos) throw (runtime_error) {
        if ((pos >= size) || (pos < 0)) {
            throw runtime_error("Position out of range.");
        }
        return leftChild(pos) >= size;
    }
    void swap(int pos1, int pos2) {
        E temp = elements[pos1];
        elements[pos1] = elements[pos2];
        elements[pos2] = temp;
    }
    void siftUp(int pos) {
        if(parent(pos) == -1){
            return;
        }
        if(elements[pos] <= elements[parent(pos)]){
            return;
        }
        int parentPos = parent(pos);
        swap(pos,parent(pos));
        siftUp(parentPos);
    }
    void siftDown(int pos) {
        if(pos >= size){
            return;
        }
        if(elements[pos] >= elements[leftChild(pos)] && elements[pos] >= elements[rightChild(pos)]){
            return;
        }
        if(elements[pos] < elements[leftChild(pos)] && greaterChild(pos) == leftChild(pos)){
            int leftPos = leftChild(pos);
            swap(pos, leftPos);
            siftDown(leftPos);
        }
        if(elements[pos] < elements[rightChild(pos)] && greaterChild(pos) == rightChild(pos)){
            int rightPos = rightChild(pos);
            swap(pos, rightPos);
            siftDown(rightPos);
        }

    }
    int greaterChild(int i) {
        if (elements[leftChild(i)] > elements[rightChild(i)]){
            return leftChild(i);
        }
        else{
            return rightChild(i);
        }
    }

public:
    MaxHeap(int maxSize = 1024) {
        this->maxSize = maxSize;
        size = 0;
        elements = new E[maxSize];

    }
    ~MaxHeap() {
        delete [] elements;
    }
    void insert(E element) throw (runtime_error) {
        if (size == maxSize){
            throw runtime_error ("Full list");
        }
        else{
            elements[size] = element;
            siftUp(size);
            size++;
        }
    }
    E removeFirst() throw (runtime_error) {
        if(size == 0){
            throw runtime_error ("No elements to delete");
        }
        if(size == 1){
            size--;
        }

        int lastPos = size-1;
        swap(0,lastPos);
        size--;
        siftDown(0);
        return elements[lastPos];
    }
    E removeAt(int pos) throw (runtime_error) {
        if(pos >= size || size == 0){
            throw runtime_error ("index out of bounds");
        }
        if(pos == size-1){
            size--;
        }
        int lastPos = size-1;
        swap(pos,lastPos);
        size--;
        siftDown(pos);
        return elements[lastPos];
    }
    int getSize() {
        return size;
    }
};
#endif // MAXHEAP_H
