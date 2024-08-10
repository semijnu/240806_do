#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            root = new Node();
            root->data = data;
            root->left = root->right = NULL;
        } else if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    int sum(Node* node) {
        if (node == NULL) return 0;
        return (node->data + sum(node->left) + sum(node->right));
    }

    int count(Node* node) {
        if (node == NULL) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    float average(Node* node) {
        if (node == NULL) return 0;
        return float(sum(node)) / float(count(node));
    }
};

int main() {
    Node* root = NULL;
    BinaryTree bt;
    
    int number;
    while (true) {
        cin >> number;
        if (number == -1) break;
        root = bt.insert(root, number);
    } 

    cout << "Sum: " << bt.sum(root) << endl;
    cout << "Average: " << bt.average(root) << endl;
    
    return 0;
}