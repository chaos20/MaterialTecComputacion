#ifndef MAXHEAP_H
#define MAXHEAP_H
#define DEFAULT_MAX = 1024

template <typename E>


class MaxHeap{
    public:
        MaxHeap(int maxSize = DEFAULT_MAX) {
            elements = new E[maxSize];
            size = 0;
            this->maxSize = maxSize;
        }
        virtual ~MaxHeap() {
            delete [] elements;
        }
        void insert(E element)throw(runtime_error){
            if (size == maxSize){
                throw runtime_error("heap is full");
            }
            elements[size] = element;
            siftUp(size);
            size++;
        }
        E remove(int pos) throw (runtime_error){
            if (pos < 0 || pos >= size){
                throw runtime_error("Index out of range");
            }
            E result = elements[pos];
            swap(pos, size-1);
            size--;
            if(size > 0){
                siftDown(pos);
            }
            return result;
        }
        E removeFirst() throw (runtime_error){
            return remove(0);
        }
        int getSize(){
            return size;
        }

        }

    protected:

    private:
        E* elements;
        int size;
        int maxSize;

        int leftChild(int pos){
            return pos * 2 + 1;
        }
        int rightChild(int pos){
            return pos * 2 + 2;
        }
        int parent(int pos){
            if (pos == 0){
                return -1;
            }
            else{
                return (pos-1)/2;
            }
        }
        bool isLeaf(int pos) throw(runtime_error){
            if(pos < 0 || pos >= size){
                throw runtime_error("index out of range");
            }
            return leftChild(pos) >= size;
        }
        void swap(int pos1, int pos2){
            int temp = elements[pos1];
            elements[pos1] = elements[pos2];
            elements[pos2] = temp;
        }
        int greaterChild(int pos){
            if(rightChild(pos) < size){
                if(elemets[rightChild(pos)] > elements[leftChild(pos)]){
                    return rightChild(pos);
                }
            }
            return leftChild(pos);
        }
        void siftUp(int pos){
            while(pos > 0 && element[pos] > elements[parent(pos)]){
                swap(pos,parent(pos));
                pos = parent(pos);
            }
        }
        void siftDown(int pos){
            while(!isLeaf(pos) && elements[pos] < elements[graterChild(pos]){
                int i = greaterChild(pos);
                swap(pos,i);
                pos = i;
            }
        }


};

#endif // MAXHEAP_H
