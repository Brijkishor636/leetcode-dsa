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
    int Height(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int lheight = Height(root->left);
        int rheight = Height(root->right);
        return max(lheight, rheight) + 1;
    }
    void printcurrentLevel(TreeNode *root, int i, vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(i == 0){
            ans.push_back(root->val);
        }
        else{
            printcurrentLevel(root->left, i-1, ans);
            printcurrentLevel(root->right, i-1, ans);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        vector<int>ans;
        int h = Height(root);
        for(int i = 0; i < h; i++){
            printcurrentLevel(root, i, ans);
            result.push_back(ans);
            ans.clear();
        }
        return result;
    }
};