#pragma once
#include "Employee.h"
#include <iostream>

using namespace std;

class BinarySearchTree
{
private:
    //declare node struct
    struct Node {
        Employee employee;
        Node* left = NULL;
        Node* right = NULL;
    };

    // make a node ptr for root node
    Node* root;
    
    int counter = 0;

    // method to insert 
    Node* insert(Employee e, Node* root)
    {
        // test if BST is empty
        if (root == NULL)
        {
            root = new Node;
            root->employee = e;
            root->left = root->right = NULL;
        }
        // test if its less than 
        else if (e.yearsOfService < root->employee.yearsOfService) {
            root->left = insert(e, root->left);
        }

        // test if its greater than
        else if (e.yearsOfService > root->employee.yearsOfService) {
            root->right = insert(e, root->right);
        }

        return root;
    }

    // minmum method
    Node* minimum(Node* root)
    {
        // check is BST is empty
        if (root == NULL) {
            return NULL;
        }

        // if tree is only root return root
        else if (root->left == NULL) {
            return root;
        }

        else {
            return minimum(root->left);
        }
    }

    //method to delete node from root ptr
    Node* remove(Employee e, Node* root) {

        //temp pointer for copying
        Node* tempPtr;

        //test if is empty
        if (root == NULL)
        {
            cout << "List is empty\n";
            return NULL;
        }

        // test if less than 
        else if (e.yearsOfService < root->employee.yearsOfService) {
            root->left = remove(e, root->left);
        }

        // test if greater than
        else if (e.yearsOfService > root->employee.yearsOfService) {
            root->right = remove(e, root->right);
        }

        else if (root->left && root->right)
        {
            tempPtr = minimum(root->right);
            //copy object
            root->employee = tempPtr->employee;
            root->right = remove(root->employee, root->right);
        }

        else
        {
            tempPtr = root;
            if (root->left == NULL) {
                root = root->right;
            }
            else if (root->right == NULL) {
                root = root->left;

            }
            //delete location in memory
            delete tempPtr;
        }

        return root;
    }

    void inorder(Node* root);
    int count(Node* root);

public:
    //class constructor
    BinarySearchTree();

    // public method for callin in main
    void add(Employee e);
    void del(Employee e);
    void returnCount();
    void display();
};

