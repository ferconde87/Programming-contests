/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

    bool isGreaterThanEveryone(int data, Node* node){
        if(node == NULL) return true;
        return node->data < data && isGreaterThanEveryone(data, node->left) && isGreaterThanEveryone(data, node->right);
    }

    bool isSmallerThanEveryone(int data, Node* node){
        if(node == NULL) return true;
        return node->data > data && isSmallerThanEveryone(data, node->left) && isSmallerThanEveryone(data, node->right);
    }


    bool checkBSTRec(Node* node){
        if(node == NULL) return true;
        if(node->left != NULL && node->right != NULL){
            if(isGreaterThanEveryone(node->data,node->left) && isSmallerThanEveryone(node->data, node->right)){
                return checkBSTRec(node->left) && checkBSTRec(node->right);
            }else{
                return false;
            }
        }
        if(node->left != NULL){
            if(isGreaterThanEveryone(node->data,node->left)){
                return checkBSTRec(node->left);
            }else{
                return false;
            }
        }
        if(node->right != NULL){
            if(isSmallerThanEveryone(node->data, node->right)){
                return checkBSTRec(node->right);
            }else{
                return false;
            }
        }
        return true;
    }    

	bool checkBST(Node* root) {
        return checkBSTRec(root);
	}
