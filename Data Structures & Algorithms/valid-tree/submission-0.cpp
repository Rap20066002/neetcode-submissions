class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for(int nei : adj[node]) {
            if(!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        dfs(0, adj, vis);

        for(int i = 0; i < n; i++) {
            if(!vis[i])
                return false;
        }

        return true;
    }
};