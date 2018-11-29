#ifndef SORTEDARRAYDICTIONARY_H
#define SORTEDARRAYDICTIONARY_H
#define DEFAULT_MAX_SIZE 1024
#include <Dictionary.h>
#include <KVPair.h>
#include <OrderedArrayList.h>
#include <DoubleLinkedList.h>

template <typename K,typename V>

class SortedArrayDictionary : public Dictionary <K ,V> {
    public:
        SortedArrayDictionary(int pMaxSize = DEFAULT_MAX_SIZE){
            pairs = new OrderedArrayList<KVPair<K,V> >(pMaxSize);
        }
        ~SortedArrayDictionary(){
            delete pairs;
        }
        void insert(K pKey, V pValue){
            checkNotExisting(pKey);
            KVPair<K,V> pair(pKey,pValue);
            pairs->insert(pair);
        }
        V remove(K pKey){
            checkExisting(pKey);
            KVPair<K,V> pair(pKey);
            for(pairs->goToStart(); pair != pairs->getElement(); pairs->next()){
                pair = pairs->remove();
            }
            return pair.getValue();
        }
        V getValue(K pKey){
            checkExisting(pKey);
            KVPair<K,V> p = pairs->getElement();
            return p.getValue();
        }
        void setValue(K pKey, V pValue) throw (runtime_error){
            checkExisting(pKey);
            int pos = pairs->indexOf(pKey);
            pairs->goToPos(pos);
            KVPair<K,V> p (pKey,pValue);
            pairs->remove();
            pairs->insert(p);
        }
        bool contains(K pKey){      //efecto -> pos actual del arraylist apunta al elemento buscado
            KVPair<K,V> p(pKey);
            return pairs->contains(p);
        }
        void clear(){
            int OriginMax = pairs->getSize();
            delete pairs;
            pairs = new OrderedArrayList<KVPair<K,V> >(OriginMax);
        }
        List<K>* getKeys(){
            List<K> *keys = new DoubleLinkedList<K>();
            for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
                KVPair<K,V> p = pairs->getElement();
                keys->append(p.getKey());
            }
            return keys;
        }
        List<V>* getValues(){
            List<V> *values = new DoubleLinkedList<V>();
            for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
                KVPair<K,V> p = pairs->getElement();
                values->append(p.getValue());
            }
            return values;
        }
        int getSize(){
            return pairs->getSize();
        }
        void update(Dictionary<K,V> &D){
            List<K> *keys = D.getKeys();
            List<V> *values = D.getValues();
            for(keys->goToStart(); !keys->atEnd(); keys->next()){
                int pos = keys->getPos();
                K actualKey = keys->getElement();
                values->goToPos(pos);
                V actualValue = values->getElement();
                if (!contains(actualKey)){
                    insert(actualKey,actualValue);
                }
                if(contains(actualKey)){
                    setValue(actualKey,actualValue);
                }
            }
        }
        void zip(List<K> &keys, List<V> &values)throw(runtime_error){
            if(keys.getSize() != values.getSize()){
                throw runtime_error ("Lists of different size");
            }
            values.goToStart();
            for (keys.goToStart(); !keys.atEnd() && !values.atEnd(); keys.next()){
                int pos = keys.getPos();
                K actualKey = keys.getElement();
                values.goToPos(pos);
                V actualValue = values.getElement();
                if (!contains(actualKey)){
                    insert(actualKey,actualValue);
                }
            }
        }


    private:
        OrderedArrayList<KVPair<K,V> > *pairs;
        void checkNotExisting(K pKey) throw(runtime_error){
            if(contains(pKey)){
                throw runtime_error("Duplicated key");
            }
        }
        void checkExisting(K pKey)throw (runtime_error){
            if(!contains(pKey)){
                throw runtime_error("Key not found");
            }
        }

};

#endif // SORTEDARRAYDICTIONARY_H
