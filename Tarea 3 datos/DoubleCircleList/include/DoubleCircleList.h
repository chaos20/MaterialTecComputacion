#ifndef DOUBLECIRCLELIST_H
#define DOUBLECIRCLELIST_H
#include <DNode.h>
#include <DoubleLinkList.h>

using namespace std;
template <typename E>


class DoubleCircleList{
    private:
        DNode<E> *current;
        int size;
    public:
        DoubleCircleList(){
            current = NULL;
            size = 0;
        }
        ~DoubleCircleList(){
            clear();
        }
        void insert(E pElement){
            if (current == NULL){
                current = new DNode<E>(pElement, NULL, NULL);
                current->next = current;
                current->previous = current;
            }
            else{
                current->next = current->next->previous = new DNode<E>(pElement, current->next, current);
            }
            size++;
        }
        E remove() throw(runtime_error){
            if(size == 0){
                throw runtime_error("Empty list");
            }
            E result = current->next->element;
            if(current->next == current){
                delete current;
                current = NULL;
                size--;
            }
            else{
                DNode<E> *temp = current->next;
                current->next = current->next->next;
                temp->next->previous = current;
                size--;
                delete temp;

            }
            return result;
        }
        void clear(){
            if(size != 0){
                DNode<E> *temp = current->next;
                while (temp != current){
                    current->next = current->next->next;
                    delete temp;
                    temp = current->next;

                }
                delete current;
                current = NULL;
                size = 0;
            }
        }
        void next(){
            if(size != 0){
                current = current->next;
            }
        }
        void previous(){
            if(size != 0){
                current = current->previous;
            }
        }
        E getFront() throw(runtime_error){
            if(size == 0){
                throw runtime_error("empty");
            }
            return current->next->element;
        }
        E getBack() throw(runtime_error){
            if(size == 0){
                throw runtime_error("empty");
            }
            return current->element;
        }
        int getSize(){
            return size;
        }
        DoubleLinkedList<E>* getElements(bool reversed){
            DoubleLinkedList<E> *elems = new DoubleLinkedList<E>() ;
            if(reversed == false){
                for (int i = 0; i < size; i++){
                    next();
                    elems->insert(getBack());
                }
            }
            else{
                for (int i = 0; i < size; i++){
                    previous();
                    elems->insert(getFront());
                }

            }
            return elems;
        }
};

#endif // DOUBLECIRCLELIST_H
