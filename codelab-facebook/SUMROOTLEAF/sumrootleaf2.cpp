#include <bits/stdc++.h>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbersRec(TreeNode *root, int number) {
    number = (number * 10 + root->val) % 1003;
    if (root->left == NULL && root->right == NULL) return number;
    int leftSide = (root->left) ? sumNumbersRec(root->left, number) : 0;
    int rightSide = (root->right) ? sumNumbersRec(root->right, number) : 0;
    return (leftSide + rightSide) % 1003;
}

int sumNumbers(TreeNode *root) {
    return sumNumbersRec(root, 0); 
}

int main(){


    return 0;
}