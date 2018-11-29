#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024
#include "List.h"
#include <stdexcept>

using std::runtime_error;

template<typename E>


class ArrayList : public List<E> {
    protected:
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
            size--;
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
                    goToPos(i);
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
};

#endif // ARRAYLIST_H
