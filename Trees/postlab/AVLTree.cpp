#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree :: insert(const string& x) {
    root = insert(x, root);
}
AVLNode* AVLTree::insert(const string& x, AVLNode*& n)  {
    // YOUR IMPLEMENTATION GOES HERE
    // cout << "insert method is being used" << endl;
    if (n == NULL) {
        // cout << "the first statement is being accessed" << endl;
        AVLNode* n = new AVLNode();
        n->value = x;
        balance(n);
        return n;
    }
    if (x < n->value) {
        n->left = insert(x, n->left);
        balance(n);
    }   
    else if (x > n->value) {
        n->right = insert(x, n->right);
        balance(n);
    }

    n->height = max(height(n->left), height(n->right)) + 1;
    return n;

}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    return pathToHelper(x, root);

}

string AVLTree :: pathToHelper(const string& x, AVLNode* n) const  {
        if (n == NULL) {
            cout << "";
            return "";
        }
        if (find(x,n) == false) {
            cout << "";
            return "";
        } 
        if (x < n->value) {
            cout << n->value << " ";
            pathToHelper(x, n->left);

        }
        if (x > n->value) {
            cout << n->value <<  " ";
            pathToHelper(x, n->right);
        }
        if (x == n-> value) {
            cout << n->value;
        }


        return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x, AVLNode*& n) const {
    // YOUR IMPLEMENTATION GOES HERE
    if (n == NULL) {
        return false;
    }
    if (x < n-> value) {
        return find(x, n->left);
    }
    if (x > n-> value) {
        return find(x, n->right);
    }
    else { 
        return true;
    }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    int daInt = numNodesHelper(root);
    return daInt;
}


int AVLTree :: numNodesHelper(AVLNode* n) const {
    // cout << "this function is even being used" << endl;
    int counter = 1;
    if (n == NULL) {
        return counter;
    }
    if (n->left != NULL) {
        counter += numNodesHelper(n->left);
    }
    if (n->right != NULL) {
        counter += numNodesHelper(n->right);
    }
    return counter;
}













// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    if (height(n->right) - height(n->left) == 2) {
        // cout << "starting left rotation";
        if (height(n->right->right) - height(n->right->left) == -1) {
            rotateRight(n->right);
        }

        rotateLeft(n);
    }
    else if (height(n->right) - height(n->left) == -2) {
        // cout << "starting right rotation" << endl;
        if (height(n->left->right) - height(n->left->left) == 1 ) {
            // cout << "starting right rotation TWO" << endl;
            rotateLeft(n->left);
        }
        // cout << "finishing rotation" << endl;

        rotateRight(n);
        // cout << n->left->value << endl;
        // cout << n->right->value << endl;
        // cout << n->value << endl;
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n)  {
    // YOUR IMPLEMENTATION GOES HERE
    // setting variables
    AVLNode* x = n->right;
    AVLNode* nodey = x-> left;
    // rotey
    x->left = n;
    n->right = nodey;
    // height
    n->height = max(height(n->left), height(n->right)) + 1;
    x->height = max(height(x->left), height(n->right)) + 1;

    n = x;
    return n;

}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n)  {
    // YOUR IMPLEMENTATION GOES HERE
    // setting variables
    AVLNode* x = n->left;
    AVLNode* nodey = x->right;
    // rotey
    x->right = n;
    n->left = nodey;

    // cout << n->right->value << endl;
    // cout << n->left->value << endl;

    // height
    n->height = max(height(n->left), height(n->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    n = x;
    return n;
}



// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}