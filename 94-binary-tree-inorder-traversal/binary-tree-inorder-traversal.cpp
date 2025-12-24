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
// class Solution {
// public:
//     void inOrder(TreeNode *root, vector<int>&result){
//         if(root == NULL)
//             return;
//         inOrder(root->left, result);
//         result.push_back(root->val);
//         inOrder(root->right, result);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>result;
//         inOrder(root, result);
//         return result;
//     }
// };


// Using stack ---->

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        if(root == NULL){
            return result;
        }
        stack<TreeNode*>st;
        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};