#ifndef UNSORTEDARRAYDICTIONARY_H
#define UNSORTEDARRAYDICTIONARY_H
#define DEFAULT_MAX_SIZE 1024
#include <Dictionary.h>
#include <KVPair.h>
#include <ArrayList.h>
#include <DoubleLinkedList.h>

template<typename K, typename V>


class UnsortedArrayDictionary : public Dictionary<K,V>{
    public:
        UnsortedArrayDictionary(int pMaxSize = DEFAULT_MAX_SIZE){
            pairs = new ArrayList<KVPair<K,V> >(pMaxSize);
        }
        ~UnsortedArrayDictionary(){
            delete pairs;
        }
        void insert(K pKey, V pValue) throw(runtime_error){
            checkNotExisting(pKey); // la llave no existe
            KVPair<K,V> pair(pKey,pValue);
            pairs->append(pair);
        }
        V remove(K pKey) throw (runtime_error){
            checkExisting(pKey);
            KVPair<K,V> pair(pKey);
            for(pairs->goToStart(); pair != pairs->getElement(); pairs->next());
            pair = pairs->remove();
            return pair.getValue();
        }
        bool contains(K pKey){      //efecto -> pos actual del arraylist apunta al elemento buscado
            KVPair<K,V> p(pKey);
            return pairs->contains(p);
        }
        V getValue(K pKey){
            checkExisting(pKey);
            KVPair<K,V> p = pairs->getElement();
            return p.getValue();
        }
        void setValue(K pKey, V pValue) throw (runtime_error){
            checkExisting(pKey);
            KVPair<K,V> p (pKey,pValue);
            pairs->remove();
            pairs->insert(p);
        }
        void clear(){
            int OriginMax = pairs->getSize();
            delete pairs;
            pairs = new ArrayList<KVPair<K,V> >(OriginMax);
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
    private:
        ArrayList<KVPair<K,V> > *pairs;
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

#endif // UNSORTEDARRAYDICTIONARY_H
