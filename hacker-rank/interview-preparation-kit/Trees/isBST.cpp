    vector<int> v;
    void getTreeDataInOrder(Node * node){
        if(node == NULL) return;
        getTreeDataInOrder(node->left);
        v.push_back(node->data);
        getTreeDataInOrder(node->right);
    }

    bool isStrictlyCrecent(vector<int> & v){
        for(int i = 0; i < v.size() - 1; ++i){
            if(v[i] >= v[i+1]){
                return false;
            }
        }
        return true;
    }

	bool checkBST(Node* root) {
        getTreeDataInOrder(root);
        return isStrictlyCrecent(v);
	}
