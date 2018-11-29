#ifndef KVPAIR_H
#define KVPAIR_H

template <typename K, typename V>


class KVPair{
    public:
        KVPair(){}
        KVPair(K pKey){
            key = pKey;
        }
        KVPair(K pKey, V pValue){
            key =pKey;
            value = pValue;
        }
        bool operator== (const KVPair&other){
            return key == other.key;
        }
        bool operator!= (const KVPair&other){
            return key != other.key;
        }
        bool operator< (const KVPair&other){
            return key < other.key;
        }
        bool operator<= (const KVPair&other){
            return key <= other.key;
        }
        bool operator> (const KVPair&other){
            return key > other.key;
        }
        bool operator>= (const KVPair&other){
            return key >= other.key;
        }
        void operator= (const KVPair&other){
            key = other.key;
            value = other.value;
        }
        void setKey(K pKey){
            this->key = pKey;

        }
        void setValue(V pValue){
            this->value = pValue;
        }
        K getKey(){
            return key;
        }
        V getValue(){
            return value;
        }
    private:
        K key;
        V value;
};

#endif // KVPAIR_H
