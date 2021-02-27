#include "BinarySearchTree.h"

// class constrcutor
BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

// iterate in order htougth all nodes
void BinarySearchTree::inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->employee.Number << " " << root->employee.firstName << " "
        << root->employee.lastName << " " << root->employee.yearsOfService << " \n";
    inorder(root->right);
}

// return count of employee's
int BinarySearchTree::count(Node* root) {
    if (root == NULL) {
        return count;
    }

    //itereat throught left subtree and right sub tree
    else {
        count(root->left);
        counter++;
        count(root->right);
    }

    return counter;
}

// method to add object to BST
void BinarySearchTree::add(Employee e) {
    root = insert(e, root);
}

// method to del object from BST
void BinarySearchTree::del(Employee e){
    root = remove(e, root);
}

//return int as count of nodes in BST
void BinarySearchTree::returnCount() {
    cout << "Employee's in BST: " << count(root) << endl;
}

// output all objects to console. 
void BinarySearchTree::display() {
    inorder(root);
}
