#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//3.831

bool encontrarRepetido(int pcumples[],int pcontador){
    bool jej = false;
    for(int i=0; i < pcontador; i++ ){
            for(int j = i+1; j < pcontador; j++){
                if(pcumples[i] == pcumples[j]){
                    jej = true;
                }
            }
            if (jej == true)
                break;
    }
    if (jej == true){
        return true;
    }
    else{
        return false;
    }
}
void crearListas(int contador){
    srand(time(0));
    int total = 10;
    int cumples[100];
    while (total != 0){
        cout << "[";
        for(int i = 0; i < contador; i++){
            int val = 1 + (rand()%(366 - 1));
            cumples[i] = val;
            cout << cumples[i] << ",";
        }
        cout << "]" << endl;
        total--;
        if (encontrarRepetido(cumples,contador) == true){
            cout << encontrarRepetido(cumples,contador);
            cout << "Hay un valor repetido!!!         <--- por aqui!!" << endl << endl;
        }
        else{
            cout << "No se repite ningun valor" << endl << endl;
        }
    }


}
int main(){

    int contador = 5;
    cout << "Se eveluan grupos de: " << contador << endl;
    while (contador <= 100){
        cout << endl;
        cout << "------------------------------------------- se incrementa el grupo en 5 ---------------------------------------------------------" << endl;
        cout << endl;
        crearListas(contador);
        contador += 5;
    }
    return 0;
}
