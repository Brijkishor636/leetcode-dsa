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
//     void postOrder(TreeNode *root, vector<int>&result){
//         if(root == NULL)
//             return;
//         postOrder(root->left, result);
//         postOrder(root->right, result);
//         result.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>result;
//         postOrder(root, result);
//         return result;
//     }
// };


// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>arr;
//         if(root == NULL){
//             return arr;
//         }
//         stack<TreeNode*>st1;
//         stack<TreeNode*>st2;
//         st1.push(root);
//         while(!st1.empty()){
//             root = st1.top();
//             st1.pop();
//             st2.push(root);
//             if(root->left != NULL){
//                 st1.push(root->left);
//             }
//             if(root->right != NULL){
//                 st1.push(root->right);
//             }
//         }
//         while(!st2.empty()){
//             root = st2.top();
//             st2.pop();
//             arr.push_back(root->val);
//         }
//         return arr;
//     }
// };

// Using one stack--->

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>arr;
        if(root == NULL){
            return arr;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            arr.push_back(root->val);
            if(root->left != NULL){
                st.push(root->left);
            }
            if(root->right != NULL){
                st.push(root->right);
            }
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};