// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class Matrix{
    private:
        int matrix[20][20];
        int dim;
        bool hashT;

    public:
        // constructor to initialize with 0x0 matrix
        Matrix();
        // constructor to initialize with NxN identity matrix
        Matrix(int dimens);
        // copy constructor
        Matrix(Matrix& Matrix_obj);

        // get the dimension of matrix
        int get_dimens() const;
        // get the desired element of matrix
        int get_element(int row, int col) const;
        // set the desired element of matrix
        void set_element(int row, int col, int value);

        // overload operators
        bool operator ==(const Matrix& mat_obj);
        bool operator <(const Matrix& mat_obj);

        // hashing function
        int hashing();
        // get hash table status
        bool get_hash_table();
        // set hash table status
        void set_hash_table(bool status);

};
