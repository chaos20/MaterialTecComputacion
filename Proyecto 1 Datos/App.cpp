#include "miniwin.h"
#include "Tortuga.h"
#include "ArrayList.h"
#include <string>
#include <iostream>


using namespace miniwin;

int main(){
    /*while(true){
        int t = tecla();
        if (t == int('A')) {
            mensaje("Has presionado la tecla 'A'");
        }
    }*/
    int t = 14;
    char *intStr = itoa(t);
    string str = string(intStr);


    return 0;
}
