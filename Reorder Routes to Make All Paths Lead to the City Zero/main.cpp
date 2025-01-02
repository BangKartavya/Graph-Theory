class Solution {
    private:
        vector<vector<int>> adj;
        vector<bool> vis;

        int dfs(int node) {
            int cnt = 0;
            vis[node] = true;

            for(auto i : adj[node]) {
                if(!vis[abs(i)]) {
                    cnt += dfs(abs(i)) + (i > 0);
                }
            }

            return cnt;
        }

    public:
        int minReorder(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n);
            vis.resize(n, false);

            for(auto i : connections) {
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(-i[0]);
            }

            this->adj = adj;

            return dfs(0);
        }
};