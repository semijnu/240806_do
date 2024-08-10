#include<iostream>
#include<vector>
using namespace std;

// Tree Node Structure
struct Node {
    int val;
    Node *left, *right;
};

Node* buildTree(vector<int>& nodes, int i) {
    // 코드를 작성하세요.
}

vector<int> findPath(Node* root, int start, int target) {
    // 코드를 작성하세요.
}

int main() {
    vector<int> nodes;
    int start, target;
    cin >> nodes >> start >> target;
    
    Node* root = buildTree(nodes, 0);
    vector<int> path = findPath(root, start, target);
    for(int i = 0; i < path.size(); i++) 
        cout << path[i] << " ";
    
    return 0;
}