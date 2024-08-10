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

    void add(int value) {
        // Code goes here.
    }

    bool contains(int value) {
        // Code goes here.
    }

    void remove(int value) {
        // Code goes here.
    }

    void inOrderTraversal() {
        // Code goes here.
    }
};

int main() {
    BinaryTree tree;
    // Testing code goes here.
    return 0;
}