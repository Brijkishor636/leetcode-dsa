class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil = INT_MAX;
        while(root != NULL){
            if(root->data == x){
                ceil = root->data;
                return ceil;
            }
            else if(root->data > x && root->data < ceil){
                ceil = root->data;
                root = root->left;
            }
            else
                root = root->right;
        }
        return (ceil == INT_MAX)? -1 : ceil;
    }
};
