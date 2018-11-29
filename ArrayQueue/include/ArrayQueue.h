#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include <Queue.h>

template <typename E>

class ArrayQueue : Queue<E>{
    private:
        E *elements;
        int front;
        int back;
        int size;
        int max;
    public:
        ArrayQueue(int max = DEFAULT_MAX_SIZE){
            elements = new E[max];
            size = 0;
            this->max = max;
            front = back = 0;
        }
        ~ArrayQueue(){
            delete [] elements;
        }
        void enqueue(E element) throw (runtime_error){
            if(size == max){
                throw runtime_error("Queue is full");
            }
            elements[back] = element;
            back =(back+1)%max;
            size++;
        }
        E dequeue() throw(runtime_error){
            if(size == 0){
                throw runtime_error("Queue is empty");
            }
            E result = elements[front];
            front = (front+1)%max;
            size--;
            return result;
        }
        E frontValue()throw(runtime_error){
            if(size == 0){
                throw runtime_error("Queue is empty");
            }
            return elements[front];
        }
        void clear(){
            delete [] elements;
            elements = new E[max];
            back = front = 0;
            size = 0;
        }
        bool isEmpty(){
            return size == 0;
        }
        int getSize(){
            return size;
        }
        void enqueueFront(E element) throw (runtime_error){
            if(size == max){
                throw runtime_error("Queue is full");
            }
            if(front == 0){
                int temp = max;
                front =(temp-1)%max;
            }
            else{
                front = (front-1)%max;
            }
            elements[front] = element;
            size++;
        }
        E dequeueRear()throw(runtime_error){
            if(size == 0){
                throw runtime_error("Queue is empty");
            }
            rear = (rear-1)%max;
            E result = elements[rear];
            size--;
            return result;
        }
        E rearValue()throw(runtime_error){
            if(size == 0){
                throw runtime_error("Queue is empty");
            }
            return elements[rear-1];
        }
        void print(){
            int temp = front;
            while(temp != rear){
                cout << elements[temp] << "\t";
                temp = (temp+1)%max;
            }
        }



};

#endif // ARRAYQUEUE_H
