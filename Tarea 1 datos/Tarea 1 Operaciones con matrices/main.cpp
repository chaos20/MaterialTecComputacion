#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "DynamicMatrix.h"

using namespace std;


void opeMatrices(int pRows, int pColumns){
     srand(time(0));
     DynamicMatrix<float> matrizG(pRows,pColumns);
     for(int i=0; i<matrizG.getRows();i++){
        for(int j=0; j<matrizG.getColumns(); j++){
            matrizG.setValue(i,j,(rand()%101));
        }
     }
     for(int i=0; i<matrizG.getRows();i++){
        for(int j=0; j<matrizG.getColumns(); j++){
            cout << matrizG.getValue(i,j) <<"\t";
        }
        cout << endl;
     }
     cout <<endl;
     int sRows = pRows/2;
     int sColumns = pColumns/2;
     DynamicMatrix<int> matrizP(sRows,sColumns);
     for(int i=0; i<matrizP.getRows();i++){
        for(int j=0; j<matrizP.getColumns(); j++){
            matrizP.setValue(i,j,0);
        }
     }
     int temp=0;
     int h=0;
     int k=0;
     for(int i=0; i<matrizG.getRows();i++){
        k=0;
        for(int j=0; j<matrizG.getColumns(); j++){
            if (i%2==0 && h < matrizP.getRows()-1 && i != 0){
                h++;
            }
            temp=0;
            temp += matrizG.getValue(i,j);
            temp += matrizP.getValue(h,k);
            matrizP.setValue(h,k,temp);
            if (j%2!=0 && k < matrizP.getColumns()-1){
                k++;
            }

        }


     }

     for(int i=0; i<matrizP.getRows();i++){
        for(int j=0; j<matrizP.getColumns(); j++){
            cout << matrizP.getValue(i,j)/4 <<"\t";
        }
        cout << endl;
     }

}

int main(){
    int rows;
    int columns;
    cout << "Introdusca las dimensiones de la matriz: " << endl;
    cin >> rows;
    cin >> columns;
    if (rows%2==0 && columns%2==0){
        opeMatrices(rows,columns);
    }
    else
        cout << "Error";


    return 0;
}
