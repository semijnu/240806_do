#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

Node* buildTree(vector<int>& nodes, int i) {
    if(i >= nodes.size() || nodes[i] == -1) 
        return NULL;

    Node* node = new Node();
    node->val = nodes[i];
    node->left = buildTree(nodes, 2*i + 1);
    node->right = buildTree(nodes, 2*i + 2);
    return node;
}

bool hasPath(Node* node, vector<int>& path, int target) {
    if(node == NULL)
        return false;

    path.push_back(node->val);

    if(node->val == target)
        return true;

    if(hasPath(node->left, path, target) || hasPath(node->right, path, target))
        return true;

    path.pop_back();

    return false;
}

vector<int> findPath(Node* root, int start, int target) {
    vector<int> path;
    vector<int> result;
    if(!hasPath(root, path, start))
        return result;
    if(!hasPath(root, result, target))
        result.clear();
    return result;
}

int main() {
    vector<int> nodes = {1,2,3,4,5,6,7,8,9};
    int start = 1;
    int target = 9;
    
    Node* root = buildTree(nodes, 0);
    vector<int> path = findPath(root, start, target);
    for(int i = 0; i < path.size(); i++) 
        cout << path[i] << " ";
    
    return 0;
}