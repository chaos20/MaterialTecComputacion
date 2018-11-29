#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include <Stack.h>

using std::runtime_error;
using std::cout;

template <typename E>


class ArrayStack : public Stack<E>{
    private:
        E *elements;
        int top;
        int max;
    public:
        ArrayStack(int max = DEFAULT_MAX_SIZE){
            elements = new E[max];
            this->max = max;
            top = 0;
        }
        ~ArrayStack(){
            delete [] elements;
        }
        void push(E element) throw(runtime_error){
            E* temp;
            if(max == top){
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
                elements[top] = element;
                top++;
            }
            else{
                elements[top] = element;
                top++;
            }
        }
        E pop() throw(runtime_error){
            if(top == 0){
                throw runtime_error("Stack underflow");
            }
            top--;
            return elements[top];
        }
        void clear(){
            delete [] elements;
            elements = new E[max];
            top = 0;
        }
        E topValue() throw (runtime_error){
            if(top == 0){
                throw runtime_error("Empty stack");
            }
            return elements[top-1];
        }
        int getSize(){
            return top;
        }
        bool isEmpty(){
            return top == 0;
        }
        void print(){
            for(int i = top-1; i >= 0; i--){
                cout << elements[i] << "\t";
            }
        }
};

#endif // ARRAYSTACK_H
