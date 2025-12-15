/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leafCount(Node *root, vector<int>&result){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            result.push_back(root->data);
        }
        else{
            leafCount(root->left, result);
            leafCount(root->right, result);
        }
    }
    
    void rightCount(Node *root, vector<int>&ans){
        if(root == NULL){
            return;
        }
        while (root) {
            if (root->left || root->right)
                ans.push_back(root->data);
            if (root->right)
                root = root->right;
            else
                root = root->left;
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int>result;
        if(root == NULL){
            return result;
        }
        result.push_back(root->data);
        Node* temp = root->left;
        while (temp) {
            if (temp->left || temp->right)
                result.push_back(temp->data);

            if (temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }
        
        temp = root;
        leafCount(temp->left, result);
        leafCount(temp->right, result);
        if(root->right){
            temp = root->right;
            vector<int>ans;
            rightCount(temp, ans);
            reverse(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++){
                result.push_back(ans[i]);
            }
        }
        return result;
    }
};