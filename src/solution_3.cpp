#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) 
      return t2;
    if (t2 == NULL) 
      return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

int main() {
    TreeNode* root = new TreeNode();
    // TreeNode 개체를 생성하고 여기에 BST를 구축하고 mergeTrees 함수를 호출하여 병합
    cout << "Complete!" << endl;
    return 0;
}