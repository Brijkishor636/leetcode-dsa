// User function Template for C++
class Solution {
  public:
    int findParent(int u, vector<int>&parent){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findParent(parent[u], parent);
    }
    
    void union_set(int u, int v, vector<int>&parent, vector<int>&rank){
        int parent_u = findParent(u, parent);
        int parent_v = findParent(v, parent);
        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }
        else{
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        vector<int>parent(V+1);
        for(int i = 0; i <= V; i++){
            parent[i] = i;
        }
        vector<int>rank(V+1, 0);
        
        int sum = 0;
        for(auto temp: edges){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            int p1 = findParent(u, parent);
            int p2 = findParent(v, parent);
            if(p1 != p2){
                union_set(u, v, parent, rank);
                sum = sum + wt;
            }
        }
        return sum;
    }
};