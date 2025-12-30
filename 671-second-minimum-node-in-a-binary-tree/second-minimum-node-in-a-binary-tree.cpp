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
    void findSecondMini(TreeNode *root, int &firstMini, long long &secondMini){
        if(root == NULL){
            return ;
        }
        else if(root->val > firstMini && root->val < secondMini){
            secondMini = root->val;
        }
        findSecondMini(root->left, firstMini, secondMini);
        findSecondMini(root->right, firstMini, secondMini);
    }
    int findMini(TreeNode *root, int &mini){
        if(root == NULL){
            return -1;
        }
        else if(root->val < mini){
            mini = root->val;
        }
        findMini(root->left, mini);
        findMini(root->right, mini);
        return mini;
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }
        int mini = INT_MAX;
        int firstMini = findMini(root, mini);
        long long secondMini = LLONG_MAX;
        findSecondMini(root, firstMini, secondMini);
        if(secondMini == LLONG_MAX){
            return -1;
        }
        return secondMini;
    }
};