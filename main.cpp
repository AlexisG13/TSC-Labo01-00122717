#include <iostream>
#include "math_tools.h"
#include "display_tools.h"
#include <stdlib.h>
#include <math.h>
using namespace std;

void reverseMatrix(Matrix matrix, Matrix &inverseMatrix){
    float matrixDeterminant = determinant(matrix);
    if(matrixDeterminant == 0) {
        exit(EXIT_FAILURE);
}
    Matrix matrixCofactors, transposeCofactors; 
    cofactors(matrix, matrixCofactors);
    transpose(matrixCofactors, transposeCofactors);
    productRealMatrix(1/matrixDeterminant, transposeCofactors , inverseMatrix);
}

int main(){
    Matrix matrix , inverseMatrix;
    zeroes(matrix,3);
    matrix.at(0).at(0)=2; matrix.at(0).at(1)=2; matrix.at(0).at(2)=3;
    matrix.at(1).at(0)=4; matrix.at(1).at(1)=5; matrix.at(1).at(2)=6;
    matrix.at(2).at(0)=7; matrix.at(2).at(1)=8; matrix.at(2).at(2)=9;
    reverseMatrix(matrix, inverseMatrix);
    cout << "Inverse matrix: " << endl;
    showMatrix(inverseMatrix);
    return 0;
}