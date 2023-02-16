// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "HT_Item.h"
#pragma once

using namespace std;

// Hash Table in the array form with linear probing
class HashTable{
    private:
        HT_Item* hash_array[65536] = {0};
        int dim;

    public:
        // constructor
        HashTable();

        // get number of items in the Table
        int get_dim();

        // look for a key
        bool key_exists(Matrix A);
        // get the value of the key
        long search(Matrix A);
        // insert the created item to the table
        void insert(Matrix A, long detA);

};
