#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N)
// Space Complexity O(N)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 void inOrder(TreeNode * A, vector<int> & result){
    if(A == NULL) return;
    inOrder(A->left, result);
    result.push_back(A->val);
    inOrder(A->right, result);
 }
 
int isSymmetric(TreeNode* A) {
    vector<int> order;
    inOrder(A, order);
    int n = order.size();
    int mid = n/2;
    for(int i = 0; i < mid; i++){
        if(order[i] != order[n-i-1]){
            return 0;
        }
    }
    return 1;
}


int main(){




    return 0;
}