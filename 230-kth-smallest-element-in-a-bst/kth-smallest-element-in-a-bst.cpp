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
    void smallest(TreeNode *root,int k, vector<int>&arr){
        if(root == NULL){
            return ;
        }
        smallest(root->left, k, arr);
        arr.push_back(root->val);
        smallest(root->right, k, arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return NULL;
        }
        vector<int>arr;
        arr.push_back(0);
        smallest(root, k, arr);
        return arr[k];
    }
};