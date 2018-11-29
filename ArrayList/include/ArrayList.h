#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024
#include "List.h"
#include <stdexcept>

using std::runtime_error;

template<typename E>


class ArrayList : public List<E> {
    private:
        E* elements;
        int max;
        int size;
        int pos;

    public:
        ArrayList(int max = DEFAULT_MAX_SIZE) {
            elements = new E [max];

            this -> max = max;
            size = 0;
            pos = 0;

        }
        ~ArrayList() {
            delete [] elements;
        }
        void insert(E element){
            E* temp;
            if (size == max){
                temp = new E [max];
                for(int i = 0; i < max; i++){
                    temp[i] = elements[i];
                }
                delete [] elements;
                max = max*2;
                elements = new E [max];
                for(int i = 0; i < max; i++){
                    elements[i] = temp[i];
                }
                delete temp;
                for (int i = size; i > pos ; i--){
                    elements[i] = elements[i-1];
                }
                elements[pos] = element;
                size++;
            }

            else{
                for (int i = size; i > pos ; i--){
                    elements[i] = elements[i-1];
                }
                elements[pos] = element;
                size++;
            }
        }
        void append (E element) throw (runtime_error){
            E* temp;
            if (size == max){
                temp = new E [max];
                for(int i = 0; i < max; i++){
                    temp[i] = elements[i];
                }
                delete [] elements;
                max = max*2;
                elements = new E [max];

                for(int i = 0; i < max; i++){
                    elements[i] = temp[i];
                }
                delete temp;
                elements[size] = element;
                size++;
            }
            elements[size] = element;
            size++;
            }
        E remove() throw (runtime_error){
            if (size == 0){
                throw runtime_error("The list is empty");
            }
            if(pos == size){
                throw runtime_error("No current element");
            }
            E result = elements[pos];
            for (int i = pos; i < size-1; i++){
                elements[i] = elements[i+1];
            }
            return result;
        }
        void clear(){
            size = 0;
            pos = 0;
            delete [] elements;
            elements = new E [max];
        }
        E getElement() throw (runtime_error){
            if (size == 0){
                throw runtime_error("The list is empty");
            }
            if(pos == size){
                throw runtime_error("No current element");
            }
            return elements[pos];
        }
        void goToStart(){
            pos = 0;
        }
        void goToEnd() {
            pos = size;
        }
        void goToPos(int newPos) throw (runtime_error){
            if (newPos < 0 || newPos > size){
                throw runtime_error("Out of range");
            }
            pos = newPos;
        }
        void next(){
            if (pos < size)
                pos++;
        }
        void previous(){
            if (pos > 0)
                pos--;
        }
        bool atStart(){
            return pos == 0;
        }
        bool atEnd(){
            return pos == size;
        }
        int getPos(){
            return pos;
        }
        int getSize(){
            return size;
        }
        bool contains(E element){
            bool temp = false;
            for(int i=0; i < size; i++){
                if(elements[i]==element){
                    temp = true;
                    break;
                }
            }
            return temp;
        }
        int indexOf(E element){
            int ind = -1;
            for(int i; i < size; i++){
                if(elements[i]==element){
                    ind = i;
                    break;
                }
            }
            return ind;
        }
        void extend(List<E> &L){
            if (L.getSize() != 0){
                E temp;
                for(int i = 0; i < L.getSize(); i++){
                    L.goToPos(i);
                    temp = L.getElement();
                    append(temp);
                }
            }
        }
        void quickSort(int low, int high){
            if(high - low <= 0){
                return;
            }
            int pivotIndex = findPivot(low,high);
            pivotIndex = partitionQS(pivotIndex, low, high);
            quickSort(low, pivotIndex-1);
            quickSort(pivotIndex + 1, high);
        }
        int findPivot(int low, int high){
            return(low+high)/2
        }
        void swap(int low, int high){}
        int particionQS(int pivotIndex, int low, int high){
            swap(pivotIndex, high);
            pivotIndex = high;
            high--;
            while(low < high){
                while(elements[low] < elements[pivotIndex]){
                    low++;
                }
                while(low < high && elements[high] >= elements[pivotIndex]){
                    high--;
                }
                if(low < high){
                    swap(low,high);
                }
            }
            if(elements[low] > elements[pivotIndex]){
                swap(low,pivotIndex);
            }
            return low;
        }
};

#endif // ARRAYLIST_H
