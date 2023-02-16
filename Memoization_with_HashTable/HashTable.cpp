// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#include "HashTable.h"
#include "Matrix.h"

using namespace std;

// constructor
HashTable::HashTable(){
    dim = 0;
}

// get number of items in the Table, update dim with insert
int HashTable::get_dim(){
    return dim;
}

// look for a key
bool HashTable::key_exists(Matrix A){
    int hash_A = A.hashing();
    int counter = 0;

    // start the search of key from the hash of input matrix
    // finish the search if NULL pointer occurs or the key is found

    // search the table for the input key
    while(hash_array[hash_A] != NULL){
        if(hash_array[hash_A]->key == A){
            return true;
        }
        // in order not to have any infinite loop
        if(counter++ > 65536){
            return false;
        }
        // move to next node in the table
        hash_A ++;
        hash_A %= 65536;
    }
    return false;
}

// get the value of the key
long HashTable::search(Matrix A){
    int hash_A = A.hashing();
    int counter = 0;
    if(hash_array == NULL){
        exit(1);
    }

    while(hash_array[hash_A] != NULL){
        if(hash_array[hash_A]->key == A){
            return hash_array[hash_A]->value;
        }

        // move to next node in the table
        hash_A ++;
        hash_A %= 65536;
    }
}

// insert the created item to the table
void HashTable::insert(Matrix A, long detA){
    if(key_exists(A) != 1){
        HT_Item* temp_item = new HT_Item;
        temp_item->key = A;
        temp_item->value = detA;
        //get the hash value
        int hash_val = A.hashing();
        // move through the table until an empty or deleted cell is found
        while(hash_array[hash_val] != NULL && !(hash_array[hash_val]->key == A)){
            // go to next cell
            hash_val++;
            // go around the table
            hash_val %= 65536;
        }
        if(hash_array[hash_val] == NULL)
            dim++;
        // insert the new item to the table
        hash_array[hash_val] = temp_item;

    }
    else
        return;
}
