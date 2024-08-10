#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:

    Node *root;

    BinaryTree() {
        root = NULL;
    }

    Node* addRecursive(Node* node, int value) {
        if (node == NULL) return new Node(value);
        if (value < node->data) {
            node->left = addRecursive(node->left, value);
        } 
        else if (value > node->data) {
            node->right = addRecursive(node->right, value);
        } 
        else {
            // value already exists
            return node;
        }
        return node;
    }

    void add(int value) {
        root = addRecursive(root, value);
    }

    bool containsNodeRecursive(Node* node, int value) {
        if (node == NULL) return false;
        if (value == node->data) return true;
        return value < node->data ? containsNodeRecursive(node->left, value) : containsNodeRecursive(node->right, value);
    }

    bool contains(int value) {
        return containsNodeRecursive(root, value);
    }

    Node* removeRecursive(Node* root, int value) {
        // Code to remove a node goes here.
    }

    void remove(int value) {
        root = removeRecursive(root, value);
    }

    void inOrderTraversal(Node* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void printInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    // Testing code goes here.
    return 0;
}