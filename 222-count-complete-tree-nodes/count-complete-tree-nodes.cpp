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
        if(root == NULL)
            return 0;
        int lHeight = Height(root->left);
        int rHeight = Height(root->right);
        return max(lHeight, rHeight) + 1;
    }
    int level(TreeNode *root, int lvl){
        if(root == NULL)
            return 0;
        if(lvl == 1)
            return 1;
        return level(root->left, lvl - 1) + level(root->right, lvl - 1);
    }
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        int h = Height(root);
        int nodes = pow(2, h-1) - 1;
        int lastLevelNodes = level(root, h);
        int totalNodes = nodes + lastLevelNodes;
        return totalNodes;
    }
};