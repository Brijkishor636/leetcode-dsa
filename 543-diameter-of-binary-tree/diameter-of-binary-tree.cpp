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
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int diameter(TreeNode *root, int &maxi){
        if(root == NULL){
            return maxi;
        }
        int l = Height(root->left);
        int r = Height(root->right);
        maxi = max(maxi, l+r);
        diameter(root->left, maxi);
        diameter(root->right, maxi);
        return maxi;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        return diameter(root, maxi);
    }
};