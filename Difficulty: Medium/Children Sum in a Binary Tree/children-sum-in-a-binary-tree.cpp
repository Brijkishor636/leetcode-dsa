/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root == NULL){
            return true;
        }
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        int leftSum = root->left ? root->left->data : 0;
        int rightSum = root->right ? root->right->data : 0;
        if(leftSum + rightSum != root->data){
            return false;
        }
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};