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
        int l = Height(root->left);
        int r = Height(root->right);
        return max(l, r) + 1;
    }

    void levelOrder(TreeNode *root, vector<int>&ans, int level, bool leftToRight){
        if(root == NULL){
            return ;
        }
        if(level == 0){
            ans.push_back(root->val);
        }
        if(leftToRight){
            levelOrder(root->left, ans, level-1, leftToRight);
            levelOrder(root->right, ans, level-1, leftToRight);
        }
        else{
            levelOrder(root->right, ans, level-1, leftToRight);
            levelOrder(root->left, ans, level-1, leftToRight);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = Height(root);
        vector<vector<int>> result;
        vector<int>ans;
        bool leftToRight = true;
        for(int i = 0; i < h; i++){
            levelOrder(root, ans, i, leftToRight);
            result.push_back(ans);
            ans.clear();
            leftToRight = !leftToRight;
        }
        return result;
    }
};