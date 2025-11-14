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
    int minElement(TreeNode *root){
        if(root->left == NULL){
            return root->val;
        }
        return minElement(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else{
                int data = minElement(root->right);
                root->val = data;
                root->right = deleteNode(root->right, data);
            }
        }
        return root;
    }
};