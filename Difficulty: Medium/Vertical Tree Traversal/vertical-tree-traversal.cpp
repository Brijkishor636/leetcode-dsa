/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
vector<vector<int>>ans;
        if (!root) return ans;
        vector<vector<int>>pos, neg;
        queue<pair<Node *, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, col] = q.front();
            q.pop();
            
            if(col >= 0){
                if(col >= pos.size())
                    pos.resize(col+1);
                pos[col].push_back(node->data);
            }
            else{
                int index = -col-1;
                if(index >= neg.size())
                    neg.resize(index+1);
                neg[index].push_back(node->data);
            }

            if(node->left != NULL){
                q.push({node->left, col-1});
            }
            if(node->right != NULL){
                q.push({node->right, col+1});
            }
        }

        for(int i = neg.size()-1; i >= 0; i--){
            ans.push_back(neg[i]);
        }
        for(auto &p : pos){
            ans.push_back(p);
        }
        return ans;
    }
};