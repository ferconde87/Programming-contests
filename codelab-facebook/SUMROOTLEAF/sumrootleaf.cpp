#include <bits/stdc++.h>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbersRec(TreeNode *root, int curSum) {
    if (root == NULL) return curSum;
    curSum = (curSum * 10 + root->val) % 1003;
    if (root->left == NULL && root->right == NULL) return curSum;
    if (!root->left) return sumNumbersRec(root->right, curSum);
    if (!root->right) return sumNumbersRec(root->left, curSum);
    return (sumNumbersRec(root->left, curSum) + sumNumbersRec(root->right, curSum)) % 1003;
}

int sumNumbers(TreeNode *root) {
    return sumNumbersRec(root, 0); 
}

int main(){


    return 0;
}