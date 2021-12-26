// Paolo Vicencio, pjv7nd, TreeCalc.cpp, 3/22/21 
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    while (expressionStack.empty()) {
        cleanTree(expressionStack.top());
    }
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree == NULL) {
        return;
    }
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    if (val == "/" || val == "*" || val == "-" || val == "+") {
        // creating a new tree node for the operator and setting it with the input value
        TreeNode *valuePointer = new TreeNode();
        valuePointer->value = val;
        // creating two new nodes out of the top two elements on the stack and prepping them for
        // left and right placement of the operator
        TreeNode* rightPointer = expressionStack.top();
        // cout << rightPointer->value << endl;
        expressionStack.pop();
        TreeNode* leftPointer = expressionStack.top();
        // cout << leftPointer->value << endl;
        expressionStack.pop();
        // setting up the new tree structure
        valuePointer->right = rightPointer;
        valuePointer->left = leftPointer;
        // adding the new tree back to the stack
        expressionStack.push(valuePointer);

        // cout << valuePointer->value << endl;
        // cout << valuePointer->left->value << endl;
        // cout << valuePointer->right->value << endl;

    }
    else {
        // making the new value pointer
        TreeNode* valuePointer = new TreeNode();
        // setting the new value
        valuePointer->value = val;
        // pushing it to the stack
        expressionStack.push(valuePointer);

 
    }


}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
        cout << tree->value;
        cout << " ";
        
        if (tree->left != NULL) {
            printPrefix(tree->left);
        }
        
        if (tree->right != NULL) {
            printPrefix(tree->right);
        }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    if (tree->left != NULL) {
        cout << "(";
        printInfix(tree->left);
        cout << " ";
    }
    cout << tree->value;

    
    if (tree->right != NULL) {
        cout << " ";
        printInfix(tree->right);
        cout << ")";
    }

}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    if (tree->left != NULL) {
        printPostfix(tree->left);
    }
    if (tree->right != NULL) {
        printPostfix(tree->right);
    }
    cout << tree->value;
    cout << " ";

}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    if (tree->value == "+") {
        int daInt = calculate(tree->left) + calculate(tree->right);
        return daInt;
    }
    if (tree->value == "-") {
        int daInt = calculate(tree->left) - calculate(tree->right);
        return daInt;
    }
    if (tree->value == "*") {
        int daInt = calculate(tree->left) * calculate(tree->right);
        return daInt;
    }
    if (tree->value == "/") {
        int daInt = calculate(tree->left) / calculate(tree->right);
        return daInt;
    }
    else {
        int daInt = stoi(tree->value);
        return daInt;
    }

}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method
    int daInt = calculate(expressionStack.top());
    cleanTree(expressionStack.top());
    
    return daInt;
    
}








