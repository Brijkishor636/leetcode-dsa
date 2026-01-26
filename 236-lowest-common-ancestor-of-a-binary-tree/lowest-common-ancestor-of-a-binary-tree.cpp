/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL || root == p || root == q){
//             return root;
//         }
//         TreeNode *left = lowestCommonAncestor(root->left, p, q);
//         TreeNode *right = lowestCommonAncestor(root->right, p, q);
//         if(left == NULL){
//             return right;
//         }
//         else if(right == NULL){
//             return left;
//         }
//         else return root;
//     }
// };

class Solution {
public:
    bool rootToNode(TreeNode *root, TreeNode *p, vector<TreeNode*>&ans){
        if(root == NULL){
            return false;
        }
        ans.push_back(root);
        if(root == p){
            return true;
        }
        if(rootToNode(root->left, p, ans) || rootToNode(root->right, p, ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *>ans1, ans2;
        rootToNode(root, p, ans1);
        rootToNode(root, q, ans2);
        int i = 0;
        TreeNode *temp = NULL;
        while(i < ans1.size() && i < ans2.size() && ans1[i] == ans2[i]){
            temp = ans1[i];
            i++;
        }
        return temp;
    }
};