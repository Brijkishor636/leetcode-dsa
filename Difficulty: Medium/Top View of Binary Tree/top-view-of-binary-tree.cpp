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
    // void addLeftBoundary(Node *root, vector<int>&result, vector<int>&ans){
    //     if(root == NULL)
    //         return;
    //     while(root){
    //         ans.push_back(root->data);
    //         root = root->left;
    //     }
    //     reverse(ans.begin(), ans.end());
    //     for(int i = 0; i < ans.size(); i++){
    //         result.push_back(ans[i]);
    //     }
    // }
    
    // void addRightBoundary(Node *root, vector<int>&result){
    //     while(root){
    //         result.push_back(root->data);
    //         root = root->right;
    //     }
    // }
    
    void findPos(Node *root, int pos, int &mini, int &maxi) {
        if (root == NULL) {
            return;
        }
        mini = min(mini, pos);
        maxi = max(maxi, pos);
        findPos(root->left, pos - 1, mini, maxi);
        findPos(root->right, pos + 1, mini, maxi);
    }
    
    void alltopData(Node *root, int mini, int maxi, vector<int>&result){
        if(root == NULL){
            return;
        }
        queue<pair<Node *, int>>q;
        vector<vector<int>>neg, pos;
        neg.resize(abs(mini) + 1);
        pos.resize(maxi+1);
        q.push({root, 0});
        while(!q.empty()){
            auto [node, idx] = q.front();
            q.pop();
            if (idx >= 0) {
                if (pos[idx].empty())
                    pos[idx].push_back(node->data);
                } else {
                    if (neg[abs(idx)].empty())
                        neg[abs(idx)].push_back(node->data);
                }
            if(node->left){
                q.push({node->left, idx-1});
            }
            if(node->right){
                q.push({node->right, idx+1});
            }
        }
        
        for(int i = neg.size()-1; i >= 0; i--){
            if(!neg[i].empty())
                result.push_back(neg[i][0]);
        }
        for(int j = 0; j < pos.size(); j++){
            if(!pos[j].empty())
                result.push_back(pos[j][0]);
        }
    }

    
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        int mini = 0;
        int maxi = 0;
        findPos(root, 0, mini, maxi);
        alltopData(root, mini, maxi, result);
        return result;
    }
};