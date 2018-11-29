#include <iostream>
#include <time.h>
#include "DynamicMatrix.h"
#include <stdlib.h>

using namespace std;

void Multiply(int pRow1, int pColumn1, int pRow2, int pColumn2) {
    srand(time(0));
    int temp = 0;
    DynamicMatrix<int> aMatriz(pRow1,pColumn1);
    DynamicMatrix<int> bMatriz (pRow2,pColumn2);
    DynamicMatrix<int> product(pRow1,pColumn2);

    for(int i=0; i<aMatriz.getRows();i++){
        for(int j=0; j<aMatriz.getColumns(); j++){
            aMatriz.setValue(i,j,(rand()%11));
        }
    }
    for(int i=0; i<bMatriz.getRows();i++){
        for(int j=0; j<bMatriz.getColumns(); j++){
            bMatriz.setValue(i,j,(rand()%11));
        }
    }

    for(int i=0; i<aMatriz.getRows();i++){
        for(int j=0; j<aMatriz.getColumns(); j++){
            cout << aMatriz.getValue(i,j) <<"\t";
        }
        cout << endl;
     }
     cout <<endl;

    for(int i=0; i<bMatriz.getRows();i++){
        for(int j=0; j<bMatriz.getColumns(); j++){
            cout << bMatriz.getValue(i,j) <<"\t";
        }
        cout << endl;
     }
     cout <<endl;

     for(int i=0; i<product.getRows();i++){
        for(int j=0; j<product.getColumns(); j++){
            product.setValue(i,j,0);
        }
     }


    for (int row = 0; row < product.getRows(); row++) {
        for (int col = 0; col < product.getColumns(); col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < pColumn1; inner++) {
                temp = product.getValue(row,col) + aMatriz.getValue(row,inner) * bMatriz.getValue(inner,col);
                product.setValue(row,col,temp);
            }
            std::cout << product.getValue(row,col) << "  ";
        }
        std::cout << "\n";
    }
}

int main() {
    int m;
    int n;
    int p;
    int q;
    cout << "introdusca las dimensiones de la primera matriz: ";
    cin >> m >> n;
    cout << "introdusca las dimensiones de la segunda matriz: ";
    cin >> p >> q;
    if (n!=p){
        cout << "Estas matrices no se pueden multiplicar";
    }
    else{
        Multiply(m,n,p,q);
    }
}
