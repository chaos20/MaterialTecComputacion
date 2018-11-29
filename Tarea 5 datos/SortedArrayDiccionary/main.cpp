#include <iostream>
#include <SortedArrayDictionary.h>
#include <DoubleLinkedList.h>
#include <string>

using namespace std;

int main(){
    SortedArrayDictionary<int,int> SAD0;
    SortedArrayDictionary<int,int> SAD1;
    DoubleLinkedList<int> A;
    DoubleLinkedList<int> B;
    A.append(5);
    A.append(6);
    A.append(3);
    B.append(67);
    B.append(99);
    B.append(555);
    SAD0.insert(1,56);
    SAD0.insert(2,4);
    SAD0.insert(3,100);
    SAD0.insert(9,5);
    SAD1.insert(0,50);
    SAD1.insert(1,0);
    SAD0.update(SAD1);
    SAD0.zip(A,B);
    cout << SAD0.getValue(0) << endl;
    cout << SAD0.getValue(1) << endl;
    cout << SAD0.getValue(2) << endl;
    cout << SAD0.getValue(3) << endl;
    cout << SAD0.getValue(5) << endl;
    cout << SAD0.getValue(6) << endl;

    cout << endl;
    cout << endl;

    SortedArrayDictionary<int,string> SAD2;
    SortedArrayDictionary<int,string> SAD3;
    DoubleLinkedList<int> C;
    DoubleLinkedList<string> D;
    C.append(5);
    C.append(6);
    C.append(3);
    D.append("hola");
    D.append("adios");
    D.append("lol");
    SAD2.insert(1,"nine");
    SAD2.insert(2,"what");
    SAD2.insert(3,"hmm");
    SAD2.insert(9,"moof");
    SAD3.insert(0,"none");
    SAD3.insert(1,"nueve");
    SAD2.update(SAD3);
    SAD2.zip(C,D);
    cout << SAD2.getValue(0) << endl;
    cout << SAD2.getValue(1) << endl;
    cout << SAD2.getValue(2) << endl;
    cout << SAD2.getValue(3) << endl;
    cout << SAD2.getValue(5) << endl;
    cout << SAD2.getValue(6) << endl;

    cout << endl;
    cout << endl;

    SortedArrayDictionary<string,string> SAD4;
    SortedArrayDictionary<string,string> SAD5;
    DoubleLinkedList<string> E;
    DoubleLinkedList<string> F;
    E.append("k");
    E.append("l");
    E.append("c");
    F.append("hola");
    F.append("adios");
    F.append("lol");
    SAD4.insert("a","nine");
    SAD4.insert("b","what");
    SAD4.insert("c","hmm");
    SAD4.insert("i","woof");
    SAD5.insert("-a","none");
    SAD5.insert("a","nueve");
    SAD4.update(SAD5);
    SAD4.zip(E,F);
    cout << SAD4.getValue("-a") << endl;
    cout << SAD4.getValue("a") << endl;
    cout << SAD4.getValue("b") << endl;
    cout << SAD4.getValue("c") << endl;
    cout << SAD4.getValue("k") << endl;
    cout << SAD4.getValue("l") << endl;

    cout << endl;
    cout << endl;

    SortedArrayDictionary<string,int> SAD6;
    SortedArrayDictionary<string,int> SAD7;
    DoubleLinkedList<string> G;
    DoubleLinkedList<int> H;
    G.append("k");
    G.append("l");
    G.append("c");
    H.append(90);
    H.append(4);
    H.append(7);
    SAD6.insert("a",234);
    SAD6.insert("b",565);
    SAD6.insert("c",0);
    SAD6.insert("i",23);
    SAD7.insert("-a",2);
    SAD7.insert("a",100101);
    SAD6.update(SAD7);
    SAD6.zip(G,H);
    cout << SAD6.getValue("-a") << endl;
    cout << SAD6.getValue("a") << endl;
    cout << SAD6.getValue("b") << endl;
    cout << SAD6.getValue("c") << endl;
    cout << SAD6.getValue("k") << endl;
    cout << SAD6.getValue("l") << endl;
    return 0;
}
