#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N)
// Space Complexity O(N)

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
   
vector<vector<int> > zigzagLevelOrder(TreeNode* A) {
    if(A == NULL) return {};
    vector<vector<int> > result({{A->val}});
    bool reverse = true;
    stack<TreeNode*> level;
    level.push(A);
    while(!level.empty()){
        vector<int> cur;
        stack<TreeNode*> tmp;
        while(!level.empty()){
            TreeNode* node = level.top();
            level.pop();
            if(reverse){
                if(node->right != NULL){
                    cur.push_back(node->right->val);
                    tmp.push(node->right);
                }
                if(node->left != NULL){
                    cur.push_back(node->left->val);
                    tmp.push(node->left);
                }
            }else{
                if(node->left != NULL){
                    cur.push_back(node->left->val);
                    tmp.push(node->left);
                }
                if(node->right != NULL){
                    cur.push_back(node->right->val);
                    tmp.push(node->right);
                }
            }
        }
        if(cur.size() == 0) break;
        result.push_back(cur);
        reverse = !reverse;
        level = tmp;
    }
    return result;
}

int main(){


    return 0;
}