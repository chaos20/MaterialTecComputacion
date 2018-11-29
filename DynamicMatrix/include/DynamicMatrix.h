#ifndef DYNAMICMATRIX_H
#define DYNAMICMATRIX_H
#include <stdexcept>

using namespace std;

template <typename E>
class DynamicMatrix{
    private:
        int rows;
        int columns;
        E** matrix;
    public:
        DynamicMatrix(int pRows, int pColumns) throw(runtime_error);{
            if (pRows <= 0 || pColumns = 0){
                throw runtime_error("Number of rows or columns must be grater than zero");
            }
            rows = pRows;
            columns = pColumns;
            matrix = new E*[rows];
            for (int i = 0; i< rows; i++){
                matrix[i] = new E[columns];
            }
        }
        ~DynamicMatrix(){
            for(int i = 0; i < rows; i++){
                delete [] matrix[i];
            }
            delete [] matrix;
        }
        E getValue (int pRows, int pColumn) throw (runtime_error);{
            if (pRow < 0 || pRow >= rows){
                throw runtime_error("Invalid Row")
            }
            if(pColumn < 0 || pColumn >= columns){
                throw runtime_error("Invalid Column")
            }
            return matrix[pRow][pColumn];
        }
        void setValue(int pRow, int pColumn, E value) throw (runtime_error){
            if (pRow < 0 || pRow >= rows){
                throw runtime_error("Invalid Row")
            }
            if(pColumn < 0 || pColumn >= columns){
                throw runtime_error("Invalid Column")
            }
            matrix[pRow][pColumn] = value;
        }
        int getRows(){
            return rows;
        }
        int getColumns(){
            return columns;
        }
};

#endif // DYNAMICMATRIX_H
