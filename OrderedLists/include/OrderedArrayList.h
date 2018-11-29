#ifndef ORDEREDARRAYLIST_H
#define ORDEREDARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024
#include <List.h>
#include <ArrayList.h>
#include <stdexcept>

using std::runtime_error;

template<typename E>

class OrderedArrayList : public ArrayList<E>{
    public:
        OrderedArrayList(int max = DEFAULT_MAX_SIZE):ArrayList<E>(max){
        }
        void insert(E element) throw(runtime_error){
            ArrayList<E>::goToStart();
            while(!ArrayList<E>::atEnd() && element >= ArrayList<E>::getElement()){
                ArrayList<E>::next();
            }
            ArrayList<E>::insert(element);

        }
        int indexOf(E element){
            int Ind1 = 0;
            int Ind2 = ArrayList<E>::getSize()-1;
            int Icent;
            while(Ind1 <= Ind2){
                Icent = (Ind1+Ind2)/2;
                ArrayList<E>::goToPos(Icent);
                if (ArrayList<E>::getElement() == element){
                    return Icent;
                }
                else{
                    if(element < ArrayList<E>::getElement()){
                        Ind2 = Icent-1;
                    }
                    else{
                        Ind1 = Icent+1;
                    }
                }
            }
            return -1;
        }

};

#endif // ORDEREDARRAYLIST_H
