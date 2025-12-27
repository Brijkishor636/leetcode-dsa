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
    int maxPath(TreeNode *root, int &maxi){
        if(root == NULL){
            return 0;
        }
        int left = maxPath(root->left, maxi);
        int right = maxPath(root->right, maxi);
        maxi = max(maxi, left+right);
        return (1+max(left, right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};