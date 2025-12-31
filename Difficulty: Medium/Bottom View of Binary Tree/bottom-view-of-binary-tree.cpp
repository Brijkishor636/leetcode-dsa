/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void findPos(Node *root, int pos, int &mini, int &maxi) {
        if (root == NULL) {
            return;
        }
        mini = min(mini, pos);
        maxi = max(maxi, pos);
        findPos(root->left, pos - 1, mini, maxi);
        findPos(root->right, pos + 1, mini, maxi);
    }
    
    void allbottomData(Node *root, int mini, int maxi, vector<int>&result){
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
                pos[idx].push_back(node->data);
            } else {
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
            if(!neg[i].empty()){
                int size = neg[i].size();
                result.push_back(neg[i][size-1]);
            }
        }
        for(int j = 0; j < pos.size(); j++){
            if(!pos[j].empty()){
                int size = pos[j].size();
                result.push_back(pos[j][size-1]);
            }
        }
    }
  
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        int mini = 0;
        int maxi = 0;
        findPos(root, 0, mini, maxi);
        allbottomData(root, mini, maxi, result);
        return result;
    }
};