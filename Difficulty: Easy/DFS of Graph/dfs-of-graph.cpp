class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        stack<int> st;
        vector<int> result;
        int v = adj.size();
        vector<bool> visited(v, false);

        st.push(0);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                visited[node] = true;
                result.push_back(node);

                for (int i = adj[node].size() - 1; i >= 0; i--) {
                    int neighbour = adj[node][i];
                    if (!visited[neighbour]) {
                        st.push(neighbour);
                    }
                }
            }
        }

        return result;
    }
};
