#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#include <Node.h>

template <typename E>

class CircleList
{
    private:
        Node<E> *current;
        int size;
    public:
        CircleList(){
            current = NULL;
            size = 0;
        }
        ~CircleList(){
            clear();
        }
        void insert(E element){
            if (current == NULL){
                current = new Node<E>(element);
                current->next = current;
            }
            else{
                current->next = new Node<E>(element, current->next);
            }
            size++;
        }
        E remove() throw (runtime_error){
            if (size == 0){
                throw runtime_error("empty list");
            }
            E result = current->next->element;
            if(current->next == current){
                delete current;
                current = NULL;
                size--;
            }
            else{
                Node<E> *temp = current->next;
                current->next = current->next->next;
                size--;
                delete temp;
            }
        }
        void clear(){
            if(size != 0){
                Node<E> *temp = current->next;
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
        void previous(){
            if(size != 0){
                Node<E> *temp = current->next;
                while(temp->next != current){
                    temp = temp->next;
                }
                current = temp;
            }
        }
        void next(){
            if(size != 0){
                current = current->next;
            }
        }
        int getSize(){
            return size;
        }
        E *getElements(bool reversed){

        }



};

#endif // CIRCLELIST_H
