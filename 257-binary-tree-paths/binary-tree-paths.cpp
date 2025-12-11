/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getAllPaths(TreeNode *root, vector<string>&result, string ans){
        if(root == NULL){
            return;
        }
        if(ans.empty()){
            ans += to_string(root->val);
        }
        else{
            ans += "->"+to_string(root->val);
        }
        if(root->left == NULL && root->right == NULL){
            result.push_back(ans);
            return ;
        }
        else{
            getAllPaths(root->left, result, ans);
            getAllPaths(root->right, result, ans);
        }
        ans.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(root == NULL){
            return result;
        }
        getAllPaths(root, result, "");
        return result;
    }
};