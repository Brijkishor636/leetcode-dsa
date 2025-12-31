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
    void rightView(TreeNode *root, vector<int>&result){
        if(root == NULL)
            return;
        queue<pair<TreeNode *, int>>q;
        vector<vector<int>>ans;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, pos] = q.front();
            q.pop();
            if(ans.size() <= pos){
                ans.resize(pos + 1);
            }
            ans[pos].push_back(node->val);
            if(node->right){
                q.push({node->right, pos+1});
            }
            if(node->left){
                q.push({node->left, pos+1});
            }
        }
        for(int i = 0; i < ans.size(); i++){
            if(!ans[i].empty()){
                result.push_back(ans[i][0]);
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root == NULL)
            return result;
        rightView(root, result);
        return result;
    }
};