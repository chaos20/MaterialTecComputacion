#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "Node.h"

template<typename E>
class LinkedStack : public Stack<E>{
private:
    Node<E> *top;
    int size;
public:
    LinkedStack(){
        top = NULL;
        size = 0;
    }

    ~LinkedStack(){
        clear();
    }

    void push(E pElement){
        top = new Node<E>(pElement,top);
        size++;
    }

    E pop() throw(runtime_error){
        if(size == 0)
            throw runtime_error("Stack is empty");
        else{
            E value = top->element;
            Node<E> *temp = top;
            top = top->next;
            delete temp;
            size--;
            return value;
        }
    }

    E topValue() throw(runtime_error){
        if(size == 0)
            throw runtime_error("Stack is empty");
        else
            return top->element;
    }

    void clear(){
        Node<E> *temp;
        while(top != NULL){
            temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
        //Se podria hacer un ciclo llamando a pop pero eso requiere mas recursos
    }

    bool isEmpty(){
        return size == 0;
    }

    int getSize(){
        return size;
    }

    void print(){
        if(size == 0)
            cout << "Stack is empty" << endl;
        else{
            Node<E> *temp = top;
            for(int i = 0; i < size; i++){
                cout << temp->element << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void lector(string str){
        int isValid = -1;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                isValid = 1;
                push(str[i]);
                cout << "Stack: ";
                print();
            }else{
                if(str[i] == ')'){
                    if(top->element == '('){
                        pop();
                        cout << "Stack: ";
                        print();
                    }else{
                        cout << "La secuencia no es valida" << endl;
                        isValid = 0;
                        break;
                    }
                }
                else if(str[i] == ']'){
                    if(top->element == '['){
                        pop();
                        cout << "Stack: ";
                        print();
                    }else{
                        cout << "La secuencia no es valida" << endl;
                        isValid = 0;
                        break;
                    }
                }
                else if(str[i] == '}'){
                    if(top->element == '{'){
                        pop();
                        cout << "Stack: ";
                        print();
                    }else{
                        cout << "La secuencia no es valida" << endl;
                        isValid = 0;
                        break;
                    }
                }
            }
        }
        if(isValid == 1)
            cout << "La secuencia es valida" << endl;
        else if(isValid == -1)
            cout << "No se introdujo ningun caracter de agrupamiento" << endl;
    }

    DLinkedList<string>* curvaDeDragon(int iterations){
        string curve = "";
        DLinkedList<string> *curvaDeDragon = new DLinkedList<string>();
        for(int i = 0; i < iterations; i++){
            curve = "90";
            if(i == 0)
                curvaDeDragon->insert(curve);
            else{
                curvaDeDragon->goToStart();
                do{
                    if(curvaDeDragon->getPos() % 2 == 0){
                        curvaDeDragon->insert(curve);
                        if(curve == "90")
                            curve = "-90";
                        else
                            curve = "90";
                    }
                curvaDeDragon->next();
                }while(curvaDeDragon->atEnd() == false);
                curvaDeDragon->append(curve);
            }
        }
        if(iterations > 0){
            curvaDeDragon->goToStart();
            do{
                if(curvaDeDragon->getPos() % 2 == 0){
                    curvaDeDragon->insert("A");
                }
                curvaDeDragon->next();
            } while(curvaDeDragon->atEnd() == false);
            curvaDeDragon->append("A");
        }
        return curvaDeDragon;
    }

    DLinkedList<string>* flechaDeSierpinski(int iterations){
        string curve = "30";
        DLinkedList<string> *flechaDeSierpinski = new DLinkedList<string>();
        for(int i = 0; i < iterations; i++){
            if(i == 0){
                flechaDeSierpinski->insert(curve);
                flechaDeSierpinski->insert(curve);
            }else{
                flechaDeSierpinski->goToStart();
                if(curve == "30")
                    curve = "-30";
                else
                    curve = "30";
                do{
                    if(flechaDeSierpinski->getPos() % 3 == 0){
                        flechaDeSierpinski->insert(curve);
                        flechaDeSierpinski->insert(curve);
                        if(curve == "30")
                            curve = "-30";
                        else
                            curve = "30";
                    }
                    flechaDeSierpinski->next();
                }while(flechaDeSierpinski->atEnd() == false);
                flechaDeSierpinski->append(curve);
                flechaDeSierpinski->append(curve);
            }
        }
        if(iterations > 0){
            flechaDeSierpinski->goToStart();
            do{
                if(flechaDeSierpinski->getPos() % 2 == 0){
                    flechaDeSierpinski->insert("A");
                }
                flechaDeSierpinski->next();
            } while(flechaDeSierpinski->atEnd() == false);
            flechaDeSierpinski->append("A");
        }
        return flechaDeSierpinski;
    }

    DLinkedList<string>* curvaDeLevy(int iterations){
        DLinkedList<string> *curvaDeLevy = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                curvaDeLevy->insert("A");
            else{
                curvaDeLevy->goToStart();
                do{
                    if(curvaDeLevy->getElement() == "A"){
                        curvaDeLevy->remove();
                        curvaDeLevy->insert("45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("A");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("-45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("-45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("A");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("45");
                    }
                    curvaDeLevy->next();
                }while(curvaDeLevy->atEnd() == false);
            }
        }
        return curvaDeLevy;
    }

    DLinkedList<string>* arbolBinario(int iterations){
        DLinkedList<string> *arbolBinario = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                arbolBinario->insert("H");
            else{
                arbolBinario->goToStart();
                do{
                    if(arbolBinario->getElement() == "H"){
                        arbolBinario->remove();
                        arbolBinario->insert("R");
                        arbolBinario->next();
                        arbolBinario->insert("(");
                        arbolBinario->next();
                        arbolBinario->insert("H");
                        arbolBinario->next();
                        arbolBinario->insert(")");
                        arbolBinario->next();
                        arbolBinario->insert("H");
                    }else if(arbolBinario->getElement() == "R"){
                        arbolBinario->remove();
                        arbolBinario->insert("R");
                        arbolBinario->next();
                        arbolBinario->insert("R");
                    }
                    arbolBinario->next();
                }while(arbolBinario->atEnd() == false);
            }
        }
        return arbolBinario;
    }

    DLinkedList<string>* planta(int iterations){
        DLinkedList<string> *planta = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                planta->insert("X");
            else{
                planta->goToStart();
                do{
                    if(planta->getElement() == "X"){
                        planta->remove();
                        planta->insert("A");
                        planta->next();
                        planta->insert("D");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("I");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("I");
                        planta->next();
                        planta->insert("A");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("I");
                        planta->next();
                        planta->insert("A");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("D");
                        planta->next();
                        planta->insert("X");
                    }else if(planta->getElement() == "A"){
                        planta->remove();
                        planta->insert("A");
                        planta->next();
                        planta->insert("A");
                    }
                    planta->next();
                }while(planta->atEnd() == false);
            }
        }
        return planta;
    }


};

#endif // LINKEDSTACK_H
