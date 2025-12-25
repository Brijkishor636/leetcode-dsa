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
    void totalSum(TreeNode *root, int &sum, int currentNum){
        if(root == NULL){
            return ;
        }
        currentNum = currentNum * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            sum = sum + currentNum;
            return ;
        }
        totalSum(root->left, sum, currentNum);
        totalSum(root->right, sum, currentNum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if(root == NULL){
            return sum;
        }
        totalSum(root, sum, 0);
        return sum;
    }
};