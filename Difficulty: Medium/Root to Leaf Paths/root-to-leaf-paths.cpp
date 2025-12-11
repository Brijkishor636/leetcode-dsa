/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void getAllPaths(Node *root, vector<vector<int>>&result, vector<int>&ans){
        if(root == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->right == NULL && root->left == NULL){
            result.push_back(ans);
        }
        else{
            getAllPaths(root->left, result, ans);
            getAllPaths(root->right, result, ans);
        }
        ans.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        vector<int> ans;
        getAllPaths(root, result, ans);
        return result;
    }
};