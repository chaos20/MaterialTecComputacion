#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <Queue.h>
#include <Node.h>
#include <stdexcept>

template <typename E>


class LinkedQueue : public Queue<E>{

    private:
        Node<E> *front;
        Node<E> *rear;
        int size;
    public:
        LinkedQueue(){
            rear = front = new Node<E>();
            size = 0;
        }
        ~LinkedQueue(){
            clear();
            delete front;
        }
        void enqueue (E element){
            rear = rear->next = new Node<E>(element);
            size++
        }
        E dequeue() throw (runtime_error){
            if(size == 0){
                throw runtime_error("empty queue")
            }
            E res = front->next->element;
            Node<E> *temp = front->next;
            front->next = front->next->next;
            delete temp;
            size--;
            if(front->next == NULL){
                rear = front;
            }
            return res;
        }
        E frontValue*() throw(runtime_error){
            if(size == 0){
                throw runtime_error("empty queue")
            }
            return front->next->element;
        }
        void clear(){
            Node<E> *temp = front->next;
            while(front->next != NULL){
                front->next = temp->next;
                delete temp;
                temp = front->next;
            }
            size = 0;
            rear = front;
        }
        bool isEmpty(){
            return size == 0;
        }
        int getSize(){
            return size;
        }
        void enqueueFront(E pElement){
            front->element = pElement;
            front = new Node<E>(front);
            size++;
        }
        E dequeueRear()throw (runtime_error){
            if(size == 0){
                throw runtime_error("empty queue");
            }
            Node<E> *temp;
            for(temp = front; temp->next != rear; temp = temp->next){

            }
            E result = rear->element;
            Node<E> *aux = rear;
            rear = temp;
            delete aux;
            delete temp;
            rear->next = NULL;
            size--;
            return result;
        }
        E rearValue()throw(runtime_error){
            if(size == 0){
                throw runtime_error("empty queue");
            }
            return rear->element;
        }
        void print(){
            Node<E> *temp;
             for(temp = front; temp->next != NULL; temp = temp->next){
                cout << temp->next->element << "\t";
             }
        }

    protected:

};

#endif // LINKEDQUEUE_H
