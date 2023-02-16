// Ercihan Kara - 2375160

#include "Matrix.h"

using namespace std;

class BST_Node{
    public:
        BST_Node* left = nullptr;
        BST_Node* right = nullptr;
        // Determinant of key matrix is value
        Matrix key;
        long value;
};
