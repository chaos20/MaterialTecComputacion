#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <List.h>
#include <DNode.h>
#include <stdexcept>

using std::runtime_error;

template <typename E>

class DoubleLinkedList : public List<E>{
    private:
        DNode<E> *head;
        DNode<E> *tail;
        DNode<E> *current;
        int size;
    public:
        DoubleLinkedList(){
            current = head = new DNode<E>(NULL,NULL);
            head->next = tail = new DNode<E>(NULL,head);
            size = 0;
        }
        ~DoubleLinkedList(){
            clear();
            delete tail;
            delete head;
        }
        void insert(E pElement){
            current->next=current->next->previous = new DNode<E>(pElement, current->next, current);
            size++;
        }
        void append(E pElement){
            tail->previous = tail->previous->next = new DNode<E>(pElement, tail, tail->previous);
            size++;
        }
        E remove() throw (runtime_error){
            if(size==0){
                throw runtime_error("Empty List");
            }
            if(current->next == tail){
                throw runtime_error("No current element");
            }
            DNode<E> *temp = current->next;
            current->next = current->next->next;
            current->next->previous = current;
            E result = temp->element;
            size--;
            return result;
        }
        void clear(){
            current = head->next;
            while(current != tail){
                head->next = head->next->next;
                delete current;
                current = head->next;
            }
            tail->previous = head;
            current = head;
            size = 0;
        }
        E getElement() throw (runtime_error){
            if(size==0){
                throw runtime_error("Empty List");
            }
            if(current->next == tail){
                throw runtime_error("No current element");
            }
            return current->next->element;
        }
        void goToStart(){
            current = head;
        }
         void goToEnd(){
            current = tail->previous;
        }
         void goToPos(int pos){
            if(pos<0 || pos>size){
                throw runtime_error("index out of bounds");
            }
            int i = 0;
            for(goToStart(); i < pos; next()){
                i++;
            }
        }
         void next(){
            if(current->next != tail){
                current = current->next;
            }
        }
         void previous(){
            if(current != head){
                current = current->previous;
            }
        }
         bool atEnd(){
            return current->next == tail;
        }
         bool atStart(){
            return current == head;
        }
         int getPos(){
            int pos = 0;
            DNode<E> *temp = head;
            while(temp != current){
                pos++;
                temp = temp->next;
            }
            return pos;
        }
         int getSize(){
            return size;
        }
};

#endif // DOUBLELINKEDLIST_H
