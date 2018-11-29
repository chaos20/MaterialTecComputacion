#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <stdexcept>
#include <Node.h>
#include <LinkedList.h>

using std::runtime_error;

template <typename E>


class OrderedLinkedList : public LinkedList<E>{
    public:
        OrderedLinkedList() : LinkedList<E>(){
        }
        void insert(E element){
            LinkedList<E>::goToStart();
            while(!LinkedList<E>::atEnd() && element >= LinkedList<E>::getElement()){
                LinkedList<E>::next();
            }
            LinkedList<E>::insert(element);

        }
        int indexOf(E element){
            int found = -1;
            LinkedList<E>::goToStart();
            while (!LinkedList<E>::atEnd()){
                if(LinkedList<E>::getElement() == element){
                    found = LinkedList<E>::getPos();
                    break;
                }
                else{
                    LinkedList<E>::next();
                }
            }
            return found;
        }

};

#endif // ORDEREDLINKEDLIST_H
