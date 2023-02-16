// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "Matrix.h"
#include "HashTable.h"
#include "utils.hpp"

using namespace std;

// create the matrix from input file
void create_mat(string file_name, int size, Matrix& mat){
    int k = 0;
    ifstream inFil(file_name);
    if(inFil){
        int x;
        vector<int> numbers_list;
        inFil >> x;

        while(inFil){
            // store number in the vector
            numbers_list.push_back(x);
            // read next number
            inFil >> x;
        }

        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++){
                mat.set_element(i, j, (int) numbers_list[k++]);
            }
    }
}

int main()
{
    int num = 15;
    Matrix mat1(num);
    create_mat("matrices/"+to_string(num)+"/"+to_string(num)+"_0.txt", num, mat1);
    Matrix mat2(num);
    create_mat("matrices/"+to_string(num)+"/"+to_string(num)+"_1.txt", num, mat2);
    Matrix mat3(num);
    create_mat("matrices/"+to_string(num)+"/"+to_string(num)+"_2.txt", num, mat3);
    Matrix mat4(num);
    create_mat("matrices/"+to_string(num)+"/"+to_string(num)+"_3.txt", num, mat4);
    Matrix mat5(num);
    create_mat("matrices/"+to_string(num)+"/"+to_string(num)+"_4.txt", num, mat5);

    HashTable HT;

    cout << "Matrix:" << endl;
    print_matrix(mat1);
    cout << endl;
    cout << "Determinant: " << det_with_HT(mat1, HT) << endl;
    //cout << "Size: " <<  HT.get_dim() << endl;
    cout << "Memory Usage: " << HT.get_dim()*sizeof(HT_Item)/pow(1024,2) << "MB" << endl;
    cout << endl;

    cout << "Matrix:" << endl;
    print_matrix(mat2);
    cout << endl;
    cout << "Determinant: " << det_with_HT(mat2, HT) << endl;
    //cout << "Size: " <<  HT.get_dim() << endl;
    cout << "Memory Usage: " << HT.get_dim()*sizeof(HT_Item)/pow(1024,2) << "MB" << endl;
    cout << endl;

    cout << "Matrix:" << endl;
    print_matrix(mat3);
    cout << endl;
    cout << "Determinant: " << det_with_HT(mat3, HT) << endl;
    //cout << "Size: " <<  HT.get_dim() << endl;
    cout << "Memory Usage: " << HT.get_dim()*sizeof(HT_Item)/pow(1024,2) << "MB" << endl;
    cout << endl;

    cout << "Matrix:" << endl;
    print_matrix(mat4);
    cout << endl;
    cout << "Determinant: " << det_with_HT(mat4, HT) << endl;
    //cout << "Size: " <<  HT.get_dim() << endl;
    cout << "Memory Usage: " << HT.get_dim()*sizeof(HT_Item)/pow(1024,2) << "MB" << endl;
    cout << endl;

    cout << "Matrix:" << endl;
    print_matrix(mat5);
    cout << endl;
    cout << "Determinant: " << det_with_HT(mat5, HT) << endl;
    cout << "Size: " <<  HT.get_dim() << endl;
    cout << "Memory Usage: " << HT.get_dim()*sizeof(HT_Item)/pow(1024,2) << "MB" << endl;
    cout << endl;

    return 0;
}
