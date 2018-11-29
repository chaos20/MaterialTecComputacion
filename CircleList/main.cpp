#include <iostream>
#include <CircleList.h>

using namespace std;

int main(){
    CircleList<int> CL;
    for(int i = 0; i < 10; i++){
        CL.insert(i);

    }
    /*for (int j = 0; j < 10; j++){
        cout << CL.getFront() <<endl;
        CL.next();
    }*/
    CL.clear();
    cout << "final" << endl;




    return 0;
}
