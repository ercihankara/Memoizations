// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include<math.h>
#include "Matrix.h"
#include "HashTable.h"
#pragma once

using namespace std;

// print matrix
void print_matrix(Matrix& mat_obj){
    int dim = mat_obj.get_dimens();
    for(int row = 0; row < dim; row++){
        for(int col = 0; col < dim; col++){
            cout << setw(2) << mat_obj.get_element(row, col) << " ";
            if(col == dim-1)
                cout << endl;
        }
    }
}

// create the sub-matrix for cofactor calculations
Matrix sub_mat(Matrix mat, int row, int col){

    int size = mat.get_dimens();
    Matrix temp_mat(size-1);

    int a = 0, b = 0;
    for(int i = 0; i < size; i++){
        if(i == row)
            continue;

        b = 0;
        for(int j = 0; j < size; j++){
            if(col == j)
                continue;
            temp_mat.set_element(a, b, mat.get_element(i, j));
            b++;
        }
        a++;
    }
    return temp_mat;
}

// calculate determinant using HT
int det_with_HT(Matrix mat_obj, HashTable& HT){
    if(HT.key_exists(mat_obj) == 1){
        return HT.search(mat_obj);
    }

    else{
        int size = mat_obj.get_dimens();
        int det_val = 0;

        // check the 1x1 case
        if(size == 1){
            return mat_obj.get_element(0, 0);
        }

        // check the 2x2 case
        else if(size == 2){
            det_val = mat_obj.get_element(0, 0)*mat_obj.get_element(1, 1) - mat_obj.get_element(1, 0)*mat_obj.get_element(0, 1);
            return det_val;
        }

        // all other cases
        else{
            for(int i = 0; i < size; i++){
                // create the sub-matrix
                Matrix sub_matrix;

                sub_matrix = sub_mat(mat_obj, 0, i);
                // get the determinant of the sub-matrix
                long sub_det = det_with_HT(sub_matrix, HT);
                // insert the related matrix and its determinant to the Hash Table
                HT.insert(sub_matrix, sub_det);
                // cofactor calculation
                long cofact = pow(-1, i) * mat_obj.get_element(0, i) * sub_det;
                // update the determinant result
                det_val += cofact;
            }
        }
        return det_val;
    }
}
