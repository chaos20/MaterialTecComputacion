#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListforLink.h"
#include "Node.h"
#include <stdlib.h>

template <typename E>

class LinkedList : public ListforLink<E>{
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
        void insert(E element, E tag) {
            current->next = new Node<E>(element,tag, current->next);
            if (current == tail){
                tail = tail->next;
            }
            size++;
        }
        void append(E element, E tag){
            tail = tail->next = new Node<E>(element,tag);
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
        E getTag() throw(runtime_error){
            if(size == 0){
                 throw runtime_error("Empty list");
            }
            if(current->next == NULL){
                 throw runtime_error("No current element");
            }
            return current->next->tag;
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
};
#endif // LINKEDLIST_H
