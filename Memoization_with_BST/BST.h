// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "BST_Node.h"
#pragma once

using namespace std;

class BST{
    private:
        BST_Node* main_root = nullptr;
        int dim = 0;
        // to get the search output faster
        BST_Node* holder = nullptr;

    public:
        // constructor
        BST();

        // get number of items in the BST
        int get_dim();
        void set_dim(int add);

        // get the root of the BST
        BST_Node* get_root();

        // look for a key
        bool key_exists(BST_Node* root, Matrix A);
        // get the value of the key
        long search(BST_Node* root, Matrix A);
        // insert the created item into the table
        void insert(BST_Node* root, Matrix A, long detA);
};
