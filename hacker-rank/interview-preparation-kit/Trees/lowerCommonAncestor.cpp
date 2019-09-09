#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    // v1 <= v2
    Node *lcaRec(Node *node, int v1, int v2){
        if(node == NULL){
            return NULL;
        }
        if(node->data < v1){
            return lcaRec(node->right, v1, v2);
        }
        if(node->data > v2){
            return lcaRec(node->left, v1, v2);
        }
        return node;
    }
  
    Node *lca(Node *root, int v1,int v2) {
        if(v1 > v2) return lcaRec(root, v2, v1);
		return lcaRec(root, v1, v2);
    }

}; //End of Solution
