#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N)
// Space Complexity O(1)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricHelper(TreeNode *leftTree, TreeNode *rightTree) {
    if (leftTree == NULL || rightTree == NULL) return leftTree == rightTree;
    if (leftTree->val != rightTree->val) return false;
    return isSymmetricHelper(leftTree->left, rightTree->right) && isSymmetricHelper(leftTree->right, rightTree->left);
}


bool isSymmetric(TreeNode *root) {
    return root == NULL || isSymmetricHelper(root->left, root->right);
}


int main(){


    return 0;
}