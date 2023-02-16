// Ercihan Kara - 2375160

#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "BST.h"
#pragma once

using namespace std;

// constructor
BST::BST(){
    main_root = nullptr;
    holder = nullptr;
    dim = 0;
}

// look for a key, get root as input
bool BST::key_exists(BST_Node* root, Matrix A){
	BST_Node* temp = new BST_Node;
	temp = root;

	// run the loop until temp points to NULL
	while(temp != nullptr){
        // input key is equal to root
		if(temp->key == A)
		{
		    holder = temp;
			return true;
		}
		// input key greater than root
		else if(temp->key < A)
			temp = temp->right;

		// input key smaller than root
		else
			temp = temp->left;
	}

	return false;
}

// get number of items in the BST
int BST::get_dim(){
    return dim;
}

void BST::set_dim(int add){
    dim = dim+add;
}

// get the root of the BST
BST_Node* BST::get_root(){
    return main_root;
}

// get the value of the key
long BST::search(BST_Node* root, Matrix A){
    // no need to check the existence of the key as
    // in determinant function, already checked
    return holder->value;
}

void BST::insert(BST_Node* root, Matrix A, long detA){
    if(key_exists(root, A) != 1){
        // insert the first node, if root is nullptr
        if(!main_root){
            //cout << "buralar " << endl;
            root = new BST_Node;
            root->key = A;
            root->value = detA;
            root->left = nullptr;
            root->right = nullptr;

            // update the main root of the tree
            main_root = root;

            // increase the size if required in future
            dim++;
        }
        // insert node, if root is nullptr
        if(!root){
            root = new BST_Node;
            root->key = A;
            root->value = detA;
            root->left = nullptr;
            root->right = nullptr;

            // increase the size if required in future
            dim++;
        }
        else{
            // input key smaller than the root, iterate through left subtree
            if(A < root->key){
                if(!root->left){
                    BST_Node* temp = new BST_Node;
                    temp->key = A;
                    temp->value = detA;
                    temp->left = nullptr;
                    temp->right = nullptr;
                    root->left = temp;
                    dim++;
                }
                else
                    // insert the recently created node
                    insert(root->left, A, detA);
            }
            // input key greater than the root, iterate through right subtree
            else{
                if(!root->right){
                    BST_Node* temp = new BST_Node;
                    temp->key = A;
                    temp->value = detA;
                    temp->left = nullptr;
                    temp->right = nullptr;
                    root->right = temp;
                    dim++;
                }
                else
                    // insert the recently created node
                    insert(root->right, A, detA);
            }
        }
    }
    else
        return;

}
