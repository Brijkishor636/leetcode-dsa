/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void rightSideView(Node *root, vector<int>&result){
        if(root == NULL)
            return;
        queue<pair<Node *, int>>q;
        vector<vector<int>>ans;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, pos] = q.front();
            q.pop();
            if(ans.size() <= pos){
                ans.resize(pos + 1);
            }
            ans[pos].push_back(node->data);
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
  
    vector<int> rightView(Node *root) {
        vector<int>result;
        if(root == NULL)
            return result;
        rightSideView(root, result);
        return result;
    }
};