#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "List.h"
#include "Node.h"
#include <stdlib.h>

template <typename E>

class LinkedList : public List<E>{
    private:
        Node<E> *head;
        Node<E> *tail;
        Node<E> *current;
        int size;
    public:
        LinkedList() {
            current = tail = head = new Node<E>();
            size = 0;
        }
        ~LinkedList() {
            clear();
            delete head;
        }
        void insert(E element) {
            current->next = new Node<E>(element, current->next);
            if (current == tail){
                tail = tail->next;
            }
            size++;
        }
        void append(E element){
            tail = tail->next = new Node<E>(element);
            size++;
        }
        E remove() throw (runtime_error) {
            if (current->next == NULL){
                throw runtime_error("No element");
            }
            E result = current->next->element;
            Node<E> *temp = current->next;
            current->next = temp->next;
            if (current->next == NULL){
                tail = current;
            }
            delete temp;
            size--;
            return result;
        }
        void clear(){
            current = head->next;
            while(head->next != NULL){
                head->next = current->next;
                delete current;
                current = head->next;
            }
            current = tail = head;
            size=0;
        }
        E getElement() throw(runtime_error){
            if(size == 0){
                 throw runtime_error("Empty list");
            }
            if(current->next == NULL){
                 throw runtime_error("No current element");
            }
            return current->next->element;
        }
        void goToStart(){
            current = head;
        }
        void goToEnd(){
            current = tail;
        }
        void goToPos(int pos) throw(runtime_error){
            if(pos < 0 || pos > size){
                 throw runtime_error("Index out of bounds");
            }
            current = head;
            for(int i = 0; i < pos; i++){
                current = current->next;
            }
        }
        void next(){
            if(current->next != NULL){
                current = current->next;
            }
        }
        void previous(){
            Node<E> *temp = head;
            while(temp->next != current && temp->next != NULL){
                temp=temp->next;
            }
            current = temp;
        }
        bool atEnd(){
            return current == tail;
        }
        bool atStart(){
            return current == head;
        }
        int getPos(){
            Node<E> *temp = head;
            int pos = 0;
            while(temp!=current){
                temp = temp->next;
                pos++;
            }
            return pos;
        }
        int getSize(){
            return size;
        }

        void reverse(){
            if (head != tail){
                int ind = size;
                for(int i = 1; i < ind ; i++){
                    goToPos(ind-i);
                    append(current->element);
                }
                goToStart();
                for(int i = 0; i < ind-1; i++){
                    Node<E> *temp = head->next;
                    head->next = temp->next;
                    if (head->next == NULL){
                        tail = current;
                    }
                    delete temp;
                    size--;
                }
            }
        }
        bool compare(List<E> &L){
            bool ver = true;
            goToStart();
            L.goToStart();
            if (size != L.getSize())
                ver = false;
            for(int i = 1; i < size-1; i++){
                if(getElement() != L.getElement()){
                    ver = false;
                    break;
                }
                else{
                    goToPos(i);
                    L.goToPos(i);
                }
            }return ver;
        }
        int getMaxDigits(){
            int maxValue = -1;
            for (goToStart(); !atEnd(); next()){
                if(maxValue < getElement()){
                    maxValue = getElement();
                }
            }
            int maxDigits = 1;
            while(maxValue > 9){
                maxValue /=10;
                maxDigits++;
            }
            return maxDigits;
        }
};

#endif // LINKEDLIST_H
