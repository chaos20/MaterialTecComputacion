#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <List.h>
#include <DNode.h>
#include <stdexcept>
#include <string>
#include <sstream>

using std::string;
using std::runtime_error;
using std::stringstream;

template <typename E>

class DLinkedList : public List<E>{
private:
    DNode<E> *head;
    DNode<E> *tail;
    DNode<E> *current;
    int size;
public:
    DLinkedList(){
        current = head = new DNode<E>(NULL,NULL);
        head->next = tail = new DNode<E>(NULL,head);
        size = 0;
    }

    ~DLinkedList(){
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
        if(size==0)
            throw runtime_error("Empty List");
        if(current->next == tail)
            throw runtime_error("No current element");
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
        if(size==0)
            throw runtime_error("Empty List");
        if(current->next == tail)
            throw runtime_error("No current element");
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

    string printList(){
        if(size == 0)
            return "Empty List";
        else{
            DNode<E> *temp = head->next;
            string stringList = "";
            while(temp != tail){
                stringstream ss;
                ss << temp->element;
                string s = ss.str();
                stringList = stringList+ s + "->";
                temp = temp->next;
            }
            return stringList;
        }
    }

    DNode<E> getHead(){
        return *head;
    }

    DNode<E> getTail(){
        return *tail;
    }

    /*void sort(){
        DLinkedList<E> *minorNumers = new DLinkedList<E>();
        DLinkedList<E> *greaterNumers = new DLinkedList<E>();
        DNode<E> *pivot = tail->previous;
        DNode<E> *aux = head->next;
        while(aux->next != tail){
            if(aux->element > pivot->element)
                greaterNumers->append(aux->element);
            else
                minorNumers->append(aux->element);
            aux = aux->next;
        }
        cout << endl << "Lista que se ordenara: " << printList() << endl;
        cout << "Pivote: " << pivot->element << endl;
        cout << "Menores al pivote: " << minorNumers->printList() << endl;
        cout << "Mayores al pivote: " << greaterNumers->printList() << endl << endl;
        if(minorNumers->getSize() > 1){
            cout << "Se entro por recursion a la lista de menores" << endl << endl;
            minorNumers->sort();
            cout << "Se salio de la recursion y ahora se esta operando con esta lista: " << printList() << endl << endl;
        }
        if(greaterNumers->getSize() > 1){
            cout << "Se entro por recursion a la lista de mayores" << endl << endl;
            greaterNumers->sort();
            cout << "Se salio de la recursion y ahora se esta operando con esta lista: " << printList() << endl << endl;
        }
        DNode<E> *valor = new DNode<E>(pivot->element);
        clear();
        cout << "La lista se vacio" << endl << endl;
        if(minorNumers->getSize() > 0){
            DNode<E> *auxMinor = minorNumers->head->next;
            while(auxMinor != minorNumers->tail){
                append(auxMinor->element);
                auxMinor = auxMinor->next;
            }
            delete auxMinor;

        }
        cout << "Se insertaron los numeros menores (si es que habian) y ahora la lista esta asi: " << printList() << endl;
        append(valor->element);
        cout << "Se inserto el pivote y ahora la lista esta asi: " << printList() << endl;
        if(greaterNumers->getSize() > 0){
            DNode<E> *auxGreater = greaterNumers->head->next;
            while(auxGreater != greaterNumers->tail){
                append(auxGreater->element);
                auxGreater = auxGreater->next;
            }
            delete auxGreater;
        }
        cout << "Se insertaron los numeros mayores (si es que habian) y ahora la lista esta asi: " << printList() << endl << endl;
        delete minorNumers;
        delete greaterNumers;
        delete pivot;
        delete aux;
        delete valor;
    }*/

    string getType(){
        return "LinkedList";
    }
};

#endif // DLINKEDLIST_H
