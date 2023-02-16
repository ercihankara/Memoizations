// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#include "Matrix.h"

// constructor to initialize with 0x0 matrix
Matrix::Matrix(){
    dim = 0;
    hashT = false;
}

// constructor to initialize with NxN identity matrix
Matrix::Matrix(int dimens){
    if(dimens > 20){
        cout << "NOT A VALID DIMENSION!";
        exit(1);
    }

    dim = dimens;
    hashT = false;
    for(int row = 0; row < dim; row++){
        for(int col = 0; col < dim; col++){
            if (row == col)
                matrix[row][col] = 1;
            else
                matrix[row][col] = 0;
        }
    }
}

// copy constructor
Matrix::Matrix(Matrix& Matrix_obj){
    dim = Matrix_obj.get_dimens();
    for(int row = 0; row < dim; row++){
        for(int col = 0; col < dim; col++)
            matrix[row][col] = Matrix_obj.get_element(row, col);
    }
}

// get the dimension of matrix
int Matrix::get_dimens() const{
    return dim;
}

// get the desired element of matrix
int Matrix::get_element(int row, int col) const{
    return matrix[row][col];
}

// set the desired element of matrix
void Matrix::set_element(int row, int col, int value){
    matrix[row][col] = value;
}

// overload operators
bool Matrix::operator ==(const Matrix mat_obj){
    int dim_obj = mat_obj.get_dimens();

    if(dim != dim_obj)
        return 0;
    else{
        for(int row = 0; row < dim; row++){
            for(int col = 0; col < dim; col++){
                if(matrix[row][col] != mat_obj.get_element(row, col))
                    return 0;
            }
        }
        return 1;
    }
}

// overload operators
bool Matrix::operator <(const Matrix mat_obj){
    int dim_obj = mat_obj.get_dimens();

    if(dim < dim_obj)
        return 1;
    else if(dim > dim_obj)
        return 0;
    else{
        for(int row = 0; row < dim; row++){
            for(int col = 0; col < dim; col++){;
                if(matrix[row][col] < mat_obj.get_element(row, col))
                    return 1;
                else if(matrix[row][col] > mat_obj.get_element(row, col))
                    return 0;
                else
                    continue;
            }
        }
    }
}
