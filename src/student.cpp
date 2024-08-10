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
    Node* insert(Node* root, int data);
    int sum(Node* node);
    int count(Node* node);
    float average(Node* node);
};

int main() {
    Node* root;
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