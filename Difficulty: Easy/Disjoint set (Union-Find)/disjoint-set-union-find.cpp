class Solution {
  public:
    int findParent(vector<int>& parent, int x){
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent, parent[x]);
    }
    
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        vector<int> parent(n + 1);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                int z = q[2];
                int px = findParent(parent, x);
                int pz = findParent(parent, z);
                parent[px] = pz;
            } else {
                int x = q[1];
                ans.push_back(findParent(parent, x));
            }
        }

        return ans;
    }
};